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

#ifndef __ast_sema_type_h__
#define __ast_sema_type_h__

typedef enum
{
	OFC_SEMA_TYPE_LOGICAL = 0,
	OFC_SEMA_TYPE_INTEGER,
	OFC_SEMA_TYPE_REAL,
	OFC_SEMA_TYPE_COMPLEX,
	OFC_SEMA_TYPE_BYTE,
	OFC_SEMA_TYPE_CHARACTER,

	OFC_SEMA_TYPE_POINTER,

	OFC_SEMA_TYPE_FUNCTION,
	OFC_SEMA_TYPE_SUBROUTINE,

	OFC_SEMA_TYPE_TYPE,
	OFC_SEMA_TYPE_RECORD,

	OFC_SEMA_TYPE_COUNT
} ofc_sema_type_e;

struct ofc_sema_type_s
{
	ofc_sema_type_e type;

	union
	{
		const ofc_sema_type_t* subtype;

		struct
		{
			ofc_sema_kind_e kind;

			unsigned len;
			bool     len_var;
		};
	};
};
#endif
