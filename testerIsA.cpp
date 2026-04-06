/*
 * @file testerIsA.cpp
 * @brief Driver program that tests FrontListIsA (public inheritance / is-a).
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 *
 *   insert() at the front
 *   retrieve() from the front
 *   remove() from the front
 *   isEmpty() and getLength()
 *   clear() (overridden version)
 *   copy constructor
 *   retrieve() on an empty list (exception test)
 *   disabled insert(int, ItemType)  – expects exception
 *   disabled remove(int)            – expects exception
 *   disabled replace(int, ItemType) – expects exception
 */

#include <iostream>
#include <string>
#include "FrontListIsA.h"

// prints the front item and the list length
template<class ItemType>
void displayFront(const FrontListIsA<ItemType>& fl, const std::string& label)
{
    std::cout << label;
    if (fl.isEmpty())
        std::cout << "  (list is empty, length = 0)\n";
    else
        std::cout << "  front = " << fl.retrieve()
                  << "  |  length = " << fl.getLength() << "\n";
} // end displayFront

int main()
{
    std::cout << "========================================\n";
    std::cout << "  Testing FrontListIsA (is-a / public inheritance)\n";
    std::cout << "========================================\n\n";

    FrontListIsA<int> fl;

    // isEmpty on a new list 
    std::cout << "--- isEmpty / getLength on new list ---\n";
    std::cout << "isEmpty()   : " << (fl.isEmpty()    ? "true" : "false") << "\n";
    std::cout << "getLength() : " << fl.getLength()   << "\n\n";

    // insert 
    std::cout << "--- insert 10, 20, 30 (each goes to front) ---\n";
    fl.insert(10);
    displayFront(fl, "After insert(10)");

    fl.insert(20);
    displayFront(fl, "After insert(20)");

    fl.insert(30);
    displayFront(fl, "After insert(30)");
    std::cout << "\n";

    // retrieve 
    std::cout << "--- retrieve (should be 30) ---\n";
    std::cout << "retrieve() = " << fl.retrieve() << "\n\n";

    // remove
    std::cout << "--- remove front entries one at a time ---\n";
    bool removed = fl.remove();
    std::cout << "remove() returned " << (removed ? "true" : "false") << "\n";
    displayFront(fl, "After first remove");

    removed = fl.remove();
    std::cout << "remove() returned " << (removed ? "true" : "false") << "\n";
    displayFront(fl, "After second remove");

    removed = fl.remove();
    std::cout << "remove() returned " << (removed ? "true" : "false") << "\n";
    displayFront(fl, "After third remove");
    std::cout << "\n";

    // remove on empty list
    std::cout << "--- remove() on empty list ---\n";
    removed = fl.remove();
    std::cout << "remove() on empty list returned "
              << (removed ? "true" : "false") << "\n\n";

    // clear 
    std::cout << "--- clear() test (overridden version) ---\n";
    fl.insert(5);
    fl.insert(15);
    fl.insert(25);
    std::cout << "Before clear: length = " << fl.getLength() << "\n";
    fl.clear();
    std::cout << "After  clear: isEmpty = "
              << (fl.isEmpty() ? "true" : "false") << "\n\n";

    // copy constructor 
    std::cout << "--- copy constructor test ---\n";
    fl.insert(100);
    fl.insert(200);
    fl.insert(300);

    FrontListIsA<int> fl2(fl);
    std::cout << "Original  : ";  displayFront(fl,  "");
    std::cout << "Copy      : ";  displayFront(fl2, "");

    fl2.remove();
    std::cout << "After removing front from the copy:\n";
    std::cout << "Original  : ";  displayFront(fl,  "");
    std::cout << "Copy      : ";  displayFront(fl2, "");
    std::cout << "\n";

    // retrieve on empty list
    std::cout << "--- retrieve() on empty list (expects exception) ---\n";
    FrontListIsA<int> emptyList;
    try
    {
        emptyList.retrieve();
        std::cout << "ERROR: no exception thrown!\n";
    }
    catch (const PrecondViolatedExcep& e)
    {
        std::cout << "Caught expected exception:\n  " << e.what() << "\n\n";
    }

    // disabled: insert(int, ItemType)
    std::cout << "--- disabled insert(int, ItemType) (expects exception) ---\n";
    try
    {
        fl.insert(1, 999);
        std::cout << "ERROR: no exception thrown!\n";
    }
    catch (const PrecondViolatedExcep& e)
    {
        std::cout << "Caught expected exception:\n  " << e.what() << "\n\n";
    }

    // disabled: remove(int)
    std::cout << "--- disabled remove(int) (expects exception) ---\n";
    try
    {
        fl.remove(1);
        std::cout << "ERROR: no exception thrown!\n";
    }
    catch (const PrecondViolatedExcep& e)
    {
        std::cout << "Caught expected exception:\n  " << e.what() << "\n\n";
    }

    // disabled: replace(int, ItemType)
    std::cout << "--- disabled replace(int, ItemType) (expects exception) ---\n";
    try
    {
        fl.replace(1, 999);
        std::cout << "ERROR: no exception thrown!\n";
    }
    catch (const PrecondViolatedExcep& e)
    {
        std::cout << "Caught expected exception:\n  " << e.what() << "\n\n";
    }

    std::cout << "========================================\n";
    std::cout << "  FrontListIsA tests complete.\n";
    std::cout << "========================================\n";

    return 0;
} // end main
