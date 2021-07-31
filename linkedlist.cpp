/*********************************
Name: Nick Jocius
Hash table with Linked List
File: linkedlist.cpp
Purpose: Create a fully functional
hash table class/object with the standare
struct(struct with int id and string for data).
**********************************/

#include "linkedlist.h"

LinkedList::LinkedList()
{

    head = nullptr;

} // end constructor

LinkedList::~LinkedList()
{
    clearList();
} // end deconstructor

void LinkedList::addHead(Node *newNode)
{
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
}

void LinkedList::addMiddle(Node *newNode, Node *current)
{
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

void LinkedList::addTail(Node *newNode, Node *current)
{
    newNode->next = NULL;
    newNode->prev = current;
    current->next = newNode;
}

bool LinkedList::addNode(int id, string *info)
{
    //
    // having trouble figuring out a better way to test for unique id, in order to reduce size of addNode
    bool outcome = true;
    if (id > 0 && sizeof(info) != 0)
    {
        Node *newNode = new Node;
        Node *current = nullptr;
        Node *temp = nullptr;
        newNode->data.id = id;
        newNode->data.data = *info;
        if (head == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
        }
        else if (head && id < head->data.id && id != head->data.id)
        {
            addHead(newNode);
        }
        else if (head && id > head->data.id && id != head->data.id)
        {
            temp = head;

            while (temp->next && id > temp->data.id && temp->next->data.id != id)
            {
                temp = temp->next;
            }
            if (temp->next == NULL && id != temp->data.id && id > temp->data.id)
            {
                addTail(newNode, temp);
            }
            else if (temp->next == NULL && id != temp->data.id && id < temp->data.id)
            {

                addMiddle(newNode, temp);
            }
            else if (temp->next && id != temp->data.id && id < temp->data.id)
            {

                addMiddle(newNode, temp);
            }
            else if (temp->next->data.id == id || temp->data.id == id || temp->prev->data.id == id)
            {
                outcome = false;
            }
        }
        else
        {
            outcome = false;
        }
    }
    else
    {
        outcome = false;
    }
    return outcome;
} // end addNode()

bool LinkedList::deleteNode(int n)
{
    bool outcome = false;
    Node *current = head;
    while (current != NULL && n > 0)
    {
        if (current->data.id == n)
        {
            if (current->prev && current->next)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            else if (current->prev == NULL && current->next)
            {
                current->next->prev = NULL;
                head = current->next;
                delete current;
            }
            else if (current->next == NULL && current->prev)
            {
                current->prev->next = NULL;

                delete current;
            }
            else if (current->next == NULL && current->prev == NULL)
            {
                head = nullptr;
            }
            outcome = true;
        }
        current = current->next;
    }
    return outcome;

} // end deleteNode()

bool LinkedList::getNode(int n, Data *data)
{
    bool outcome = false;
    Node *current = head;
    while (current)
    {
        if (current->data.id == n)
        {
            data->id = current->data.id;
            data->data = current->data.data;
            outcome = true;
        }
        current = current->next;
    }
    return outcome;

} // end getNode()

void LinkedList::printList(bool backward)
{
    Node *current = head;
    bool tail = false;
    if (backward == true)
    {
        while (current && !tail)
        {
            if (current->next)
            {
                current = current->next;
            }
            else
            {
                tail = true;
            }
        }
        while (current)
        {
            std::cout << current->data.id;
            current = current->prev;
        }
    }
    else
    {
        while (current)
        {
            if (current->next)
            {
                std::cout << current->data.id << " -> ";
            }
            else if (current->next == NULL)
            {
                std::cout << current->data.id;
            }

            current = current->next;
        }
    }

} // end printList()

int LinkedList::getCount()
{
    Node *current = head;
    int length = 0;
    if (current)
    {
        while (current = current->next)
        {
            length++;
        }
        length++;
    }
    return length;

} // end getCount()

void LinkedList::clearList()
{
    Node *current = head;
    if (current)
    {
        while (current = current->next)
        {
            delete current;
        }
    }
    head = NULL;
} // end clearList()

bool LinkedList::exists(int n)
{
    bool outcome = false;
    Node *current = head;
    while (current)
    {
        if (current->data.id == n)
        {

            outcome = true;
        }
        current = current->next;
    }
    return outcome;

} // end exists()