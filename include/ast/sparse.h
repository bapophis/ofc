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

#ifndef __ast_sparse_h__
#define __ast_sparse_h__

#include <stdbool.h>
#include "label_table.h"

typedef struct ast_sparse_s ast_sparse_t;


#include "ast/str_ref.h"

typedef struct
{
	const ast_sparse_t* sparse;
	ofc_str_ref_t       string;
} ast_sparse_ref_t;


typedef struct
{
	const char* ptr;
	unsigned    len;
	unsigned    off;
} ofc_sparse_entry_t;

struct ast_sparse_s
{
//	ofc_file_t*   file;
//	ofc_sparse_t* parent;
	ast_sparse_t* parent; 
	unsigned len, count, max_count;
	ofc_sparse_entry_t* entry;

	char* strz;

	ofc_label_table_t* labels;

//	unsigned ref;
};
/*
#define OFC_SPARSE_REF_EMPTY (ofc_sparse_ref_t){ \
	.sparse = NULL, .string = { .base = NULL, .size = 0 } }
*/


#endif
