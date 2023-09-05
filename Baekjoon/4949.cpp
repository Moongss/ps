#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	string str;
	int i;
	while (true)
	{
		int pointer = 0;
		char stack[101] = {0};
		getline(cin, str);
		if (str[0] == '.')
			break;
		for (i = 0; i < str.length(); i++)
		{
			if (str[i] == '[' || str[i] == '(')
				stack[pointer++] = str[i];
			else if (str[i] == ']')
			{
				if (stack[0] && stack[pointer - 1] == '[')
					stack[--pointer] = 0;
				else
					break ;
			}
			else if (str[i] == ')')
			{
				if (stack[0] && stack[pointer - 1] == '(')
					stack[--pointer] = 0;
				else
					break ;
			}
		}
		if (i == str.length() && !stack[0])
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return (0);
}