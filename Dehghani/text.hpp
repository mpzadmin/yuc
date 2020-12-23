#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
// display(str) = display string
void display(string str)
{
       cout << str;
}

// string and add endl with boolean
void display(string str, bool newLine)
{
    display(str);
    if (newLine)
    {
        cout << endl;
    }
}

// delay (takhir)
void delay(unsigned milliseconds)
{
    #ifdef _WIN32
    Sleep(milliseconds);
    #else
    usleep(milliseconds*1000);
    #endif
}

// the max of numbers
int myMax(int a, int b)
{
    int result;
    if (a > b)
        result = a;
    else
        result = b;

    return result;

}

// max float number
float myMax(float a, float b)
{
    float result;
    if (a > b)
    {
        result = a;
    }else
    {
        result = b;
    }
    return result;

}

// max double number
double myMax(double a, double b)
{
    double result;
    if (a > b)
    {
        result = a;
    }
    else
    {
        result = b;
    }
    return result;
    
}


// the min of numbers
int myMin(int a, int b)
{
    int result;
    if (a < b)
        result = a;
    else
        result = b;

    return result;

}

// min float number
float myMin(float a, float b)
{
    float result;
    if (a < b)
    {
        result = a;
    }else
    {
        result = b;
    }
    return result;
        
}

// min double number
double myMin(double a, double b)
{
    double result;
    if (a < b)
    {
        result = a;
    }
    else
    {
        result = b;
    }
    return result;
    
}

// find even number
bool isEven(int number)
{
    bool result = false;
    if ((number % 2 ) == 0 )
    {
        result = true;
    }
    return result;
    
}

// find odd number
bool isOdd(int number)
{
    bool result = false;
    if ((number % 2) != 0 )
    {
        result = true;
    }
    return result;
}

// takhir
void delay(int delayValue)
{
    for (int index = 0; index < delayValue; index++)
    {
        for(int counter = 0; counter < 1000000; counter++);
    }
}


int myRandom(int number, int minRandomNumber, int maxRandomNumber)
{
    srand((unsigned) time(0));
    for (int index = 1; index <= 5; index++)
    {   
        //number = (rand() % 100) + 1;       // 1 - 100
        //number = (rand() % 30) + 1985;       // 1985 - 2014
        number = minRandomNumber + (rand() % (maxRandomNumber - minRandomNumber)) +1;

    }
}

int myRandom2 (int number)
{
    srand((unsigned) time(0));
    for (int index=1; index <= 5; index++)
    {
        cout << rand() << endl;
    }
}


