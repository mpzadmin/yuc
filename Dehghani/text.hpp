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
/**
 * 
 * @param  {string} str : for print string str.
 */
void display(string str)
{
       cout << str;
}

/**
 * 
 * @param  {string} str   : for print string str.
 * @param  {bool} newLine : add endl with boolean.
 */
void display(string str, bool newLine)
{
    display(str);
    if (newLine)
    {
        cout << endl;
    }
}

/**
 * 
 * @param  {unsigned} milliseconds : takhir at program.
 */
void delay(unsigned milliseconds)
{
    #ifdef _WIN32
    Sleep(milliseconds);
    #else
    usleep(milliseconds*1000);
    #endif
}

/**
 * 
 * @param  {int} a : number1.
 * @param  {int} b : number2.
 * @return {int}   : print maximum number.
 */
int myMax(int a, int b)
{
    int result;
    if (a > b)
        result = a;
    else
        result = b;

    return result;

}

/**
 * 
 * @param  {float} a : number1.
 * @param  {float} b : number2.
 * @return {float}   : print maximum number.
 */
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

/**
 * 
 * @param  {double} a : number1.
 * @param  {double} b : number2.
 * @return {double}   : print maximum number.
 */
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


/**
 * 
 * @param  {int} a : number1.
 * @param  {int} b : number2.
 * @return {int}   : print minimum of numbers.
 */
int myMin(int a, int b)
{
    int result;
    if (a < b)
        result = a;
    else
        result = b;

    return result;

}

/**
 * 
 * @param  {float} a : number1
 * @param  {float} b : number2
 * @return {float}   : print minimum of numbers.
 */
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

/**
 * 
 * @param  {double} a : number1
 * @param  {double} b : number2
 * @return {double}   : print minimum of numbers.
 */
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

/**
 * 
 * @param  {int} number : number.
 * @return {bool}       : Distinguish Even Number.
 */
bool isEven(int number)
{
    bool result = false;
    if ((number % 2 ) == 0 )
    {
        result = true;
    }
    return result;
    
}

/**
 * 
 * @param  {int} number : number.
 * @return {bool}       : Distinguish Odd Number.
 */
bool isOdd(int number)
{
    bool result = false;
    if ((number % 2) != 0 )
    {
        result = true;
    }
    return result;
}

/**
 * 
 * @param  {int} delayValue : delay at program.
 */
void delay(int delayValue)
{
    for (int index = 0; index < delayValue; index++)
    {
        for(int counter = 0; counter < 1000000; counter++);
    }
}

/**
 * 
 * @param  {int} number          : a number.
 * @param  {int} minRandomNumber : max random in numbers limited.
 * @param  {int} maxRandomNumber : min random in numbers limited.
 * @return {int}                 : 
 */
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
/**
 * 
 * @param  {int} number : one number.
 * @return {int}        : find numbers with random. 
 */
int myRandom2 (int number)
{
    srand((unsigned) time(0));
    for (int index=1; index <= 5; index++)
    {
        cout << rand() << endl;
    }
}


