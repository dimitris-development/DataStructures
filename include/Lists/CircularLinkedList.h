//
// Created by dimitrios on 20/3/21.
//

#ifndef DATASTRUCTURES_CIRCULARLINKEDLIST_H
#define DATASTRUCTURES_CIRCULARLINKEDLIST_H


#include "Lists/NodeFactory.h"

template <typename T>
class CircularLinkedList {
private:
    bool status;
public:
    Node<T> * currNode;
    Node<T> * HEAD;

    explicit CircularLinkedList(T &HEAD)
            :
            HEAD(NodeFactory<T>::NewDNode(HEAD, this->HEAD, this->HEAD)),
            currNode(this->HEAD),
            status(false){}

    bool getStatus () const {
        return this->status;
    }

    CircularLinkedList * find(const T& Data);

    CircularLinkedList * insert(const T& prevData, const T& Data);

    CircularLinkedList * remove(const T& Data);

    CircularLinkedList * printList();

    ~CircularLinkedList();
};

#include "Lists/CircularLinkedList_impl.h"

#endif //DATASTRUCTURES_CIRCULARLINKEDLIST_H
