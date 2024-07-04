#include <iostream>
#include "product.h"
#include "productfactory.h"
#include "list.h"


using namespace std;


int main()
{
    List<int> l;
    l.pushBack(5);
    l.pushBack(15);
    l.pushBack(25);
    l.pushBack(35);

    l.printItems();
    return 0;
}
