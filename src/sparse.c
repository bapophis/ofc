/* Copyright 2015 Codethink Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "ofc/fctype.h"
#include "ofc/file.h"

/*
typedef struct
{
	const char* ptr;
	unsigned    len;
	unsigned    off;
} ofc_sparse_entry_t;
*/
struct ofc_sparse_s
{
	ofc_file_t*   file;
	ofc_sparse_t* parent;

//	unsigned len, count, max_count;
//	ofc_sparse_entry_t* entry;

//	char* strz;

//	ofc_label_table_t* labels;
	ast_sparse_t ast;
	unsigned ref;
};



static ofc_sparse_t* ofc_sparse__create(
	ofc_file_t* file, ofc_sparse_t* parent)
{
	ofc_sparse_t* sparse
		= (ofc_sparse_t*)malloc(
			sizeof(ofc_sparse_t));
	if (!sparse) return NULL;

	sparse->ast.labels
		= ofc_label_table_create();
	if (!sparse->ast.labels)
	{
		free(sparse);
		return NULL;
	}

	sparse->file   = file;
	sparse->parent = parent;

	sparse->ast.len       = 0;
	sparse->ast.count     = 0;
	sparse->ast.max_count = 0;
	sparse->ast.entry     = NULL;

	sparse->ast.strz = NULL;

	sparse->ref = 0;

	return sparse;
}

ofc_sparse_t* ofc_sparse_create_file(ofc_file_t* file)
{
	if (!ofc_file_reference(file))
		return NULL;
	ofc_sparse_t* sparse
		= ofc_sparse__create(file, NULL);
	if (!sparse) ofc_file_delete(file);
	return sparse;
}

ofc_sparse_t* ofc_sparse_create_child(ofc_sparse_t* parent)
{
	if (!ofc_sparse_reference(parent))
		return NULL;

	ofc_sparse_t* sparse
		= ofc_sparse__create(NULL, parent);
	if (!sparse)
	{
		ofc_sparse_delete(parent);
		return NULL;
	}

	/* Lock parent so it can't be modified. */
	ofc_sparse_lock(parent);

	return sparse;
}

bool ofc_sparse_reference(ofc_sparse_t* sparse)
{
	if (!sparse)
		return false;

	unsigned nref = sparse->ref + 1;
	if (nref == 0) return false;

	sparse->ref += 1;
	return true;
}

void ofc_sparse_delete(ofc_sparse_t* sparse)
{
	if (!sparse)
		return;

	if (sparse->ref > 0)
	{
		sparse->ref -= 1;
		return;
	}

	ofc_sparse_delete(sparse->parent);
	ofc_file_delete(sparse->file);

	ofc_label_table_delete(sparse->ast.labels);

	free(sparse->ast.strz);
	free(sparse->ast.entry);
	free(sparse);
}



unsigned ofc_sparse_len(const ofc_sparse_t* sparse)
{
	return (sparse ? sparse->ast.len : 0);
}



bool ofc_sparse_append_strn(
	ofc_sparse_t* sparse,
	const char* src, unsigned len)
{
	if (!sparse)
		return false;
	if (len == 0)
		return true;
	if (!src)
		return false;

	/* If strz has been called disallow further modifications. */
	if (sparse->ast.strz)
		return false;

	if (sparse->ast.count >= sparse->ast.max_count)
	{
		unsigned ncount = (sparse->ast.max_count << 1);
		if (ncount == 0) ncount = 16;

		ofc_sparse_entry_t* nentry = (ofc_sparse_entry_t*)realloc(sparse->ast.entry,
				(sizeof(ofc_sparse_entry_t) * ncount));
		if (!nentry) return false;
		sparse->ast.entry = nentry;
		sparse->ast.max_count = ncount;
	}

	sparse->ast.entry[sparse->ast.count].ptr = src;
	sparse->ast.entry[sparse->ast.count].len = len;
	sparse->ast.entry[sparse->ast.count].off = sparse->ast.len;
	sparse->ast.count++;
	sparse->ast.len += len;

	return true;
}

void ofc_sparse_lock(ofc_sparse_t* sparse)
{
	if (!sparse || sparse->ast.strz)
		return;

	sparse->ast.strz = (char*)malloc(sparse->ast.len + 1);
	if (!sparse->ast.strz) return;

	unsigned i, j;
	for (i = 0, j = 0; i < sparse->ast.count; j += sparse->ast.entry[i++].len)
		memcpy(&sparse->ast.strz[j], sparse->ast.entry[i].ptr, sparse->ast.entry[i].len);
	sparse->ast.strz[j] = '\0';
}

