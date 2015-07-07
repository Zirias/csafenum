#ifndef CSAFENUM_H
#define CSAFENUM_H

#ifndef __GNUC__
#define __attribute__(x)
#endif

#include <assert.h>

#define CSAFENUM_DECL(tname) struct tname##_struct; \
    typedef const struct tname##_struct * tname; \
    const char *tname##_name(tname e) __attribute__((nonnull(1))); \
    int tname##_val(tname e) __attribute__((nonnull(1))); \
    struct tname##_struct

#define CSE_DECL(tname, name) extern const struct tname##_struct * const name

#define CSAFENUM_DEF(tname) struct tname##_struct { \
    int val; \
    const char * const name; \
}; \
const char *tname##_name(tname e) \
{ \
    assert(e); \
    return e->name; \
} \
int tname##_val(tname e) \
{ \
    assert(e); \
    return e->val; \
} \
struct tname##_struct

#define CSE_DEF(tname, name, v) \
    static const struct tname##_struct name##_memb = { v, #name }; \
    const struct tname##_struct * const name = &name##_memb

#endif
