/*********************************
Name: Nick Jocius
Hash table with Linked List
File: hashtable.cpp
Purpose: Create a fully functional
hash table class/object with the standare
struct(struct with int id and string for data).
**********************************/

#include "hashtable.h"

Hashtable::Hashtable(/* args */)
{
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        listArray[i] = nullptr;
    }
} // end constructor

Hashtable::~Hashtable()
{
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        if (listArray[i])
        {
            delete listArray[i];
        }
    }
} // end deconstructor

bool Hashtable::insertEntry(int id, string *info)
{
    bool inserted = false;
    if (id > 0 && sizeof(info) != 0)
    {
        int pos = hash(id);
        if (listArray[pos] == nullptr)
        {
            LinkedList *newItem = new LinkedList;
            newItem->addNode(id, info);
            listArray[pos] = newItem;
            count++;
            inserted = true;
        }
        if (listArray[pos])
        {
            listArray[pos]->addNode(id, info);
            inserted = true;
        }
    }

    return inserted;

} // end insertEntry

string Hashtable::getData(int id)
{
    string str = "";
    int pos = hash(id);
    Data data;

    if (listArray[pos] && id > 0)
    {
        listArray[pos]->getNode(id, &data);
        str = data.data;
    }

    return str;

} // end getData

bool Hashtable::removeEntry(int id)
{
    bool del = false;
    int nodeCnt;
    int pos = hash(id);
    //TODO need to delete LinkedList node if match and not the whole index
    if (id > 0 && listArray[pos])
    {
        listArray[pos]->deleteNode(id);
        nodeCnt = listArray[pos]->getCount();
        if (nodeCnt == 0)
        {
            delete listArray[pos];
            listArray[pos] = nullptr;
            count--;
        }
        del = true;
    }
    return del;

} // end removeEntry

int Hashtable::getCount()
{
    return count;
} // end getCount

void Hashtable::printTable()
{
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        if (listArray[i])
        {
            cout << "Table Entry " << i << ": ";
            listArray[i]->printList();
            cout << endl;
        }
        else
        {
            cout << "Table Entry " << i << ": EMPTY" << endl;
        }
    }

} // end printtable

int Hashtable::hash(int id)
{
    return (id % HASHTABLESIZE);

} // end hash