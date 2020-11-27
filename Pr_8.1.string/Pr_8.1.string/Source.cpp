#include <iostream>
#include <string>

using namespace std;

int kilkist(const string str);
string modified(string& str);

int main()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);

    cout << "Number of 'abc': " << kilkist(str) << endl;
    cout << "Modified string: " << modified(str) << endl;

    return 0;
}
int kilkist(const string str)
{
    int k = 0;
    size_t pos = 0;
    while ((pos = str.find("abc", pos, 3)) < str.size())
    {
        k++;
        pos += 3;
    }
    return k;
}
string modified(string& str)
{
    size_t pos = 0;
    while ((pos = str.find("abc", pos, 3)) < str.size())
        str.replace(pos, 3, "**");
    return str;
}