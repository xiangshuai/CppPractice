#include <iostream>
#include "Singleton.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Singleton* s = Singleton::Instance();
    return 0;
}
