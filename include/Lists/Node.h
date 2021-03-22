//
// Created by dimitrios on 21/3/21.
//

#ifndef DATASTRUCTURES_NODE_H
#define DATASTRUCTURES_NODE_H

template <typename T>
class Node {
private:
    Node(const T Data, Node<T> * next, Node<T> * prev)
        : Data(Data), next(next), prev(prev) {}
public:
    template <typename U>
    friend class NodeFactory;
    T Data;
    Node<T> * next;
    Node<T> * prev;
};

#endif //DATASTRUCTURES_NODE_H
