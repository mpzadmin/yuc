#include<iostream>
#include<string>
#include"test3.hpp"
using namespace std;

void display(string str);
void display(string str , bool test);

int main()
{
    display("hello");
    display("hi" , true);
    display("hello world" ,100000000);
}
