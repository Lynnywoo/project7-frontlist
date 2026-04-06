/**
 * @file FrontListAsA.h
 * @brief FrontList is implemented through the private inheritance of LinkedList (as-a).
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 * 
 * Having private inheritance means that the LinkedList's interface is completely hidden
 * from other clients. The FrontListInterface virtuals are being satisfied by
 * the explicitly overriding method which includes isEmpty() and getLength(),
 * these delegate straight to the base of private. Positional insert/remove/replace
 * aren't accessible to clients during the compile (private base), so
 * no runtime guards are needed for them.
 */

#ifndef FRONT_LIST_AS_A_H
#define FRONT_LIST_AS_A_H

#include "LinkedList.h"
#include "FrontListInterface.h"

template<class ItemType>
class FrontListAsA : private LinkedList<ItemType>,
                     public  FrontListInterface<ItemType>
{
public:
    // ── Constructors / destructor ──────────────────────────────────
    FrontListAsA();
    FrontListAsA(const FrontListAsA<ItemType>& aList);
    virtual ~FrontListAsA();

    // ── All of the virutals of FrontListInterface  ───────────
    bool     isEmpty()   const;          // delegates LinkedList
    int      getLength() const;          // delegates LinkedList
    bool     insert(const ItemType& newEntry);
    bool     remove();
    ItemType retrieve() const throw(PrecondViolatedExcep);
    void     clear();

}; // end of FrontListAsA

#include "FrontListAsA.cpp"
#endif
