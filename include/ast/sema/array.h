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

#ifndef __ast_sema_array_h__
#define __ast_sema_array_h__


typedef struct
{
	ofc_sema_expr_t* first;
	ofc_sema_expr_t* last;
} ofc_sema_array_dims_t;

typedef struct
{
	bool                  scan;
	unsigned              dimensions;
	ofc_sema_array_dims_t segment[0];
} ofc_sema_array_t;


typedef struct
{
	unsigned         dimensions;
	ofc_sema_expr_t* index[0];
} ofc_sema_array_index_t;

typedef struct
{
	bool is_index;
	ofc_sema_expr_t* first;
	ofc_sema_expr_t* last;
	ofc_sema_expr_t* stride;
} ofc_sema_array_segment_t;

typedef struct
{
	unsigned                 dimensions;
	ofc_sema_array_segment_t segment[0];
} ofc_sema_array_slice_t;

#endif
