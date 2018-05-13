#ifndef LINKEDLIST_H
#define LINKEDLIST_H



class Sprite;


struct node
{
    Sprite *data{nullptr};
    node * next{nullptr};

};

class LinkedList
{
public:

    LinkedList();
    void createNode(Sprite *newData);
    void displayList();

    void pushFront(Sprite *newData);
    void pushBack(Sprite *newData);
    void push(Sprite *newData, int pos);

    void popFront();
    void popBack();
    void popAt(int pos);

    long getSize();

    Sprite getItemAtPos(int pos);


    ~LinkedList();


protected:

private:
    //creates a head and tail to track positions of the list
    //set as null so that we don't get unwanted pointers
    node *head{nullptr}, * tail{nullptr};
};

#endif // LINKEDLIST_H
