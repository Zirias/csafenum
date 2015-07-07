#ifndef CSAFENUM_H
#define CSAFENUM_H

#ifndef __GNUC__
#define __attribute__(x)
#endif

#include <assert.h>

/* declare an enum type: CSAFENAME_DECL(TypeName); */
#define CSAFENUM_DECL(tname) struct tname##_struct; \
    typedef const struct tname##_struct * tname; \
    const char *tname##_name(tname e) __attribute__((nonnull(1))); \
    int tname##_val(tname e) __attribute__((nonnull(1))); \
    struct tname##_struct

/* declare an enum member: CSE_DECL(TypeName, MemberName); */
#define CSE_DECL(tname, name) extern const struct tname##_struct * const name

/* define an enum type: CSAFENAME_DEF(TypeName); */
#define CSAFENUM_DEF(tname) struct tname##_struct { \
    int val; \
    const char * const name; \
}; \
const char *tname##_name(tname tname##_cannot_be_null) \
{ \
    assert(tname##_cannot_be_null); \
    return tname##_cannot_be_null->name; \
} \
int tname##_val(tname tname##_cannot_be_null) \
{ \
    assert(tname##_cannot_be_null); \
    return tname##_cannot_be_null->val; \
} \
struct tname##_struct

/* define an enum member: CSE_DEF(TypeName, MemberName, IntegerValue); */
#define CSE_DEF(tname, name, v) \
    static const struct tname##_struct name##_memb = { v, #name }; \
    const struct tname##_struct * const name = &name##_memb

#endif
