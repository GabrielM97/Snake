#include "linkedlist.h"
#include <iostream>
#include"SPRITE.H"
using namespace std;

LinkedList::LinkedList()
{

}

void LinkedList::createNode(Sprite *newData)
{
    // create a new temporary node
    node*temp = new node;
    // set the data to be stored inside the node
    temp->data = newData;
    temp->next = nullptr;
    if(head == nullptr)
    {

        //check if head is null, if so nothing in list so we set the head and tail to be equal to the new node temp;
        head = temp;
        tail = temp;
        temp = nullptr;
    }
    else
    {
        //if head not null the we just set the previous element to point to the next element(temp) and move tail to point to the new element
        tail->next = temp;
        tail = temp;
    }
}


void LinkedList::displayList()
{
    //create a temp node
    node*temp = new node;

    //make temp equal head, so that we start at the beginning of the list
    temp = head;

    while (head != nullptr)
    {
        temp = temp->next;
    }

    delete temp;

}

void LinkedList::pushFront(Sprite *newData)
{
    node* temp = new node;
    temp->data= newData;
    //points next to head as it is now the first element in the list
    temp->next = head;

    //head the points back to temp which is the new node added to the front
    head = temp;

}

void LinkedList::pushBack(Sprite *newData)
{
    node *temp = new node;
    temp->data = newData;
    temp->next = nullptr;

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
        temp = nullptr;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }


}

void LinkedList::push(Sprite *newData, int pos)
{
    //create pointers for current previous and temp
    node * previous = new node;
    node * current = new node;
    node * temp = new node;

    //current points to head as we always start looking through the start or end of a linked list;
    current = head;

    for(int i = 1; i <pos; i++)
    {
        //previous becomes current as current moves along the list;
        previous = current;
        current = current->next;
    }

    //previous now points to the new element and the new element points to current element on the list;
    temp->data = newData;
    previous->next=temp;
    temp->next = current;

}
// pop the first item from the list.
void LinkedList::popFront()
{
    //creates temporary node which sits at the beginning of the list.
    node*temp = new node;

    //temp is the made into the head and the head is advanced forward to the next item in the list.
    //effectively destroys the link between the first node now them and the next node which is now head.
    temp = head;
    head = head->next;

    //the memory allocated to the node is now deleted.
    delete temp;
}
void LinkedList::popBack()
{
    //creates two nodes to traverse through the list, this is so that when  current->next  becomes null
    // we are on the item to be deleted  we also know that the previous  node will point to the node before the last node
    node *current = new node;
    node *previous = new node;

    current = head;

    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;
    }

    //Tail is then set to previous destroying the link between the last(current) node and the previous node
    tail = previous;
    previous->next = nullptr;
    //current is the deleted
    delete current;


}
void LinkedList::popAt(int pos)
{


    node * previous = new node;
    node *current = new node;

    current = head;

    //loop through till the desired position is found
    for(int i = 0; i < pos; i ++)
    {

        previous = current;
        current = current->next;
    }

    // when found it the link to it is destroyed by making previous point to the item set after the current
    previous->next = current->next;

    //current item is the deleted
    delete current;

}

long LinkedList::getSize()
{
    long listSize = 0;
    node *current = new node;

    current = head;

    while (current != nullptr)
    {
        current = current->next;
        listSize++;
    }

    return listSize;

}

Sprite LinkedList::getItemAtPos(int pos)
{
    node * current = new node;

    current = head;

    for (int i =0; i < pos; i++)
    {

        current = current->next;

    }

    return *current->data;

}


LinkedList::~LinkedList()
{

}

