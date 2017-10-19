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

#ifndef __ast_sema_h__
#define __ast_sema_h__

typedef struct ast_sema_lhs_s ast_sema_lhs_t;

/*
typedef struct ast_sema_stmt_s       ast_sema_stmt_t;
typedef struct ast_sema_scope_s      ast_sema_scope_t;
typedef struct ast_sema_module_s     ast_sema_module_t;
typedef struct ast_sema_type_s       ast_sema_type_t;
typedef struct ast_sema_expr_s       ast_sema_expr_t;
typedef struct ast_sema_lhs_s        ast_sema_lhs_t;
typedef struct ast_sema_decl_s       ast_sema_decl_t;
typedef struct ast_sema_decl_alias_s ast_sema_decl_alias_t;
typedef struct ast_sema_implicit_s   ast_sema_implicit_t;

typedef struct ast_sema_decl_list_s         ast_sema_decl_list_t;
typedef struct ast_sema_decl_alias_map_s    ast_sema_decl_alias_map_t;
typedef struct ast_sema_expr_list_s         ast_sema_expr_list_t;
typedef struct ast_sema_stmt_list_s         ast_sema_stmt_list_t;
typedef struct ast_sema_lhs_list_s          ast_sema_lhs_list_t;
typedef struct ast_sema_module_list_s       ast_sema_module_list_t;
typedef struct ast_sema_format_label_list_s ast_sema_format_label_list_t;
*/

#include <ast/sema/kind.h>
#include <ast/sema/array.h>
//#include <ast/sema/structure.h>
#include <ast/sema/typeval.h>
//#include <ast/sema/parameter.h>
//#include <ast/sema/equiv.h>
//#include <ast/sema/common.h>
//#include <ast/sema/format.h>
//#include <ast/sema/label.h>
//#include <ast/sema/external.h>
//#include <ast/sema/dummy_arg.h>
//#include <ast/sema/intrinsic.h>
//#include <ast/sema/io.h>
#include <ast/sema/arg.h>
//#include <ast/sema/range.h>
#include <ast/sema/accessibility.h>

//#include <ast/sema/stmt.h>
#include <ast/sema/type.h>
#include <ast/sema/expr.h>
#include <ast/sema/lhs.h>
//#include <ast/sema/decl.h>
//#include <ast/sema/implicit.h>
//#include <ast/sema/scope.h>
//#include <ast/sema/module.h>

//#include <ast/sema/pass.h>

#endif
