/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file eight_queens_puzzle.cpp
 * @brief A program to solve the eight queens puzzle.
 */

/** External Libraries **/
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Constants **/
const int chessboardSize = 8;
const int maxQueens = 8;

/** Other Variables **/
int board[chessboardSize][chessboardSize] = {0}; // [row][column]

/** Function Declarations **/
void showBoard();
void occupy(const size_t &queenRow, const size_t &queenCol);
bool canOccupy(const size_t &queenRow, const size_t &queenCol);

// Program's Entry Point
int main()
{
    /** Local Variables **/
    size_t currentQueens = 1;
    occupy(5,0);

    clearConsole();

    //Print the program info
    printLine(".:: Eight queens puzzle solver program ::.");
    printLine("\nDeveloped by: Ali Khaleqi Yekta\n");

    for (int i = 0; i < chessboardSize; ++i)
    {
        for (int j = 0; j < chessboardSize; ++j)
        {
            if (currentQueens >= maxQueens)
            {
                break;
            }

            if (canOccupy(i,j))
            {
                occupy(i,j);
            }
        }

    }

    // Show the result
    showBoard();

    /** End of the program **/
    pauseConsole();
    return 0;
}

bool canOccupy(const size_t &queenRow, const size_t &queenCol)
{
    if (board[queenRow][queenCol] == 2 || board[queenRow][queenCol] == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void occupy(const size_t &queenRow, const size_t &queenCol)
{
    size_t sum = queenRow + queenCol;

    // Occupy a plus shape (+)
    for (int i = 0; i < chessboardSize; ++i)
    {
        board[i][queenCol] = 1;
        board[queenRow][i] = 1;
    }

    // Diagonal
    for (int i = -chessboardSize; i < chessboardSize; ++i)
    {
        bool isRowIndexValid = (queenRow + i < chessboardSize) && (queenRow + i >= 0);
        bool isColIndexValid = (queenCol + i < chessboardSize) && (queenCol + i >= 0);

        if (!isRowIndexValid || !isColIndexValid)
        {
            continue;
        }

        board[queenRow + i][queenCol + i] = 1;
    }

    // Diagonal
    for (int i = 0; i < chessboardSize; ++i)
    {
        for (int j = 0; j < chessboardSize; ++j)
        {
            if (i + j == sum)
            {
                board[i][j] = 1;
            }
        }
    }

    board[queenRow][queenCol] = 2;
}

void showBoard()
{
    printLine("   a  b  c  d  e  f  g  h");

    for (int i = chessboardSize - 1; i >= 0; --i)
    {
        print( to_string(i + 1) + " ");

        for (int j = 0; j < chessboardSize; ++j)
        {
            if (board[i][j] == 2)
            {
                print("[#]");
            }
            else
            {
                print("[ ]");
            }
        }
        printLine(" " + to_string(i + 1));
    }

    printLine("   a  b  c  d  e  f  g  h\n");
}

size_t random()
{
    return rand() % chessboardSize; // column = 0 - 7
}
