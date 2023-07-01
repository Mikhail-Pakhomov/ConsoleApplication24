#include <cstring>  
#include <cassert>  
#include <iostream>

class OurString
{
private:
    char* m_data;
    int m_length;

public:
    OurString(const char* source = "")
    {
        assert(source); // перевіряємо, чи не є source нульовим

        m_length = strlen(source) + 1;
        m_data = new char[m_length];
        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];
        m_data[m_length - 1] = '\0';
    }

    // Конструктор копіювання
    OurString(const OurString& other)
    {
        m_length = other.m_length;
        m_data = new char[m_length];
        for (int i = 0; i < m_length; ++i)
            m_data[i] = other.m_data[i];
    }

    ~OurString()
    {
        delete[] m_data;
    }

    char* getString() { return m_data; }
    int getLength() { return m_length; }
};

int main()
{
    OurString hello("Hello, group!");
    OurString copy = hello;

    std::cout << hello.getString() << '\n';

    return 0;
}
