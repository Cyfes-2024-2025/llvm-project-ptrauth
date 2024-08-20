#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;
using namespace std;

namespace {
    struct JustForFunPass : public FunctionPass {
        static char ID;
        JustForFunPass() : FunctionPass(ID) {}

        virtual bool runOnFunction(Function &F) {
            errs() << "Just for fun: " << F.getName() << "\n";
            return false;
        }
    };
}

//llvm::PassPluginLibraryInfo getJustForFunPluginInfo() {
//    return {LLVM_PLUGIN_API_VERSION, "JustForFun", LLVM_VERSION_STRING,
//            [](PassBuilder &PB) {
//                PB.registerPipelineParsingCallback(
//                        [](StringRef Name, FunctionPassManager &FPM,
//                           ArrayRef<PassBuilder::PipelineElement>) {
//                            if (Name == "just-for-fun") {
//                                FPM.addPass(JustForFunPass());
//                                return true;
//                            }
//                            return false;
//                        });
//            }};
//}
//
//// This is the core interface for pass plugins. It guarantees that 'opt' will
//// be able to recognize HelloWorld when added to the pass pipeline on the
//// command line, i.e. via '-passes=hello-world'
//extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
//llvmGetPassPluginInfo() {
//    return getJustForFunPluginInfo();
//}
