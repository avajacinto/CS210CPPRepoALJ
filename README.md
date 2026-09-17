# CS 210 Fall 2026: C++ Foundations (starter code)

This is the fill-in version of the C++ Bootcamp. Each lecture's idea has been pulled out and left
as a `// TODO` for us to write together in class.

## Opening the project in CLion

`File > Open`, pick this folder, wait for
"CMake project loaded," then use the run-configuration dropdown (top
right, next to the green play button) to pick a target.

**Some targets won't build until their TODOs are filled in.** That's
expected, not a sign something's broken. A few will even compile with
just warnings (missing return values) before you touch them, and a
couple are built to fail on purpose (Tasks 09 and 10) until you make
the fix we talk about in class.

## What's blanked, task by task

| # | Folder | What to fill in |
|---|---|---|
| 1 | `01_compile_model` | Two `std::cout` lines in `main.cpp` |
| 2 | `02_header_cpp_split` | `circleArea` / `rectangleArea` bodies in `shape_utils.cpp` |
| 3 | `03_adt_stack` | All five `Stack` method bodies in `Stack.cpp` |
| 4 | `04_classes_objects` | Constructor + all four method bodies in `Rectangle.cpp` |
| 5 | `05_namespaces` | Both `circleArea` bodies in `geometry.cpp` (one takes a radius, one a diameter) |
| 6 | `06_constructors_modern` | All three `Point` constructors in `Point.cpp` -- rewrite each to use a member initializer list / delegation |
| 7 | `07_overloading` | All three `add` bodies in `Calculator.cpp` |
| 8 | `08_overriding_virtual` | `Circle` and `Square` constructors + `area()`/`name()` bodies |
| 9 | `09_diamond_inheritance` | One missing keyword in `Swimmer.h` and `Runner.h` (build it broken first, read the error, then fix it) |
| 10 | `10_access_specifiers` | The missing access specifier on `balance_` in `BankAccount.h`, plus `applyMonthlyInterest()`'s body |
| 11 | `11_main_wrapup` | `Book`'s constructor, and all three `Catalog` method bodies |

Every blanked spot has a comment telling you exactly what to write, and
sometimes the exact line to type. Tasks 9 and 10 are set up so the
*first* thing you do is build the broken version and read the real
compiler error, before fixing it.

## Reflection Questions

1. Immediately after construction, the topIndex variable contains -1. The first valid position in the data array has an index of 0. The index of -1 indicates that the stack contains no elements inside. My function for isEmpty() only needs to evaluate topIndex == -1. Therefore, the true is returned after construction without needing another variable or case.
2. My push function first calls isFull() to determine whether all 100 positions are occupied. If the stack is full, it will print out an error message and doesn't change the stack. Otherwise, it will increment topIndex and store the value in data[topIndex]. The order is important because topIndex starts at -1. In the first push, it must be incremented to 0 before the value is stored. If the operations were reversed, then the code would try to write the first value into data[-1], but it is outside of the array bounds.
3. 
- My push function is O(1). It checks isFull(), increments topIndex, and assigns one value to data[topIndex].
- My pop function is O(1). It checks isEmpty(), copies the value from data[topIndex], decrements topIndex, and returns the copied value. 
- My peek function is O(1). It checks isEmpty(), and returns the value stored at data[topIndex].
- My isEmpty function is O(1) because it has one comparison between topIndex and -1. 
- My isFull function is O(1) because it performs one comparison between topIndex and 99.
- My size function is O(1) because it calculates and returns topIndex + 1.
None of these functions have loops or traverse through the elements, therefore the number of elements currently stored doesn't change the number of stacks performed.
4. When my stack is full, topIndex equals 99, meaning that isFull() returns true. My push function prints "Cannot push, stack is full", then executes return. Since push has a void return type, it doesn't return a value. topIndex stays as 99, and none of the values in data are changed.
5. When pop is called while the stack is empty, isEmpty() returns true. The function prints "Cannot pop: stack is empty", and returns -1. It doesn't decrement topIndex, and topIndex will remain -1. When peek is called while the stack is empty, it prints "Cannot peek: stack is empty" and returns -1. It doesn't change the stack and will remain -1. I chose this behavior because we cannot use exceptions. Printing a message explains the problem, and by returning -1 provides a consistent value. However, -1 could also be a stored integer, so the return value alone cannot distinguish an error from a succesful operation. 
6. In order to increase the fixed capacity, I would change data[100] to a larger C-style array and update the boundary in isFull(). For example, an array with 200 positions would be full when topIndex == 199. The six operations would remain O(1), although each stack object would use more memory. In a future version, the class could use more dynamic storage at the expense of time complexity, creating a larger array. Resizing would take O(n) time because the existing elements would need to be copied. Regular pushes would stay as O(1), but a push that causes resizing would have O(n) complexity. 
7. One advantage of a linked-list implementation is that it could add the nodes as needed, while memory is available (rather than being limited to the 100 positions). One disadvantage is that every node would need to store a pointer along with its integer value. Managing the nodes and pointers would make the implementation more complicated, rather than tracking positions in a fixed array. 