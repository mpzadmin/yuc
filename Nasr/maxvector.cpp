#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec;
    int number;
    int maxNumber, minNumber;
    float sum=0;
    int tempNumber;

    system("cls");
    cout<<"Enter a number";
    cin>>number;

    for(size_t index=0; index<number; index++ )
    {
        cout<<"Enter a number ("<<index+1<<") : ";
        cin>>tempNumber;
        vec.push_back(tempNumber);
    }
    minNumber= vec.at(0);
    maxNumber= vec.at(0);
    for(size_t index=0; index<number; index++)
    {
        if(vec[index]>maxNumber)
        {
            maxNumber=vec[index];
        }
        if(vec[index]<minNumber)
        {
            minNumber=vec[index];
        }
        sum+=vec[index];      
     }
     cout<<"the maxNumber is "<<minNumber<<endl;
     cout<<"the maxnumber is "<<maxNumber<<endl;
     cout<<"The average is"<< sum/(float)vec.size();
}
