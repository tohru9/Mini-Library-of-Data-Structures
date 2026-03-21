#include <iostream>
#include <string>
#include <stdexcept>
#include "../src/arrayDeque.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {

auto start = high_resolution_clock::now();

    cout << "Situation: Waiting for sr eli tan to review our code" << endl << endl;

    ArrayDeque<string> reviewLine(5); // there are 5 chairs/slots available

    // test for empty
    cout << "Is the office empty? " << (reviewLine.isEmpty() ? "Yes" : "No") << endl;
    cout << "Students currently waiting: " << reviewLine.size() << endl << endl;

    // normal add, at the tail
    cout << " sr eli tan arrives " << endl;
    reviewLine.addLast("Hya");
    reviewLine.addLast("Russel");
    reviewLine.addLast("Sean");
    reviewLine.displayLine();
    cout << "Hya, Russel, and Sean sit down in the office to get their code checked." << endl;
    cout << "Students currently waiting: " << reviewLine.size() << endl << endl;

    // add at the head, senior? idk
    cout << " surprise event badum tsss" << endl;
    reviewLine.addFirst("Panicking Blockmate");
    cout << "A panicking blockmate whose project is due in 5 minutes uses addFirst() to cut the line!" << endl;
    
    cout << "\nThis is the current line now: " << endl;
    reviewLine.displayLine();
    
    // peeking
    cout << "\n[Sr Eli Tan peeks out the office door...]" << endl;
    cout << "Next to be reviewed (peekFirst): " << reviewLine.peekFirst() << " (Should be panicking blockmate)" << endl;
    cout << "Last in line (peekLast): " << reviewLine.peekLast() << " (Should be Sean)" << endl << endl;

    // sr is done checking so remove head and move to next
    cout << " Sr Eli Tan starts reviewing the codes " << endl;
    cout << reviewLine.removeFirst() << "'s code survived the review :0 (Should be Panicking Senior)" << endl;
    
    cout << "This is the current line now: " << endl;
    reviewLine.displayLine();

    cout << endl;

    cout << reviewLine.removeFirst() << "'s code survived the review >< (Should be Hya)" << endl;

    cout << "This is the current line now: " << endl;
    reviewLine.displayLine();

    // remove last, someone bailed out
    cout << "\nA student leaves the queue " << endl;
    cout << reviewLine.removeLast() << " got bored and left the queue to play mlbb (Should be Sean)" << endl;
    
    cout << "This is the current line now: " << endl;
    reviewLine.displayLine();

    // it's already past 9pm, close the office lmao
    cout << "\n SR ELI TAN LEAVES THE OFFICE??? " << endl;
    cout << "Sr Eli Tan: 'Office hours are over nadaw huhur'" << endl;
    reviewLine.clear();
    cout << "Is the office empty now? " << (reviewLine.isEmpty() ? "Yes" : "No") << endl;
    cout << "Students currently waiting: " << reviewLine.size() << endl << endl;

    // other tests
    cout << " Error testing " << endl;
    cout << "Sr Eli Tan opens the door and tries to review a student that isn't there..." << endl;
    try {
        reviewLine.removeFirst();
    } catch (const out_of_range& e) {
        cout << "Error Caught: " << e.what() << endl; // ghost front"
    }

    //NEW ADDITIONS TEST
    // ... (After Hya, Russel, and Sean are in line) ...
    reviewLine.addLast("Hya");
    reviewLine.addLast("Sean");
    

    cout << "\nThis is our line atm to test additions" << endl;
    reviewLine.displayLine();
    
    // test for search func
    cout << "Is Hya in line? " << (reviewLine.isWaiting("Hya") ? "Yep!" : "Nope.") << endl;
    cout << "Is Rubelito in line? " << (reviewLine.isWaiting("Rubelito") ? "Yep!" : "Nope.") << endl;

    // test the inverse
    cout << "\nSr Eli Tan said the late comers go first daw xd" << endl;
    reviewLine.unoReverse();
    cout << "Front is now (peekFirst): " << reviewLine.peekFirst() << " (Should be Sean)" << endl;
    cout << "Last is now (peekLast): " << reviewLine.peekLast() << " (Should be Hya)" << endl;
    reviewLine.displayLine();

    cout << "\n  Please sir 1.0 sa  Final Project t-t \n\n";

    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;

    std::cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}