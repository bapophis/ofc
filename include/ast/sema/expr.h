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

#ifndef __ast_sema_expr_h__
#define __ast_sema_expr_h__

typedef enum
{
	OFC_SEMA_EXPR_CONSTANT = 0,
	OFC_SEMA_EXPR_LHS,
	OFC_SEMA_EXPR_CAST,
	OFC_SEMA_EXPR_INTRINSIC,
	OFC_SEMA_EXPR_FUNCTION,
	OFC_SEMA_EXPR_IMPLICIT_DO,
	OFC_SEMA_EXPR_ARRAY,
	OFC_SEMA_EXPR_RESHAPE,

	OFC_SEMA_EXPR_POWER,
	OFC_SEMA_EXPR_MULTIPLY,
	OFC_SEMA_EXPR_CONCAT,
	OFC_SEMA_EXPR_DIVIDE,
	OFC_SEMA_EXPR_ADD,
	OFC_SEMA_EXPR_SUBTRACT,
	OFC_SEMA_EXPR_NEGATE,
	OFC_SEMA_EXPR_EQ,
	OFC_SEMA_EXPR_NE,
	OFC_SEMA_EXPR_LT,
	OFC_SEMA_EXPR_LE,
	OFC_SEMA_EXPR_GT,
	OFC_SEMA_EXPR_GE,
	OFC_SEMA_EXPR_NOT,
	OFC_SEMA_EXPR_AND,
	OFC_SEMA_EXPR_OR,
	OFC_SEMA_EXPR_XOR,
	OFC_SEMA_EXPR_EQV,
	OFC_SEMA_EXPR_NEQV,

	OFC_SEMA_EXPR_COUNT
} ofc_sema_expr_e;

/*
struct ofc_sema_expr_s
{
	ofc_sema_expr_e type;

	ofc_sparse_ref_t src;//don't move

	ofc_sema_typeval_t* constant;
	ofc_sema_label_t*   label;//has an ast component

	bool brackets;

	unsigned repeat;

	bool is_alt_return;
	bool is_label;
	bool is_format;

	union
	{
		ofc_sema_lhs_t* lhs;

		struct
		{
			const ofc_sema_type_t* type;
			ofc_sema_expr_t*       expr;
		} cast;

		struct
		{
			ofc_sema_expr_t* a;
			ofc_sema_expr_t* b;
		};

		struct
		{
			union
			{
				const ofc_sema_intrinsic_t* intrinsic;
				const ofc_sema_decl_t*      function;
			};
			ofc_sema_dummy_arg_list_t* args;
		};

		struct
		{
			ofc_sema_expr_list_t* expr;
			ofc_sema_decl_t* iter;
			ofc_sema_expr_t* init;
			ofc_sema_expr_t* last;
			ofc_sema_expr_t* step;

			bool     count_var;
			unsigned count;
		} implicit_do;

		ofc_sema_expr_list_t* array;

		struct
		{
			ofc_sema_expr_list_t* source;
			ofc_sema_array_t*     shape;
		} reshape;
	};
};

struct ofc_sema_expr_list_s
{
	unsigned          count;
	ofc_sema_expr_t** expr;
};
*/
#endif
