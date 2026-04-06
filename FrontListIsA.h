/*
 * @file FrontListIsA.h
 * @brief FrontList implemented via public inheritance from LinkedList (is-a).
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 *
 * Inheriting all members of LinkedList with public access, except
 * for position-based insertion, position-based removal, and replacement,
 * to provide front-only access. The clear() method is overridden since
 * the removal by position(int) cannot be done anymore.
 */

#ifndef FRONT_LIST_IS_A_H
#define FRONT_LIST_IS_A_H

#include "LinkedList.h"
#include "FrontListInterface.h"

template<class ItemType>
class FrontListIsA : public LinkedList<ItemType>
{
public:
    // Constructors / destructor 
    FrontListIsA();
    FrontListIsA(const FrontListIsA<ItemType>& aList);
    virtual ~FrontListIsA();

    // FrontListInterface
    bool     insert(const ItemType& newEntry);
    bool     remove();
    ItemType retrieve() const throw(PrecondViolatedExcep);

    // isEmpty() and getLength() are inherited from LinkedList

    // Override clear() so it works without positional remove(int)
    void clear();
    
    /*
     * Disabled – positional insert is not part of the FrontList ADT.
     * Calling this method throws PrecondViolatedExcep.
     */

    bool insert(int newPosition, const ItemType& newEntry);

    /*
     * Disabled – positional remove is not part of the FrontList ADT.
     * Calling this method throws PrecondViolatedExcep.
     */

    bool remove(int position);

    /*
     * Disabled – replace is not part of the FrontList ADT.
     * Calling this method throws PrecondViolatedExcep.
     */
    
    void replace(int position, const ItemType& newEntry)
        throw(PrecondViolatedExcep);

}; // end FrontListIsA

#include "FrontListIsA.cpp"
#endif
