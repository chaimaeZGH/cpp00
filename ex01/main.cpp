#include <iostream>
#include <string>
using namespace std;

class Contact
{
    private:
    string name;
    int numb;
    public:
    // Constructor
    Contact(string n, int a) 
    { name = n; numb = a; }
    string getName() 
    {return name;}
    void setName(string n) 
    {name = n;}
    int getAge() 
    {return numb;}
    void setAge(int a) 
    {numb = a;}
};

class PhoneBook
{
    private:
        Contact a;

};



void display()
{
    std::cout << "******** PHONE BOOK ********" << std::endl;
    std::cout << "    ADD = save a new contact\n    SEARCH = display a specific contact\n    EXIT = exit phone book" << std::endl;
    std::cout << "YOUR CHOICE --> ";
}


int main()
{
    std::string input;
    while (1)
    {
        display();
        std::getline(std::cin,input);
        if (std::cin.eof())
        {
            std::cout << "End of input reached.\n";
            break;
        }
        else if ("EXIT" == input)
            break;
    }
    return 0;
}