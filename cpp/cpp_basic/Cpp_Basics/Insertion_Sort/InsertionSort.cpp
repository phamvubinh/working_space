#include <iostream>
using namespace std;

/*

{8,4,5,3,2,9,4,1}
{8} {4,5,3,2,9,4,1}
{4,8} {5,3,2,9,4,1}
{4,5,8} {3,2,9,4,1}
{3,4,5,8} {2,9,4,1}
{2,3,4,5,8} {9,4,1}
{2,3,4,5,8,9} {4,1}
{2,3,4,4,5,8,9} {1}
{1,2,3,4,4,5,8,9}

*/

#define SIZE 10

void swap(int &a, int &b);
void insertionSort(int arr[], int size);
void print(int arr[], int size);

int main(int argc, char const *argv[])
{
	int testArr[]={9, 8 ,4 , 5, 2 , 1, 3, 55, 12, 10};
	print(testArr, SIZE);

	insertionSort(testArr, 10);
	print(testArr, SIZE);

	return 0;
}

void insertionSort(int arr[], int size)
{
	int temp;

	for (int i = 1; i < size; i++)
	{
		for (int prev = 0; prev < i ;prev++)
		{
			// find the postition till arr[i] < arr[prev] in sorted array
			if(arr[i] < arr[prev])
			{
				temp = arr[i];

				// create the slot for arr[i] (now is temp)
				for (int shift = i; shift > prev; shift--)
				{
					arr[shift] = arr[shift-1];
				}

				// assign the value of the slot to arr[i]
				arr[prev] = temp;

				// find the first position that a[i] < a[prev], that is the correct position
				break;
			}
		}
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print(int arr[], int size)
{
	cout << "arr = [";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << "]" << endl;
}