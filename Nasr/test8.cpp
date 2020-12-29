#include<iostream>

using namespace std;
int fact(int count);
int main()
{
  int number;

  cout<<"Enter your number: ";
  cin>>number;

    cout<<fact(number);
}
int fact(int count)
{
    if(count<0)
    {
      cout<<"enter a positive number";
      return 0;
    }
    if(count==0 || count==1)
    {
      return 1;
    }
    else
    {  
    return count *fact(count-1);
    }
}