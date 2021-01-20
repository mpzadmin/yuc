#include<iostream>
#include"models/student.hpp"
#include<string>
#include<list>

using namespace std;

int main()
{
   Student *ptr;
   ptr= new Student;
   ptr->setName("Mohammad Nasr")->setCode(1)->setAverage(19)->add();
   ptr->setName("Ali Hoseini")->setCode(2)->setAverage(19.5)->add();
   ptr->setName("Hasan Akbari")->setCode(3)->setAverage(20)->add();
   ptr->setName("Jvad Mansoori")->setCode(4)->setAverage(19)->add();
   ptr->setName("Fatemeh Mohammadi")->setCode(5)->setAverage(12)->add();
   ptr->setName("Ali Hoseini")->setCode(11)->setAverage(10)->add();
   ptr->list();
   cout<<endl;
   cout<<"---------------------"<<endl;
   ptr->setName("Ali Hoseini")->filter(Field::Name)->list(true);
   //ptr->setName("Mahmood sadeghi")->setCode(6)
   //->setAverage(19)->filter(Field::Average)->list(true);


/*
   cout<<"***************"<<endl<<endl;
   ptr->setName("Hosein")->setAverage(14)->setCode(1)->remove()->list();
   ptr->setCode(1)->remove();
   if(ptr->fail())
   {
      cout<<ptr->getError()<<endl;
   }
   */
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
