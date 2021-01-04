#include <iostream>
#include <iomanip>

using namespace std;
bool promising (int* s, int n, int limit);
void solveQueen(int n);
void queen(int* s, int n, int limit);


int main ()
{
    int number = 8;
    solveQueen(number);
}

bool promising (int* s, int n, int limit)
{
    if (limit == 0 )
    {
        return true;

    }
    for (int i=0; i <=limit-1; i++)
    {
        for (int j=i+1; j<=limit; j++)
        {
            if ((s[i] >= n) || (s[j] >= n) || (s[i] == s[j]) || (i-j ==s[i]-s[j] )) 
            {
            return false;
            }   
        }
    }
    return true;
}

void solveQueen(int n)
{
    int* s;
    s = new int[n];
    for (int index = 0; index < n; index++ )
    {
        s[0] = index;
        queen(s,n,0);
    }

}

void queen(int* s, int n, int limit)
{
     static int counter = 0;
    if (promising(s,n,limit))
    {
        if (limit == n-1)
        {
            int row = 0;
            counter++;
            cout << "\t" << counter << ": ";
            for (int count=0; count < n; count++)
            {
                cout << "\t" << "[" << row << "  " << s[count] << "]";
                row++;
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j <n; j++)
            {
                s[limit+1] = j;
                queen (s,n,limit+1);
            }
        }
    }
}