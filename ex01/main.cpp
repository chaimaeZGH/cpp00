#include "Phonebook.hpp"

void display()
{
    std::cout << "******** PHONE BOOK ********" << std::endl;
    std::cout << "    ADD = save a new contact\n    SEARCH = display a contact\n    EXIT = exit phone book" << std::endl;
    std::cout << "YOUR CHOICE --> ";
}

int main()
{
    std::string input;
    PhoneBook ph;
    int i = 0;
    while (1)
    {
        display();
        std::getline(std::cin,input);
        if (std::cin.eof())
        {
            std::cout << "End of input reached.\n";
            break;
        }
        if("ADD" == input)
        {
            // ------
            std::cout << "give the first name" << std::endl;
            std::string fi_name;
            while (1) 
            {
                if (!std::getline(std::cin, fi_name)) 
                {
                    std::cout << "Input error or end of file" << std::endl;
                    exit(1);
                }
    
                if (fi_name.empty()) 
                    std::cout << "First name can't be empty" << std::endl;
                else
                    break;
            }
             // ------
            std::cout << "give the last name" << std::endl;
            std::string la_name;
            while (1) 
            {
                if (!std::getline(std::cin, la_name)) 
                {
                    std::cout << "Input error or end of file" << std::endl;
                    exit(1);
                }
    
                if (la_name.empty()) 
                    std::cout << "last name cant be empty" << std::endl;
                else
                    break;
            }
            // ------
            std::cout << "nick name the name" << std::endl;
            std::string ni_name;
           while (1) 
            {
                if (!std::getline(std::cin, ni_name)) 
                {
                    std::cout << "Input error or end of file" << std::endl;
                    exit(1);
                }
    
                if (ni_name.empty()) 
                    std::cout << "last name cant be empty" << std::endl;
                else
                    break;
            }
            // ------
            std::cout << "give the numberme" << std::endl;
            std::string line;
             while (1) 
            {
                bool valid = true;
                if (!std::getline(std::cin, line)) 
                {
                    std::cout << "Input error or end of file" << std::endl;
                    exit(1);
                }
                for (size_t i = 0; i < line.length(); i++)
                {
                    if(!std::isdigit(line[i]))
                    {  
                        valid = false;
                        std::cout << "please inter valid phone number" << std::endl;
                        break;
                    }
                }
                if(valid)
                    break;
            }
            // ------
            std::cout << "give the darkest secret" << std::endl;
            std::string desec;
            while (1) 
            {
                if (!std::getline(std::cin, desec)) 
                {
                    std::cout << "Input error or end of file" << std::endl;
                    exit(1);
                }
    
                if (desec.empty()) 
                    std::cout << "darkest secret cant be empty" << std::endl;
                else
                    break;
            }
            // ------
            
            Contact con(fi_name,la_name,ni_name,line,desec);
            ph.addContact(con,i);
        }
        if ("SEARCH" == input)
        {
            int index;
            ph.showClass(i);
            std::cout << "choose your index" << std::endl;
            std::cin >> index;
            if (i > 8)
                i = 8;
            while(1)
            {
                if(std::cin.eof())
                {
                    std::cout << "Input error or end of file" << std::endl;
                    exit(1);
                }
                if(i==0)
                {
                    std::cin.ignore(10000, '\n');
                    std::cout << "empty phonebook, add contact first" << std::endl;
                    break;
                }
                if (std::cin.fail() || index < 0 || index >= i)
                {
                    std::cout << "Invalid index, please enter a correct one" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cin >> index;
                }
                else
                {
                    std::cin.ignore(10000, '\n');
                    ph.getContact(index);
                    break;
                }
            }
        }
        else if ("EXIT" == input)
            break;
    }
    return 0;
}