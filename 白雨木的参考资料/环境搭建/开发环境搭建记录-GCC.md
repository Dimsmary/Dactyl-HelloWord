230316
使用稚辉君同款的编译器：

下载arm-none-eabi-gcc，更改Clion的c和c++编译器，cmakelists.text使用默认配置（仅更改了版本号），报错如下：
```
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=/Applications/ARM/bin/arm-none-eabi-gcc -DCMAKE_CXX_COMPILER=/Applications/ARM/bin/arm-none-eabi-g++ -DCMAKE_DEPENDS_USE_COMPILER=FALSE -G "CodeBlocks - Unix Makefiles" /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw
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

[Finished]

```

将arm-none-eabi-gcc路径添加到/etc/paths，注意要重启后才能生效。之前用Path命令，无法在Clion中找到。现在可以完成编译了。

发现在VSCode打开，使用GCC编译器也可以正常编译。

总结：
过程中安装的软件：
1. CMake
2. OpenOCD
3. GCC
4. arm-none-eabi-gcc
5. VScode (闭源软件，基于开源的Code OSS)

VSCode插件：
1. C/C++（代码公开，但非自由软件）（可使用Clangd替代，但代码提示有错误）
2. CMake
3. CMake Tools

主要参考了稚晖君的这篇[文章](https://zhuanlan.zhihu.com/p/145801160)。