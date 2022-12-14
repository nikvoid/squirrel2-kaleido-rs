
// This file contains third-party (mine) extensions to squirrel api

#include "sqpcheader.h"
#include "sqvm.h"
#include "sqextension.h"

SQInteger sq_getcallstacksize(HSQUIRRELVM v) {
    return v->_callsstacksize;
}