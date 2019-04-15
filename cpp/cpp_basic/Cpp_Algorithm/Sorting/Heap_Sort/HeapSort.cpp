#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is an index in arr[], n is size of the heap
void heapify(int arr[], int n , int i)
{
	int largest = i; // Initialize largest as root
	int left    = i*2 + 1;
	int right   = i*2 + 2;

	if((left < n) && (arr[largest] < arr[left]))
	{
		largest = left;
	}

	if((right < n) && (arr[largest] < arr[right]))
	{
		largest = right;
	}

	if(largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	int i = 0;

	// Build the heap, rearrange the array
	for (i = n/2 -1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	// One by one extract the element from the heap
	for (i = n - 1; i >= 0; i--)
	{
		// Swap the current root with last leave of current heap
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap, size of the heap equal to i
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}
