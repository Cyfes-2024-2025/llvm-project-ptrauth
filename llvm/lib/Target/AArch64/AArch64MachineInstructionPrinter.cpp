#include "AArch64.h"
#include "AArch64InstrInfo.h"
#include "MCTargetDesc/AArch64MCTargetDesc.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"
#include "llvm/IR/DebugLoc.h"

using namespace llvm;

#define AARCH64_MACHINEINSTR_PRINTER_PASS_NAME "Dummy AArch64 machineinstr printer pass"

namespace {

class AArch64MachineInstrPrinter : public MachineFunctionPass {
public:
    static char ID;

    AArch64MachineInstrPrinter() : MachineFunctionPass(ID) {
        initializeAArch64MachineInstrPrinterPass(*PassRegistry::getPassRegistry());
    }

    bool runOnMachineFunction(MachineFunction &MF) override;

    StringRef getPassName() const override { return AARCH64_MACHINEINSTR_PRINTER_PASS_NAME; }
};

char AArch64MachineInstrPrinter::ID = 0;

bool AArch64MachineInstrPrinter::runOnMachineFunction(MachineFunction &MF) {

    outs() << "Processing function: " << MF.getName() << "\n";
    int firstInsertion = 1;
    // Iterate over each basic block in the machine function
    for (MachineBasicBlock &MBB : MF) {
        outs() << "Processing basic block: " << MBB.getName() << "\n";
        for (auto &MI : MBB) {
            if (firstInsertion) {
                outs() << "Found first instruction\n";
                outs() << MI.getOpcode() << "\n";
                const TargetInstrInfo &TII = *MF.getSubtarget().getInstrInfo();
                MachineBasicBlock &MBB = MF.front();
                DebugLoc DL;
                MachineInstr *MI = BuildMI(&MBB, DL, TII.get(AArch64::MOVZXi), AArch64::X10).addImm(42);
                outs() << "Inserted the instruction!\n";
                firstInsertion = 0;
                return true;
            }
        }
    }
    return false;
}

} // end of anonymous namespace

INITIALIZE_PASS(AArch64MachineInstrPrinter, "AArch64-machineinstr-printer",
    AARCH64_MACHINEINSTR_PRINTER_PASS_NAME,
    false, // is CFG only?
    false  // is analysis?
)

namespace llvm {

FunctionPass *createAArch64MachineInstrPrinterPass() {
    return new AArch64MachineInstrPrinter();
}

} // end namespace llvm
