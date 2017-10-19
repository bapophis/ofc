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

#ifndef __ast_sema_lhs_h__
#define __ast_sema_lhs_h__

typedef enum
{
	OFC_SEMA_LHS_DECL,
	OFC_SEMA_LHS_ARRAY_INDEX,
	OFC_SEMA_LHS_ARRAY_SLICE,
	OFC_SEMA_LHS_SUBSTRING,
	OFC_SEMA_LHS_STRUCTURE_MEMBER,
	OFC_SEMA_LHS_IMPLICIT_DO,
} ofc_sema_lhs_e;

struct ast_sema_lhs_s
{
	ofc_sema_lhs_e type;

	ofc_sparse_ref_t src;

	union
	{
		ofc_sema_decl_t* decl;

		struct
		{
			ofc_sema_lhs_list_t* lhs;
			ofc_sema_decl_t* iter;
			ofc_sema_expr_t* init;
			ofc_sema_expr_t* last;
			ofc_sema_expr_t* step;

			bool     count_var;
			unsigned count;
		} implicit_do;

		struct
		{
			ofc_sema_lhs_t* parent;

			union
			{
				struct
				{
					ofc_sema_array_slice_t* slice;
					ofc_sema_array_t*       dims;
				} slice;

				ofc_sema_array_index_t* index;

				struct
				{
					ofc_sema_expr_t* first;
					ofc_sema_expr_t* last;
				} substring;

				ofc_sema_decl_t* member;
			};
		};
	};

//	unsigned refcnt;
};

#endif
