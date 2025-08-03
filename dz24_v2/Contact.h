#pragma once
#include <cstring>
class Contact
{
public:
    char* m_firstAndLastName = new char[30];
    char m_homePhoneNumber[15]{};
    char m_mobilePhoneNumber[15]{};
    char m_additionalInfoAboutContact[30]{};
    Contact(const char* fullName, const char* homeNumber, const char* mobileNumber, const char* additionalInfo) 
    {
        strcpy_s(m_firstAndLastName, 30, fullName);
        strcpy_s(m_homePhoneNumber, 15, homeNumber);
        strcpy_s(m_mobilePhoneNumber, 15, mobileNumber);
        strcpy_s(m_additionalInfoAboutContact, 30, additionalInfo);
    }
    Contact(const Contact& rhs)
    {
        strcpy_s(m_firstAndLastName, 30, rhs.m_firstAndLastName);
        strcpy_s(m_homePhoneNumber, 15, rhs.m_homePhoneNumber);
        strcpy_s(m_mobilePhoneNumber, 15, rhs.m_mobilePhoneNumber);
        strcpy_s(m_additionalInfoAboutContact, 30, rhs.m_additionalInfoAboutContact);
    }
    Contact() {}
    ~Contact()
    {
        delete[] m_firstAndLastName;
        m_firstAndLastName = nullptr;
    }
};

