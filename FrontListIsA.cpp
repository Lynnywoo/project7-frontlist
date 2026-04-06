/*
 * @file FrontListIsA.cpp
 * @brief Implementation of FrontListIsA (public inheritance / is-a).
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#include "FrontListIsA.h"

// Constructors / destructor
template<class ItemType>
FrontListIsA<ItemType>::FrontListIsA()
{

} // end default constructor

template<class ItemType>
FrontListIsA<ItemType>::FrontListIsA(const FrontListIsA<ItemType>& aList)
    : LinkedList<ItemType>(aList)
{

} // end copy constructor

template<class ItemType>
FrontListIsA<ItemType>::~FrontListIsA()
{

} // end destructor

//FrontList operations
template<class ItemType>
bool FrontListIsA<ItemType>::insert(const ItemType& newEntry)
{

    return LinkedList<ItemType>::insert(1, newEntry);
} // end insert

template<class ItemType>
bool FrontListIsA<ItemType>::remove()
{

    return LinkedList<ItemType>::remove(1);
} // end remove

template<class ItemType>
ItemType FrontListIsA<ItemType>::retrieve() const throw(PrecondViolatedExcep)
{
    if (LinkedList<ItemType>::isEmpty())
        throw PrecondViolatedExcep("retrieve() called empty: FrontList.");

    return LinkedList<ItemType>::getEntry(1);
} // end retrieve

template<class ItemType>
void FrontListIsA<ItemType>::clear()
{
    // callS front-only remove() until empty
    while (!LinkedList<ItemType>::isEmpty())
        LinkedList<ItemType>::remove(1);  // call base, avoidS recursion
} // end clear

// Disabled positional operations 
template<class ItemType>
bool FrontListIsA<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    throw PrecondViolatedExcep(
        "insert(int, ItemType) is disabled:FrontListIsA. "
        "Use insert(ItemType) to add.");
    return false;
} // end disable insert

template<class ItemType>
bool FrontListIsA<ItemType>::remove(int position)
{
    throw PrecondViolatedExcep(
        "remove(int) is disabled: FrontListIsA. "
        "Use remove() to remove.");
    return false;
} // end disable remove

template<class ItemType>
void FrontListIsA<ItemType>::replace(int position, const ItemType& newEntry)
    throw(PrecondViolatedExcep)
{
    throw PrecondViolatedExcep(
        "replace(int, ItemType) is disabled: FrontListIsA.");
} // end disable replace
