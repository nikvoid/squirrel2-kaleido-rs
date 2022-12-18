
// This file contains third-party (mine) extensions to squirrel api

#ifndef _SQ_EXTENSION_H_
#define _SQ_EXTENSION_H_

#include "squirrel.h"

#ifdef __cplusplus
extern "C" {
#endif

// Get size of vm calls stack
SQUIRREL_API SQInteger sq_getcallstacksize(HSQUIRRELVM v);

// Exported sqbaselib function.
// Get parameters of closure at the index idx of the stack and push formed table
SQUIRREL_API SQRESULT sq_closure_getinfos(HSQUIRRELVM v, SQInteger idx);

#ifdef __cplusplus
}      // extern "C"
#endif

#endif // _SQ_EXTENSION_H_