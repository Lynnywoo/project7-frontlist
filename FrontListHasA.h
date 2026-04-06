/*
 * @file FrontListHasA.h
 * @brief FrontList is implemented through containment
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 * 
 * Internally owns the LinkedList<ItemType> instance and delegates all
 * of the work to position=1 of the list.
 */

#ifndef FRONT_LIST_HAS_A_H
#define FRONT_LIST_HAS_A_H

#include "FrontListInterface.h"
#include "LinkedList.h"

template<class ItemType>
class FrontListHasA : public FrontListInterface<ItemType>
{
private:
    LinkedList<ItemType> list;  // Contained linked list

public:
    // Constructors / destructor 
    FrontListHasA();
    FrontListHasA(const FrontListHasA<ItemType>& aList);
    virtual ~FrontListHasA();

    // FrontListInterface override
    bool     isEmpty()   const;
    int      getLength() const;
    bool     insert(const ItemType& newEntry);
    bool     remove();
    ItemType retrieve()  const throw(PrecondViolatedExcep);
    void     clear();
}; // end FrontListHasA

#include "FrontListHasA.cpp"
#endif
