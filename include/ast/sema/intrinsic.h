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

#ifndef __ast_sema_intrinsic_h__
#define __ast_sema_intrinsic_h__

//typedef struct ofc_sema_intrinsic_s ofc_sema_intrinsic_t;
/*
static const char* ofc_sema_intrinsics__reserved_list[]=
{
	"AdjustL",
	"AdjustR",
	"All",
	"Allocated",
	"Any",
	"Associated",
	"Ceiling",
	"Count",
	"CShift",
	"Digits",
	"Dot_Product",
	"EOShift",
	"Epsilon",
	"Exponent",
	"Floor",
	"Fraction",
	"Huge",
	"Kind",
	"LBound",
	"Logical",
	"MatMul",
	"MaxExponent",
	"MaxLoc",
	"MaxVal",
	"Merge",
	"MinExponent",
	"MinLoc",
	"MinVal",
	"Modulo",
	"Nearest",
	"Pack",
	"Precision",
	"Present",
	"Product",
	"Radix",
	"Random_Number",
	"Random_Seed",
	"Range",
	"Repeat",
	"Reshape",
	"RRSpacing",
	"Scale",
	"Scan",
	"Selected_Int_Kind",
	"Selected_Real_Kind",
	"Set_Exponent",
	"Shape",
	"Spacing",
	"Spread",
	"Sum",
	"Tiny",
	"Transfer",
	"Transpose",
	"Trim",
	"UBound",
	"Unpack",
	"Verify",

	NULL
};
*/
typedef enum
{
	OFC_SEMA_INTRINSIC_OP,
	OFC_SEMA_INTRINSIC_FUNC,
	OFC_SEMA_INTRINSIC_SUBR,

	OFC_SEMA_INTRINSIC_INVALID
} ofc_sema_intrinsic_e;

typedef enum
{
	OFC_SEMA_INTRINSIC__TYPE_NORMAL = 0,
	OFC_SEMA_INTRINSIC__TYPE_ANY,
	OFC_SEMA_INTRINSIC__TYPE_SCALAR,

	/* Same as argument(s) */
	OFC_SEMA_INTRINSIC__TYPE_SAME,

	/* Return type calculated in callback */
	OFC_SEMA_INTRINSIC__TYPE_CALLBACK,
} ofc_sema_intrinsic__type_e;

typedef struct
{
	ofc_sema_intrinsic__type_e type_type;
	ofc_sema_type_e            type;
	ofc_sema_kind_e            kind;
	unsigned                   size;
	bool                       intent_in;
	bool                       intent_out;
} ofc_sema_intrinsic__param_t;

