#include <iostream>
#include <cstring>
#include "PhoneBook.h"

int menu(PhoneBook& list);
int addContact(PhoneBook& list);
int remove(PhoneBook& list, int index);


int main()
{
    PhoneBook phoneBook;
    if (menu(phoneBook) == -1) return -1;
}




int menu(PhoneBook& list)
{
    fopen_s(&file, "data.txt", "w");
    if (file == nullptr)
    {
        cout << "Error\nFile didn't open!";
        return 1;
    }
    char operation;
    do
    {
        cout << "Menu\n"
            << "Enter \"A\" if you want to add a new subscriber\n"
            << "Enter \"R\" if you want to remove a subscriber\n"
            << "Enter \"F\" if you want to find subscriber by their first and last name\n"
            << "Enter \"S\" to see all subscribers\n"
            << "Enter \"f\" if you want to add information to file\n"
            << "Enter \"Q\" if you want to finish program\n";
        cout << "What do you want to do?: ";
        cin >> operation;
        if (operation != 'A' && operation != 'R' && operation != 'F' && operation != 'S' && operation != 'f' && operation != 'Q')
        {
            cout << "Error! Incorrect input";
            if (file != nullptr) fclose(file);
            break;
        }
        switch (operation)
        {
        case 'A':
            if(addContact(list) != 0) return -1;
            break;

        case 'R':
        {
            std::cout << "\n\nWhich subscriber do you want to delete? Enter index: ";
            int index{};
            std::cin >> index;
            std::cout << "\n\n";
            if (remove(list, index) == -1) return -1;
            break;
        }
        case 'F':
        {
            char* fullName = new char[30];
            cout << "\n\nEnter subscriber's first and last name: ";
            cin.ignore();
            gets_s(fullName, 30);
            list.find(fullName);
            delete[] fullName;
            break;
        }
        case 'S':
            list.show();
            break;

        case 'f':
            list.addToFile();
            break;
        default:
            fprintf(file, "\n\n\nSubscribers: ");
            for (int i{ 0 }; i < list.size(); ++i)
            {
                fprintf(file, "Full name: %s\nHome phone number: %s\nMobile phone number: %s\nAdditional information: %s\n\n", list[i].m_firstAndLastName, list[i].m_homePhoneNumber, list[i].m_mobilePhoneNumber, list[i].m_additionalInfoAboutContact);
            }
            if (file != nullptr) fclose(file);
            cout << "\n\nBye!";
            break;
        }
    } while (operation != 'Q');

    return 0;
}

int addContact(PhoneBook& list)
{
    if (list.size() >= list.capacity())
    {
        list.resize(list.capacity() + 5, 5);
    }
    std::cout << "\n\nAdding a new contact \nEnter their full name: ";
    cin.ignore();
    gets_s(list[list.size()].m_firstAndLastName, 30);
    std::cout << "Enter their home phone number: ";
    gets_s(list[list.size()].m_homePhoneNumber, 15);
    std::cout << "Enter their mobile phone number: ";
    gets_s(list[list.size()].m_mobilePhoneNumber, 15);
    if (list.errorCheck(list[list.size()]) == -1) return -1;
    cout << "Enter additional information: ";
    gets_s(list[list.size()].m_additionalInfoAboutContact, 30);
    std::cout << "\nSuccess\n\n";
    Contact contact =
    {
        Contact(list[list.size()].m_firstAndLastName, list[list.size()].m_homePhoneNumber, list[list.size()].m_mobilePhoneNumber, list[list.size()].m_additionalInfoAboutContact)
    };
    list.add(contact);
    return 0;
}

int remove(PhoneBook& list, int index)
{
    if (index < 0 || index >= list.size())
    {
        cout << "Error! Index must be from 0 to " << list.size() - 1 << "!\n";
        return -1;
    }
    list.remove(index);
    return 0;
}