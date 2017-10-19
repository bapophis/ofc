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

#ifndef __ast_sema_structure_h__
#define __ast_sema_structure_h__

typedef enum
{
	OFC_SEMA_STRUCTURE_VAX_STRUCTURE,
	OFC_SEMA_STRUCTURE_VAX_UNION,
	OFC_SEMA_STRUCTURE_VAX_MAP,
	OFC_SEMA_STRUCTURE_F90_TYPE,
	OFC_SEMA_STRUCTURE_F90_TYPE_SEQUENCE,
} ofc_sema_structure_e;

typedef struct ast_sema_structure_s ast_sema_structure_t;
/*
typedef struct
{
	bool is_structure;

	union
	{
		ofc_sema_structure_t* structure;
		ofc_sema_decl_t*      decl;
	};
} ast_sema_structure_member_t;
*/
struct ast_sema_structure_s
{
//	ofc_sparse_ref_t      name;
	ofc_sema_structure_e  type;

//	ofc_sema_implicit_t* implicit;

//	unsigned count;
//	ofc_sema_structure_member_t** member;

//	ofc_hashmap_t* map;

//	unsigned refcnt;
};
/*
typedef struct
{
	unsigned count, size;
	ofc_sema_structure_t** structure;
	ofc_hashmap_t* map;
} ofc_sema_structure_list_t;
*/
#endif
