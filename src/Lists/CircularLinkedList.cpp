//
// Created by dimitrios on 20/3/21.
//

#include "Lists/CircularLinkedList.h"
#include "DoublyLinkedListNode.h"
#include <string>
#include <iostream>

CircularLinkedList * CircularLinkedList::find(const std::string& Data) {
    DoublyLinkedListNode * memoNode = this->currNode;
    this->currNode = this->HEAD;
    while (this->currNode->data != Data) {
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

CircularLinkedList * CircularLinkedList::insert(const std::string &prevData, const std::string &Data) {
    DoublyLinkedListNode * memoNode = this->currNode;
    if (!find(prevData)->getStatus()) {
        this->currNode = memoNode;
        return this;
    }

    auto * newNode = new DoublyLinkedListNode(Data, this->currNode, this->currNode->next);

    if (this->currNode->next != this->HEAD) {
        this->currNode->next->prev = newNode;
    }

    this->currNode->next = newNode;
    this->status = true;
    return this;
}

CircularLinkedList * CircularLinkedList::remove(const std::string &Data){
    DoublyLinkedListNode * memoNode = this->currNode;
    if (!CircularLinkedList::find(Data)->getStatus()) {
        this->currNode = memoNode;
        return this;
    }

    if (this->currNode->next != this->HEAD) {
        this->currNode->next->prev = this->currNode->prev;
    }

    this->currNode->prev->next = this->currNode->next;

    DoublyLinkedListNode * removedNode = this->currNode;
    this->currNode = this->currNode->next;

    delete removedNode;
    this->status = true;
    return this;
}

CircularLinkedList * CircularLinkedList::printList() {
    this->currNode = this->HEAD->next;
    while(this->currNode != this->HEAD) {
        std::cout << this->currNode->data << std::endl;
        this->currNode = this->currNode->next;
    }

    return this;
}

CircularLinkedList::~CircularLinkedList(){
    this->currNode = this->HEAD->next;
    while (this->currNode != this->HEAD) {
        DoublyLinkedListNode * memoCurrNode = this->currNode;
        delete memoCurrNode;
        this->currNode = this->currNode->next;
    }

    delete this->HEAD;
}