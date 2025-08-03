#pragma once
#include "Contact.h"
#include <vector>
using namespace std;

class PhoneBook
{
public:
    std::vector<Contact> list;
    static int menu(std::vector<Contact> list, int& listSize);
    static inline void printPhoneBook(std::vector<Contact> list, int listSize, int index);
    static int errorCheck(char homePhoneNum[], char mobilePhoneNum[]);
    PhoneBook();


};


