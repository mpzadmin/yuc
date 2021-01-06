#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main()
{
    struct Test
    {
        string name;
        int num;
    };
    list<Test> ls;
    ls.push_back({"po", 15});
    Test test;
    Test test2;
    test.num = 10;
    test.name = "pouya";
    fstream file;
    file.open("text.bin", ios::out | ios::trunc | ios::binary);
    file.write((char*) &test, sizeof(test));
    file.close();

    file.open("text.bin", ios::in | ios::binary);
    file.read((char*) &test2, sizeof(test2));
    file.close();

    for (Test s : ls)
    {
        s.name = "akbar";
    }

    cout << ls.front().name << endl;
    cout << test.name << " " << test.num << endl;
    cout << test2.name << " " << test2.num << endl;
}