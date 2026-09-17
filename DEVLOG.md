

# Development Log

## 9/15/26 - Stack Representation

I replaced the vector representation with the fixed array 'data[100]'. I also initialized the 'topIndex' to -1 so that the empty state could be represented without a separate variable. 


## 9/16/26 - Stack operations

I implemented push, pop, peek, isEmpty, isFull, and size. I also decided to print a message for boundary errors (full or empty). If there is an unsuccessful pop or peek, then -1 is returned.

I chose this method since we cannot throw exceptions, and it will prevent invalid array access. 


## 9/16/26 - Tests and reflection

I tested the stack using 10, 20, and 30. The program had showed 30 was at the top and that it was the first value removed. I also checked the size before and after the pop. 

What I would do differently is to test the empty and full conditions earlier, including filling all 100 of the positions and attempting another push.

