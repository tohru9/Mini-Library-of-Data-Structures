#include <iostream>
#include "../src/arrayDeque.h"   

using namespace std;

int main() {
    ArrayDeque<int> ListOfNums;

    cout << "Adding elements..." << endl;
    ListOfNums.add(0, 10);
    ListOfNums.add(1, 20);
    ListOfNums.add(2, 30);
    ListOfNums.add(1, 15); 

    cout << "Current ListOfNums:" << endl;
    ListOfNums.printList();
    cout << endl;

    cout << "\nSetting index 2 to 99..." << endl;
    ListOfNums.set(2, 99);

    cout << "ListOfNums after set:" << endl;
    ListOfNums.printList();
    cout << endl;

    cout << "\nRemoving index 1..." << endl;
    int removed = ListOfNums.remove(1);
    cout << "Removed value: " << removed << endl;

    cout << "Final ListOfNums:" << endl;
    ListOfNums.printList();
    cout << endl;

    cout << "\nFinal size: " << ListOfNums.size() << endl;

    return 0;
}