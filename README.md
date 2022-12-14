# squirrel2-kaleido-rs

Bindings for Squirrel language and VM variant used in games built on Kaleido ADV engine

Known supported games:

- Konosuba: Kono Yokubukai Game ni Shinpan o!  

## Changes to VM

```cpp
// squirrel.h
typedef
+ #ifdef _MSC_VER
+ __declspec(align(8)) 
+ #endif
struct tagSQObject 
{
    SQObjectType _type;
    + SQInteger _junk;
    SQObjectValue _unVal;
    + SQInteger _zeroes;
} 
+ #ifdef __GNUC__
+  __attribute__((aligned(8)))
+ #endif
SQObject;

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
    SQCOMPILERERROR _compilererrorhandler;
    SQPRINTFUNCTION _printfunc; 

    + void* _unk_code_ptr;

    bool _debuginfo;
    bool _notifyallexceptions;
private:
    SQChar *_scratchpad;
    SQInteger _scratchpadsize;
};

// sqfuncproto.h
struct alignas(8) SQLocalVarInfo {...};
       ^^^^^^^^^^
```
