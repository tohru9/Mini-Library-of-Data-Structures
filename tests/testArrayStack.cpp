#include <iostream>
#include <cstddef>
#include<string>
#include "../src/arrayStack.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {
    auto start = high_resolution_clock::now();

    ArrayStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Top: " << stack.top() << std::endl;    // 30
    std::cout << "Pop: " << stack.pop() << std::endl;    // 30
    std::cout << "Top: " << stack.top() << std::endl;    // 20
    std::cout << "Size: " << stack.size() << std::endl;  // 2

    std::cout << "Pop: " << stack.pop() << std::endl;    // 20
    std::cout << "Size: " << stack.size() << std::endl;  // 1
    std::cout << "Top: " << stack.top() << std::endl;    // 10

    std::cout << "Pop: " << stack.pop() << std::endl;    // 10
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(60);
    std::cout << "Top: " << stack.top() << std::endl;    // 60
    std::cout << "Size: " << stack.size() << std::endl;  // 1
    std::cout << "Pop: " << stack.pop() << std::endl;    // 60
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout << "Size: " << stack.size() << std::endl;  // 5
    std::cout << "Pop: " << stack.pop() << std::endl;    // 5
    std::cout << "Pop: " << stack.pop() << std::endl;    // 4
    std::cout << "Pop: " << stack.pop() << std::endl;    // 3
    std::cout << "Pop: " << stack.pop() << std::endl;    // 2
    std::cout << "Pop: " << stack.pop() << std::endl;    // 1
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(-5);
    stack.push(0);
    stack.push(-1);
    std::cout << "Top: " << stack.top() << std::endl;    // -1
    std::cout << "Pop: " << stack.pop() << std::endl;    // -1
    std::cout << "Pop: " << stack.pop() << std::endl;    // 0
    std::cout << "Pop: " << stack.pop() << std::endl;    // -5
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(7);
    stack.push(7);
    stack.push(7);
    std::cout << "Size: " << stack.size() << std::endl;  // 3
    std::cout << "Pop: " << stack.pop() << std::endl;    // 7
    std::cout << "Pop: " << stack.pop() << std::endl;    // 7
    std::cout << "Pop: " << stack.pop() << std::endl;    // 7
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(42);
    std::cout << "Top: " << stack.top() << std::endl;    // 42
    std::cout << "Top: " << stack.top() << std::endl;    // 42 (still there)
    std::cout << "Size: " << stack.size() << std::endl;  // 1
    std::cout << "Pop: " << stack.pop() << std::endl;    // 42
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    duration<double> duration = high_resolution_clock::now() - start;
    std::cout << "\nExecution time: " << duration.count() << " seconds" << endl;

    return 0;
}
    /*
    cout << "There are 3 things inside Queen's Bag" << endl;
    stack.push("Perfume");
    stack.push("Umbrella");
    stack.push("Wet Wipes");

    //cout << "Top: " << stack.top() << endl;    

    cout << "Althea visits Queen in her Math 54 class and asks if she could borrow her perfume" << endl;
    cout << "Queen hurriedly opened her bag and grabbed the perfume, but it was in the bottom of her bag" << endl;
    cout << "Queen gets the one on top which is her " << stack.pop() << endl;    
    cout << "And then her " << stack.pop() << endl;
    cout << "Now she can finally grab what she needed and let Althea borrow some " << stack.pop() << endl;   
    cout << "However, she needs to put back everything again :< so hassle" << endl;
    cout << "She puts her umbrella back." << stack.push("Umbrella") << endl;
    cout << "Queen!" << endl;
    cout <<
    */