static const ofc_sema_intrinsic__param_t ofc_sema_intrinsic__param[] =
{
	{ OFC_SEMA_INTRINSIC__TYPE_ANY     , 0, OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* ANY  */
	{ OFC_SEMA_INTRINSIC__TYPE_SAME    , 0, OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* SAME */
	{ OFC_SEMA_INTRINSIC__TYPE_SCALAR  , 0, OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* SCALAR */
	{ OFC_SEMA_INTRINSIC__TYPE_CALLBACK, 0, OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* CALLBACK */

	{ 0, OFC_SEMA_TYPE_LOGICAL  , OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* LOGICAL */
	{ 0, OFC_SEMA_TYPE_INTEGER  , OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* INTEGER */
	{ 0, OFC_SEMA_TYPE_REAL     , OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* REAL */
	{ 0, OFC_SEMA_TYPE_COMPLEX  , OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* COMPLEX */
	{ 0, OFC_SEMA_TYPE_CHARACTER, OFC_SEMA_KIND_NONE, 0, 1, 0 }, /* CHARACTER */

	{ 0, OFC_SEMA_TYPE_CHARACTER, OFC_SEMA_KIND_NONE, 1, 1, 0 }, /* CHARACTER_1 */

	{ 0, OFC_SEMA_TYPE_LOGICAL, OFC_SEMA_KIND_DEFAULT, 0, 1, 0 }, /* DEF_LOGICAL */
	{ 0, OFC_SEMA_TYPE_INTEGER, OFC_SEMA_KIND_DEFAULT, 0, 1, 0 }, /* DEF_INTEGER */
	{ 0, OFC_SEMA_TYPE_REAL   , OFC_SEMA_KIND_DEFAULT, 0, 1, 0 }, /* DEF_REAL */
	{ 0, OFC_SEMA_TYPE_COMPLEX, OFC_SEMA_KIND_DEFAULT, 0, 1, 0 }, /* DEF_COMPLEX */

	{ 0, OFC_SEMA_TYPE_REAL   , OFC_SEMA_KIND_DOUBLE, 0, 1, 0 }, /* DEF_DOUBLE */
	{ 0, OFC_SEMA_TYPE_COMPLEX, OFC_SEMA_KIND_DOUBLE, 0, 1, 0 }, /* DEF_DOUBLE_COMPLEX */

	{ 0, OFC_SEMA_TYPE_INTEGER, OFC_SEMA_KIND_HALF, 0, 1, 0 }, /* DEF_HALF_INTEGER */

	{ 0, OFC_SEMA_TYPE_INTEGER, OFC_SEMA_KIND_1_BYTE, 0, 1, 0 }, /* INTEGER_1 */
	{ 0, OFC_SEMA_TYPE_INTEGER, OFC_SEMA_KIND_2_BYTE, 0, 1, 0 }, /* INTEGER_2 */
	{ 0, OFC_SEMA_TYPE_INTEGER, OFC_SEMA_KIND_4_BYTE, 0, 1, 0 }, /* INTEGER_4 */

	{ 0, OFC_SEMA_TYPE_REAL   , OFC_SEMA_KIND_16_BYTE, 0, 1, 0 }, /* REAL_16 */
	{ 0, OFC_SEMA_TYPE_COMPLEX, OFC_SEMA_KIND_16_BYTE, 0, 1, 0 }, /* COMPLEX_32 */

	{ 0, OFC_SEMA_TYPE_REAL, OFC_SEMA_KIND_DEFAULT, 2, 1, 0 }, /* DEF_REAL_A2 */
	{ 0, OFC_SEMA_TYPE_REAL, OFC_SEMA_KIND_DEFAULT, 2, 0, 1 }, /* DEF_REAL_A2_OUT */

	{ 0, OFC_SEMA_TYPE_CHARACTER, OFC_SEMA_KIND_NONE, 0, 0, 1 }, /* CHARACTER_OUT */
	{ 0, OFC_SEMA_TYPE_INTEGER  , OFC_SEMA_KIND_NONE, 0, 0, 1 }, /* INTEGER_OUT */
	{ 0, OFC_SEMA_TYPE_REAL     , OFC_SEMA_KIND_NONE, 0, 0, 1 }, /* REAL_OUT */

	{ 0, OFC_SEMA_TYPE_INTEGER, OFC_SEMA_KIND_NONE,  3, 0, 1 }, /* INTEGER_A3_OUT */
	{ 0, OFC_SEMA_TYPE_INTEGER, OFC_SEMA_KIND_NONE, 13, 1, 0 }, /* INTEGER_A13 */
	{ 0, OFC_SEMA_TYPE_INTEGER, OFC_SEMA_KIND_NONE, 13, 0, 1 }, /* INTEGER_A13_OUT */
};


typedef enum
{
	IP_ANY = 0,  /* Any type */
	IP_SAME,     /* Same as argument */
	IP_SCALAR,   /* Any scalar type */
	IP_CALLBACK, /* Use a callback to determine return type. */

	IP_LOGICAL,
	IP_INTEGER,
	IP_REAL,
	IP_COMPLEX,
	IP_CHARACTER,

	IP_CHARACTER_1,

	IP_DEF_LOGICAL,
	IP_DEF_INTEGER,
	IP_DEF_REAL,
	IP_DEF_COMPLEX,

	IP_DEF_DOUBLE,
	IP_DEF_DOUBLE_COMPLEX,

	IP_DEF_HALF_INTEGER,

	IP_INTEGER_1,
	IP_INTEGER_2,
	IP_INTEGER_4,

	IP_REAL_16,
	IP_COMPLEX_32,

	IP_DEF_REAL_A2,
	IP_DEF_REAL_A2_OUT,

	IP_INTEGER_OUT,
	IP_REAL_OUT,
	IP_CHARACTER_OUT,

	IP_INTEGER_A3_OUT,
	IP_INTEGER_A13,
	IP_INTEGER_A13_OUT,

	IP_COUNT
} ofc_sema_intrinsic__param_e;

/*
typedef struct
{
	const char*                 name;
	unsigned                    arg_min, arg_max;
	ofc_sema_intrinsic__param_e return_type;
	ofc_sema_intrinsic__param_e arg_type;

	ofc_sema_typeval_t* (*constant)(
		const ofc_sema_intrinsic_t*,
		const ofc_sema_dummy_arg_list_t*);
} ofc_sema_intrinsic_op_t;
*/
/*
static const ofc_sema_intrinsic_op_t ofc_sema_intrinsic__op_list[] =
{
	//Casts
	{ "INT"   , 1, 1, IP_DEF_INTEGER        , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "IFIX"  , 1, 1, IP_DEF_INTEGER        , IP_DEF_REAL          , ofc_sema_intrinsic_op__constant_cast },
	{ "IDINT" , 1, 1, IP_DEF_INTEGER        , IP_DEF_DOUBLE        , ofc_sema_intrinsic_op__constant_cast },
	{ "IQINT" , 1, 1, IP_DEF_INTEGER        , IP_REAL_16           , ofc_sema_intrinsic_op__constant_cast },
	{ "HFIX"  , 1, 1, IP_DEF_HALF_INTEGER   , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "INT1"  , 1, 1, IP_INTEGER_1          , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "INT2"  , 1, 1, IP_INTEGER_2          , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "INT4"  , 1, 1, IP_INTEGER_4          , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "INTC"  , 1, 1, IP_INTEGER_2          , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "JFIX"  , 1, 1, IP_INTEGER_4          , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "REAL"  , 1, 1, IP_DEF_REAL           , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "FLOAT" , 1, 1, IP_DEF_REAL           , IP_DEF_INTEGER       , ofc_sema_intrinsic_op__constant_cast },
	{ "SNGL"  , 1, 1, IP_DEF_REAL           , IP_DEF_DOUBLE        , ofc_sema_intrinsic_op__constant_cast },
	{ "SNGLQ" , 1, 1, IP_DEF_REAL           , IP_REAL_16           , ofc_sema_intrinsic_op__constant_cast },
	{ "DBLE"  , 1, 1, IP_DEF_DOUBLE         , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "DFLOAT", 1, 1, IP_DEF_DOUBLE         , IP_DEF_INTEGER       , ofc_sema_intrinsic_op__constant_cast },
	{ "DREAL" , 1, 1, IP_DEF_DOUBLE         , IP_DEF_DOUBLE_COMPLEX, ofc_sema_intrinsic_op__constant_cast },
	{ "DBLEQ" , 1, 1, IP_DEF_DOUBLE         , IP_REAL_16           , ofc_sema_intrinsic_op__constant_cast },
	{ "QREAL" , 1, 1, IP_REAL_16            , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "QFLOAT", 1, 1, IP_REAL_16            , IP_DEF_INTEGER       , ofc_sema_intrinsic_op__constant_cast },
	// http://kiwi.atmos.colostate.edu/rr/tidbits/xlf/pgs/lr298.htm 
	{ "QEXT"  , 1, 1, IP_REAL_16            , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "QEXTD" , 1, 1, IP_REAL_16            , IP_DEF_DOUBLE        , ofc_sema_intrinsic_op__constant_cast },
	{ "CMPLX" , 1, 2, IP_DEF_COMPLEX        , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "DCMPLX", 1, 2, IP_DEF_DOUBLE_COMPLEX , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },
	{ "QCMPLX", 1, 2, IP_COMPLEX_32         , IP_ANY               , ofc_sema_intrinsic_op__constant_cast },

	// Truncation 
	{ "AINT", 1, 1, IP_SAME, IP_REAL      , NULL },
	{ "DINT", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QINT", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	// Rounding 
	{ "ANINT" , 1, 1, IP_SAME       , IP_REAL      , NULL },
	{ "DNINT" , 1, 1, IP_SAME       , IP_DEF_DOUBLE, NULL },
	{ "QNINT" , 1, 1, IP_SAME       , IP_REAL_16   , NULL },
	{ "NINT"  , 1, 1, IP_DEF_INTEGER, IP_REAL      , NULL },
	{ "IDNINT", 1, 1, IP_DEF_INTEGER, IP_DEF_DOUBLE, NULL },
	{ "IQNINT", 1, 1, IP_DEF_INTEGER, IP_REAL_16   , NULL },

	{ "ABS"  , 1, 1, IP_SCALAR    , IP_ANY               , NULL },
	{ "IABS" , 1, 1, IP_SAME      , IP_DEF_INTEGER       , NULL },
	{ "DABS" , 1, 1, IP_SAME      , IP_DEF_DOUBLE        , NULL },
	{ "CABS" , 1, 1, IP_DEF_REAL  , IP_DEF_COMPLEX       , NULL },
	{ "QABS" , 1, 1, IP_SAME      , IP_REAL_16           , NULL },
	{ "ZABS" , 1, 1, IP_DEF_DOUBLE, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CDABS", 1, 1, IP_DEF_DOUBLE, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CQABS", 1, 1, IP_SAME      , IP_COMPLEX_32        , NULL },

	{ "MOD"   , 2, 2, IP_SAME, IP_SCALAR    , NULL },
	{ "AMOD"  , 2, 2, IP_SAME, IP_DEF_REAL  , NULL },
	{ "DMOD"  , 2, 2, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QMOD"  , 2, 2, IP_SAME, IP_REAL_16   , NULL },
	{ "MODULO", 2, 2, IP_SAME, IP_SCALAR    , NULL },

	{ "FLOOR"  , 1, 1, IP_SAME, IP_REAL, NULL },
	{ "CEILING", 1, 1, IP_SAME, IP_REAL, NULL },


	// Transfer of sign 
	{ "SIGN" , 2, 2, IP_SAME, IP_SCALAR     , NULL },
	{ "ISIGN", 2, 2, IP_SAME, IP_DEF_INTEGER, NULL },
	{ "DSIGN", 2, 2, IP_SAME, IP_DEF_DOUBLE , NULL },
	{ "QSIGN", 2, 2, IP_SAME, IP_REAL_16    , NULL },

	// Positive difference 
	{ "DIM" , 2, 2, IP_SAME, IP_SCALAR     , NULL },
	{ "IDIM", 2, 2, IP_SAME, IP_DEF_INTEGER, NULL },
	{ "DDIM", 2, 2, IP_SAME, IP_DEF_DOUBLE , NULL },
	{ "QDIM", 2, 2, IP_SAME, IP_REAL_16    , NULL },

	// Inner product 
	{ "DPROD", 2, 2, IP_DEF_DOUBLE, IP_DEF_REAL, NULL },
	{ "QPROD", 2, 2, IP_DEF_DOUBLE, IP_REAL_16 , NULL },

	{ "MAX"  , 2, 0, IP_SAME       , IP_SCALAR     , NULL },
	{ "MAX0" , 2, 0, IP_SAME       , IP_DEF_INTEGER, NULL },
	{ "AMAX1", 2, 0, IP_SAME       , IP_DEF_REAL   , NULL },
	{ "DMAX1", 2, 0, IP_SAME       , IP_DEF_DOUBLE , NULL },
	{ "QMAX1", 2, 0, IP_SAME       , IP_REAL_16    , NULL },
	{ "AMAX0", 2, 0, IP_DEF_REAL   , IP_DEF_INTEGER, NULL },
	{ "MAX1" , 2, 0, IP_DEF_INTEGER, IP_DEF_REAL   , NULL },
	{ "MIN"  , 2, 0, IP_SAME       , IP_SCALAR     , NULL },
	{ "MIN0" , 2, 0, IP_SAME       , IP_DEF_INTEGER, NULL },
	{ "AMIN1", 2, 0, IP_SAME       , IP_DEF_REAL   , NULL },
	{ "DMIN1", 2, 0, IP_SAME       , IP_DEF_DOUBLE , NULL },
	{ "QMIN1", 2, 0, IP_SAME       , IP_REAL_16    , NULL },
	{ "AMIN0", 2, 0, IP_DEF_REAL   , IP_DEF_INTEGER, NULL },
	{ "MIN1" , 2, 0, IP_DEF_INTEGER, IP_DEF_REAL   , NULL },

	{ "IMAG" , 1, 1, IP_REAL      , IP_COMPLEX           , NULL},
	{ "AIMAG", 1, 1, IP_DEF_REAL  , IP_DEF_COMPLEX       , NULL},
	{ "DIMAG", 1, 1, IP_DEF_DOUBLE, IP_DEF_DOUBLE_COMPLEX, NULL},
	{ "QIMAG", 1, 1, IP_REAL_16   , IP_COMPLEX_32        , NULL},

	{ "CONJG" , 1, 1, IP_SAME, IP_COMPLEX           , NULL},
	{ "DCONJG", 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL},
	{ "QCONJG", 1, 1, IP_SAME, IP_COMPLEX_32        , NULL},

	{ "SQRT"  , 1, 1, IP_SAME, IP_ANY               , NULL },
	{ "DSQRT" , 1, 1, IP_SAME, IP_DEF_DOUBLE        , NULL },
	{ "QSQRT" , 1, 1, IP_SAME, IP_REAL_16           , NULL },
	{ "CSQRT" , 1, 1, IP_SAME, IP_DEF_COMPLEX       , NULL },
	{ "ZSQRT" , 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CDSQRT", 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CQSQRT", 1, 1, IP_SAME, IP_COMPLEX_32        , NULL },

	{ "CBRT"  , 1, 1, IP_SAME, IP_ANY               , NULL },
	{ "DCBRT" , 1, 1, IP_SAME, IP_DEF_DOUBLE        , NULL },
	{ "QCBRT" , 1, 1, IP_SAME, IP_REAL_16           , NULL },
	{ "CCBRT" , 1, 1, IP_SAME, IP_DEF_COMPLEX       , NULL },
	{ "ZCBRT" , 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CDCBRT", 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CQCBRT", 1, 1, IP_SAME, IP_COMPLEX_32        , NULL },

	{ "EXP"  , 1, 1, IP_SAME, IP_ANY               , NULL },
	{ "DEXP" , 1, 1, IP_SAME, IP_DEF_DOUBLE        , NULL },
	{ "QEXP" , 1, 1, IP_SAME, IP_REAL_16           , NULL },
	{ "CEXP" , 1, 1, IP_SAME, IP_DEF_COMPLEX       , NULL },
	{ "ZEXP" , 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CDEXP", 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CQEXP", 1, 1, IP_SAME, IP_COMPLEX_32        , NULL },

	{ "LOG"  , 1, 1, IP_SAME, IP_ANY               , NULL },
	{ "ALOG" , 1, 1, IP_SAME, IP_DEF_REAL          , NULL },
	{ "DLOG" , 1, 1, IP_SAME, IP_DEF_DOUBLE        , NULL },
	{ "QLOG" , 1, 1, IP_SAME, IP_REAL_16           , NULL },
	{ "CLOG" , 1, 1, IP_SAME, IP_DEF_COMPLEX       , NULL },
	{ "ZLOG" , 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CDLOG", 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CQLOG", 1, 1, IP_SAME, IP_COMPLEX_32        , NULL },

	{ "LOG10" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "ALOG10", 1, 1, IP_SAME, IP_DEF_REAL  , NULL },
	{ "DLOG10", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QLOG10", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	// Trigonometric functions 
	{ "SIN"  , 1, 1, IP_SAME, IP_ANY               , NULL },
	{ "DSIN" , 1, 1, IP_SAME, IP_DEF_DOUBLE        , NULL },
	{ "CSIN" , 1, 1, IP_SAME, IP_DEF_COMPLEX       , NULL },
	{ "QSIN" , 1, 1, IP_SAME, IP_REAL_16           , NULL },
	{ "ZSIN" , 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CDSIN", 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CQSIN", 1, 1, IP_SAME, IP_COMPLEX_32        , NULL },
	{ "SIND" , 1, 1, IP_SAME, IP_ANY               , NULL },
	{ "DSIND", 1, 1, IP_SAME, IP_DEF_DOUBLE        , NULL },
	{ "QSIND", 1, 1, IP_SAME, IP_REAL_16           , NULL },

	{ "COS"  , 1, 1, IP_SAME, IP_ANY               , NULL },
	{ "DCOS" , 1, 1, IP_SAME, IP_DEF_DOUBLE        , NULL },
	{ "CCOS" , 1, 1, IP_SAME, IP_DEF_COMPLEX       , NULL },
	{ "QCOS" , 1, 1, IP_SAME, IP_REAL_16           , NULL },
	{ "ZCOS" , 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CDCOS", 1, 1, IP_SAME, IP_DEF_DOUBLE_COMPLEX, NULL },
	{ "CQCOS", 1, 1, IP_SAME, IP_COMPLEX_32        , NULL },
	{ "COSD" , 1, 1, IP_SAME, IP_ANY               , NULL },
	{ "DCOSD", 1, 1, IP_SAME, IP_DEF_DOUBLE        , NULL },
	{ "QCOSD", 1, 1, IP_SAME, IP_REAL_16           , NULL },

	{ "TAN"  , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DTAN" , 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QTAN" , 1, 1, IP_SAME, IP_REAL_16   , NULL },
	{ "TAND" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DTAND", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QTAND", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "ASIN"  , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DASIN" , 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QASIN" , 1, 1, IP_SAME, IP_REAL_16   , NULL },
	{ "ASIND" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DASIND", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QASIND", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "ACOS"  , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DACOS" , 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QACOS" , 1, 1, IP_SAME, IP_REAL_16   , NULL },
	{ "ACOSD" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DACOSD", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QACOSD", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "ATAN"  , 1, 2, IP_SAME, IP_ANY       , NULL },
	{ "DATAN" , 1, 2, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QATAN" , 1, 2, IP_SAME, IP_REAL_16   , NULL },
	{ "ATAN2" , 2, 2, IP_SAME, IP_ANY       , NULL },
	{ "DATAN2", 2, 2, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QATAN2", 2, 2, IP_SAME, IP_REAL_16   , NULL },

	{ "SINH" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DSINH", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QSINH", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "COSH" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DCOSH", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QCOSH", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "TANH" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DTANH", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QTANH", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "ASINH" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DASINH", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QASINH", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "ACOSH" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DACOSH", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QACOSH", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "ATANH" , 1, 1, IP_SAME, IP_ANY       , NULL },
	{ "DATANH", 1, 1, IP_SAME, IP_DEF_DOUBLE, NULL },
	{ "QATANH", 1, 1, IP_SAME, IP_REAL_16   , NULL },

	{ "IAND", 2, 2, IP_SAME, IP_INTEGER, ofc_sema_intrinsic_op__constant_iand },
	{ "IEOR", 2, 2, IP_SAME, IP_INTEGER, ofc_sema_intrinsic_op__constant_ieor },
	{ "IOR" , 2, 2, IP_SAME, IP_INTEGER, ofc_sema_intrinsic_op__constant_ior },
	{ "NOT" , 1, 1, IP_SAME, IP_INTEGER, ofc_sema_intrinsic_op__constant_not },

	{ NULL, 0, 0, 0, 0, NULL }
};

// For the specific functions that are also generic 
static const ofc_sema_intrinsic_op_t ofc_sema_intrinsic__op_list_override[] =
{
	{ "AINT" , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "ANINT", 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "NINT" , 1, 1, IP_DEF_INTEGER, IP_DEF_REAL    , NULL },
	{ "ABS"  , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "MOD"  , 2, 2, IP_SAME,        IP_DEF_INTEGER , NULL },
	{ "SIGN" , 2, 2, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "DIM"  , 2, 2, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "SQRT" , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "EXP"  , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "SIN"  , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "COS"  , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "TAN"  , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "ASIN" , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "ACOS" , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "ATAN" , 1, 2, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "ATAN2", 2, 2, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "SINH" , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "COSH" , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "TANH" , 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "ASINH", 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "ACOSH", 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "ATANH", 1, 1, IP_SAME,        IP_DEF_REAL    , NULL },
	{ "DBLE" , 1, 1, IP_DEF_DOUBLE,  IP_INTEGER     , ofc_sema_intrinsic_op__constant_cast },
	{ "QEXT" , 1, 1, IP_REAL_16   ,  IP_DEF_INTEGER , ofc_sema_intrinsic_op__constant_cast },

	{ NULL, 0, 0, 0, 0, NULL }

};
*/
/*
typedef struct
{
	const char*                 name;
	unsigned                    arg_min, arg_max;
	ofc_sema_intrinsic__param_e return_type;
	ofc_sema_intrinsic__param_e arg_type[4];

	const ofc_sema_type_t* (*return_type_callback)(const ofc_sema_dummy_arg_list_t*);

	ofc_sema_typeval_t* (*constant)(
		const ofc_sema_intrinsic_t*,
		const ofc_sema_dummy_arg_list_t*);
} ofc_sema_intrinsic_func_t;

static const ofc_sema_intrinsic_func_t ofc_sema_intrinsic__func_list[] =
{
	{ "MClock",  0, 0, IP_INTEGER_1, { 0 }, NULL, NULL },
	{ "MClock8", 0, 0, IP_INTEGER_2, { 0 }, NULL, NULL },
	{ "FDate",   0, 0, IP_CHARACTER, { 0 }, NULL, NULL },
	{ "Second",  0, 0, IP_DEF_REAL,  { 0 }, NULL, NULL },

	{ "Loc",      1, 1, IP_DEF_INTEGER, { IP_ANY           }, NULL, NULL },
	{ "IRand",    0, 1, IP_DEF_INTEGER, { IP_INTEGER       }, NULL, NULL },
	{ "LnBlnk",   1, 1, IP_DEF_INTEGER, { IP_CHARACTER     }, NULL, NULL },
	{ "IsaTty",   1, 1, IP_DEF_LOGICAL, { IP_INTEGER       }, NULL, NULL },
	{ "AImag",    1, 1, IP_REAL,        { IP_DEF_COMPLEX   }, NULL, NULL },
	{ "Len_Trim", 1, 1, IP_DEF_INTEGER, { IP_CHARACTER     }, NULL, NULL },
	{ "BesJ0",    1, 1, IP_REAL,        { IP_REAL          }, NULL, NULL },
	{ "BesJ1",    1, 1, IP_REAL,        { IP_REAL          }, NULL, NULL },
	{ "BesJN",    1, 1, IP_DEF_INTEGER, { IP_REAL          }, NULL, NULL },
	{ "BesY0",    1, 1, IP_REAL,        { IP_REAL          }, NULL, NULL },
	{ "BesY1",    1, 1, IP_REAL,        { IP_REAL          }, NULL, NULL },
	{ "CTime",    1, 1, IP_CHARACTER,   { IP_INTEGER       }, NULL, NULL },
	{ "DErF",     1, 1, IP_DEF_DOUBLE,  { IP_DEF_DOUBLE    }, NULL, NULL },
	{ "DErFC",    1, 1, IP_DEF_DOUBLE,  { IP_DEF_DOUBLE    }, NULL, NULL },
	{ "ErF",      1, 1, IP_REAL,        { IP_REAL          }, NULL, NULL },
	{ "ErFC",     1, 1, IP_REAL,        { IP_REAL          }, NULL, NULL },
	{ "ETime",    1, 1, IP_DEF_REAL,    { IP_DEF_REAL_A2   }, NULL, NULL },
	{ "FTell",    1, 1, IP_DEF_INTEGER, { IP_INTEGER       }, NULL, NULL },
	{ "GetCWD",   1, 1, IP_DEF_INTEGER, { IP_CHARACTER_OUT }, NULL, NULL },
	{ "HostNm",   1, 1, IP_DEF_INTEGER, { IP_CHARACTER_OUT }, NULL, NULL },
	{ "TtyNam",   1, 1, IP_CHARACTER,   { IP_INTEGER       }, NULL, NULL },

	{ "Stat",   2, 2, IP_DEF_INTEGER, { IP_CHARACTER, IP_INTEGER_A13_OUT }, NULL, NULL },
	{ "LStat",  2, 2, IP_DEF_INTEGER, { IP_CHARACTER, IP_INTEGER_A13_OUT }, NULL, NULL },
	{ "FStat",  2, 2, IP_DEF_INTEGER, { IP_INTEGER  , IP_INTEGER_A13_OUT }, NULL, NULL },
	{ "Access", 2, 2, IP_DEF_INTEGER, { IP_CHARACTER, IP_CHARACTER       }, NULL, NULL },
	{ "LGe",    2, 2, IP_DEF_LOGICAL, { IP_CHARACTER, IP_CHARACTER       }, NULL, NULL },
	{ "LGt",    2, 2, IP_DEF_LOGICAL, { IP_CHARACTER, IP_CHARACTER       }, NULL, NULL },
	{ "LLe",    2, 2, IP_DEF_LOGICAL, { IP_CHARACTER, IP_CHARACTER       }, NULL, NULL },
	{ "LLt",    2, 2, IP_DEF_LOGICAL, { IP_CHARACTER, IP_CHARACTER       }, NULL, NULL },
	{ "LShift", 2, 2, IP_DEF_INTEGER, { IP_INTEGER  , IP_INTEGER         }, NULL, NULL },
	{ "IShft",  2, 2, IP_INTEGER,     { IP_INTEGER  , IP_INTEGER         }, NULL, NULL },
	{ "BesYN",  2, 2, IP_REAL,        { IP_INTEGER  , IP_REAL            }, NULL, NULL },
	{ "BTest",  2, 2, IP_DEF_LOGICAL, { IP_INTEGER  , IP_INTEGER         }, NULL, NULL },

	{ "IShftC", 3, 3, IP_INTEGER, { IP_INTEGER, IP_INTEGER, IP_INTEGER }, NULL, NULL },

	{ "Len", 1, 2, IP_CALLBACK, { IP_CHARACTER, IP_INTEGER },
		ofc_sema_intrinsic__len_rt, ofc_sema_intrinsic__len_tv },

	{ "Char" , 1, 2, IP_CALLBACK, { IP_INTEGER    , IP_INTEGER },
		ofc_sema_intrinsic__char_rt, ofc_sema_intrinsic__char_tv },
	{ "AChar", 1, 2, IP_CALLBACK, { IP_INTEGER    , IP_INTEGER },
		ofc_sema_intrinsic__char_rt, ofc_sema_intrinsic__char_tv },
	{ "IChar", 1, 2, IP_CALLBACK, { IP_CHARACTER_1, IP_INTEGER },
		ofc_sema_intrinsic__ichar_rt, ofc_sema_intrinsic__ichar_tv },
	{ "IAChar", 1, 2, IP_CALLBACK, { IP_CHARACTER_1, IP_INTEGER },
		ofc_sema_intrinsic__ichar_rt, ofc_sema_intrinsic__ichar_tv },

	{ "Index", 2, 4, IP_INTEGER, { IP_CHARACTER, IP_CHARACTER, IP_LOGICAL, IP_INTEGER },
		NULL, NULL },

	{ "Transfer", 2, 3, IP_CALLBACK, { IP_ANY, IP_ANY, IP_INTEGER },
		ofc_sema_intrinsic__transfer_rt,
		ofc_sema_intrinsic__transfer_tv },

	{ NULL, 0, 0, 0, { 0 }, NULL, NULL }
};

static const ofc_sema_intrinsic_func_t ofc_sema_intrinsic__subr_list[] =
{
	{ "ITime",  1, 1, 0, { IP_INTEGER_A3_OUT }, NULL, NULL },
	{ "FDate",  1, 1, 0, { IP_CHARACTER_OUT  }, NULL, NULL },
	{ "Second", 1, 1, 0, { IP_REAL_OUT       }, NULL, NULL },

	{ "ChDir",  1, 2, 0, { IP_CHARACTER      , IP_INTEGER_OUT   }, NULL, NULL },
	{ "LTime",  2, 2, 0, { IP_INTEGER        , IP_CHARACTER_OUT }, NULL, NULL },
	{ "CTime",  2, 2, 0, { IP_INTEGER        , IP_CHARACTER_OUT }, NULL, NULL },
	{ "DTime",  2, 2, 0, { IP_DEF_REAL_A2_OUT, IP_REAL_OUT      }, NULL, NULL },
	{ "ETime",  2, 2, 0, { IP_DEF_REAL_A2_OUT, IP_REAL_OUT      }, NULL, NULL },
	{ "FGet",   1, 2, 0, { IP_CHARACTER_OUT  , IP_INTEGER_OUT   }, NULL, NULL },
	{ "FPut",   1, 2, 0, { IP_CHARACTER      , IP_INTEGER_OUT   }, NULL, NULL },
	{ "FTell",  2, 2, 0, { IP_INTEGER        , IP_INTEGER_OUT   }, NULL, NULL },
	{ "GetCWD", 1, 2, 0, { IP_CHARACTER_OUT  , IP_INTEGER_OUT   }, NULL, NULL },
	{ "HostNm", 1, 2, 0, { IP_CHARACTER_OUT  , IP_INTEGER_OUT   }, NULL, NULL },
	{ "System", 1, 2, 0, { IP_CHARACTER      , IP_INTEGER_OUT   }, NULL, NULL },
	{ "TtyNam", 2, 2, 0, { IP_INTEGER        , IP_CHARACTER_OUT }, NULL, NULL },
	{ "UMask",  1, 2, 0, { IP_INTEGER        , IP_INTEGER_OUT   }, NULL, NULL },
	{ "Unlink", 1, 2, 0, { IP_CHARACTER      , IP_INTEGER_OUT   }, NULL, NULL },

	{ "ChMod",  2, 3, 0, { IP_CHARACTER, IP_CHARACTER      , IP_INTEGER_OUT }, NULL, NULL },
	{ "SymLnk", 2, 3, 0, { IP_CHARACTER, IP_CHARACTER      , IP_INTEGER_OUT }, NULL, NULL },
	{ "Kill",   2, 3, 0, { IP_INTEGER  , IP_INTEGER        , IP_INTEGER_OUT }, NULL, NULL },
	{ "Stat",   2, 3, 0, { IP_CHARACTER, IP_INTEGER_A13_OUT, IP_INTEGER_OUT }, NULL, NULL },
	{ "FStat",  2, 3, 0, { IP_INTEGER  , IP_INTEGER_A13_OUT, IP_INTEGER_OUT }, NULL, NULL },
	{ "LStat",  2, 3, 0, { IP_CHARACTER, IP_INTEGER_A13_OUT, IP_INTEGER_OUT }, NULL, NULL },
	{ "Alarm",  2, 3, 0, { IP_INTEGER  , IP_INTEGER_A13    , IP_INTEGER_OUT }, NULL, NULL },
	{ "FGetC",  2, 3, 0, { IP_INTEGER  , IP_CHARACTER_OUT  , IP_INTEGER_OUT }, NULL, NULL },
	{ "FPutC",  2, 3, 0, { IP_INTEGER  , IP_CHARACTER      , IP_INTEGER_OUT }, NULL, NULL },
	{ "Link",   2, 3, 0, { IP_CHARACTER, IP_CHARACTER      , IP_INTEGER_OUT }, NULL, NULL },
	{ "Rename", 2, 3, 0, { IP_CHARACTER, IP_CHARACTER      , IP_INTEGER_OUT }, NULL, NULL },

	{ NULL, 0, 0, 0, { 0 }, NULL, NULL }
};
*/
/*
struct ofc_sema_intrinsic_s
{
	ofc_sema_intrinsic_e type;

	ofc_str_ref_t name;

	union
	{
		const ofc_sema_intrinsic_op_t*   op;
		const ofc_sema_intrinsic_func_t* func;
	};
};
*/
#endif
