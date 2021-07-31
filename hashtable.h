/*********************************
Name: Nick Jocius
Hash table with Linked List
File: hashtable.h
Purpose: Create a fully functional
hash table class/object with the standare
struct(struct with int id and string for data).
**********************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#define HASHTABLESIZE 15

#include <iostream>
#include <string>
#include "linkedlist.h"

using std::cout;
using std::endl;
using std::string;

class Hashtable
{
private:
    int hash(int);
    int count;
    LinkedList *listArray[HASHTABLESIZE];

public:
    Hashtable(/* args */);
    ~Hashtable();
    bool insertEntry(int, string *);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();
};

#endif // HASHTABLE_H