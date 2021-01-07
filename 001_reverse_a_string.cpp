// reverse the string

#include <iostream>
using namespace std;
string reverseWord(string str)
{

    string result = str;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        result[i] = str[len - i - 1];
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    string str;
    while (t--)
    {
        cin >> str;
        cout << reverseWord(str);
    }
    return 0;
}