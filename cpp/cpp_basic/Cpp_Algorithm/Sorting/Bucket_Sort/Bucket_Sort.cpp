#include <iostream>
#include <vector>
using namespace std;

void bucketSort(int a[], int size);
void bucketSort(vector<int> & list, int radix);
void printBuckets(const vector<int> bucket[]);
void print(const vector<int> list);

const int NUM_BUCKETS = 10;

int main() {
	const int SIZE = 13;
	int a[] = {28, 104, 25, 593, 22, 129, 4, 11, 129, 4, 111, 20, 9};
	bucketSort(a, SIZE);
}

void bucketSort(int a[], int size)
{
	// find maximum to decide on the number of significant digits
	int max = a[0];
	int radix = 1;

	for (int i = 0; i < size; ++i)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}

	cout << max << endl;
	// Decide on the max radix (1000, 100, 10, 1, etc)
 	while(max/radix > 0)
 	{
 		max = max/radix;
 		radix *= 10;
 	}

 	cout << radix << endl;
	// copy the array into a vector
 	vector<int> list(size);
 	for (int i = 0; i < size; ++i)
 	{
 		list[i] = a[i];
 	}
	bucketSort(list, radix);
}

void bucketSort(vector<int> & list, int radix)
{
	int bucketIndex = 0;

	// print to sort list
	print(list);
	cout << endl;

	// sort the list if have more than 2 element
	if(list.size() > 1 && radix > 0)
	{
		// create the bucket vector that have 10 bucket to save result of %10 from 0 to 9
		vector<int> bucket[NUM_BUCKETS];
		for (int i = 0; i < list.size(); ++i)
		{
			bucketIndex  = (list[i] / radix) % 10;
			bucket[bucketIndex].push_back(list[i]);
		}

		printBuckets(bucket);
		cout << endl;

		radix = radix  / 10;
		for (int bucketIndex = 0; bucketIndex < NUM_BUCKETS; ++bucketIndex)
		{
			bucketSort(bucket[bucketIndex], radix);
		}

		// Gather all the bucket into list and return
		list.resize(0);  // remove all elements
		for (int bi = 0; bi < NUM_BUCKETS; ++bi)
		{
			for (int j = 0; j < bucket[bi].size(); ++j)
			{
				list.push_back((bucket[bi])[j]);
			}
		}

		// For tracing
		cout << "Sorted: ";
		print(list);
	}
}

void printBuckets(const vector<int> bucket[])
{
	for (int i = 0; i < NUM_BUCKETS; ++i)
	{
		cout << "{";
		for (int ib = 0; ib < (bucket[i]).size(); ++ib)
		{
			cout << (bucket[i])[ib];
		}
		cout << "} , ";
	}
}

void print(const vector<int> list)
{
	cout << "{";
	for (int i = 0; i < list.size(); ++i)
	{
		cout << " " << list[i];
	}
	cout << "}";
}