const char* ofc_sparse_strz(const ofc_sparse_t* sparse)
{
	return (sparse ? sparse->ast.strz : NULL);
}


static bool ofc_sparse__ptr(
	const ofc_sparse_t* sparse, const char* ptr,
	ofc_sparse_entry_t* entry, unsigned* offset,
	ofc_sparse_entry_t** prev)
{
	if (!sparse || !sparse->ast.strz || !ptr)
		return false;

	uintptr_t off = ((uintptr_t)ptr - (uintptr_t)sparse->ast.strz);
	if (off > sparse->ast.len)
		return false;

	unsigned mid;
	if (off == sparse->ast.len)
	{
		/* Pointing at end of sparse. */
		mid = (sparse->ast.count - 1);
	}
	else
	{
		unsigned hi  = (sparse->ast.count - 1);
		unsigned lo  = 0;

		for (mid = lo + ((hi - lo) / 2); hi != lo; mid = lo + ((hi - lo) / 2))
		{
			unsigned start = sparse->ast.entry[mid].off;
			unsigned end   = start + sparse->ast.entry[mid].len;

			if (off < start)
				hi = (mid - 1);
			else if (off >= end)
				lo = (mid + 1);
			else
				break;
		}
	}

	off -= sparse->ast.entry[mid].off;

	if (prev  ) *prev   = ((off == 0) && (mid > 0) ? &sparse->ast.entry[mid - 1] : NULL);
	if (entry ) *entry  = sparse->ast.entry[mid];
	if (offset) *offset = off;
	return true;
}

static const ofc_file_t* ofc_sparse__file(
	const ofc_sparse_t* sparse)
{
	if (!sparse)
		return NULL;

	if (sparse->file)
		return sparse->file;

	return ofc_sparse__file(
		sparse->parent);
}


bool ofc_sparse_label_add(
	ofc_sparse_t* sparse, unsigned number)
{
	if (!sparse || sparse->ast.strz)
		return false;
	return ofc_label_table_add(
		sparse->ast.labels, sparse->ast.len, number);
}

bool ofc_sparse_label_find(
	const ofc_sparse_t* sparse, const char* ptr, unsigned* number)
{
	if (!sparse || !sparse->ast.strz)
		return false;

	unsigned offset = ((uintptr_t)ptr - (uintptr_t)sparse->ast.strz);

	if (ofc_label_table_find(
		sparse->ast.labels, offset, number))
		return true;

	if (!sparse->parent)
		return false;

	ofc_sparse_entry_t entry;
	ofc_sparse_entry_t* prev = NULL;

	if (!ofc_sparse__ptr(sparse, ptr,
		&entry, &offset, &prev))
		return false;

	/* If we're at an the start of an entry, ensure there's no label attached
	   to the end of the previous entry. */
	if (prev && ofc_sparse_label_find(
		sparse->parent, &prev->ptr[prev->len], number))
		return true;

	return ofc_sparse_label_find(
		sparse->parent, &entry.ptr[offset], number);
}


bool ofc_sparse_sequential(
	const ofc_sparse_t* sparse, const char* ptr, unsigned size)
{
	if (!sparse || !ptr)
		return false;

	ofc_sparse_entry_t entry;
	unsigned offset;

	if (!ofc_sparse__ptr(
		sparse, ptr,
		&entry, &offset, NULL))
		return NULL;

	return ((offset + size) <= entry.len);
}

const char* ofc_sparse_parent_pointer(
	const ofc_sparse_t* sparse, const char* ptr)
{
	if (!sparse || !ptr)
		return NULL;

	ofc_sparse_entry_t entry;
	unsigned offset;

	if (!ofc_sparse__ptr(
		sparse, ptr,
		&entry, &offset, NULL))
		return NULL;

	return &entry.ptr[offset];
}


const ofc_lang_opts_t* ofc_sparse_lang_opts(const ofc_sparse_t* sparse)
{
	if (!sparse)
		return NULL;

	if (sparse->file)
		return ofc_file_get_lang_opts(sparse->file);

	return ofc_sparse_lang_opts(sparse->parent);
}

const ofc_file_t* ofc_sparse_file(const ofc_sparse_t* sparse)
{
	if (!sparse)
		return NULL;

	return ofc_sparse__file(sparse);
}


