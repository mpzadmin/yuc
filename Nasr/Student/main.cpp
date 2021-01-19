#include<iostream>
#include"models/student.hpp"
#include<string>
#include<list>

using namespace std;

int main()
{
   Student *ptr;
   ptr= new Student;
   ptr->setName("Mohammad")->setCode(1)->setAverage(18)->add();
   ptr->setName("Ali")->setCode(2)->setAverage(19.5)->add();
   ptr->setName("Hasan")->setCode(3)->setAverage(20)->add();
   ptr->setName("Jvad")->setCode(2)->setAverage(19)->add();
   ptr->list();
   cout<<"***************"<<endl<<endl;
   ptr->setName("Hosein")->setAverage(14)->setCode(1)->remove()->list();
   ptr->setCode(1)->remove();
   if(ptr->fail())
   {
      cout<<ptr->getError()<<endl;
   }
  // if(ptr->setName("naghi")->setCode(1)->setAverage(15)->add()->fail()==false)
  // {
  //    cout<<"Success"<<endl;
  // }
  // else
  // {
   //   cout<<   ptr->getError()<<endl;
  // }
   
/*
   if(ptr->setName("Mohammad")->setAverage(17)->setCode(3)->find(Field::Code)==true)
   {
     ptr->debug();
   }
   else
   {
      cout<<"NOT FOUND"<<endl;
   } 
   */
   delete[]ptr;
}
