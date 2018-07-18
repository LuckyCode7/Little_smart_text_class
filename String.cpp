#include "String.h"

int String::numberOfSentences = 0;

String::String()
{
    this->length = 0;
    this->sentence = new char[1];
    this->sentence[0] = '/0';
    this->numberOfSentences++;
}

String::String(const char* s)
{
    this->length = std::strlen(s);
    this->sentence = new char[length + 1];
    std::strcpy(sentence, s);
    this->numberOfSentences++;
}

String::String(const String& s)
{
    this->length = std::strlen(s.sentence);
    this->sentence = new char[length + 1];
    std::strcpy(sentence, s.sentence);
    this->numberOfSentences++;
}

String::~String()
{
    --numberOfSentences;
    delete[] sentence;
}

String& String::operator=(const String& s)
{
    if (this == &s)
        return *this;
    delete[] sentence;
    this->length = std::strlen(s.sentence);
    this->sentence = new char[length + 1];
    std::strcpy(sentence, s.sentence);
    return *this;
}

String& String::operator=(const char* s)
{
    delete[] sentence;
    this->length = std::strlen(s);
    this->sentence = new char[length + 1];
    std::strcpy(sentence, s);
    return *this;
}

int String::size() const
{
    return this->length;
}

char& String::operator[](int i)
{
    return this->sentence[i];
}

const char& String::operator[](int i) const
{
    return this->sentence[i];
}

int String::howManySentences()
{
    return numberOfSentences;
}

void String::replaceLetter(const char& a, const char& b)
{
    bool find = false;
    for (int i = 0; i < this->length; i++)
    {
        if (this->sentence[i] == a)
        {
            this->sentence[i] = b;
            find = true;
        }
    }
    if (!find)
        std::cout << "Ther is no letter '" << a << "' in sentence '" << this->sentence << "'" << std::endl;
}

int String::countWords(const char* a) const
{
    int j = 0;
    int counter = 0;
    for (int i = 0; i < this->length; i++)
    {
        if (this->sentence[i] == a[j])
        {
            if (j == std::strlen(a) - 1)
            {
                counter++;
                j = 0;
            }
            else
            {
                j++;
            }
        }
        else
        {
            j = 0;
        }
    }
    return counter;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
    os << s.sentence;
    return os;
}

std::istream& operator >> (std::istream& is, String& s)
{
    is >> s.sentence;
    return is;
}

bool operator<(const String& s1, const String& s2)
{
    return (std::strcmp(s1.sentence, s2.sentence) < 0);
}

bool operator>(const String& s1, const String& s2)
{
    return s1 < s2;
}

bool operator==(const String& s1, const String& s2)
{
    return (std::strcmp(s1.sentence, s2.sentence) == 0);
}














