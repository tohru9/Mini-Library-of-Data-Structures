#include <iostream>
#include <string>
#include <stdexcept>
#include "../src/skipList.h" 
#include <chrono>
 
using namespace std::chrono;
using namespace std;
 
const int N = 100000;

int main() {
    //=== Functional Test ===
    cout << "\nCMSC 127: Sir Erik's SQL Database using skip list haha sorna " << endl << endl;

    SkipList<string> database;

    cout << " INSERT Queries " << endl;
    cout << "Query: INSERT INTO students VALUES ('Sean');" << endl;
    database.add("Sean");
    
    cout << "Query: INSERT INTO students VALUES ('Russel');" << endl;
    database.add("Russel");

    cout << "Query: INSERT INTO students VALUES ('Hya');" << endl;
    database.add("Hya");

    cout << "\n Testing UNIQUE Constraint (No Duplicates) " << endl;
    cout << "Query: INSERT INTO students VALUES ('Sean');" << endl;
    bool didSeanJoin = database.add("Sean");
    if (!didSeanJoin) {
        cout << "SQL error lols Primary Key is already present, 'Sean' is already in the database." << endl;
    }

    cout << "\n Database with express lane" << endl;
    // database alphabetical for express lane
    database.displayLanes();

    cout << "\n SELECT Queries (find) " << endl;
    try {
        cout << "Query: SELECT * FROM students WHERE name = 'Hya'..." << endl;
        cout << "Result: Found " << database.find("Hya") << "!" << endl;
        
        cout << "\nQuery: SELECT * FROM students WHERE name = 'Ghost'..." << endl;
        database.find("Ghost"); // error
    } catch (const out_of_range& e) {
        cout << "SQL Error: " << e.what() << endl; 
    }

    cout << "\n  DELETE Queries (remove) " << endl;
    cout << "Query: DELETE FROM students WHERE name = 'Russel';" << endl;
    cout << "Result: Successfully removed " << database.remove("Russel") << "." << endl;
    
    cout << "\n Testing Exception on DELETE " << endl;
    try {
        cout << "Query: DELETE FROM students WHERE name = 'Sir Ryan';" << endl;
        database.remove("Sir Ryan"); // should be error
    } catch (const out_of_range& e) {
        cout << "SQL Error: " << e.what() << endl; 
    }

    cout << "\nTotal rows remaining in database: " << database.size() << endl;

    // Benchmark
    cout << "\n=== Benchmark (" << N << " operations) ===" << endl;
 
    SkipList<int> bench;
 
    high_resolution_clock::time_point start, stop;
    duration<double> dur;
 
    // Benchmark 1: N insertions
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.add(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "add    " << N << " elements:               " << dur.count() << " seconds" << endl;
 
    // Benchmark 2: N successful finds
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.find(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "find   " << N << " elements (all present): " << dur.count() << " seconds" << endl;
 
    // Benchmark 3: N unsuccessful finds
    start = high_resolution_clock::now();
    for (int i = N; i < 2 * N; i++) {
        try { bench.find(i); } catch (...) {}
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "find   " << N << " elements (none present):" << dur.count() << " seconds" << endl;
 
    // Benchmark 4: N removals
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.remove(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "remove " << N << " elements:               " << dur.count() << " seconds" << endl;
 
    return 0;
}