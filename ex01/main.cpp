#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Contact
{
    private:
    string first_name;
    string last_name;
    string nickname;
    string numb;
    string darkest_secret;
    public:
    // Constructor
    Contact(string first,string last,string nick, string a,string darkest) 
        { first_name = first; last_name=last;nickname=nick; numb = a;darkest_secret=darkest; }
    // ------
    string getfirst_name() 
        {return first_name;}
    void setfirst_name(string first) 
        {first_name = first;}
    // ------
     string getlast_name() 
        {return last_name;}
    void setlast_name(string last) 
        {last_name = last;}
    // ------
     string getnicknam() 
        {return nickname;}
    void setnicknam(string nick) 
        {nickname = nick;}
    // ------
    string getNumb() 
        {return numb;}
    void setNumb(string a) 
        {numb = a;}
    // ------
     string getdarkest_secret() 
        {return darkest_secret;}
    void setName(string darkest) 
        {darkest_secret = darkest;}
    // ------
    void display() const {
        cout << "first name: " << first_name << ", last name: " << last_name << ", nickname: " << nickname << ", numb: " << numb << ", darkest secret: " << darkest_secret << endl;
    }
    ~Contact() {
    // std::cout << "Contact destroyed: " << first_name << std::endl;
}
};


class PhoneBook {
private:
    std::vector<Contact> contacts;
public:
  void addContact(const Contact& newContact) {
        contacts.push_back(newContact);
    }
    
    void setContact(size_t i, Contact c) {
        if (i >= 0 && i < contacts.size()) contacts[i] = c;
    }
    void showClass() const {
        for (size_t i = 0; i < contacts.size(); i++) {
            contacts[i].display();
        }
    }
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
    PhoneBook ph;
    int i = 0;
    int j = 0;
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
            if(i==8)
            {
                ph.setContact((size_t)j, con);
                j++;
                if(j==8)
                    j=0;
            }
            else
            {
                ph.addContact(con);
                i++;
            }
        }
        if("SEARCH" == input)
        {
            ph.showClass();
        }
        else if ("EXIT" == input)
            break;
    }
    return 0;
}