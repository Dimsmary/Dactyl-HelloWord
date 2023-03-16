230315
Clion下载后默认设置，报错如下（其实之前改过Cnakelists.text的版本号，所以没有Cmake版本不对的提示）
```
-- The C compiler identification is unknown
-- The CXX compiler identification is unknown
-- The ASM compiler identification is unknown
-- Found assembler: arm-none-eabi-gcc
CMake Error at CMakeLists.txt:19 (project):
  The CMAKE_C_COMPILER:

    arm-none-eabi-gcc

  is not a full path and was not found in the PATH.

  Tell CMake where to find the compiler by setting either the environment
  variable "CC" or the CMake cache entry CMAKE_C_COMPILER to the full path to
  the compiler, or to the compiler name if it is in the PATH.


CMake Error at CMakeLists.txt:19 (project):
  The CMAKE_CXX_COMPILER:

    arm-none-eabi-g++

  is not a full path and was not found in the PATH.

  Tell CMake where to find the compiler by setting either the environment
  variable "CXX" or the CMake cache entry CMAKE_CXX_COMPILER to the full path
  to the compiler, or to the compiler name if it is in the PATH.


CMake Error at CMakeLists.txt:19 (project):
  The CMAKE_ASM_COMPILER:

    arm-none-eabi-gcc

  is not a full path and was not found in the PATH.

  Tell CMake where to find the compiler by setting either the environment
  variable "ASM" or the CMake cache entry CMAKE_ASM_COMPILER to the full path
  to the compiler, or to the compiler name if it is in the PATH.


-- Warning: Did not find file Compiler/-ASM
-- Configuring incomplete, errors occurred!
See also "/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeOutput.log".
See also "/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeError.log".

```

230316
注释编译器前三项对应的cmake.text后
```
-- The C compiler identification is AppleClang 14.0.0.14000029
-- The CXX compiler identification is AppleClang 14.0.0.14000029
-- The ASM compiler identification is Clang
-- Found assembler: /Library/Developer/CommandLineTools/usr/bin/cc
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - failed
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc - broken
CMake Error at /Applications/CLion.app/Contents/bin/cmake/mac/share/cmake-3.20/Modules/CMakeTestCCompiler.cmake:66 (message):
  The C compiler

    "/Library/Developer/CommandLineTools/usr/bin/cc"

  is not able to compile a simple test program.

  It fails with the following output:

    Change Dir: /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeTmp
    
    Run Build Command(s):/usr/bin/make -f Makefile cmTC_119c2/fast && /Library/Developer/CommandLineTools/usr/bin/make  -f CMakeFiles/cmTC_119c2.dir/build.make CMakeFiles/cmTC_119c2.dir/build
    Building C object CMakeFiles/cmTC_119c2.dir/testCCompiler.c.obj
    /Library/Developer/CommandLineTools/usr/bin/cc    -MD -MT CMakeFiles/cmTC_119c2.dir/testCCompiler.c.obj -MF CMakeFiles/cmTC_119c2.dir/testCCompiler.c.obj.d -o CMakeFiles/cmTC_119c2.dir/testCCompiler.c.obj -c /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeTmp/testCCompiler.c
    Linking C static library libcmTC_119c2.a
    /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -P CMakeFiles/cmTC_119c2.dir/cmake_clean_target.cmake
    /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E cmake_link_script CMakeFiles/cmTC_119c2.dir/link.txt --verbose=1
    arm-none-eabi-ar qc libcmTC_119c2.a CMakeFiles/cmTC_119c2.dir/testCCompiler.c.obj
    Error running link command: No such file or directory
    make[1]: *** [libcmTC_119c2.a] Error 2
    make: *** [cmTC_119c2/fast] Error 2
    
    

  

  CMake will not be able to correctly generate this project.
Call Stack (most recent call first):
  CMakeLists.txt:19 (project)


-- Configuring incomplete, errors occurred!
See also "/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeOutput.log".
See also "/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeError.log".

[Finished]
```

将编译选项注入为如下
```
set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
#set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
#set(SIZE arm-none-eabi-size)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
```

