#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <cctype>

class Contact
{
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string numb;
    std::string darkest_secret;
    public:
   Contact() {}
    std::string getfirst_name();
    std::string getlast_name(); 
    std::string getnicknam();
    std::string getNumb(); 
    std::string getdarkest_secret(); 
    // Constructor
    Contact(std::string first,std::string last,std::string nick, std::string a,std::string darkest) ;
    // ------
    void showdisplay();
    ~Contact() {
    // std::std::cout << "Contact destroyed: " << first_name << std::endl;
    }
};

#endif