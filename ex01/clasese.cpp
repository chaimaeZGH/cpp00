#include "All.hpp"

std::string Contact:: getfirst_name() 
        {return first_name;}
std::string Contact:: getlast_name() 
        {return last_name;}
std::string Contact:: getnicknam() 
        {return nickname;}
std::string Contact:: getNumb() 
        {return numb;}
std::string Contact:: getdarkest_secret() 
        {return darkest_secret;}
Contact :: Contact(std::string first,std::string last,std::string nick, std::string a,std::string darkest) 
        { first_name = first; last_name=last;nickname=nick; numb = a;darkest_secret=darkest; }
void Contact::showdisplay()
    {std::cout << "first name: " << first_name << std::endl << "last name: " << last_name << std::endl << "nickname: " << nickname << std::endl << "numb: " << numb << std::endl << "darkest secret: " << darkest_secret << std::endl;};

void PhoneBook::addContact(Contact s,int &index)  
  {
            if(index >= 8)
                contacts[index%8] = s;
            else
                contacts[index] = s;
            index++;
    };

void PhoneBook::showClass(int index) 
{
    int ff;
    if(index < 8)
        ff = index;
    else
        ff = 8;
    std::cout << "     index| firstname|  lastname|  nickname|" << std::endl;
    for (int i = 0; i < ff; i++) 
    {
        int s = 0;
        while(s < 9)
        {
            std::cout << " ";
            s++;
        }
        std::cout << i << "|";
        // -------
        if (contacts[i].getfirst_name().size() <= 10)
        {
            int j = 10 - contacts[i].getfirst_name().size();
            s = 0;
            while(s < j)
            {
               std::cout << " ";
               s++;
            }
            std::cout << contacts[i].getfirst_name() << "|";
        }
        else
        {
            std::cout << contacts[i].getfirst_name().substr(0, 9) + "." << "|";
        }
        // ------
         if (contacts[i].getlast_name().size() <= 10)
        {
            int j = 10 - contacts[i].getlast_name().size();
            s = 0;
            while(s < j)
            {
               std::cout << " ";
               s++;
            }
            std::cout << contacts[i].getlast_name() << "|";
        }
        else
        {
            std::cout << contacts[i].getlast_name().substr(0, 9) + "." << "|";
        }
        // -----
         if (contacts[i].getnicknam().size() <= 10)
        {
            int j = 10 - contacts[i].getnicknam().size();
            s = 0;
            while(s < j)
            {
               std::cout << " ";
               s++;
            }
            std::cout << contacts[i].getnicknam() << "|" << std::endl;
        }
        else
        {
           std::cout << contacts[i].getnicknam().substr(0, 9) + "." << "|" << std::endl;
        }
    }
};
void PhoneBook::getContact(int index)
{
    contacts[index].showdisplay();
};