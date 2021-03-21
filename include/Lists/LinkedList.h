//
// Created by dimitrios on 19/3/21.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H


#include "LinkedListNode.h"
#include <string>

class LinkedList {
private:
    bool status;
public:
    LinkedListNode * currNode;
    LinkedListNode * HEAD;

    LinkedList(){
        this->HEAD = new LinkedListNode("HEAD", nullptr);
        this->currNode = this->HEAD;
        this->status = false;
    }

    bool getStatus() const {
        return this->status;
    }

    LinkedList * find(const std::string& Data);

    LinkedList * findPrev(const std::string& Data);

    LinkedList * insert(const std::string& prevData, const std::string& Data);

    LinkedList * remove(const std::string& Data);

    LinkedList * printList();

    ~LinkedList();

};


#endif //DATASTRUCTURES_LINKEDLIST_H