bool ofc_sparse_ref_bridge(
	ofc_sparse_ref_t a, ofc_sparse_ref_t b,
	ofc_sparse_ref_t* c)
{
	c->sparse = a.sparse;

	if (ofc_sparse_ref_empty(a))
		c->string = b.string;
	else if (ofc_sparse_ref_empty(b))
		c->string = a.string;
	else if (a.sparse != b.sparse)
		return false;
	else
		c->string = ofc_str_ref_bridge(a.string, b.string);

	return true;
}



static const char* ofc_sparse__file_pointer(
	const ofc_sparse_t* sparse, const char* ptr,
	const char** sol)
{
	ofc_sparse_entry_t entry;
	unsigned offset;

	if (!ofc_sparse__ptr(
		sparse, ptr,
		&entry, &offset, NULL))
		return NULL;

	const char* pptr = &entry.ptr[offset];

	if (sparse->parent)
	{
		return ofc_sparse__file_pointer(
			sparse->parent, pptr, sol);
	}

	/* A sparse with no file or parent, can't have a file pointer. */
	if (!sparse->file)
		return NULL;

	if (sol)
	{
		const char* s = sparse->ast.strz;
		const char* p;
		for (p = sparse->ast.strz; p < ptr; p++)
		{
			if (ofc_is_vspace(*p))
				s = &p[1];
		}

		ofc_sparse_entry_t sol_entry;
		if (ofc_sparse__ptr(
			sparse, s,
			&sol_entry, &offset, NULL))
			*sol = &sol_entry.ptr[offset];
	}

	return pptr;
}

const char* ofc_sparse_file_pointer(
	const ofc_sparse_t* sparse, const char* ptr)
{
	if (!sparse || !ptr)
		return NULL;

	return ofc_sparse__file_pointer(sparse, ptr, NULL);
}

void ofc_sparse_error_va(
	const ofc_sparse_t* sparse, ofc_str_ref_t ref,
	const char* format, va_list args)
{
	const ofc_file_t* file = ofc_sparse__file(sparse);
	const char*       fsol = NULL;
	const char*       fptr = ofc_sparse__file_pointer(sparse, ref.base, &fsol);

	ofc_file_error_va(file, fsol, fptr, format, args);
}

void ofc_sparse_warning_va(
	const ofc_sparse_t* sparse, ofc_str_ref_t ref,
	const char* format, va_list args)
{
	const ofc_file_t* file = ofc_sparse__file(sparse);
	const char*       fsol = NULL;
	const char*       fptr = ofc_sparse__file_pointer(sparse, ref.base, &fsol);

	ofc_file_warning_va(file, fsol, fptr, format, args);
}

void ofc_sparse_error(
	const ofc_sparse_t* sparse, ofc_str_ref_t ref,
	const char* format, ...)
{
	va_list args;
	va_start(args, format);
	ofc_sparse_error_va(sparse, ref, format, args);
	va_end(args);
}

void ofc_sparse_warning(
	const ofc_sparse_t* sparse, ofc_str_ref_t ref,
	const char* format, ...)
{
	va_list args;
	va_start(args, format);
	ofc_sparse_warning_va(sparse, ref, format, args);
	va_end(args);
}

void ofc_sparse_error_ptr(
	const ofc_sparse_t* sparse, const char* ptr,
	const char* format, ...)
{
	va_list args;
	va_start(args, format);
	ofc_sparse_error_va(sparse, ofc_str_ref(ptr, 0), format, args);
	va_end(args);
}

void ofc_sparse_warning_ptr(
	const ofc_sparse_t* sparse, const char* ptr,
	const char* format, ...)
{
	va_list args;
	va_start(args, format);
	ofc_sparse_warning_va(sparse, ofc_str_ref(ptr, 0), format, args);
	va_end(args);
}


void ofc_sparse_ref_error(
	ofc_sparse_ref_t ref,
	const char* format, ...)
{
	va_list args;
	va_start(args, format);
	ofc_sparse_error_va(ref.sparse, ref.string, format, args);
	va_end(args);
}

void ofc_sparse_ref_warning(
	ofc_sparse_ref_t ref,
	const char* format, ...)
{
	va_list args;
	va_start(args, format);
	ofc_sparse_warning_va(ref.sparse, ref.string, format, args);
	va_end(args);
}
