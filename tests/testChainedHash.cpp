#include <iostream>
#include <string>
#include <vector>
#include "../src/ChainedHashTable.h"

template <typename T>
void report(const std::string &testName, T actual, T expected)
{
    std::cout << "[TEST] " << testName << "\n";
    std::cout << "  - Expected: " << expected << "\n";
    std::cout << "  - Actual:   " << actual << "\n";
    if (actual == expected)
    {
        std::cout << "  - Result:   PASS\n";
    }
    else
    {
        std::cout << "  - Result:   FAIL\n";
    }
    std::cout << "-----------------------------------\n";
}

void test_integers()
{
    std::cout << "=== RUNNING INTEGER TESTS ===\n\n";
    ChainedHashTable<int> intTable;

    report("Initial Size", (int)intTable.size(), 0);

    intTable.add(10);
    intTable.add(20);
    intTable.add(30);
    report("Size after 3 additions", (int)intTable.size(), 3);

    report("Add duplicate (20)", intTable.add(20), false);
    report("Find existing (10)", intTable.find(10), 10);
    report("Find non-existent (99)", intTable.find(99), 0);

    int removed = intTable.remove(20);
    report("Remove existing (20)", removed, 20);
    report("Size after removal", (int)intTable.size(), 2);
    report("Find removed (20)", intTable.find(20), 0);

    // Large scale test
    for (int i = 100; i < 1000; ++i)
    {
        intTable.add(i);
    }
    report("Size after adding 900 elements", (int)intTable.size(), 902);
    report("Find element 500", intTable.find(500), 500);

    bool threw_exception = false;
    try
    {
        intTable.remove(9999);
    }
    catch (const std::invalid_argument &)
    {
        threw_exception = true;
    }
    report("Exception thrown on invalid remove", threw_exception, true);
}

void test_strings()
{
    std::cout << "\n=== RUNNING STRING TESTS ===\n\n";
    ChainedHashTable<std::string> stringTable;

    stringTable.add("apple");
    stringTable.add("banana");

    report("Add duplicate 'apple'", stringTable.add("apple"), false);
    report("Current size", (int)stringTable.size(), 2);
    report("Find 'banana'", stringTable.find("banana"), std::string("banana"));
    report("Find non-existent 'grape'", stringTable.find("grape"), std::string(""));

    report("Remove 'apple'", stringTable.remove("apple"), std::string("apple"));
    report("Final size", (int)stringTable.size(), 1);
}

int main()
{
    test_integers();
    test_strings();

    std::cout << "\nAll tests completed.\n";
    return 0;
}