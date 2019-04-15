#include <iostream>
using namespace std;

/*
{8,4,5,3,2,9,4,1}
{8,4,5,1,2,9,4,3} {1,4,5,8,2,9,4,3} {1,2,5,8,4,9,4,3} =>{1,2}  {3} {8,4,9,4,5}
{2,1} =>{}  {1} {2}
{8,4,5,4,9} {8,4,5,4,9} {8,4,5,4,9} {8,4,5,4,9} {8,4,5,4,9} =>{8,4,5,4}  {9} {}
{8,4,5,4} =>{}  {4} {4,5,8}
{4,8,5} {4,8,5} =>{4}  {5} {8}
{1,2,3,4,4,5,8,9}
*/

void quickSort(int a[], int size);
void quickSort(int a[], int left, int right);
void choosePivot(int a[], int left, int right);
int partition(int a[], int left, int right);
void print(const int a[], int left, int right);

int main(int argc, char const *argv[])
{
	// Test 1
	const int SIZE_1 = 8;
	int a1[SIZE_1] = {8, 4, 5, 3, 2, 9, 4, 1};

	print(a1, 0, SIZE_1 - 1);
	cout << endl;
	quickSort(a1, SIZE_1);
	print(a1, 0, SIZE_1 - 1);
	cout << endl << endl;

	// Test 2
	const int SIZE_2 = 13;
	int a2[SIZE_2] = {8, 4, 5, 3, 2, 9, 4, 1, 9, 1, 2, 4, 5};

	print(a2, 0, SIZE_2 - 1);
	cout << endl;
	quickSort(a2, SIZE_2);
	print(a2, 0, SIZE_2 - 1);
	cout << endl;

	return 0;
}

void quickSort(int a[], int size)
{
	quickSort(a, 0, size -1);
}

void quickSort(int a[], int left, int right)
{
	// recursive condition to stop till the array number has only 1 element
	if((right - left) >= 1)   // check number of element > 1
	{
		// take the pivot value and swap it to the right of array
		choosePivot(a, left, right);

		// create the partition by comape to pivot value, return the pivot index
		int pivotIndex = partition(a, left, right);

		// devive the array to small array to recursive
		quickSort(a, left, pivotIndex -1);
		quickSort(a, pivotIndex + 1, right);
	}
}

void choosePivot(int a[], int left, int right)
{
	// choose the middle number and swap it to the number in the right of array
	int pivotIndex = (left + right) / 2;
	int temp = a[right];
	a[right] = a[pivotIndex];
	a[pivotIndex] = temp;
}

int partition(int a[], int left, int right)
{
	int pivot = a[right];
	int storeIndex = left;
	int temp = 0;

	print (a, left, right);
	for (int i = left; i <= right; ++i)
	{
		if(a[i] < pivot)
		{


			// swap the current value to storeIndex value to save
			temp = a[i];
			a[i] = a[storeIndex];
			a[storeIndex] = temp;

			print (a, left, right);
			// increase storeIndex due to found new valid number that < pivot
			storeIndex++;
		}
	}

	// swap the pivot value and the storeIndex value for next recursive
	a[right] = a[storeIndex];
	a[storeIndex] = pivot;

	cout << "=>";
	print(a, left, storeIndex - 1);
	cout << " {" << a[storeIndex] << "} ";
	print(a, storeIndex + 1, right);
	cout << endl;

	// return store index that is saved pivot value
	return storeIndex;
}

// Print the contents of the given array from left to right (inclusive)
void print(const int a[], int left, int right)
{
	cout << "{";
	for (int i = left; i <= right; ++i)
	{
		cout << a[i];
		if (i < right) cout << ",";
	}
	cout << "} ";
}