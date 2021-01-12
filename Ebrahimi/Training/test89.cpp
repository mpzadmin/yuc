#include <iostream>
#include <string>

using namespace std;

class Phone
{
    private:
        string applicationPassword;
    public:
        string brand;
        string cpu;
        size_t ram;
        size_t internalStorage;
        void setApplicationPassword(string password);
        string getApplicationPassword();
        Phone(string brand, string cpu, size_t ram, size_t internalStorage);
        Phone();
        ~Phone();
};

Phone::Phone(string brand, string cpu, size_t ram, size_t internalStorage)
{
    cout << "Phone class init" << endl;
    this->brand = brand;
    this->cpu = cpu;
    this->ram = ram;
    this->internalStorage = internalStorage;

    cout << "brand: " << brand << "\t" << "cpu: " << cpu << endl;
    cout << "ram: " << ram << "\t" << "internal storage: " << internalStorage << endl;
}

Phone::Phone()
{
    cout << "Phone class init" << endl;
}

void Phone::setApplicationPassword(string password)
{
    size_t age;
    string firstChallenge, secondChallenge;

    cout << "Enter your age: ";
    cin >> age;
    if (age > 18)
    {
        cout << "Are you seriously older than 17 ? (just yes or no): ";
        cin >> firstChallenge;
        if (firstChallenge == "yes")
        {
            cout << "OK!" << endl;
            cout << "Calculate the integral of (2sin(x)cos(x)): ";
            cin.ignore();
            getline(cin, secondChallenge);
            if (secondChallenge == "sin^2x")
            {
                cout << "OK! We'll give you the password" << endl;
                applicationPassword = password;
            }
            else
            {
                cout << "You were lying to me!" << endl;
                cout << "First of all try not to lie to everyone!" << endl;
                cout << "For the second, Start to study your lessons instead of tricking others and wasting time!" << endl;
            }
        }
        else
        {
            cout << "Go home and continue studying your lessons, baby!" << endl;
        }
    }
    else
    {
        cout << "Go home and continue studying your lessons, baby!" << endl;
    }
}

string Phone::getApplicationPassword()
{
    return "The password of some applications: " + applicationPassword;
}

Phone::~Phone()
{
    cout << "Destruct Phone class" << endl;
}

int main()
{
    Phone huawei("HUAWEI", "Octa-core 1.2 GHz", 2, 16);

    huawei.setApplicationPassword("Welcome to huawei phones collection!");

    if (huawei.getApplicationPassword() == "The password of some applications: ")
    {
        cout << "Sorry! Access denied!" << endl;
    } 
    else
    {
        cout << huawei.getApplicationPassword() << endl;
    }  
}