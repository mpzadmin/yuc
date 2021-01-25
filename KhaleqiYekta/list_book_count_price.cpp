/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file list_book_count_price.cpp
 * @brief A program which gets the list of books with their prices
 * and displays the count of books and the total price.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Constants **/
const char lineChar = '=';
const int lineSize = 40;

/** Other Variables **/
int booksCount = 0;

/** Function Declarations **/
int getPrice(list<int> prices, int index);
string getBook(list<string> books, int index);
void sortList(list<string> &books, list<int> &prices);

// Program's Entry Point
int main()
{
    list<string> books;
    list<int> prices;

    int sum = 0;
    string book = " ";
    int price;

    clearConsole();

    for (size_t i = 1; true; ++i)
    {
        book = askForString("Enter the name of book " + to_string(i) + " [Empty if done]: ");

        // Break the loop if the input is empty
        if (book.empty())
        {
            break;
        }

        price = askForInt("Enter the price of book " + to_string(i) + ": ");

        if (price <= 0)
        {
            printLine("Invalid price!");
            return 0;
        }

        books.push_back(book);
        prices.push_back(price);

        sum += price;
        booksCount ++;
    }

    sortList(books, prices);

    // Print the results
    printSeparatorLine(lineChar, lineSize);
    printLine("Result: \n");

    // User added some books.
    if (booksCount != 0)
    {
        // Print books details
        for (int i = 0; i < books.size(); ++i)
        {
            printLine("Book: " + getBook(books, i) + "\t\tPrice: " + to_string(getPrice(prices, i)));
        }

        printLine("\nThe total number of books: " + to_string(booksCount));
        printLine("The total price: " + to_string(sum));
    }
    // No books are added.
    else
    {
        printLine("\tThere are no books!");
    }

    printSeparatorLine(lineChar, lineSize);

    /** End of the program **/
    pauseConsole();
    return 0;
}

// Sorts the list
void sortList(list<string> &books, list<int> &prices)
{
    for(int i = 0; i < booksCount; ++i)
    {
        for (int j = i+1; j < booksCount; ++j)
        {
            if (getPrice(prices, i) < getPrice(prices, j))
            {
                swap(*next(books.begin(), i), *next(books.begin(), j));
                swap(*next(prices.begin(), i), *next(prices.begin(), j));
            }
        }
    }
}

// Get the price which is in a specific index.
int getPrice(list<int> prices, int index)
{
    if (prices.size() > index)
    {
        return *next(prices.begin(), index);
    }
    else
    {
        return 0;
    }
}

// Get the book which is in a specific index.
string getBook(list<string> books, int index)
{
    if (books.size() > index)
    {
        return *next(books.begin(), index);
    }
    else
    {
        return "";
    }
}
