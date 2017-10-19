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

#ifndef __ast_sema_scope_h__
#define __ast_sema_scope_h__

//#include <ofc/sema/intrinsic.h>

typedef enum
{
	OFC_SEMA_SCOPE_SUPER = 0,
	OFC_SEMA_SCOPE_GLOBAL,
	OFC_SEMA_SCOPE_PROGRAM,
	OFC_SEMA_SCOPE_STMT_FUNC,
	OFC_SEMA_SCOPE_SUBROUTINE,
	OFC_SEMA_SCOPE_FUNCTION,
	OFC_SEMA_SCOPE_MODULE,
	OFC_SEMA_SCOPE_BLOCK_DATA,

	OFC_SEMA_SCOPE_COUNT
} ofc_sema_scope_e;
/*
typedef struct
{
	unsigned           count;
	ofc_sema_scope_t** scope;
} ofc_sema_scope_list_t;
*/

struct ast_sema_scope_s
{
////	ofc_parse_file_t* file;
////	ofc_sparse_ref_t src;

////	ofc_sema_scope_t*      parent;
////	ofc_sema_scope_list_t* child;

	ofc_sema_scope_e     type;
	ofc_str_ref_t        name;
//	ofc_sema_arg_list_t* args;

	ofc_sema_accessibility_e access;

	bool attr_external;
	bool attr_intrinsic;
	bool attr_save;
	bool attr_recursive;

	bool contains_automatic;

//	ofc_sema_implicit_t*  implicit;

//	ofc_sema_common_map_t*  common;
//	ofc_sema_decl_list_t*   decl;
//	ofc_sema_equiv_list_t*  equiv;
//	ofc_sema_module_list_t* module;
//	ofc_sema_label_map_t*   label;
//	ofc_sema_external_list_t* external;
	// namelist_list_map 

//	ofc_sema_structure_list_t* structure;
//	ofc_sema_structure_list_t* derived_type;

//	ofc_sema_stmt_list_t* stmt;
//	ofc_sema_expr_t*      expr;
};

#endif
