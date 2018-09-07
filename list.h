#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "node.h"

class list
{
    node *top;
public:
    list()
    {top=NULL;}

    void push();
    void pop();
    void display();

};


#endif // LIST_H_INCLUDED