```
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_DEPENDS_USE_COMPILER=FALSE -G "CodeBlocks - Unix Makefiles" /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw
-- The CXX compiler identification is AppleClang 14.0.0.14000029
-- The ASM compiler identification is Clang
-- Found assembler: /Library/Developer/CommandLineTools/usr/bin/cc
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - failed
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/CC
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/CC - broken
CMake Error at /Applications/CLion.app/Contents/bin/cmake/mac/share/cmake-3.20/Modules/CMakeTestCXXCompiler.cmake:59 (message):
  The C++ compiler

    "/Library/Developer/CommandLineTools/usr/bin/CC"

  is not able to compile a simple test program.

  It fails with the following output:

    Change Dir: /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeTmp
    
    Run Build Command(s):/usr/bin/make -f Makefile cmTC_e8209/fast && /Library/Developer/CommandLineTools/usr/bin/make  -f CMakeFiles/cmTC_e8209.dir/build.make CMakeFiles/cmTC_e8209.dir/build
    Building CXX object CMakeFiles/cmTC_e8209.dir/testCXXCompiler.cxx.obj
    /Library/Developer/CommandLineTools/usr/bin/CC    -MD -MT CMakeFiles/cmTC_e8209.dir/testCXXCompiler.cxx.obj -MF CMakeFiles/cmTC_e8209.dir/testCXXCompiler.cxx.obj.d -o CMakeFiles/cmTC_e8209.dir/testCXXCompiler.cxx.obj -c /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeTmp/testCXXCompiler.cxx
    Linking CXX executable cmTC_e8209
    /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E cmake_link_script CMakeFiles/cmTC_e8209.dir/link.txt --verbose=1
    /Library/Developer/CommandLineTools/usr/bin/CC CMakeFiles/cmTC_e8209.dir/testCXXCompiler.cxx.obj -o cmTC_e8209 
    ld: library not found for -lSystem
    clang: error: linker command failed with exit code 1 (use -v to see invocation)
    make[1]: *** [cmTC_e8209] Error 1
    make: *** [cmTC_e8209/fast] Error 2
    
    

  

  CMake will not be able to correctly generate this project.
Call Stack (most recent call first):
  CMakeLists.txt:19 (project)


-- Configuring incomplete, errors occurred!
See also "/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeOutput.log".
See also "/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug/CMakeFiles/CMakeError.log".

[Failed to reload]
```

如下设置后
```
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
#set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
#set(SIZE arm-none-eabi-size)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
```

```
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_DEPENDS_USE_COMPILER=FALSE -G "CodeBlocks - Unix Makefiles" /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw
-- The CXX compiler identification is AppleClang 14.0.0.14000029
-- The ASM compiler identification is Clang
-- Found assembler: /Library/Developer/CommandLineTools/usr/bin/cc
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/clang++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Minimal optimization, debug info included
-- Configuring done
-- Generating done
-- Build files have been written to: /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug

Problems were encountered while collecting compiler information:
	clang: error: unknown argument: '-mthumb-interwork'

[Finished]
```
似乎快要解决了，而且main.c的错误提示也没有了，小锤子也变绿了。

在VSCode也有了compile_commands.json，之前的错误提示少了很多。

发现这样设置更容易看懂，其实只要设置前面两个参数就可以了
```
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
#set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
#set(CMAKE_AR arm-none-eabi-ar)
#set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
#set(CMAKE_OBJDUMP arm-none-eabi-objdump)
#set(SIZE arm-none-eabi-size)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
```

注释掉这个选项就没有错误提示了。
```
#add_compile_options(-mcpu=cortex-m3 -mthumb -mthumb-interwork)w
```
```
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_DEPENDS_USE_COMPILER=FALSE -G "CodeBlocks - Unix Makefiles" /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw
-- Minimal optimization, debug info included
-- Configuring done
-- Generating done
-- Build files have been written to: /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug

[Finished]
```
Clion的错误提示比VSCode好一点。


首次编译输出如下

