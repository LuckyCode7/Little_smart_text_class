#include "String.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    //class test:
    String testA("testA");
    String testB("testB");
    String testC = "testC";
    String testD(testA);

    cout << testA << endl;
    cout << testB << endl;
    cout << testC << endl;
    cout << testD << endl;
    testC = testD;
    cout << testC << endl;

    cout << "Size of testA: " << testA.size() << endl;
    cout << "Number of object: " << String::howManySentences() << endl;
    if (testA > testB) cout << testA << " is alphabetically first" << endl;
    cout << "Last letter of " << testA << " is '" << testA[testA.size()-1] << "'" << endl;
    testA.replaceLetter('A', 'X');
    cout << testA << endl;
    String testE = "red ble green red";
    cout << "Number of words 'red' in sentence '" << testE << "' :" << testE.countWords("red") << endl;

    return 0;
}