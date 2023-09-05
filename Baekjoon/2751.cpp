#include <iostream>

using namespace std;
void merge(int *arr, int *save, int start, int mid, int end)
{
	int i, j, k;

	i = start;
	k = start;
	j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
			save[k++] = arr[i++];
		else
			save[k++] = arr[j++];
	}

	if (i > mid)
	{
		for (int idx = j; idx <= end; idx++)
			save[k++] = arr[idx];
	}
	else
	{
		for (int idx = i; idx <= mid; idx++)
			save[k++] = arr[idx];
	}

	for (int idx = start; idx <= end; idx++)
	{
		arr[idx] = save[idx];
	}
	return ;
}


void mergesort(int *arr, int *save, int start, int end)
{
	int mid = (start + end) / 2;
	if (start < end)
	{
		mergesort(arr, save, start, mid);
		mergesort(arr, save, mid + 1, end);
		merge(arr, save, start, mid, end);
	}
}

int main(void)
{
	int arr[1000001];
	int save[1000001];
	int num;

	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergesort(arr, save, 1, num);
	for (int i = 1; i <= num; i++)
	{
		cout << arr[i] << "\n";
	}
}