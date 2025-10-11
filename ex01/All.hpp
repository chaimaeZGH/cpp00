#ifndef ALL_HPP
#define ALL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
// using namespace std;
class Contact
{
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string numb;
    std::string darkest_secret;
    public:
   
    std::string getfirst_name() 
        {return first_name;}
    void setfirst_name(std::string first) 
        {first_name = first;}
    // ------
    std::string getlast_name() 
        {return last_name;}
    void setlast_name(std::string last) 
        {last_name = last;}
    // ------
    std::string getnicknam() 
        {return nickname;}
    void setnicknam(std::string nick) 
        {nickname = nick;}
    // ------
    std::string getNumb() 
        {return numb;}
    void setNumb(std::string a) 
        {numb = a;}
    // ------
    std::string getdarkest_secret() 
        {return darkest_secret;}
    void setName(std::string darkest) 
        {darkest_secret = darkest;}
    // ------ 
    // Constructor
    Contact(std::string first,std::string last,std::string nick, std::string a,std::string darkest) 
        { first_name = first; last_name=last;nickname=nick; numb = a;darkest_secret=darkest; }
    // ------
    void showdisplay()  {
        std::cout << "first name: " << first_name << std::endl << "last name: " << last_name << std::endl << "nickname: " << nickname << std::endl << "numb: " << numb << std::endl << "darkest secret: " << darkest_secret << std::endl;
    }
    ~Contact() {
    // std::std::cout << "Contact destroyed: " << first_name << std::endl;
    }

};


class PhoneBook {
private:
    std::vector<Contact> contacts;
public:
  void addContact(const Contact& newContact) {
        contacts.push_back(newContact);
    }
    
    void setContact(size_t i, Contact c) 
    {
        if (i >= 0 && i < contacts.size()) 
            contacts[i] = c;
    }
    void showClass() 
    {
        std::cout << "     index| firstname|  lastname|  nickname|" << std::endl;
        for (size_t i = 0; i < contacts.size(); i++) 
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
        
    }
    void getContact(int index)
    {
            contacts[index].showdisplay();
    } 
};

#endif