/*********************************
Name: Nick Jocius
Hash table with Linked List
File: hashtable.cpp
Purpose: Create a fully functional
hash table class/object with the standare
struct(struct with int id and string for data).
**********************************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data
{
    int id;
    string data;
};

struct Node
{
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */
