//
// Created by dimitrios on 20/3/21.
//

#include "Lists/LinkedList.h"
#include "Lists/DoublyLinkedList.h"
#include "Lists/CircularLinkedList.h"

int main() {
    auto * Names = new LinkedList();

    Names->insert("HEAD", "James")
        ->insert("James", "Alexia")
        ->insert("Alexia", "Marios")
        ->insert("Marios", "Maths")
        ->printList()
        ->remove("Maths")
        ->printList();

    auto * Dates = new DoublyLinkedList();

    Dates->insert("HEAD", "1-2-2020")
            ->insert("1-2-2020", "2-2-2020")
            ->insert("2-2-2020", "3-2-2020")
            ->insert("3-2-2020", "5-2-2020")
            ->printList()
            ->remove("5-2-2020")
            ->printList();


    auto * Circle = new CircularLinkedList();

    Circle->insert("HEAD", "1")
        ->insert("1", "4")
        ->insert("4", "3")
        ->printList()
        ->remove("4")
        ->printList()
        ->insert("1", "2")
        ->printList();


}