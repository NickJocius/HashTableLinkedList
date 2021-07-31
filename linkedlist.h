/*********************************
Name: Nick Jocius
Hash table with Linked List
File: linkedlist.h
Purpose: Create a fully functional
hash table class/object with the standare
struct(struct with int id and string for data).
**********************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "data.h"
class LinkedList
{

public:
    LinkedList();
    ~LinkedList();
    bool addNode(int, string *);
    bool deleteNode(int);
    bool getNode(int, Data *);
    void printList(bool = false);
    int getCount();
    void clearList();
    bool exists(int);

protected:
    Node *head;
    void addHead(Node *);
    void addMiddle(Node *, Node *);
    void addTail(Node *, Node *);
};

#endif //LINKED_LIST_H
