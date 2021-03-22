//
// Created by dimitrios on 20/3/21.
//

#include "Lists/NodeFactory.h"
#include <iostream>

template <typename T>
CircularLinkedList<T> * CircularLinkedList<T>::find(const T& Data) {
    Node<T> * memoNode = this->currNode;
    this->currNode = this->HEAD;
    while (this->currNode->Data != Data) {
        this->currNode = this->currNode->next;
        if (this->currNode == this->HEAD) {
            this->currNode = memoNode;
            this->status = false;
            return this;
        }
    }
    this->status = true;
    return this;
}

template <typename T>
CircularLinkedList<T> * CircularLinkedList<T>::insert(const T &prevData, const T &Data) {
    Node<T> * memoNode = this->currNode;
    if (!find(prevData)->getStatus()) {
        this->currNode = memoNode;
        return this;
    }

    auto * newNode = NodeFactory<T>::NewDNode(Data, this->currNode, this->currNode->next);

    if (this->currNode->next != this->HEAD) {
        this->currNode->next->prev = newNode;
    }

    this->currNode->next = newNode;
    this->status = true;
    return this;
}

template <typename T>
CircularLinkedList<T> * CircularLinkedList<T>::remove(const T &Data){
    Node<T> * memoNode = this->currNode;
    if (!CircularLinkedList::find(Data)->getStatus()) {
        this->currNode = memoNode;
        return this;
    }

    if (this->currNode->next != this->HEAD) {
        this->currNode->next->prev = this->currNode->prev;
    }

    this->currNode->prev->next = this->currNode->next;

    Node<T> * removedNode = this->currNode;
    this->currNode = this->currNode->next;

    delete removedNode;
    this->status = true;
    return this;
}

template <typename T>
CircularLinkedList<T> * CircularLinkedList<T>::printList() {
    this->currNode = this->HEAD->next;
    while(this->currNode != this->HEAD) {
        std::cout << this->currNode->Data << std::endl;
        this->currNode = this->currNode->next;
    }

    return this;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList(){
    this->currNode = this->HEAD->next;
    while (this->currNode != this->HEAD) {
        Node<T> * memoCurrNode = this->currNode;
        delete memoCurrNode;
        this->currNode = this->currNode->next;
    }

    delete this->HEAD;
}