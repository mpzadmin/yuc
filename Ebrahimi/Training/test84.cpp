#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream file;

int main(int argc, const char** argv)
{
    string name;
    size_t count = 0;

    if (argc != 3)
    {
        cerr << "You should have entered a file name and a name in command line respectively!" << endl;
        return 0;
    }

    file.open(argv[1], ios::in);
    if (file.is_open() != 1)
    {
        cerr << "Error in opening the file!" << endl;
        return 0;
    }
    while (getline(file, name))
    {
        if (name == argv[2])
        {
            count++;
        }

        if (file.fail() == 1)
        {
            perror("Error in taking data of the file");
        }
    }

    cout << "The number of repetitions of the name " << argv[2] << " in the file " << argv[1] << ": " << count << endl;
    file.close();
}