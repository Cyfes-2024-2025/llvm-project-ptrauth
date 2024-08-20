#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
    struct testCustomPass : public FunctionPass {
        static char ID;
        testCustomPass() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override {
            errs() << "Just for fun: " << F.getName() << "\n";
            // Return false to indicate that we did not modify the original code, true otherwise
            return false;
        }

    };
}
// LLVM uses the address of this static member to identify the pass, so the init value is not important
char testCustomPass::ID = 0;
// Here we are registering the pass: cli-argument, name, if a pass walks the CFG without modifying it => true, if it's an analysis pass => true
static RegisterPass<testCustomPass> X("test-custom-pass", "Non so cosa sto facendo", false, false);