#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name, lineContent, letter;
    int wordLayerCount = 7, charecterDistance = 2, separationIndex;
    bool multiplePart = false, needDash = false;
    string alphabet[26][wordLayerCount] ={
        {"      #      ",
         "     # #     ",
         "    #   #    ",
         "   #     #   ",
         "  #########  ",
         " #         # ",
         "#           #"},

        {"####### ",
         "#      #",
         "#      #",
         "######  ",
         "#      #",
         "#      #",
         "####### "},

        {"    ######  ",
         "  ##      ##",
         "##          ",
         "#           ",
         "##          ",
         "  ##      ##",
         "    ######  "},

        {"#####   ",
         "#     # ",
         "#      #",
         "#      #",
         "#      #",
         "#     # ",
         "#####   "},

        {"#######",
         "#      ",
         "#      ",
         "#######",
         "#      ",
         "#      ",
         "#######"},

        {"#######",
         "#      ",
         "#      ",
         "#######",
         "#      ",
         "#      ",
         "#      "},

        {"    ######    ",
         "  ##      ##  ",
         "##            ",
         "#       ######",
         "##          ##",
         "  ##      ##  ",
         "    ######    "},

        {"#        #",
         "#        #",
         "#        #",
         "##########",
         "#        #",
         "#        #",
         "#        #"},

        {"#####",
         "  #  ",
         "  #  ",
         "  #  ",
         "  #  ",
         "  #  ",
         "#####"},

        {"  #####",
         "    #  ",
         "    #  ",
         "    #  ",
         "    #  ",
         "#   #  ",
         " ###   "},

        {"#      #",
         "#     # ",
         "#    #  ",
         "####    ",
         "#    #  ",
         "#     # ",
         "#      #"},

        {"#       ",
         "#       ",
         "#       ",
         "#       ",
         "#       ",
         "#       ",
         "########"},

        {"##         ##",
         "# #       # #",
         "#  #     #  #",
         "#   #   #   #",
         "#    # #    #",
         "#     #     #",
         "#           #"},
        
        {"##      #",
         "# #     #",
         "#  #    #",
         "#   #   #",
         "#    #  #",
         "#     # #",
         "#      ##"},

        {"    ######    ",
         "  ##      ##  ",
         "##          ##",
         "#            #",
         "##          ##",
         "  ##      ##  ",
         "    ######    "},

        {"###### ",
         "#     #",
         "#     #",
         "###### ",
         "#      ",
         "#      ",
         "#      "},

        {"    ######    ",
         "  ##      ##  ",
         "##          ##",
         "#            #",
         "##      ##  ##",
         "  ##      ##  ",
         "    ######  ##"},

        {"######  ",
         "#     # ",
         "#     # ",
         "#####   ",
         "#    #  ",
         "#     # ",
         "#      #"},

        {" ##### ",
         "#     #",
         " #     ",
         "   #   ",
         "     # ",
         "#     #",
         " ##### "},

        {"###########",
         "#    #    #",
         "     #     ",
         "     #     ",
         "     #     ",
         "     #     ",
         "     #     "},

        {"#          #",
         "#          #",
         "#          #",
         "#          #",
         "#          #",
         " ##      ## ",
         "   ######   "},

        {"#            #",
         " #          # ",
         "  #        #  ",
         "   #      #   ",
         "    #    #    ",
         "     #  #     ",
         "      ##      "},

        {"#           #",
         "#     #     #",
         "#    # #    #",
         "#   #   #   #",
         "#  #     #  #",
         "# #       # #",
         "##         ##"},

        {"###       ###",
         "  #       #  ",
         "    #   #    ",
         "      #      ",
         "    #   #    ",
         "  #       #  ",
         "###       ###"},

        {"###       ###",
         "  #       #  ",
         "    #   #    ",
         "      #      ",
         "      #      ",
         "      #      ",
         "     ###     "},

        {"###########",
         "         # ",
         "       #   ",
         "     #     ",
         "   #       ",
         " #         ",
         "###########"},
    };
    cout << "Enter your name: ";
    getline(cin,name);
    for (int i = 0; i < wordLayerCount ; i++)
    {
        lineContent = "";
        for (int j = 0; j < name.length() ; j++)
        {
            letter = name.substr(j , 1);
            if (j > 7)
            {
                separationIndex = j - 1;
                multiplePart = true;
                needDash = true;
                break;
            }
            if (letter == "A")
            {
                lineContent += alphabet[0][i];
            }
            else if (letter == "B")
            {
                lineContent += alphabet[1][i];
            }
            else if (letter == "C")
            {
                lineContent += alphabet[2][i];
            }
            else if (letter == "D")
            {
                lineContent += alphabet[3][i];
            }
            else if (letter == "E")
            {
                lineContent += alphabet[4][i];
            }
            else if (letter == "F")
            {
                lineContent += alphabet[5][i];
            }
            else if (letter == "G")
            {
                lineContent += alphabet[6][i];
            }
            else if (letter == "H")
            {
                lineContent += alphabet[7][i];
            }
            else if (letter == "I")
            {
                lineContent += alphabet[8][i];
            }
            else if (letter == "J")
            {
                lineContent += alphabet[9][i];
            }
            else if (letter == "K")
            {
                lineContent += alphabet[10][i];
            }
            else if (letter == "L")
            {
                lineContent += alphabet[11][i];
            }
            else if (letter == "M")
            {
                lineContent += alphabet[12][i];
            }
            else if (letter == "N")
            {
                lineContent += alphabet[13][i];
            }
            else if (letter == "O")
            {
                lineContent += alphabet[14][i];
            }
            else if (letter == "P")
            {
                lineContent += alphabet[15][i];
            }
            else if (letter == "Q")
            {
                lineContent += alphabet[16][i];
            }
            else if (letter == "R")
            {
                lineContent += alphabet[17][i];
            }
            else if (letter == "S")
            {
                lineContent += alphabet[18][i];
            }
            else if (letter == "T")
            {
                lineContent += alphabet[19][i];
            }
            else if (letter == "U")
            {
                lineContent += alphabet[20][i];
            }
            else if (letter == "V")
            {
                lineContent += alphabet[21][i];
            }
            else if (letter == "W")
            {
                lineContent += alphabet[22][i];
            }
            else if (letter == "X")
            {
                lineContent += alphabet[23][i];
            }
            else if (letter == "Y")
            {
                lineContent += alphabet[24][i];
            }
            else if (letter == "Z")
            {
                lineContent += alphabet[25][i];
            }
            else if (letter == " ")
            {
                separationIndex = j;
                multiplePart = true;
                break;
            }
            for (int d = 0; d < charecterDistance ; d++)
            {
                lineContent += " ";
            }
        }
        if (needDash && i == 3)
        {
            cout << lineContent << "#######" << endl;
        }
        else
        {
            cout << lineContent << endl;
        }
        for (int delay = 0; delay < 20000000; delay++);
        if (i == wordLayerCount - 1 && multiplePart){
            name = name.substr(separationIndex + 1 , name.length() - separationIndex - 1);
            i = -1;
            needDash = false;
            multiplePart = false;
            cout << endl;
        }
    }
}