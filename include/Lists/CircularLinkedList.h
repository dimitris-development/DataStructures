//
// Created by dimitrios on 20/3/21.
//

#ifndef DATASTRUCTURES_CIRCULARLINKEDLIST_H
#define DATASTRUCTURES_CIRCULARLINKEDLIST_H

#include "DoublyLinkedListNode.h"
#include <string>

class CircularLinkedList {
private:
    bool status;
public:
    DoublyLinkedListNode * currNode;
    DoublyLinkedListNode * HEAD;

    CircularLinkedList() {
        this->HEAD = new DoublyLinkedListNode("HEAD", nullptr, nullptr);
        this->HEAD->next = this->HEAD;
        this->HEAD->prev = this->HEAD;
        this->currNode = this->HEAD;
        this->status = false;
    }

    bool getStatus () const {
        return this->status;
    }

    CircularLinkedList * find(const std::string &Data);

    CircularLinkedList * insert(const std::string &prevData, const std::string &Data);

    CircularLinkedList * remove(const std::string &Data);

    CircularLinkedList * printList();

    ~CircularLinkedList();
};



#endif //DATASTRUCTURES_CIRCULARLINKEDLIST_H
