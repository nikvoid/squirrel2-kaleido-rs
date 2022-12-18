
// This file contains third-party (mine) extensions to squirrel api

#include "sqpcheader.h"
#include "sqvm.h"
#include "sqextension.h"
#include "sqtable.h"
#include "sqfuncproto.h"
#include "sqarray.h"
#include "sqclosure.h"

// From sqbaselib.cpp
extern SQInteger closure_getinfos(HSQUIRRELVM v);

SQInteger sq_getcallstacksize(HSQUIRRELVM v) {
    return v->_callsstacksize;
}

SQRESULT sq_closure_getinfos(HSQUIRRELVM v, SQInteger idx) {
	SQObject o = stack_get(v, idx);
	SQTable *res = SQTable::Create(_ss(v),4);
	if(type(o) == OT_CLOSURE) {
		SQFunctionProto *f = _funcproto(_closure(o)->_function);
		SQInteger nparams = f->_nparameters + (f->_varparams?1:0);
		SQObjectPtr params = SQArray::Create(_ss(v),nparams);
		for(SQInteger n = 0; n<f->_nparameters; n++) {
			_array(params)->Set((SQInteger)n,f->_parameters[n]);
		}
		if(f->_varparams) {
			_array(params)->Set(nparams-1,SQString::Create(_ss(v),_SC("..."),-1));
		}
		res->NewSlot(SQString::Create(_ss(v),_SC("native"),-1),false);
		res->NewSlot(SQString::Create(_ss(v),_SC("name"),-1),f->_name);
		res->NewSlot(SQString::Create(_ss(v),_SC("src"),-1),f->_sourcename);
		res->NewSlot(SQString::Create(_ss(v),_SC("parameters"),-1),params);
		res->NewSlot(SQString::Create(_ss(v),_SC("varargs"),-1),f->_varparams);
	}
	else if (type(o) == OT_NATIVECLOSURE) {
		SQNativeClosure *nc = _nativeclosure(o);
		res->NewSlot(SQString::Create(_ss(v),_SC("native"),-1),true);
		res->NewSlot(SQString::Create(_ss(v),_SC("name"),-1),nc->_name);
		res->NewSlot(SQString::Create(_ss(v),_SC("paramscheck"),-1),nc->_nparamscheck);
		SQObjectPtr typecheck;
		if(nc->_typecheck.size() > 0) {
			typecheck =
				SQArray::Create(_ss(v), nc->_typecheck.size());
			for(SQUnsignedInteger n = 0; n<nc->_typecheck.size(); n++) {
					_array(typecheck)->Set((SQInteger)n,nc->_typecheck[n]);
			}
		}
		res->NewSlot(SQString::Create(_ss(v),_SC("typecheck"),-1),typecheck);
	}
    else {
        return sq_throwerror(v, _SC("Expected closure or native closure"));
    }
	v->Push(res);
	return SQ_OK;
}