/**
 * @file LinkedList.cpp
 * @brief Implementation of the LinkedList template class.
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#include "LinkedList.h"
#include <cassert>

// ── Private helper ──────────────────────────────────────────────────────────

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    // Precondition: position is valid (1 <= position <= itemCount)
    assert((position >= 1) && (position <= itemCount));

    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
} // end getNodeAt

// ── Constructors / destructor ───────────────────────────────────────────────

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
    : itemCount(aList.itemCount)
{
    Node<ItemType>* origChainPtr = aList.headPtr; // Points into original list

    if (origChainPtr == nullptr)
    {
        headPtr = nullptr; // Original list is empty
    }
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);

            newChainPtr  = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        } // end while

        newChainPtr->setNext(nullptr); // terminate the new chain
    } // end if
} // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
} // end destructor

// ── Public methods ──────────────────────────────────────────────────────────

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
} // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
} // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

        if (newPosition == 1)
        {
            // Insert before first node
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node before insertion point
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        } // end if

        itemCount++;
    } // end if

    return ableToInsert;
} // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;

        if (position == 1)
        {
            curPtr  = headPtr;
            headPtr = headPtr->getNext();
        }
        else
        {
            Node<ItemType>* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        } // end if

        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
    } // end if

    return ableToRemove;
} // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
} // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
    throw(PrecondViolatedExcep)
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedExcep(message));
    } // end if
} // end getEntry

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
    throw(PrecondViolatedExcep)
{
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    }
    else
    {
        std::string message = "replace() called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedExcep(message));
    } // end if
} // end replace