```
====================[ Build | HelloWord-Keyboard-fw.elf | Debug ]===============
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/cmake-build-debug --target HelloWord-Keyboard-fw.elf -- -j 6
[ 13%] Building C object CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Core/Src/stm32f1xx_it.c.obj
[ 13%] Building C object CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Core/Src/main.c.obj
[ 13%] Building C object CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Core/Src/syscalls.c.obj
[ 13%] Building C object CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c.obj
[ 13%] Building C object CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c.obj
[ 13%] Building C object CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c.obj
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Src/syscalls.c:66:31: error: register 'sp' unsuitable for global register variables on this target
register char * stack_ptr asm("sp");
                              ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Src/syscalls.c:117:1: error: unknown type name 'caddr_t'
caddr_t _sbrk(int incr)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Src/syscalls.c:132:11: error: use of undeclared identifier 'caddr_t'
                return (caddr_t) -1;
                        ^
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Src/stm32f1xx_it.c:26:
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/UserApp/common_inc.h:8:10: fatal error: /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Src/syscalls.c:137'stdint-gcc.h' file not found:10
: error: use of undeclared identifier 'caddr_t'
        return (caddr_t) prev_heap_end;
                ^
#include "stdint-gcc.h"
         ^~~~~~~~~~~~~~
4 errors generated.
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:179:26: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
                         ^~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:179:53: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
                                                    ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:179:81: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
                                                                                ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:179:107: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
                                                                                                          ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:262:26: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
                         ^~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:262:53: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
                                                    ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:262:81: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
                                                                                ^~~~~~~~~~~~~~~~~~~~~~~
make[3]: *** [CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Core/Src/syscalls.c.obj] Error 1
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.cmake[3]: :262:107*** Waiting for unfinished jobs....: 
warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
                                                                                                          ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c:200:1: warning: '__weak' only applies to pointer types; type here is 'void' [-Wignored-attributes]
__weak void HAL_MspInit(void)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c:211:1: warning: '__weak' only applies to pointer types; type here is 'void' [-Wignored-attributes]
__weak void HAL_MspDeInit(void)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c:234:1: warning: '__weak' only applies to pointer types; type here is 'HAL_StatusTypeDef' [-Wignored-attributes]
__weak HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c:481:1: /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c:warning: 293:'__weak' only applies to pointer types; type here is 'void' [-Wignored-attributes]1: 
warning: '__weak' only applies to pointer types; type here is 'void' [-Wignored-attributes]
__weak void HAL_IncTick(void)
^
__weak void HAL_SYSTICK_Callback(void)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c:304:1: warning: '__weak' only applies to pointer types; type here is 'uint32_t' (aka 'unsigned int') [-Wignored-attributes]
__weak uint32_t HAL_GetTick(void)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c:370:1: warning: '__weak' only applies to pointer types; type here is 'void' [-Wignored-attributes]
__weak void HAL_Delay(uint32_t Delay)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c:396:1: warning: '__weak' only applies to pointer types; type here is 'void' [-Wignored-attributes]
__weak void HAL_SuspendTick(void)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c:412:1: warning: '__weak' only applies to pointer types; type here is 'void' [-Wignored-attributes]
__weak void HAL_ResumeTick(void)
^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:215:3: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_GL1 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:215:42: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_GL1 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:216:3: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_GL2 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:216:42: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_GL2 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:217:3: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_GL3 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
1/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477: error32 generated: .
warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:217:42: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_GL3 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:218:3: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_GL4 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:218:42: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_GL4 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:219:3: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_GL5 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:219:42: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_GL5 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
In file included from #define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Src/main.c
:31                                                                  ^~~~~~~~:

/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/UserApp/common_inc.h:8:10: fatal error: 'stdint-gcc.h' file not found
#include "stdint-gcc.h"
         ^~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:220:3: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_GL6 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:477:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:220:42: note: expanded from macro '__HAL_DMA_GET_GI_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_GL6 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
make[3]:                                                                   ^~~~~~~~
1*** [CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Core/Src/stm32f1xx_it.c.obj] Error 1
 error generated.
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:173:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:173:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:174:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:174:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:175:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:175:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:176:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.hmake[3]: :176:42*** [CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Core/Src/main.c.obj] Error 1: 
note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:177:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:177:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:178:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:526:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:178:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:187:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:187:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:188:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:188:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:189:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:189:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:190:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:190:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:191:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:191:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:192:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:531:12: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:192:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
                                         ^~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:201:3: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TE1 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:201:42: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TE1 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:202:3: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TE2 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:202:42: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TE2 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:203:3: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TE3 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:203:42: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TE3 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:204:3: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TE4 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:204:42: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TE4 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:205:3: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TE5 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:205:42: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TE5 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:206:3: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TE6 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:539:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
        ~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:206:42: note: expanded from macro '__HAL_DMA_GET_TE_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TE6 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:236:66: note: expanded from macro '__HAL_DMA_GET_FLAG'
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))
                                                                 ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:173:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:173:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:174:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:174:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:175:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:175:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:176:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:176:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:177:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:177:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:178:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:579:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:178:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:187:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:187:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:188:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:188:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:189:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:189:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:190:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:190:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:191:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:191:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:192:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:588:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:192:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:187:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:187:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:188:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:188:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:189:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:189:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:190:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:190:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:191:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:191:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:192:3: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:618:32: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:192:42: note: expanded from macro '__HAL_DMA_GET_HT_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:173:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:173:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:174:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:174:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:175:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:175:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:176:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:176:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:177:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:177:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:178:3: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
  ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c:642:34: warning: cast to smaller integer type 'uint32_t' (aka 'unsigned int') from 'DMA_Channel_TypeDef *' [-Wpointer-to-int-cast]
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:178:42: note: expanded from macro '__HAL_DMA_GET_TC_FLAG_INDEX'
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
                                         ^
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h:250:67: note: expanded from macro '__HAL_DMA_CLEAR_FLAG'
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))
                                                                  ^~~~~~~~
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c:83:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h:30:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Inc/stm32f1xx_hal_conf.h:237:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h:29:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h:30:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h:131:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h:132:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/core_cm3.h:115:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/cmsis_compiler.h:48:
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/cmsis_gcc.h:879:19: error: invalid instruction mnemonic 'dsb'
  __ASM volatile ("dsb 0xF":::"memory");
                  ^
<inline asm>:1:2: note: instantiated into assembly here
        dsb 0xF
        ^~~
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c:83:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h:30:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Inc/stm32f1xx_hal_conf.h:237:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h:29:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h:30:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h:131:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h:132:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/core_cm3.h:115:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/cmsis_compiler.h:48:
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/cmsis_gcc.h:868:19: error: invalid instruction mnemonic 'isb'
  __ASM volatile ("isb 0xF":::"memory");
                  ^
<inline asm>:1:2: note: instantiated into assembly here
        isb 0xF
        ^~~
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c:83:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h:30:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Inc/stm32f1xx_hal_conf.h:237:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h:29:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h:30:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h:131:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h:132:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/core_cm3.h:115:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/cmsis_compiler.h:48:
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/cmsis_gcc.h:879:19: error: invalid instruction mnemonic 'dsb'
  __ASM volatile ("dsb 0xF":::"memory");
                  ^
<inline asm>:1:2: note: instantiated into assembly here
        dsb 0xF
        ^~~
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c:83:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h:30:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Core/Inc/stm32f1xx_hal_conf.h:237:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h:29:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h:30:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h:131:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h:132:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/core_cm3.h:115:
In file included from /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/cmsis_compiler.h:48:
/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw/Drivers/CMSIS/Include/cmsis_gcc.h:879:19: error: invalid instruction mnemonic 'dsb'
  __ASM volatile ("dsb 0xF":::"memory");
                  ^
<inline asm>:1:2: note: instantiated into assembly here
        dsb 0xF
        ^~~
8 warnings generated.
1 warning and 4 errors generated.
make[3]: *** [CMakeFiles/HelloWord-Keyboard-fw.elf.dir/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c.obj] Error 1
104 warnings generated.
make[2]: *** [CMakeFiles/HelloWord-Keyboard-fw.elf.dir/all] Error 2
make[1]: *** [CMakeFiles/HelloWord-Keyboard-fw.elf.dir/rule] Error 2
make: *** [HelloWord-Keyboard-fw.elf] Error 2
```

由于arm-none-eabi-gcc已经完成配置，故不再对Clangd开发环境做搭建。