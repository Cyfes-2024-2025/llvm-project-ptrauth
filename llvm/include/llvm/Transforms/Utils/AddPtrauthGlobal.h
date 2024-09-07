#ifndef __LLVM_ADD_PTRAUTH_GLOBAL_H
#define __LLVM_ADD_PTRAUTH_GLOBAL_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class AddPtrauthGlobal : public PassInfoMixin<AddPtrauthGlobal> {
public:
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);
  static bool isRequired() { return true; }
};

} // namespace llvm

#endif // __LLVM_ADD_PTRAUTH_GLOBAL_H
