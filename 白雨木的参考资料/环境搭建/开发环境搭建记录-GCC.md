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
1. C/C++（代码公开，但非自由软件）（可使用Clangd替代，但代码有少量错误提示）
2. CMake
3. CMake Tools

主要参考了稚晖君的这篇[文章](https://zhuanlan.zhihu.com/p/145801160)。

230317
微软的C/C++插件没有跳转提示，所以才没有错误？

通过控制变量，在相同的配置文件、相同的编译工具下编译，通过对比Clion和VSCode所编译的二进制，可知二进制代码完全相同，并未因编辑器不同而导致编译差异。

230318
```
[variant] Loaded new set of variants
[kit] Successfully loaded 2 kits from /Users/byvm/.local/share/CMakeTools/cmake-tools-kits.json
[proc] Executing command: /usr/local/bin/cmake --version
[proc] Executing command: /usr/local/bin/gcc-12 -v
[proc] The command: ninja --version failed with error: Error: spawn ninja ENOENT
[proc] The command: ninja-build --version failed with error: Error: spawn ninja-build ENOENT
[main] Configuring project: Byvm 
[proc] Executing command: /usr/local/bin/cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_C_COMPILER:FILEPATH=/usr/local/bin/gcc-12 -DCMAKE_CXX_COMPILER:FILEPATH=/usr/local/bin/g++-12 -S/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/HelloWord-Keyboard-fw -B/Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/build -G "Unix Makefiles"
[cmake] Not searching for unused variables given on the command line.
[cmake] -- Maximum optimization for speed
[cmake] -- Configuring done (0.0s)
[cmake] You have changed variables that require your cache to be deleted.
[cmake] Configure will be re-run and you may have to reset some variables.
[cmake] The following variables have changed:
[cmake] CMAKE_C_COMPILER= /usr/local/bin/gcc-12
[cmake] CMAKE_CXX_COMPILER= /usr/local/bin/g++-12
[cmake] 
[cmake] -- The C compiler identification is GNU 10.3.1
[cmake] -- The CXX compiler identification is GNU 10.3.1
[cmake] -- The ASM compiler identification is GNU
[cmake] -- Found assembler: /Applications/ARM/bin/arm-none-eabi-gcc
[cmake] -- Detecting C compiler ABI info
[cmake] -- Detecting C compiler ABI info - done
[cmake] -- Check for working C compiler: /Applications/ARM/bin/arm-none-eabi-gcc - skipped
[cmake] -- Detecting C compile features
[cmake] -- Detecting C compile features - done
[cmake] -- Detecting CXX compiler ABI info
[cmake] -- Detecting CXX compiler ABI info - done
[cmake] -- Check for working CXX compiler: /Applications/ARM/bin/arm-none-eabi-g++ - skipped
[cmake] -- Detecting CXX compile features
[cmake] -- Detecting CXX compile features - done
[cmake] -- Minimal optimization, debug info included
[cmake] -- Configuring done (1.6s)
[cmake] -- Generating done (0.8s)
[cmake] -- Build files have been written to: /Volumes/SanDisk/Byme/Dactyl-HelloWord/Dactyl-HelloWord/Firmware/Byvm/build
```

虽然可以编译了，但是注意到提示中有一个error,VSCode的提示没有颜色区分真令人头痛。不过不影响，因为稚晖君的开发环境也没有这个ninja。

230321
使用C/C++插件需要在Settings.json里配置这个选项为默认（这个参考https://www.bilibili.com/video/BV1gD4y1y7um）
```
"C_Cpp.intelliSenseEngine": "default"
```

然后要更改C/C++插件使用的编译器，在 Byvm/.vscode/c_cpp_properties.json
```
<<<<<<< HEAD
"compilerPath": "/Applications/ARM/bin/arm-none-eabi-gcc"
```

用DACTYL-HWLLOWORD做工作根目录打开main.c会出现以下问题，但以Byvm做根目录则不会。
```
没有找到库：stdint-gcc.h
```

当然，可以手动添加库路径
```
/Applications/ARM/lib/gcc/arm-none-eabi/10.3.1/include/stdint-gcc.h
```
=======
"compilerPath": "/usr/local/bin/gcc-12"
```

这样就解决这个问题了（如果使用arm-none-eabi-gcc或clang就会有这个问题）：
```
没有找到库：stdint-gcc.h
```
>>>>>>> 7ca75c01c249f37af6f4c016d4c3a869c95d83d2
