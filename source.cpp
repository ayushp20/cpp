#include "node.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const node& n)
{
    os<<"Data : "<<n.a;
    return os;
}
