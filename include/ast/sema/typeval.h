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

#ifndef __ast_sema_typeval_h__
#define __ast_sema_typeval_h__

typedef struct
{
    const ofc_sema_type_t* type;

	ofc_sparse_ref_t src;

	struct
	{
		bool        logical;
		int64_t     integer;
		long double real;

		struct
		{
			long double real;
			long double imaginary;
		} complex;

		char* character;
	};
} ofc_sema_typeval_t;

#endif
