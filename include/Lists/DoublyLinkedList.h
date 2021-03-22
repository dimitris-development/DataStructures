//
// Created by dimitrios on 20/3/21.
//

#ifndef DATASTRUCTURES_DOUBLYLINKEDLIST_H
#define DATASTRUCTURES_DOUBLYLINKEDLIST_H

#include "Lists/NodeFactory.h"

template <typename T>
class DoublyLinkedList {
private:
    bool status;
public:
    Node<T> * currNode;
    Node<T> * HEAD;

    explicit DoublyLinkedList(T &HEAD)
            :
            HEAD(NodeFactory<T>::NewDNode(HEAD, nullptr, nullptr)),
            currNode(this->HEAD),
            status(false){}

    bool getStatus() const {
        return this->status;
    }
    
    DoublyLinkedList<T> * find(const T& Data);

    DoublyLinkedList<T> * insert(const T& prevData, const T& Data);

    DoublyLinkedList<T> * remove(const T& Data);

    DoublyLinkedList<T> * printList();

    ~DoublyLinkedList();
};


#include "Lists/DoublyLinkedList_impl.h"

#endif //DATASTRUCTURES_DOUBLYLINKEDLIST_H
