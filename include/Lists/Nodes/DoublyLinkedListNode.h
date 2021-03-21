//
// Created by dimitrios on 20/3/21.
//

#ifndef DATASTRUCTURES_DOUBLYLINKEDLISTNODE_H
#define DATASTRUCTURES_DOUBLYLINKEDLISTNODE_H

#include <string>
#include <utility>

class DoublyLinkedListNode {
public:
    std::string data;
    DoublyLinkedListNode * prev;
    DoublyLinkedListNode * next;

    DoublyLinkedListNode( std::string Data, DoublyLinkedListNode * prev, DoublyLinkedListNode * next) {
        this->prev = prev;
        this->data = std::move(Data);
        this->next = next;
    }
};


#endif //DATASTRUCTURES_DOUBLYLINKEDLISTNODE_H
