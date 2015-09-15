#ifndef __str_ref_h__
#define __str_ref_h__

#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	const char* base;
	unsigned    size;
} str_ref_t;

static const str_ref_t STR_REF_EMPTY = { .base = NULL, .size = 0 };

static inline str_ref_t str_ref(const char* base, unsigned size)
	{ return (str_ref_t){ base, size }; }

bool str_ref_empty(const str_ref_t ref);
bool str_ref_equal(const str_ref_t a, const str_ref_t b);

#endif
