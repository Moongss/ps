#include <iostream>
#include <algorithm>
using namespace std;

//swap
void swap(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	//to input and output
	int N; 
	int *result;

	//get data 
	cin >> N;
	result = new int[N](); 
	for (int i = 0; i < N; i++)
	{
		cin >> result[i];
	}

	//sort data
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (result[i] > result[j])
				swap(result[i], result[j]);
		}
	}

	//print sort result
	for (int i = 0; i < N; i++)
	{
		cout << result[i] << '\n';
	}

	delete []result;
	return 0;
}