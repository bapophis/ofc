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

#ifndef __ofc_noopt_h__
#define __ofc_noopt_h__

#if defined(__clang__)
#define NO_OPT __attribute__((optnone))
#elif defined(__GNUC__)
#define NO_OPT __attribute__((optimize("O0")))
#else
#warning "Code may optimize incorrectly on some compilers."
#endif

#endif
