#include "Contact.hpp"

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
    {std::cout << "first name: " << first_name << std::endl << "last name: " << last_name << std::endl << "nickname: " << nickname << std::endl << "numb: " << numb << std::endl << "darkest secret: " << darkest_secret << std::endl;}


