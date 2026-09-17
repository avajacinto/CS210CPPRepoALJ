// TASK 03 -- Using the Stack ADT
//
// Read this file without ever opening Stack.cpp. You should still be
// able to tell exactly what this program does. That's the ADT promise
// in action: the header alone is enough documentation to use the type.

#include <iostream>
#include "Stack.h"

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Top: " << stack.peek() << std::endl;

    std::cout << "Popped: " << stack.pop() << std::endl;




    return 0;
}

// TRY IT LIVE: ask the class "what data structure is UNDER this stack?"
// Nobody can answer just from reading this file, and that's correct --
// it's not their business. Then open Stack.h to reveal it's a vector.
