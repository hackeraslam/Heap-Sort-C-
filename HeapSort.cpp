#include<iostream>
using namespace std;

void MaxHeap(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i;
	int right = (2 * i) + 1;
	int temp;

	while (left <= n && arr[left] < arr[largest])
	{
		largest = left;
	}

	while (right <= n && arr[right] < arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		MaxHeap(arr, n, largest);
	}
}

void HeapSort(int arr[], int n)
{
	int temp;
	for (int i = (n / 2 - 1); i >= 0; i--)
	{
		MaxHeap(arr, n, i);
	}
	for (int i = n; i >= 0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		MaxHeap(arr, n, 0);

	}
}


int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter Value " << i + 1 << " = ";
		cin >> arr[i];
	}
	HeapSort(arr, 4);
	cout << "Sorted: ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ,";
	}
	cout << endl;

	system("pause");
}
