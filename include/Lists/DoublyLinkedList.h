//
// Created by dimitrios on 20/3/21.
//

#ifndef DATASTRUCTURES_DOUBLYLINKEDLIST_H
#define DATASTRUCTURES_DOUBLYLINKEDLIST_H

#include "DoublyLinkedListNode.h"

class DoublyLinkedList {
private:
    bool status;
public:
    DoublyLinkedListNode * currNode;
    DoublyLinkedListNode * HEAD;

    DoublyLinkedList(){
        this->HEAD = new DoublyLinkedListNode("HEAD", nullptr, nullptr);
        this->currNode = this->HEAD;
        this->status = false;
    }

    bool getStatus() const {
        return this->status;
    }

    DoublyLinkedList * find(const std::string& Data);

    DoublyLinkedList * insert(const std::string& prevData, const std::string& Data);

    DoublyLinkedList * remove(const std::string& Data);

    DoublyLinkedList * printList();

    ~DoublyLinkedList();
};

#endif //DATASTRUCTURES_DOUBLYLINKEDLIST_H
