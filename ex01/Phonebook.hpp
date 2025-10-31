#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
private:       
    Contact contacts[8];
public:
    void addContact(Contact s,int &index);
    void showClass(int index);
    void getContact(int index); 
};
#endif