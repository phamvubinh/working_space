#include <iostream>
using namespace std;

/*
{8,4,5,3,2,9,4,1}
{8} {4} => {4,8}
{5} {3} => {3,5}
{4,8} {3,5} => {3,4,5,8}
{2} {9} => {2,9}
{4} {1} => {1,4}
{2,9} {1,4} => {1,2,4,9}
{3,4,5,8} {1,2,4,9} => {1,2,3,4,4,5,8,9}
{1,2,3,4,4,5,8,9}

{8,4,5,3,2,9,4,1,9,1,2,4,5}
{8} {4} => {4,8}
{5} {3} => {3,5}
{4,8} {3,5} => {3,4,5,8}
{2} {9} => {2,9}
{2,9} {4} => {2,4,9}
{3,4,5,8} {2,4,9} => {2,3,4,4,5,8,9}
{1} {9} => {1,9}
{1,9} {1} => {1,1,9}
{2} {4} => {2,4}
{2,4} {5} => {2,4,5}
{1,1,9} {2,4,5} => {1,1,2,4,5,9}
{2,3,4,4,5,8,9} {1,1,2,4,5,9} => {1,1,2,2,3,4,4,4,5,5,8,9,9}
{1,1,2,2,3,4,4,4,5,5,8,9,9}
*/

void mergeSort(int a[], int size);
void mergeSort(int a[], int iLeft, int iRight, int work[]);
void merge(int a[], int iLeftHaftLeft, int iLeftHalfRigt, int iRightHalfLeft, int iRightHalfRight, int work[]);

void print(const int a[], int iLeft, int iRight);

int main()
{
	// Test 1
	const int SIZE_1 = 8;
	int a1[SIZE_1] = {8, 4, 5, 3, 2, 9, 4, 1};

	print(a1, 0, SIZE_1 -1);
	cout << endl;

	mergeSort(a1, SIZE_1);
	print(a1, 0, SIZE_1 -1);
	cout << endl << endl;
	return 0;
}

void mergeSort(int a[], int size)
{
	int work[size]; // work space
	mergeSort(a, 0, size - 1, work);
}

void mergeSort(int a[], int iLeft, int iRight, int work[])
{
	if((iRight - iLeft) >= 1) // more than 1 elements, divide and sort
	{
		// devide into left and right half
		int iLeftHalfLeft   = iLeft;
		int iLeftHalfRight  = (iRight + iLeft) / 2; // truncate
		int iRightHalfLeft  = iLeftHalfRight + 1;
		int iRightHalfRight = iRight;

		// Recusive sort each half
		mergeSort(a, iLeftHalfLeft, iLeftHalfRight, work);
		mergeSort(a, iRightHalfLeft, iRightHalfRight, work);

		// merge two halves
		merge(a, iLeftHalfLeft, iLeftHalfRight, iRightHalfLeft, iRightHalfRight, work);
	}
}

// Merge two halves in [iLeftHalfLeft, iLeftHalfRight] and [iRightHalfLeft, iRightHalfRight]
// Assume that iLeftHalfRight + 1 = iRightHalfLeft
void merge(int a[], int iLeftHalfLeft, int iLeftHalfRight,
					int iRightHalfLeft, int iRightHalfRight, int work[])
{
	int size = iRightHalfRight - iLeftHalfLeft + 1;
	int iResult = 0;
	int iLeft = iLeftHalfLeft;
	int iRight = iRightHalfLeft;
	while (iLeft <= iLeftHalfRight && iRight <= iRightHalfRight)
	{
		if(a[iLeft] <= a[iRight])
		{
			work[iResult++] = a[iLeft++];
		}
		else
		{
			work[iResult++] = a[iRight++];
		}
	}

	// Copy the remaining left or right into work
	while(iLeft <= iLeftHalfRight)
	{
		work[iResult++] = a[iLeft++];
	}
	while(iRight <= iRightHalfRight)
	{
		work[iResult++] = a[iRight++];
	}

	// for tracing
	print(a, iLeftHalfLeft, iLeftHalfRight);
	print(a, iRightHalfLeft, iRightHalfRight);

	cout << "=>";
	print(work, 0, size - 1);
	cout << endl;

	// copy the work back to the original array
	for (iResult = 0, iLeft = iLeftHalfLeft; iResult < size; ++iResult, ++iLeft)
	{
		a[iLeft] = work[iResult];
	}
}

// Print the contents of the given array from iLeft to iRight (inclusive)
void print(const int a[], int iLeft, int iRight)
{
	cout << "{";
	for (int i = iLeft; i <= iRight; ++i)
	{
		cout << a[i];
		if (i < iRight) cout << ",";
	}
	cout << "} ";
}