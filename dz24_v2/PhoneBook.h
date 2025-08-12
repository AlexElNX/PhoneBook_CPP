#pragma once
#include "Contact.h"
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
extern FILE* file;

using namespace std;

class PhoneBook
{
    int m_capacity;
    int m_grow;
    int m_size;
    Contact* m_data;
public:
    PhoneBook() : m_capacity{ 2 }, m_grow{ 5 }, m_size{ 0 }, m_data{ new Contact[m_capacity] } {}
    Contact& operator[](int index)
    {
        return m_data[index];
    }
    int errorCheck(Contact contact)
    {
    
        for (int i{}; i < strlen(m_data->m_homePhoneNumber); ++i)
        {
            if (!isdigit(m_data->m_homePhoneNumber[i]))
            {
                cout << "Error: Invalid input!";
                return -1;
            }
            if (!isdigit(m_data->m_mobilePhoneNumber[i]))
            {
                cout << "Error: Invalid input!";
                return -1;
            }
        }
        if (strlen(m_data->m_homePhoneNumber) < 11 || strlen(m_data->m_homePhoneNumber) > 15)
        {
            cout << "Error! Home phone number must be at least 11 digits and maximum of 15";
            if (file != nullptr) fclose(file);
            return -1;
        }
        else if (strlen(m_data->m_mobilePhoneNumber) < 11 || strlen(m_data->m_mobilePhoneNumber) > 15)
        {
            cout << "Error! Mobile phone number must be at least 11 digits and maximum of 15";
            if (file != nullptr) fclose(file);
            return -1;
        }
    
        return 0;
    }
    void add(const Contact &contact)
    {
        m_data[m_size] = contact;
        ++m_size;
    }

    void resize(int capacity, int grow)
    {
        Contact* contacts = new Contact[capacity];
        m_size = m_size < capacity ? m_size : capacity;
        for (int i{}; i < m_size; ++i)
        {
            contacts[i] = m_data[i];
        }
        delete[] m_data;
        m_data = contacts;
        m_capacity = capacity;
    }
    void remove(int index)
    {
        for (int i{ index }; i < m_size - 1; ++i)
        {
            m_data[i] = m_data[i + 1];
        }
        --m_size;
    }
    int size() const
    {
        return m_size;
    }
    int capacity()
    {
        return m_capacity;
    }
    void show() const 
    { 
        for (int i{}; i < m_size; ++i)
        {
            std::cout << "\n\nContact: " << i << "\n" 
                << "Full name: " << m_data[i].m_firstAndLastName << std::endl
                << "Home phone number: " << m_data[i].m_homePhoneNumber << std::endl
                << "Mobile phone number: " << m_data[i].m_mobilePhoneNumber << std::endl
                << "Additional information: " << m_data[i].m_additionalInfoAboutContact << "\n\n";
        }
    }
    void showSpecified(int index) const
    {
        std::cout << "\n\nContact: " << index << "\n"
            << "Full name: " << m_data[index].m_firstAndLastName << std::endl
            << "Home phone number: " << m_data[index].m_homePhoneNumber << std::endl
            << "Mobile phone number: " << m_data[index].m_mobilePhoneNumber << std::endl
            << "Additional information: " << m_data[index].m_additionalInfoAboutContact << "\n\n";
    }
    void find(char* fullName)
    {
        bool isFound = false;
        for (int i{ 0 }; i < PhoneBook::m_size; ++i)
        {
            if (strcmp(m_data[i].m_firstAndLastName, fullName) == 0)
            {
                showSpecified(i);
                isFound = true;
                break;
            }
        }
        if (isFound == false) cout << "There's no subscriber with that name and last name\n";
        cout << "\n\n\n";
    }
    
    void addToFile()
    {
        fprintf(file, "\nSubscribers: \n");
        for (int i{ 0 }; i < m_size; ++i)
        {
            fprintf(file, "Full name: %s\nHome phone number: %s\nMobile phone number: %s\nAdditional information: %s\n\n", m_data[i].m_firstAndLastName, m_data[i].m_homePhoneNumber, m_data[i].m_mobilePhoneNumber, m_data[i].m_additionalInfoAboutContact);
        }
        cout << "\n\nSuccess!\n\n";
    }


};


// 123456789101
// 101987654321