//
// Created by dimitrios on 19/3/21.
//

#ifndef DATASTRUCTURES_LINKEDLISTNODE_H
#define DATASTRUCTURES_LINKEDLISTNODE_H

#include <string>
#include <utility>

class LinkedListNode {
public:
    std::string data;
    LinkedListNode * next;

    LinkedListNode(std::string data, LinkedListNode * next) {
        this->data = std::move(data);
        this->next = next;
    }
};


#endif //DATASTRUCTURES_LINKEDLISTNODE_H
