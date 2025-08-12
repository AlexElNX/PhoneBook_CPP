#pragma once
#include <cstring>
class Contact
{
public:
    char* m_firstAndLastName;
    char m_homePhoneNumber[15];
    char m_mobilePhoneNumber[15];
    char m_additionalInfoAboutContact[30];
    Contact(const char* fullName, const char* homeNumber, const char* mobileNumber, const char* additionalInfo) 
        : m_firstAndLastName{ new char[30] {} }
        , m_homePhoneNumber{}
        , m_mobilePhoneNumber{}
        , m_additionalInfoAboutContact{}
    {
        strcpy_s(m_firstAndLastName, 30, fullName);
        strcpy_s(m_homePhoneNumber, 15, homeNumber);
        strcpy_s(m_mobilePhoneNumber, 15, mobileNumber);
        strcpy_s(m_additionalInfoAboutContact, 30, additionalInfo);
    }
    Contact(const Contact& rhs) : Contact(rhs.m_firstAndLastName, rhs.m_homePhoneNumber, rhs.m_mobilePhoneNumber, rhs.m_additionalInfoAboutContact) {}
    Contact() : Contact("undef", "", "", "") {}
    Contact& operator=(const Contact& other)
    {
        if (this == &other)
        {
            return *this;
        }
        strcpy_s(m_firstAndLastName, 30, other.m_firstAndLastName);
        strcpy_s(m_homePhoneNumber, 15, other.m_homePhoneNumber);
        strcpy_s(m_mobilePhoneNumber, 15, other.m_mobilePhoneNumber);
        strcpy_s(m_additionalInfoAboutContact, 30, other.m_additionalInfoAboutContact);
        return *this;
    }

    ~Contact()
    {
        delete[] m_firstAndLastName;
        m_firstAndLastName = nullptr;
    }
};

