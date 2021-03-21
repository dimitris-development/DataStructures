//
// Created by dimitrios on 20/3/21.
//

#include "Lists/DoublyLinkedList.h"
#include <string>
#include <iostream>

DoublyLinkedList * DoublyLinkedList::find(const std::string &Data) {
    this->currNode = this->HEAD;
    while (this->currNode->data != Data) {
        if (this->currNode->next == nullptr) {
            this->status = false;
            return this;
        }

        this->currNode = this->currNode->next;
    }

    this->status = true;
    return this;
}

DoublyLinkedList * DoublyLinkedList::insert(const std::string &prevData, const std::string &Data) {
    DoublyLinkedListNode * memoNode = this->currNode;
    if (!find(prevData)->getStatus()) {
        this->currNode = memoNode;
        return this;
    }

    auto * newNode = new DoublyLinkedListNode(Data, this->currNode, this->currNode->next);

    if (this->currNode->next != nullptr) {
        this->currNode->next->prev = newNode;
    }

    this->currNode->next = newNode;
    this->status = true;
    return this;
}

DoublyLinkedList * DoublyLinkedList::remove(const std::string &Data){
    DoublyLinkedListNode * memoNode = this->currNode;
    if (!DoublyLinkedList::find(Data)->getStatus()) {
        this->currNode = memoNode;
        return this;
    }

    if (this->currNode->next != nullptr) {
        this->currNode->next->prev = this->currNode->prev;
    }

    this->currNode->prev->next = this->currNode->next;

    DoublyLinkedListNode * removedNode = this->currNode;
    this->currNode = this->currNode->next;

    delete removedNode;
    this->status = true;
    return this;
}

DoublyLinkedList * DoublyLinkedList::printList() {
    this->currNode = this->HEAD->next;
    while(this->currNode != nullptr) {
        std::cout << this->currNode->data << std::endl;
        this->currNode = this->currNode->next;
    }

    return this;
}

DoublyLinkedList::~DoublyLinkedList(){
    this->currNode = this->HEAD;
    while (this->currNode != nullptr) {
        DoublyLinkedListNode * memoCurrNode = this->currNode;
        delete memoCurrNode;
        this->currNode = this->currNode->next;
    }
}