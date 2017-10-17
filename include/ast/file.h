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

#ifndef __ast_file_h__
#define __ast_file_h__

#include <stdbool.h>
//#include "lang_opts.h"

typedef struct
{
	char**   path;
	unsigned count;
} ast_file_include_list_t;

typedef struct ast_file_s ast_file_t;

struct ast_file_s
{
	const ast_file_t*      parent;

//	ofc_sparse_ref_t include_stmt;

	char*                    path;
	ast_file_include_list_t* include;
	char*                    strz;
//	ofc_lang_opts_t          opts;
//	unsigned                 size;
//	unsigned                 ref;
};
/*
typedef struct
{
	unsigned     count;
	ofc_file_t** file;
} ofc_file_list_t;
*/
#endif
