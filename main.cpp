//
// Created by dimitrios on 20/3/21.
//

#include "LinkedList.h"

int main() {
    auto * Names = new LinkedList();

    Names->insert("HEAD", "James")
        ->insert("James", "Alexia")
        ->insert("Alexia", "Marios")
        ->insert("Marios", "Maths")
        ->printList()
        ->remove("Maths")
        ->printList();
}