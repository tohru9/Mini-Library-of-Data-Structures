#include <iostream>
#include <string>
#include <stdexcept>
#include "../src/DLL.h"
#include <chrono> 
using namespace std::chrono;
using namespace std;


auto start = high_resolution_clock::now();

// for printing thr list
void printList(const DLL<string>& row) {
    cout << "[List: ";
    for (size_t i = 0; i < row.size(); i++) {
        cout << row.get(i);
        if (i < row.size() - 1) cout << " <-> "; // for visual
    }
    cout << "]" << endl;
}

int main() {
    cout << " CMSC 141 Automata Quiz: Sir Ryan's Class " << endl << endl;

    DLL<string> quizList;

    cout << "The quiz begins. Sean sits at the very front (index 0)." << endl;
    quizList.add(0, "Sean");
    printList(quizList);

    cout << "\nHya sits right behind Sean at index 1." << endl;
    quizList.add(1, "Hya");
    printList(quizList);

    cout << "\nRussel realizes he doesn't know how to convert an NFA to a DFA." << endl;
    cout << "   He squeezes in exactly between Sean and Hya (index 1) to copy!" << endl;
    quizList.add(1, "Russel");
    printList(quizList);

    cout << "\n A TENNIS PLAYER ARRIVES???" << endl;
    cout << "Sir Ryan stops the timer! His favorite person, Alexandra Eala, walks in." << endl;
    cout << "He immediately gives her the best seat at the absolute front (index 0)." << endl;
    quizList.add(0, "Alexandra Eala");
    printList(quizList);

    cout << "\n Sir Ryan checks the class and tells them, I woke up in the morning feeling like Charles Babbage" << endl;
    cout << "Sir Ryan asks: 'Who is sitting at index 2?'" << endl;
    cout << "Result: " << quizList.get(2) << " (Should be Russel, sweating nervously)" << endl;
    cout << "Sir Ryan asks: 'Who is sitting at the very back (index 3)?'" << endl;
    cout << "Result: " << quizList.get(3) << ", who is answering swiftly but blankly (Should be Hya)" << endl;

    cout << "\n Is this subject even useful haysttt" << endl;
    cout << "Sean sees the Turing Machine question and completely gives up because he is not gay" << endl;
    cout << "He swaps seats with Terrence Tao at index 1." << endl;
    string oldStudent = quizList.set(1, "Terrence Tao");
    cout << oldStudent << " handed in a blank paper and left!" << endl;
    printList(quizList);

    // new additions test
    cout << "\nSir Ryan walks from the back of the room to the front!" << endl;
    quizList.patrolBackwards(); 
    //Hya -> Russel -> Terrence Tao -> Alexandra Eala

    cout << "\nSir Ryan gets suspicious of Russel..." << endl;
    quizList.checkNeighbors("Russel");
    // terrence front, hya behind

    cout << "\nSir Ryan checks on his favorite student..." << endl;
    quizList.checkNeighbors("Alexandra Eala");
    // result is nobody

    cout << "\n Time's up na lolz" << endl;
    cout << "Alexandra Eala finishes the Automata quiz in 3 minutes flat." << endl;
    cout << "Removed index 0: " << quizList.remove(0) << " leaves to go win a tennis tournament." << endl;
    printList(quizList);

    cout << "\nRussel gets caught trying to draw a state diagram on his hand." << endl;
    cout << "Removed index 1: " << quizList.remove(1) << " gets kicked out by Sir Ryan." << endl;
    printList(quizList);

    cout << "\n Testing for exceptions" << endl;
    cout << "Sir Ryan tries to deduct points from the student sitting at index 100..." << endl;
    try {
        quizList.get(100);
    } catch (const out_of_range& e) {
        cout << "Error Caught: " << e.what() << endl; 
    }
    cout << "\nSir Ryan wants to look at hya..." << endl;
    try { 
        quizList.checkNeighbors("Hya");
    } catch (const out_of_range& e) {
        cout << "Error Caught: " << e.what() << endl; 
    } 
    // terrence front, no one behind
    printList(quizList);

    cout << "Sir patrols one more time..." << endl;
    try { 
        quizList.patrolBackwards();
    } catch (const out_of_range& e) {
        cout << "Error Caught: " << e.what() << endl; 
    }    

    cout << "\n Quiz is done and no one passed..." << endl;

    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;

    std::cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}