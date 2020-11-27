//пейспяхбмхи яоня╡а
#include <iostream>
using namespace std;

int kilkist(char* str, const int i, int k);
char* modified(char* str, char* t, int i, char* tmp);
void print(const char* x, int i);

int main()
{
	char str[201];

	cout << "Enter string: ";
	cin.getline(str, 200); cout << endl;

	cout << "Number of 'abc': " << kilkist(str, 0, 0) << endl;
	cout << "Modified string: ";

	char* tmp1 = new char[121];
	tmp1[0] = '\0';

	char* tmp2;
	tmp2 = modified(str, tmp1, 0, tmp1);
	print(tmp2, 0);

	return 0;
}
int kilkist(char* str, int i, int k)
{
	if (strlen(str) < 3)
		return 0;
	if (i < strlen(str))
	{
		if (str[i] == 'a' &&
			str[i + 1] == 'b' &&
			str[i + 2] == 'c')
			k++;
		return kilkist(str, i + 1, k);
	}
	else
		return k;
}
char* modified(char* str, char* t, int i, char* tmp)
{
	if (str[i] != 0)
	{
		if (str[i] == 'a' &&
			str[i + 1] == 'b' &&
			str[i + 2] == 'c')
		{
			strcat_s(t, sizeof(str), "**");
			return modified(str, t + 2, i + 3, tmp);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return modified(str, t, i, tmp);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return tmp;
	}
}
void print(const char* x, int i)
{
	if (x[i] != '\0')
	{
		cout << x[i];
		return print(x, i + 1);
	}
}
