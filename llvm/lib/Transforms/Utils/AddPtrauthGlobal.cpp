#include "llvm/Transforms/Utils/AddPtrauthGlobal.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Debug.h"
#include "llvm/Transforms/Utils/ModuleUtils.h"

using namespace llvm;

PreservedAnalyses AddPtrauthGlobal::run(Module &M, ModuleAnalysisManager &AM) {
  auto &C = M.getContext();

  llvm::dbgs() << "Adding global to module\n";

  auto *GV = new GlobalVariable(
    Type::getInt32Ty(C)->getPointerTo(), // uint64_t*
    false,                               // isConstant
    GlobalValue::ExternalLinkage,        // extern
    nullptr,                             // no initializer
    "__global_ptrauth_device_base",      // name
    GlobalValue::NotThreadLocal,
    0,
    true                                 // is externally initialized
  );

  GV->setAlignment(Align(8));

  SmallVector<GlobalValue*, 1> Globals;
  Globals.push_back(GV);

  appendToUsed(M, Globals);

  M.insertGlobalVariable(GV);

  return PreservedAnalyses::all();
}
