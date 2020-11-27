#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str);
char* Change(char* str);

int main()
{

    char str[201];
    cout << "Enter string: ";
    cin.getline(str, 200); cout << endl;
    cout << "Number of 'abc': " << Count(str) << endl;
    char* second = new char[121];
    second = Change(str);
    cout << "Modified string: " << second;
    return 0;
}
int Count(char* str)
{
    int k = 0;
    int pos = 0;
    char* t;

    while (t = strchr(str + pos, 'a'))
    {
        pos = t - str + 1;
        if (str[pos] == 'b' &&
            str[pos + 1] == 'c')
            k++;
    }
    return k;
}
char* Change(char* str)
{
    char* tmp = new char[strlen(str)];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *tmp = 0;

    while (p = strchr(str + pos1, 'a'))
    {
        if (str[p - str + 1] == 'b' &&
            str[p - str + 2] == 'c')
        {
            pos2 = p - str + 3;
            strncat(tmp, str + pos1, pos2 - pos1 - 3);
            strcat(tmp, "**");
            pos1 = pos2;
        }
    }
    strcat(tmp, str + pos1);

    strcpy(str, tmp);

    return tmp;
}