//
// Created by dimitrios on 20/3/21.
//

#include "Lists/NodeFactory.h"
#include <iostream>

template <typename T>
LinkedList<T> * LinkedList<T>::find(const T& Data) {
    Node<T> * memoCurrNode = this->currNode;
    this->currNode = this->HEAD;
    while(this->currNode->Data != Data) {
        if (this->currNode->next == nullptr) {
            this->status = false;
            this->currNode = memoCurrNode;
            return this;
        }

        this->currNode = this->currNode->next;
    }

    this->status = true;
    return this;
}

template <typename T>
LinkedList<T> * LinkedList<T>::findPrev(const T& Data) {
    Node<T> * memoCurrNode = this->currNode;
    this->currNode = this->HEAD;
    while (this->currNode->next->Data != Data) {
        if (this->currNode->next->next == nullptr) {
            this->status = false;
            this->currNode = memoCurrNode;
            return this;
        }

        this->currNode = this->currNode->next;
    }

    this->status = true;
    return this;
}

template <typename T>
LinkedList<T> * LinkedList<T>::insert(const T& prevData, const T& Data) {
    Node<T> * memoNode = this->currNode;
    if (!LinkedList::find(prevData)->getStatus()){
        this->currNode = memoNode;
        return this;
    }

    auto * newNode = NodeFactory<T>::NewSNode(Data, this->currNode->next);
    this->currNode->next = newNode;
    this->status = true;
    return this;
}

template <typename T>
LinkedList<T> * LinkedList<T>::remove(const T& Data) {
    Node<T> * memoNode = this->currNode;
    if (!LinkedList::findPrev(Data)->getStatus()){
        this->currNode = memoNode;
        return this;
    }
    Node<T> * memoRemovedNode = this->currNode->next;
    this->currNode->next = this->currNode->next->next;

    delete memoRemovedNode;
    return this;
}

template <typename T>
LinkedList<T> * LinkedList<T>::printList() {
    this->currNode = this->HEAD;
    while(this->currNode != nullptr) {
        std::cout << this->currNode->Data << std::endl;
        this->currNode = this->currNode->next;
    }

    return this;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    this->currNode = this->HEAD;
    while (this->currNode != nullptr) {
        Node<T> * memoCurrNode = this->currNode;
        delete memoCurrNode;
        this->currNode = this->currNode->next;
    }
}