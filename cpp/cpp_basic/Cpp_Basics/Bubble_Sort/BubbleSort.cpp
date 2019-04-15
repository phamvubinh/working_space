#include <iostream>
using namespace std;

/*
{8,4,5,3,2,9,4,1}
PASS 1 ...
{8,4,5,3,2,9,4,1} => {4,8,5,3,2,9,4,1}
{4,8,5,3,2,9,4,1} => {4,5,8,3,2,9,4,1}
{4,5,8,3,2,9,4,1} => {4,5,3,8,2,9,4,1}
{4,5,3,8,2,9,4,1} => {4,5,3,2,8,9,4,1}
{4,5,3,2,8,9,4,1} => {4,5,3,2,8,4,9,1}
{4,5,3,2,8,4,9,1} => {4,5,3,2,8,4,1,9}
PASS 2 ...
{4,5,3,2,8,4,1,9} => {4,3,5,2,8,4,1,9}
{4,3,5,2,8,4,1,9} => {4,3,2,5,8,4,1,9}
{4,3,2,5,8,4,1,9} => {4,3,2,5,4,8,1,9}
{4,3,2,5,4,8,1,9} => {4,3,2,5,4,1,8,9}
PASS 3 ...
{4,3,2,5,4,1,8,9} => {3,4,2,5,4,1,8,9}
{3,4,2,5,4,1,8,9} => {3,2,4,5,4,1,8,9}
{3,2,4,5,4,1,8,9} => {3,2,4,4,5,1,8,9}
{3,2,4,4,5,1,8,9} => {3,2,4,4,1,5,8,9}
PASS 4 ...
{3,2,4,4,1,5,8,9} => {2,3,4,4,1,5,8,9}
{2,3,4,4,1,5,8,9} => {2,3,4,1,4,5,8,9}
PASS 5 ...
{2,3,4,1,4,5,8,9} => {2,3,1,4,4,5,8,9}
PASS 6 ...
{2,3,1,4,4,5,8,9} => {2,1,3,4,4,5,8,9}
PASS 7 ...
{2,1,3,4,4,5,8,9} => {1,2,3,4,4,5,8,9}
PASS 8 ...
{1,2,3,4,4,5,8,9}
*/

#define SIZE 10

void swap(int &a, int &b);
void bubbleSort(int a[], int size);
void print(int arr[], int size);

int main(int argc, char const *argv[])
{
	int testArr[]={9, 8 ,4 , 5, 2 , 1, 3, 55, 12, 10};

	print(testArr, SIZE);

	bubbleSort(testArr, 10);

	print(testArr, SIZE);

	return 0;
}

void bubbleSort(int a[], int size)
{
	bool finish= false;
	while(!finish)
	{
		finish = true;
		for (int i = 0; i < size-1; i++)
		{
			if (a[i] > a[i+1])
			{
				swap(a[i], a[i+1]);
				finish = false;
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