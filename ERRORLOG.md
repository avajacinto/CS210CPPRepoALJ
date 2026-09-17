## Error 1: Missing implementation of size

**Date:** September 16th, 2026

**Error type:** Linker error

====================[ Build | 03_adt_stack | Debug ]============================
C:\Users\avaja\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe --build C:\Users\avaja\CLionProjects\CS210CPPRepo\cmake-build-debug --target 03_adt_stack -- -j 10
[ 33%] Building CXX object CMakeFiles/03_adt_stack.dir/03_adt_stack/Stack.cpp.obj
[ 66%] Linking CXX executable 03_adt_stack.exe
C:/Users/avaja/AppData/Local/Programs/CLion/bin/mingw/bin/../lib/gcc/x86_64-w64-mingw32/15.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: CMakeFiles\03_adt_stack.dir/objects.a(main.cpp.obj): in function `main':
C:/Users/avaja/CLionProjects/CS210CPPRepo/03_adt_stack/main.cpp:17:(.text+0x76): undefined reference to `Stack::size() const'
collect2.exe: error: ld returned 1 exit status
mingw32-make[3]: *** [CMakeFiles\03_adt_stack.dir\build.make:117: 03_adt_stack.exe] Error 1
mingw32-make[2]: *** [CMakeFiles\Makefile2:180: CMakeFiles/03_adt_stack.dir/all] Error 2
mingw32-make[1]: *** [CMakeFiles\Makefile2:187: CMakeFiles/03_adt_stack.dir/rule] Error 2
mingw32-make: *** [Makefile:149: 03_adt_stack] Error 2

**Cause:** I had declare the int size() const in the main.cpp, but I was missing the corresponding implementation (should have been in Stack.cpp). The source files compiles because the declaration existed, but the linker couldn't find the function body. 

**Fix:** I added the following matching implementation in Stack.cpp (int Stack::size() const {return topIndex +1;}), and after adding the function body the linker was able to find Stack::size() const.



**Error 2**

**Date:** September 16th, 2026

**Error type:** Compile-time type error

====================[ Build | 03_adt_stack | Debug ]============================
C:\Users\avaja\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe --build C:\Users\avaja\CLionProjects\CS210CPPRepo\cmake-build-debug --target 03_adt_stack -- -j 10
[ 33%] Building CXX object CMakeFiles/03_adt_stack.dir/03_adt_stack/Stack.cpp.obj
C:\Users\avaja\CLionProjects\CS210CPPRepo\03_adt_stack\Stack.cpp: In member function 'void Stack::push(int)':
C:\Users\avaja\CLionProjects\CS210CPPRepo\03_adt_stack\Stack.cpp:24:10: error: request for member 'push_back' in '((Stack*)this)->Stack::data', which is of non-class type 'int [100]'
24 |     data.push_back(value);
|          ^~~~~~~~~
mingw32-make[3]: *** [CMakeFiles\03_adt_stack.dir\build.make:92: CMakeFiles/03_adt_stack.dir/03_adt_stack/Stack.cpp.obj] Error 1
mingw32-make[2]: *** [CMakeFiles\Makefile2:180: CMakeFiles/03_adt_stack.dir/all] Error 2
mingw32-make[1]: *** [CMakeFiles\Makefile2:187: CMakeFiles/03_adt_stack.dir/rule] Error 2
mingw32-make: *** [Makefile:149: 03_adt_stack] Error 2

**Cause:** I attempted to use data.pushback(value) inside of Stack::push. But because data is declared as int data[100], it is a fixed C-style array. The array doesn't have a push_back member function and therefore wouldn't compile. 

**Fix:** I replaced data.push_back(value) with direct array access. I checked that the stack wasn't full, and incremented topIndex once and stored the value (data[topIndex] = value). This way it uses the C-style array.


