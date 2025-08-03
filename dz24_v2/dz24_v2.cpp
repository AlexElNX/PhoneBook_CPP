#include <iostream>
#include <cstring>

#include "PhoneBook.h"

int main()
{
    int size{ 1 };
    std::vector<Contact> phoneBook =
    {
        Contact("John Smith", "+1(123)1234567", "+1(987)654+321", "He loves cats")
    };

    if (PhoneBook::menu(phoneBook, size) == -1) return -1;
    

}

