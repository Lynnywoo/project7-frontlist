/**
 * @file ListInterface.h
 * @brief Abstract interface for a positional list ADT.
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 *
 * Defines the contract that all concrete list implementations must satisfy.
 */

#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

#include "PrecondViolatedExcep.h"

template<class ItemType>
class ListInterface
{
public:
    /** Returns whether the list is empty. */
    virtual bool isEmpty() const = 0;

    /** Returns the number of entries in the list. */
    virtual int getLength() const = 0;

    /** Inserts newEntry at the given 1-based position. */
    virtual bool insert(int newPosition, const ItemType& newEntry) = 0;

    /** Removes the entry at the given 1-based position. */
    virtual bool remove(int position) = 0;

    /** Removes all entries from the list. */
    virtual void clear() = 0;

    /** Returns the entry at the given 1-based position. */
    virtual ItemType getEntry(int position) const
        throw(PrecondViolatedExcep) = 0;

    /** Replaces the entry at the given 1-based position. */
    virtual void replace(int position, const ItemType& newEntry)
        throw(PrecondViolatedExcep) = 0;

    /** Virtual destructor. */
    virtual ~ListInterface() {}
}; // end ListInterface

#endif
