export ARM_GCC=/home/ledi/Programs/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi/
if [ -n "${PATH}" ]; then
  export PATH=/home/ledi/Programs/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi/bin/:$PATH
else
  export PATH=/home/ledi/Programs/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi/bin/
fi
