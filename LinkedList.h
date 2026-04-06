/*
 * @file LinkedList.h
 * @brief Implementation of the ListInterface.
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr;  
    int             itemCount; 

    Node<ItemType>* getNodeAt(int position) const;

public:
    // Constructors / destructor 
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);  
    virtual ~LinkedList();                           

    // ListInterface 
    bool     isEmpty()    const;
    int      getLength()  const;
    bool     insert(int newPosition, const ItemType& newEntry);
    bool     remove(int position);
    void     clear();
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);
    void     replace(int position, const ItemType& newEntry)
                 throw(PrecondViolatedExcep);
}; // end 

#include "LinkedList.cpp"
#endif
