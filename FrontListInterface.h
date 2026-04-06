/**
 * @file FrontListInterface.h
 * @brief Abstract interface for the ADT FrontList.
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 *
 * In FrontList, all operations for inserting, deleting, and accessing elements can only be performed on 
 * the front element in the list.
 *
 * Operations include:
 *   insert(newEntry)     – insert newEntry to the front
 *   remove()             – delete front element
 *   retrieve()           – return the front element without deletion
 *   isEmpty()            – true if there is nothing in the list
 *   getLength()          – number of elements in the list
 *   clear()              – delete all elements
 */

#ifndef FRONT_LIST_INTERFACE_H
#define FRONT_LIST_INTERFACE_H

#include "PrecondViolatedExcep.h"

template<class ItemType>
class FrontListInterface
{
public:
    /** Returns true if the list contains no entries. */
    virtual bool isEmpty() const = 0;

    /** Returns the number of entries in the list. */
    virtual int getLength() const = 0;

    /**
     * Inserts newEntry at the front of the list.
     * @return true if insertion succeeded, false otherwise.
     */
    virtual bool insert(const ItemType& newEntry) = 0;

    /**
     * Removes the entry at the front of the list.
     * @return true if removal succeeded (list was non-empty), false otherwise.
     */
    virtual bool remove() = 0;

    /**
     * Returns the entry at the front of the list without removing it.
     * @throw PrecondViolatedExcep if the list is empty.
     */
    virtual ItemType retrieve() const throw(PrecondViolatedExcep) = 0;

    /** Removes all entries from the list. */
    virtual void clear() = 0;

    /** Virtual destructor. */
    virtual ~FrontListInterface() {}
}; // end FrontListInterface

#endif
