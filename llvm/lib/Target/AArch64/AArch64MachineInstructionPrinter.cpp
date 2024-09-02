#include "AArch64.h"
#include "AArch64InstrInfo.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"

using namespace llvm;

#define AARCH64_MACHINEINSTR_PRINTER_PASS_NAME "Dummy AArch64 machineinstr printer pass"

namespace {

class AArch64MachineInstrPrinter : public MachineFunctionPass {
public:
    static char ID;

    AArch64MachineInstrPrinter() : MachineFunctionPass(ID) {
        // initializeAArch64MachineInstrPrinterPass(*PassRegistry::getPassRegistry());
    }

    bool runOnMachineFunction(MachineFunction &MF) override;

    StringRef getPassName() const override { return AARCH64_MACHINEINSTR_PRINTER_PASS_NAME; }
};

char AArch64MachineInstrPrinter::ID = 0;

bool AArch64MachineInstrPrinter::runOnMachineFunction(MachineFunction &MF) {

    for (auto &MBB : MF) {
        outs() << "Contents of MachineBasicBlock:\n";
        outs() << MBB << "\n";
        const BasicBlock *BB = MBB.getBasicBlock();
        outs() << "Contents of BasicBlock corresponding to MachineBasicBlock:\n";
        outs() << BB << "\n";
    }

    return false;
}

} // end of anonymous namespace

// INITIALIZE_PASS(AArch64MachineInstrPrinter, "AArch64-machineinstr-printer",
//     AARCH64_MACHINEINSTR_PRINTER_PASS_NAME,
//     true, // is CFG only?
//     true  // is analysis?
// )

namespace llvm {

FunctionPass *createAArch64MachineInstrPrinterPass() { return new AArch64MachineInstrPrinter(); }

} // end namespace llvm
