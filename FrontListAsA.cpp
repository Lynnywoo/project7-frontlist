/**
 * @file FrontListAsA.cpp
 * @brief Implementation of FrontListAsA (private inheritance / as-a).
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#include "FrontListAsA.h"

// ── Constructors / destructor ───────────────────────────────────────────────

template<class ItemType>
FrontListAsA<ItemType>::FrontListAsA()
{
    // The LinkedList's default constructor is called automatically
} // end of default the constructor

template<class ItemType>
FrontListAsA<ItemType>::FrontListAsA(const FrontListAsA<ItemType>& aList)
    : LinkedList<ItemType>(aList)
{
    // The LinkedList's copy constructor performs a deep copy
} // end copy constructors copy

template<class ItemType>
FrontListAsA<ItemType>::~FrontListAsA()
{
    // The LinkedList's destructor which releases all of the nodes automatically
} // end of the destructor

// ── FrontListInterface overrides ────────────────────────────────────────────

template<class ItemType>
bool FrontListAsA<ItemType>::isEmpty() const
{
    return LinkedList<ItemType>::isEmpty();
} // end of isEmpty

template<class ItemType>
int FrontListAsA<ItemType>::getLength() const
{
    return LinkedList<ItemType>::getLength();
} // end ofgetLength

template<class ItemType>
bool FrontListAsA<ItemType>::insert(const ItemType& newEntry)
{
    // Delegates to the LinkedList::insert private section at the position = 1
    return LinkedList<ItemType>::insert(1, newEntry);
} // end of insert

template<class ItemType>
bool FrontListAsA<ItemType>::remove()
{
    // Delegate to the private LinkedList::remove at position 1
    return LinkedList<ItemType>::remove(1);
} // end of remove

template<class ItemType>
ItemType FrontListAsA<ItemType>::retrieve() const throw(PrecondViolatedExcep)
{
    if (LinkedList<ItemType>::isEmpty())
        throw PrecondViolatedExcep("retrieve() called on an empty FrontList.");

    return LinkedList<ItemType>::getEntry(1);
} // end of retrieve

template<class ItemType>
void FrontListAsA<ItemType>::clear()
{
    // Calls the base-class remove(1) directly and the positional operations are private
    // but also accessible here as we are inside the derived class.
    while (!LinkedList<ItemType>::isEmpty())
        LinkedList<ItemType>::remove(1);
} // end of clear
