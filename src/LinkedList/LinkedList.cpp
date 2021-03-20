//
// Created by dimitrios on 20/3/21.
//


#include "LinkedListNode.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

LinkedList * LinkedList::find(const std::string &Data) {
    LinkedListNode * memoCurrNode = this->currNode;
    this->currNode = this->HEAD;
    while(this->currNode->data != Data) {
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

LinkedList * LinkedList::findPrev(const std::string &Data) {
    LinkedListNode * memoCurrNode = this->currNode;
    this->currNode = this->HEAD;
    while (this->currNode->next->data != Data) {
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

LinkedList * LinkedList::insert(const std::string &prevData, const std::string &Data) {
    if (!LinkedList::find(prevData)->getStatus()) return this;

    auto * newNode = new LinkedListNode(Data, this->currNode->next);
    this->currNode->next = newNode;
    this->status = false;
    return this;
}

LinkedList * LinkedList::remove(const std::string &Data) {
    if (!LinkedList::findPrev(Data)->getStatus()) return this;
    LinkedListNode * memoRemovedNode = this->currNode->next;
    this->currNode->next = this->currNode->next->next;

    delete memoRemovedNode;
    return this;
}

LinkedList * LinkedList::printList() {
    this->currNode = this->HEAD->next;
    while(this->currNode != nullptr) {
        std::cout << this->currNode->data << std::endl;
        this->currNode = this->currNode->next;
    }

    return this;
}


LinkedList::~LinkedList(){
    this->currNode = this->HEAD;
    while (this->currNode != nullptr) {
        LinkedListNode * memoCurrNode = this->currNode;
        delete memoCurrNode;
        this->currNode = this->currNode->next;
    }
}