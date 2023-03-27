#include <iostream>
#include <vector>
#include <string>
#include "HelloWorld.hpp"

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    HelloWorld world;
    world.say();
    cout << endl;
    return 0;
}
