//
// Created by dimitrios on 21/3/21.
//

#ifndef DATASTRUCTURES_NODEFACTORY_H
#define DATASTRUCTURES_NODEFACTORY_H

#include "Node.h"

template <typename T>
class NodeFactory {
public:
    /**
     * Creates a DNode (A node with both next and prev pointers)
     *
     * @param Data
     * @param next
     * @param prev
     * @return
     */
    static Node<T> * NewDNode(const T Data, Node<T> * next, Node<T> * prev) {
        return new Node<T>(Data, next, prev);
    }

    /**
     * Create a SNode (A node with only a next pointer)
     *
     * @param Data
     * @param next
     * @return
     */
    static Node<T> * NewSNode(const T Data, Node<T> * next) {
        // Setting newNode->prev to nullptr will make delete ignore it.
        // Therefore I'll point the prev pointer to next and then delete it.
        auto * newNode = new Node<T>(Data, next, next);
        delete newNode->prev;
        return newNode;
    }
};


#endif //DATASTRUCTURES_NODEFACTORY_H