#pragma once
#include<iostream>
#include <cstring>

class String
{
private:
    char* sentence;
    int length;
    static int numberOfSentences;
public:
    String();
    String(const char*);
    String(const String&);
    ~String();
    String& operator=(const String&);
    String& operator=(const char*);
    int size() const;
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator >> (std::istream&, String&);
    friend bool operator<(const String& s1, const String& s2);
    friend bool operator>(const String& s1, const String& s2);
    friend bool operator==(const String& s1, const String& s2);
    char& operator[](int);
    const char& operator[](int) const;
    static int howManySentences();
    void replaceLetter(const char&, const char&);
    int countWords(const char*) const;
};
