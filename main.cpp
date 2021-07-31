/*********************************
Name: Nick Jocius
Hash table with Linked List
File: main.cpp
Purpose: Create a fully functional
hash table class/object with the standare
struct(struct with int id and string for data).
**********************************/

#include "main.h"

int main()
{
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++)
    {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++)
        {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize - 2] = ids[testdatasize - 3];
    strs[testdatasize - 2] = "known duplicate";
    ids[testdatasize - 1] = -1;
    strs[testdatasize - 1] = "known bad";

    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++)
    {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */

    // create your hash table object here
    cout << "Creating Hashtable object..." << endl;
    Hashtable mytable;
    cout << "Done \n"
         << endl;

    int count;
    bool outcome;
    string data;

    // show it is empty by calling getCount and printTable
    cout << "**************** Empty Test *****************" << endl;
    count = mytable.getCount();
    if (count > 0)
    {
        cout << "Not Empty" << endl;
        mytable.printTable();
        cout << endl;
    }
    else
    {
        cout << "Empty \n"
             << endl;
        mytable.printTable();
        cout << endl;
    }

    // try and put ALL the test data into the table and show what happens
    cout << "*************** Adding Test Data **************" << endl;
    for (int i = 0; i < testdatasize; i++)
    {
        outcome = mytable.insertEntry(ids[i], &strs[i]);
        if (outcome)
        {
            cout << "Inserted" << endl;
        }
        else
        {
            cout << "Error Inserting" << endl;
        }
    }
    cout << endl;
    cout << "Done adding" << endl
         << endl;
    cout << "There are " << mytable.getCount() << " objects in the array.\n"
         << endl;
    mytable.printTable();
    cout << endl;

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    cout << "************ Random Data *************" << endl;

    for (int i = 0; i < 4; i++)
    {
        int getid = ids[rand() % testdatasize];
        cout << "getting " << getid << "... ";
        data = mytable.getData(getid);
        if (!data.empty())
        {
            cout << "found " << getid << ": " << data << endl;
        }
        else
        {
            cout << "failed to find " << getid << endl;
        }
    }
    cout << endl;
    cout << "*********** Random Id Deletion *************" << endl;

    for (int i = 0; i < testdatasize - 1; i++)
    {
        int delid = ids[rand() % testdatasize];
        cout << "deleting " << delid << "... ";
        if (mytable.removeEntry(delid))
        {
            cout << "Success deleting: " << delid << endl;
        }
        else
        {
            cout << "Failed to delete: " << delid << endl;
        }
    }
    cout << endl;
    cout << "*********** Check Deletion Outcome *************" << endl;
    cout << "There are " << mytable.getCount() << " objects in the array.\n"
         << endl;

    mytable.printTable();

    cout << "************ Adding Random Data ***********" << endl;
    int rndAdd = rand() % testdatasize;
    for (int i = 0; i < rndAdd; i++)
    {
        int randData = rand() % testdatasize;
        outcome = mytable.insertEntry(ids[randData], &strs[randData]);
        if (outcome)
        {
            cout << "Inserted" << endl;
        }
        else
        {
            cout << "Error Inserting: " << randData << endl;
        }
    }
    cout << endl;
    cout << "Done adding" << endl
         << endl;
    cout << "There are " << mytable.getCount() << " objects in the array.\n"
         << endl;
    mytable.printTable();
    cout << endl;

    return 0;
}