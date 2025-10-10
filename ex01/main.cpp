#include "All.hpp"

void display()
{
    std::cout << "******** PHONE BOOK ********" << std::endl;
    std::cout << "    ADD = save a new contact\n    SEARCH = display a specific contact\n    EXIT = exit phone book" << std::endl;
    std::cout << "YOUR CHOICE --> ";
}

int main()
{
    std::string input;
    PhoneBook ph;
    int i = 0;
    int j = 0;
    bool ajs = true;
    while (ajs)
    {
        display();
        std::getline(std::cin,input);
        if (std::cin.eof())
        {
            std::cout << "End of input reached.\n";
            ajs=false;
        }
        if("ADD" == input)
        {
            // ------
            std::cout << "give the first name" << std::endl;
            std::string fi_name;
            std::getline(std::cin,fi_name);
            while (fi_name.empty())
            {
                std::cout << "first name cant be empty" << std::endl;
                std::getline(std::cin,fi_name);
            }
             // ------
            std::cout << "give the last name" << std::endl;
            std::string la_name;
            std::getline(std::cin,la_name);
            while (la_name.empty())
            {
                std::cout << "last name cant be empty" << std::endl;
                std::getline(std::cin,la_name);
            }
            // ------
            std::cout << "nick name the name" << std::endl;
            std::string ni_name;
            std::getline(std::cin,ni_name);
            while (ni_name.empty())
            {
                std::cout << "nick name cant be empty" << std::endl;
                std::getline(std::cin,ni_name);
            }
            // ------
            std::cout << "give the numberme" << std::endl;
            std::string line;
            std::getline(std::cin, line);
            for (size_t i = 0; i < line.length(); i++)
            {
                if(!std::isdigit(line[i]))
                {
                    std::cout << "please inter valid phone number" << std::endl;
                    std::getline(std::cin, line);
                }
            }
            // ------
            std::cout << "give the darkest secret" << std::endl;
            std::string desec;
            std::getline(std::cin,desec);
            while (desec.empty())
            {
                std::cout << "darkest secret cant be empty" << std::endl;
                std::getline(std::cin,desec);
            }
            // ------
            
            Contact con(fi_name,la_name,ni_name,line,desec);
            if(i == 8)
            {
                ph.setContact((size_t)j, con);
                j++;
                if(j == 8)
                    j = 0;
            }
            else
            {
                ph.addContact(con);
                i++;
            }
        }
        if("SEARCH" == input)
        {
            int index;
            ph.showClass();
            std::cout << "shoos ure index" << std::endl;
            std::cin >> index;
            while (std::cin.fail() || index < 0 || index >= i) 
            {
                std::cout << "Invalid index, please inter a corect one" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> index;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ph.getContact(index);
        }
        else if ("EXIT" == input)
            ajs=false;
    }
    return 0;
}