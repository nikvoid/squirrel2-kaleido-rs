
// This file contains third-party (mine) extensions to squirrel api

#ifndef _SQ_EXTENSION_H_
#define _SQ_EXTENSION_H_

#include "squirrel.h"

#ifdef __cplusplus
extern "C" {
#endif

// Get size of vm calls stack
SQUIRREL_API SQInteger sq_getcallstacksize(HSQUIRRELVM v);

#ifdef __cplusplus
}      // extern "C"
#endif

#endif // _SQ_EXTENSION_H_