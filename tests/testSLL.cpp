#include <iostream>
#include "../src/SLL.h" 
#include<chrono>
using namespace std::chrono;
using namespace std;

auto start = high_resolution_clock::now();

int main() {
    SLL<int> myQueue; 

    cout << "Adding 10, 20, and 30 to the queue..." << endl;
    myQueue.add(10);
    myQueue.add(20);
    myQueue.add(30);

    cout << "Removing the first element.." << endl;
    int removedElement = myQueue.remove();
    cout << "element removed: " << removedElement << " (10)" << endl;
    cout << "Removing the next element..." << endl;
    removedElement = myQueue.remove();
    cout << "element removed: " << removedElement << " (20)" << endl;

    if (myQueue.empty()) {
        cout << "The queue is currently empty." << endl;
    } else {
        cout << "The queue is NOT empty, (naay 30)" << endl;
    }
    removedElement = myQueue.remove();
    cout << "element removed: " << removedElement << " (30)" << endl;

    if (myQueue.empty()) {
        cout << "The queue is currently empty." << endl;
    } else {
        cout << "The queue is NOT empty, (trash element frfr)" << endl;
    }

    cout << "############################" << endl;

    // FOR TESTING THE NEW ADDITIONS


    SLL<string> line;
    cout << "\n\nTesting the Errors" << endl;
    try {
        line.whoYou();
    } catch (const out_of_range& e) {
        cout << "Error Caught: " << e.what() << endl; // "Ghost??"
    }
    try {
        line.whoLast();
    } catch (const out_of_range& e) {
        cout << "Error Caught: " << e.what() << endl; // "blud???"
    }
    // we have people now
 
    line.add("Hya");
    line.add("Russel");
    line.add("Sean");

    cout << "\nLine order: Hya -> Russel -> Sean" << endl;
    cout << "\n\nHya wants to code first because mpa2 is coming t-t" << endl;
    cout << "whoYou() returns:  " << line.whoYou() << " (Hya)" << endl;
    cout << "\n\nRussel goes next because his motor wheels were flattened" << endl;
    cout << "whoNext() returns: " << line.whoNext() << " (Russel)" << endl;
    cout << "\n\nSean is late because he keeps on playing mobile legends" << endl;
    cout << "whoLast() returns: " << line.whoLast() << " (Sean)" << endl;

    cout << "\nSr Eli Tan uses 'I am your professor' to cut the line!" << endl;
    line.letSenior("Sr Eli Tan");

    cout << "\nLine order: Sr Eli Tan -> Hya -> Russel -> Sean" << endl;
    cout << "\nSir please dakog grado sa subject" << endl;
    cout << "\nwhoYou() returns:  " << line.whoYou() << " (Should be Sr Eli Tan)" << endl;
    cout << "whoNext() returns: " << line.whoNext() << " (Should be Hya)" << endl;
    cout << "whoLast() returns: " << line.whoLast() << " (Should still be Sean)" << endl;

    // Remove everything
    line.remove(); // Removes Sr Eli Tan
    line.remove(); // Removes Hya
    line.remove(); // Removes Russel
    // Now only Sean is left, the goat frfr
    
    cout << "Only Sean is left in line..." << endl;
    try {
        line.whoNext();
    } catch (const out_of_range& e) {
        cout << "Error Caught: " << e.what() << endl; // Should print "Who you calling??? again brotato"
    }

    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;

    std::cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}