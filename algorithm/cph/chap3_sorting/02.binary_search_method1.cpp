#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> data;

void input()
{
    cin >> N;
    int tmp;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        data.push_back(tmp);
    }
}

void binarysearch_1(vector<int>& vInt, int x)
{
    int st = 0;
    int end = vInt.size()-1;
    int mid = 0;
    while(st <= end) {
        mid = (st + end)/2;
        if(vInt[mid] == x) {
            cout << "Found x at: " << mid << endl;
            return;
        }
        if(vInt[mid] > x) {
            end = mid - 1;
            cout << "end: " << end << endl;
        }
        if(vInt[mid] < x) {
            st = mid + 1;
            cout << "st: " << st << endl;
        }
    }
    cout << "Next step" << endl;
}

void output()
{
    for(auto it: data) {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    input();
    binarysearch_1(data, 7);
    return 0;
}
