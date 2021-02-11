#include <iostream>

using namespace std;

int main()
{
    string list1[] = {"text1","text2"};
    string* listptr1 = list1;
    char list2[] = {'p','o'};
    char* listptr2 = list2;
    int list3[] = {1,2,3};
    int* listptr3 = list3;

    //adress chap meishe
    cout << list1 << endl;
    cout << listptr1 << endl;
    //moshkel man chizie ke vahti list2 va listotr2 ro chap mikonim chap mishe
    //be jaie adress mohtava chap mishe
    cout << list2 << endl;
    cout << listptr2 << endl;
    //hala adress chap mishe
    cout << &list2 << endl;
    cout << &listptr2 << endl;
    //adress chap mishe
    cout << list3 << endl;
    cout << listptr3 << endl;
}