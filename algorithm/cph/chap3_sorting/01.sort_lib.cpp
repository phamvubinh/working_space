#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Sort a vector
    vector <int> vInt = {14, 15, 7, 8, 9};
    cout << "Sort a vector" << endl;
    sort(vInt.begin(), vInt.end());
    for(auto it: vInt) {
        cout << it << " ";
    }
    cout << endl;

    // Sort an array
    int arr[] = {14, 145, 7, 3, 444};
    cout << "Sort an array" << endl;
    sort(arr, arr+5);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
