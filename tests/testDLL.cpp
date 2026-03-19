#include <iostream>
#include <string>
#include <stdexcept>
#include "../src/DLL.h" 

using namespace std;

// for printing thr list
void printRow(const DLL<string>& row) {
    cout << "[List: ";
    for (size_t i = 0; i < row.size(); i++) {
        cout << row.get(i);
        if (i < row.size() - 1) cout << " <-> "; // for visual
    }
    cout << "]" << endl;
}

int main() {
    cout << " CMSC 141 Automata Quiz: Sir Ryan's Class " << endl << endl;

    DLL<string> quizRow;

    cout << "The quiz begins. Sean sits at the very front (index 0)." << endl;
    quizRow.add(0, "Sean");
    printRow(quizRow);

    cout << "\nHya sits right behind Sean at index 1." << endl;
    quizRow.add(1, "Hya");
    printRow(quizRow);

    cout << "\nRussel realizes he doesn't know how to convert an NFA to a DFA." << endl;
    cout << "   He squeezes in exactly between Sean and Hya (index 1) to copy!" << endl;
    quizRow.add(1, "Russel");
    printRow(quizRow);

    cout << "\n A TENNIS PLAYER ARRIVES???" << endl;
    cout << "Sir Ryan stops the timer! His favorite person, Alexandra Eala, walks in." << endl;
    cout << "He immediately gives her the best seat at the absolute front (index 0)." << endl;
    quizRow.add(0, "Alexandra Eala");
    printRow(quizRow);

    cout << "\n Sir Ryan checks the class and tells them, I woke up in the morning feeling like Charles Babbage" << endl;
    cout << "Sir Ryan asks: 'Who is sitting at index 2?'" << endl;
    cout << "Result: " << quizRow.get(2) << " (Should be Russel, sweating nervously)" << endl;
    cout << "Sir Ryan asks: 'Who is sitting at the very back (index 3)?'" << endl;
    cout << "Result: " << quizRow.get(3) << ", who is answering swiftly but blankly (Should be Hya)" << endl;

    cout << "\n Is this subject even useful haysttt" << endl;
    cout << "Sean sees the Turing Machine question and completely gives up because he is not gay" << endl;
    cout << "He swaps seats with Terrence Tao at index 1." << endl;
    string oldStudent = quizRow.set(1, "Terrence Tao");
    cout << oldStudent << " handed in a blank paper and left!" << endl;
    printRow(quizRow);

    cout << "\n Time's up na lolz" << endl;
    cout << "Alexandra Eala finishes the Automata quiz in 3 minutes flat." << endl;
    cout << "Removed index 0: " << quizRow.remove(0) << " leaves to go win a tennis tournament." << endl;
    printRow(quizRow);

    cout << "\nRussel gets caught trying to draw a state diagram on his hand." << endl;
    cout << "Removed index 1: " << quizRow.remove(1) << " gets kicked out by Sir Ryan." << endl;
    printRow(quizRow);

    cout << "\n Testing for exceptions" << endl;
    cout << "Sir Ryan tries to deduct points from the student sitting at index 100..." << endl;
    try {
        quizRow.get(100);
    } catch (const out_of_range& e) {
        cout << "Error Caught: " << e.what() << endl; 
    }

    cout << "\n Quiz is done and no one passed..." << endl;

    return 0;
}