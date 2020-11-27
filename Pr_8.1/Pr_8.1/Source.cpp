//≤“≈–¿÷≤…Õ»… —œŒ—≤¡
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int kilkist(char* str);
char* modified(char* str);
void print(const char* x);

int main()
{


	char str[201];

	cout << "Enter string: ";
	cin.getline(str, 200); cout << endl;

	cout << "Number of 'abc': " << kilkist(str) << endl;
	cout << "Modified string: ";
	print(modified(str));


	return 0;
}
int kilkist(char* str)
{
	if (strlen(str) < 3)
		return 0;
	int k = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == 'a' &&
			str[i + 1] == 'b' &&
			str[i + 2] == 'c' )
			k++;
	return k;
}
char* modified(char* str)
{
	if (strlen(str) < 3)
		return str;

	char* tmp = new char[strlen(str) * 2 /3 + 1];
	char* t = tmp;

	tmp[0] = '\0';
	int i = 0;
	while (str[i] != 0)
	{
		if (str[i] == 'a' &&
			str[i + 1] == 'b' &&
			str[i + 2] == 'c' )
			
		{
			strcat(t, "**");
			t += 2;
			i += 3;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}
void print(const char* x)
{
	int i = 0;
	while (x[i] != '\0')
		cout << x[i++];
}