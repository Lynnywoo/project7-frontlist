/*
 * @file FrontListHasA.cpp
 * @brief (containment / has-a).
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#include "FrontListHasA.h"

// Constructors / destructor 
template<class ItemType>
FrontListHasA<ItemType>::FrontListHasA()
{

} // end default constructor

template<class ItemType>
FrontListHasA<ItemType>::FrontListHasA(const FrontListHasA<ItemType>& aList)
    : list(aList.list)
{

} // end copy constructor

template<class ItemType>
FrontListHasA<ItemType>::~FrontListHasA()
{

} // end destructor

// FrontListInterface 
template<class ItemType>
bool FrontListHasA<ItemType>::isEmpty() const
{
    return list.isEmpty();
} // end isEmpty

template<class ItemType>
int FrontListHasA<ItemType>::getLength() const
{
    return list.getLength();
} // end getLength

template<class ItemType>
bool FrontListHasA<ItemType>::insert(const ItemType& newEntry)
{

    return list.insert(1, newEntry);
} // end insert

template<class ItemType>
bool FrontListHasA<ItemType>::remove()
{
    
    return list.remove(1);
} // end remove

template<class ItemType>
ItemType FrontListHasA<ItemType>::retrieve() const throw(PrecondViolatedExcep)
{
    if (list.isEmpty())
        throw PrecondViolatedExcep("retrieve() retreived an empty FrontList.");

    return list.getEntry(1);
} // end retrieve

template<class ItemType>
void FrontListHasA<ItemType>::clear()
{
    list.clear();
} // end clear
