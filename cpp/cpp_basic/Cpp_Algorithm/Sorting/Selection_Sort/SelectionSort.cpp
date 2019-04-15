#include <iostream>
using namespace std;

/*

{8,4,5,3,2,9,4,1}
{} {8,4,5,3,2,9,4,1} => {} {1,4,5,3,2,9,4,8}
{1} {4,5,3,2,9,4,8} => {1} {2,5,3,4,9,4,8}
{1,2} {5,3,4,9,4,8} => {1,2} {3,5,4,9,4,8}
{1,2,3} {5,4,9,4,8} => {1,2,3} {4,5,9,4,8}
{1,2,3,4} {5,9,4,8} => {1,2,3,4} {4,9,5,8}
{1,2,3,4,4} {9,5,8} => {1,2,3,4,4} {5,9,8}
{1,2,3,4,4,5} {9,8} => {1,2,3,4,4,5} {8,9}
{1,2,3,4,4,5,8,9}

*/

#define SIZE 10

void swap(int &a, int &b);
void selectionSort(int arr[], int size);
void print(int arr[], int size);

int main(int argc, char const *argv[])
{
	int testArr[]={9, 8 ,4 , 5, 2 , 1, 3, 55, 12, 10};
	print(testArr, SIZE);

	selectionSort(testArr, 10);
	print(testArr, SIZE);

	return 0;
}

void selectionSort(int arr[], int size)
{
	int minIndex = 0;
	for (int i = 0; i < size-1; i++)
	{
		// choose the fisrt position that is the smallest number
		minIndex = i;

		// check from the next position to the end to find the index that include smallest number
		for (int j = i+1; j < size; j++)
		{
			// finding the smallest number, save the index for next comparation
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		// swap only when the index is differrent
		if (minIndex != i)
		{
			swap(arr[i], arr[minIndex]);
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