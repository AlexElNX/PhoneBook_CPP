#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctype.h>
FILE* file = nullptr;
#include "PhoneBook.h"


int PhoneBook::menu(std::vector<Contact> list, int& listSize)
{
    fopen_s(&file, "data.txt", "w");
    if (file == nullptr)
    {
        cout << "Error\nFile didn't open!";
        return 1;
    }
    char operation;
    bool isFound = false;
    int index{};
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
        {
            list.resize(list.size() + 1);
            cout << "\n\nAdding a new contact \nEnter their full name: ";
            cin.ignore();
            gets_s(list[list.size() - 1].m_firstAndLastName, 30);
            cout << "Enter their home phone number: ";
            gets_s(list[list.size() - 1].m_homePhoneNumber, 15);
            cout << "Enter their mobile phone number: ";
            gets_s(list[list.size() - 1].m_mobilePhoneNumber, 15);
            if (PhoneBook::errorCheck(list[list.size() - 1].m_homePhoneNumber, list[list.size() - 1].m_mobilePhoneNumber) == 1) return -1;
            cout << "Enter additional information: ";
            gets_s(list[list.size() - 1].m_additionalInfoAboutContact, 30);


            cout << "\n\n\nInformation was successfully added: \n";
            for (int i{ 0 }; i < list.size(); ++i) printPhoneBook(list, list.size(), i);
            cout << "\n\n";

            break;
        }

        case 'R': // Единственное удаление контакта, которое получилось сделать 
            cout << "Which subscriber do you want to delete? Enter index: ";
            cin >> index;
            if (index < 0 || index >= list.size())
            {
                cout << "Error! Index must be from 0 to " << list.size() - 1 << "!\n";
                return -1;
            }
            list[index].m_firstAndLastName[0] = '\0';
            list[index].m_homePhoneNumber[0] = '\0';
            list[index].m_mobilePhoneNumber[0] = '\0';
            list[index].m_additionalInfoAboutContact[0] = '\0';

            cout << "\nSuccess!\n\n";
            break;

        case 'F':
        {

            cout << "\n\n\n";
            char* fullName = new char[30];
            cout << "\nEnter subscriber's first and last name: ";

            cin.ignore();
            gets_s(fullName, 30);

            for (int i{ 0 }; i < listSize; ++i)
            {
                if (strcmp(list[i].m_firstAndLastName, fullName) == 0)
                {
                    printPhoneBook(list, listSize, i);
                    isFound = true;
                    break;
                }
            }
            if (isFound == false) cout << "There's no subscriber with that name and last name\n";
            cout << "\n\n\n";
            delete[] fullName;
            break;
        }


        case 'S':
            cout << "\n\n\n";
            for (int i{}; i < list.size(); ++i)
            {
                cout << "Subscriber [" << i << "]: \n";
                printPhoneBook(list, list.size(), i);
            }
            cout << "\n\n\n";
            break;



        case 'f':
            cout << "\n\n";
            fprintf(file, "\nSubscribers: \n");
            for (int i{ 0 }; i < list.size(); ++i)
            {
                fprintf(file, "Full name: %s\nHome phone number: %s\nMobile phone number: %s\nAdditional information: %s\n\n", list[i].m_firstAndLastName, list[i].m_homePhoneNumber, list[i].m_mobilePhoneNumber, list[i].m_additionalInfoAboutContact);
            }
            cout << "Success!\n\n";
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


PhoneBook::PhoneBook() {}

void PhoneBook::printPhoneBook(std::vector<Contact> list, int listSize, int index)
{

    cout << "First and last name: " << list[index].m_firstAndLastName
        << "\nHome phone number: " << list[index].m_homePhoneNumber
        << "\nMobile phone number: " << list[index].m_mobilePhoneNumber
        << "\nAdditional information: " << list[index].m_additionalInfoAboutContact;
    cout << "\n\n";
}

int PhoneBook::errorCheck(char homePhoneNum[], char mobilePhoneNum[])
{

    for (int i{}; i < strlen(homePhoneNum); ++i)
    {
        if (!isdigit(homePhoneNum[i]))
        {
            cout << "Error: Invalid input!";
            return 1;
        }
    }
    if (strlen(homePhoneNum) < 11 || strlen(homePhoneNum) > 15)
    {
        cout << "Error! Home phone number must be at least 11 digits and maximum of 15";
        if (file != nullptr) fclose(file);
        return 1;
    }
    else if (strlen(mobilePhoneNum) < 11 || strlen(mobilePhoneNum) > 15)
    {
        cout << "Error! Mobile phone number must be at least 11 digits and maximum of 15";
        if (file != nullptr) fclose(file);
        return 1;
    }

    return 0;
}
