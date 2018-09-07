#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include<iostream>

class node
{

friend std::ostream& operator<<(std::ostream& os, const node& n);
    friend class list;

private:
    node *link;
    int a;
};



#endif // NODE_H_INCLUDED
