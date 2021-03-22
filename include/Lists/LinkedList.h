//
// Created by dimitrios on 19/3/21.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

#include "Lists/NodeFactory.h"

template <class T>
class LinkedList {
private:
    bool status;
public:
    Node<T> * currNode;
    Node<T> * HEAD;

    explicit LinkedList(T HEAD) :
        HEAD(NodeFactory<T>::NewSNode(HEAD, nullptr)),
        currNode(this->HEAD),
        status(false){}

    bool getStatus() const {
        return this->status;
    }

    LinkedList<T> * find(const T& Data);

    LinkedList<T> * findPrev(const T& Data);

    LinkedList<T> * insert(const T& prevData, const T& Data);

    LinkedList<T> * remove(const T& Data);

    LinkedList<T> * printList();

    ~LinkedList();

};

#include "Lists/LinkedList_impl.h"

#endif //DATASTRUCTURES_LINKEDLIST_H
