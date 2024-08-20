add_llvm_library(TestCustomPass MODULE
  TestCustomPass.cpp

  PLUGIN_TOOL
  opt
)