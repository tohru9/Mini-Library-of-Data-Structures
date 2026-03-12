#include <iostream>
#include <cstddef>
#include "../src/arrayStack.h"

int main() {
    ArrayStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top: " << stack.top() << std::endl;    // 30
    std::cout << "Pop: " << stack.pop() << std::endl;    // 30
    std::cout << "Top: " << stack.top() << std::endl;    // 20
    std::cout << "Size: " << stack.size() << std::endl;  // 2

    return 0;
}
