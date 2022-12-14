# squirrel2-kaleido-rs

Bindings for Squirrel language and VM variant used in games built on Kaleido ADV engine

Known supported games:

- Konosuba: Kono Yokubukai Game ni Shinpan o!  

## Changes to VM

```cpp
// squirrel.h
struct SqObject {
    SQObjectType _type;
    + SQInteger _junk;
    SQObjectValue _unVal;
    + SQInteger _zeroes;
};

// sqvm.h
struct SQVM {
    ...
    SQInteger _stackbase;
    SQObjectPtr _roottable;
    SQObjectPtr _lasterror;
    SQObjectPtr _errorhandler;
    SQObjectPtr _debughook;
    
    SQObjectPtr temp_reg;
    + SQObjectPtr unknown_closure;
    
    CallInfo* _callsstack;
    SQInteger _callsstacksize;
    ...
};

// sqstate.h
struct SQSharedState {
    ...
    SQObjectPtrVec *_metamethods;
    + SQInteger _junk;
    SQObjectPtr _metamethodsmap;
    ...
    SQObjectPtr _constructoridx;
#ifndef NO_GARBAGE_COLLECTOR
    SQCollectable *_gc_chain;
    + SQInteger _junk2;
#endif
    ...
    SQCOMPILERERROR _compilererrorhandler;
    SQPRINTFUNCTION _printfunc; 

    + void* _unk_code_ptr;

    bool _debuginfo;
    bool _notifyallexceptions;
private:
    SQChar *_scratchpad;
    SQInteger _scratchpadsize;
};

// sqtable.h
struct SQTable : public SQDelegable 
{
private:
    struct _HashNode
    {
        _HashNode() { next = NULL; }
        SQObjectPtr val;
        SQObjectPtr key;
        _HashNode *next;
        + SQInteger _junk;
    };
    ...
};

// sqclosure.h
struct SQNativeClosure : public CHAINABLE_OBJ {
    ...
    SQInteger _nparamscheck;
    SQIntVec _typecheck;
    SQObjectPtrVec _outervalues;
    + SQInteger _junk;
    SQObjectPtr _env;
    SQFUNCTION _function;
    + SQInteger _junk2;
    SQObjectPtr _name;
};

// sqfuncproto.h
struct  SQFunctionProto : public SQRefCounted {
    ...
    + SQInteger _junk;  

    SQObjectPtr _sourcename;
    SQObjectPtr _name;
    SQInteger _stacksize;
    bool _bgenerator;
    bool _varparams;
    ...
};

// sqfuncproto.h
struct alignas(8) SQLocalVarInfo {...};
       ^^^^^^^^^^
```
