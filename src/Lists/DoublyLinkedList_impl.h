//
// Created by dimitrios on 20/3/21.
//

#include "Lists/NodeFactory.h"
#include <iostream>

template <typename T>
DoublyLinkedList<T> * DoublyLinkedList<T>::find(const T &Data) {
    this->currNode = this->HEAD;
    while (this->currNode->Data != Data) {
        if (this->currNode->next == nullptr) {
            this->status = false;
            return this;
        }

        this->currNode = this->currNode->next;
    }

    this->status = true;
    return this;
}

template <typename T>
DoublyLinkedList<T> * DoublyLinkedList<T>::insert(const T& prevData, const T& Data) {
    Node<T> memoNode = this->currNode;
    if (!find(prevData)->getStatus()) {
        this->currNode = memoNode;
        return this;
    }

    auto * newNode = NodeFactory<T>::NewDNode(Data, this->currNode, this->currNode->next);

    if (this->currNode->next != nullptr) {
        this->currNode->next->prev = newNode;
    }

    this->currNode->next = newNode;
    this->status = true;
    return this;
}

template <typename T>
DoublyLinkedList<T> * DoublyLinkedList<T>::remove(const T& Data){
    Node<T> memoNode = this->currNode;
    if (!DoublyLinkedList::find(Data)->getStatus()) {
        this->currNode = memoNode;
        return this;
    }

    if (this->currNode->next != nullptr) {
        this->currNode->next->prev = this->currNode->prev;
    }

    this->currNode->prev->next = this->currNode->next;

    Node<T> removedNode = this->currNode;
    this->currNode = this->currNode->next;

    delete removedNode;
    this->status = true;
    return this;
}

template <typename T>
DoublyLinkedList<T> * DoublyLinkedList<T>::printList() {
    this->currNode = this->HEAD->next;
    while(this->currNode != nullptr) {
        std::cout << this->currNode->Data << std::endl;
        this->currNode = this->currNode->next;
    }

    return this;
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    this->currNode = this->HEAD;
    while (this->currNode != nullptr) {
        Node<T> memoCurrNode = this->currNode;
        delete memoCurrNode;
        this->currNode = this->currNode->next;
    }
}