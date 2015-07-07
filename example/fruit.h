#ifndef FRUIT_H
#define FRUIT_H

#include <csafenum.h>

CSAFENUM_DECL(Fruit);

CSE_DECL(Fruit, Apple);
CSE_DECL(Fruit, Banana);
CSE_DECL(Fruit, Pear);
CSE_DECL(Fruit, Strawberry);

#endif
