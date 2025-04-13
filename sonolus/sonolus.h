using namespace std;

#define Constructor
#define Destructor
#define Blocked
#define NonType
#define CppLoop

// 解释器部分内容
int ForBlockCount = 0;
string callFromFile = "";
int callFromLine = 0;
int callFromColumn = 0;
string callFromFunc = "";
string callFromFuncParam = "";
string archetypeName = "";
string callbackName = "";

struct CallStack {
    string file;
    int line, column;
    string func, param;
};
vector<CallStack> callStacks;
void printStack() {
    cerr << "Call Stack: " << endl;
    for (int i = int(callStacks.size()) - 2; i >= 0; i--)
        cerr << "#" << int(callStacks.size()) - 2 - i 
             << " in " << (callStacks[i].func == "" ? "???" : callStacks[i].func)
             << " (" << callStacks[i].param 
             << ") at " << callStacks[i].file 
             << ":" 
             << callStacks[i].line << ":" << callStacks[i].column << endl;
}

#if false
// 用宏定义定义一个虚假函数，让解释器识别到这个函数并自动加到 UserDefined 函数列表中
void SonolusAssert() {}
#endif
// SonolusAssert 宏定义一定要禁止解释器解析，不然解释器会识别到两个同名的宏定义然后出现错误
#define DISABLE_INTERPRETER
#ifndef COMPILE_RUNTIME
// 供 IDE 识别的 SonolusAssert 函数
#define SonolusAssert(expr, ...) (void)( \
    (!!(expr)) || \
    (__builtin_SonolusAssert("", "", 0, 0, "", #expr, __VA_ARGS__), 0) \
)
#else
// 供编译器识别的 SonolusAssert 函数
#define SonolusAssert(arg1, arg2, arg3, arg4, arg5, expr, ...) (void)( \
    (!!(expr)) || \
    (__builtin_SonolusAssert(arg1, arg2, arg3, arg4, arg5, #expr, __VA_ARGS__), 0) \
)
#endif
#undef DISABLE_INTERPRETER
Blocked void __builtin_SonolusAssert(
    string callFromFuncParam, string callFromFunc, int callFromLine, int callFromColumn, string callFromFile,
    string exprString, const char* format, ...
) {
    callStacks.push_back({callFromFile, callFromLine, callFromColumn, callFromFunc, callFromFuncParam});
    
    const int size = 128 * 1024;
    va_list args;
    va_start(args, format);
    char buf[size];
    memset(buf, '\0', sizeof buf);
    int n = vsnprintf(buf, size, format, args);
    va_end(args);

    cerr << "Build Failed!" << endl << endl;
    cerr << "Error: " << buf << endl;
    cerr << "Assertion `" << exprString << "` failed!" << endl << endl;
    printStack();
    callStacks.pop_back();
    abort();
}

// 库部分内容
#include"utils/json.h"
#include"utils/gzip.h"

string dist = "./dist";
map<int, set<string> > readable, writable;
map<int, string> blockName;

#include"privates/FuncNode.h"
#define Get __builtin_Get
#define Set __builtin_Set
#define Spawn __builtin_Spawn
#include"privates/Functions.h"
#undef Get
#undef Set
#undef Spawn
FuncNode Get(FuncNode id, FuncNode index) {
    SonolusAssert(
        !id.getNode().isValue || readable[id.getNode().value].count(callbackName),
        "`%s` block is not readable in `%s` callback at `%s` archetype!",
        blockName[id.getNode().value].c_str(),
        callbackName.c_str(),
        archetypeName.c_str()
    );
    return __builtin_Get(id, index);
}
FuncNode Set(FuncNode id, FuncNode index, FuncNode value) {
    SonolusAssert(
        !id.getNode().isValue || writable[id.getNode().value].count(callbackName),
        "`%s` block is not writable in `%s` callback at `%s` archetype!",
        blockName[id.getNode().value].c_str(),
        callbackName.c_str(),
        archetypeName.c_str()
    );
    return __builtin_Set(id, index, value);
}
FuncNode Spawn(FuncNode id, vector<FuncNode> memory) {
    memory.insert(memory.begin(), 0);
	return __builtin_Spawn(id, memory);
}
#include"privates/Operators.h"
#include"privates/Variable.h"
#include"privates/Blocks.h"

using var = Variable;
#define SonolusApi var
#include"engine/EngineLiterals.h"
#include"engine/EngineDataBucket.h"
#include"engine/EngineInstruction.h"
vector<pair<string, string> > skin_sprites;
vector<pair<string, string> > effect_clips;
vector<pair<string, string> > particle_effects;
#ifdef play
#include"engine/play/Blocks.h"
#include"engine/play/Runtime.h"
#include"engine/play/Archetype.h"
#include"engine/play/Build.h"
#endif
#ifdef tutorial
#include"engine/tutorial/Blocks.h"
#include"engine/tutorial/Runtime.h"
#include"engine/tutorial/Build.h"
#endif
#ifdef preview
#include"engine/preview/Blocks.h"
#include"engine/preview/Runtime.h"
#include"engine/preview/Archetype.h"
#include"engine/preview/Build.h"
#endif
#ifdef watch
#include"engine/watch/Blocks.h"
#include"engine/watch/Runtime.h"
#include"engine/watch/Archetype.h"
#include"engine/watch/Build.h"
#endif
#include"engine/configuration/Build.h"

#include"containers/Array.h"
#include"containers/Collection.h"
#include"containers/Dictionary.h"
#include"containers/Mat.h"
#include"containers/Vec.h"
#include"containers/Range.h"
#include"containers/Rect.h"
#include"containers/Quad.h"


#include"resource/Skins.h"
#include"resource/Effects.h"
#include"resource/Particles.h"
#include"resource/Levels.h"