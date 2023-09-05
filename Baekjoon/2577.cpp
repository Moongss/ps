#include <iostream>
#include <string>
#include <sstream>

int main(void)
{
	int			a, b, c;
	int			temp;
	std::string result;

	std::cin >> a >> b >> c;
	result = std::to_string(a * b * c);

	for (int i = 0; i <= 9; i++)
	{
		temp = 0;
		for (int j = 0; j < result.length(); j++)
		{
			if ((i + '0') == result[j])
				temp++;
		}
		std::cout << temp << std::endl;
	}
}