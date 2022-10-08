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

void binarysearch_3(vector<int>& vInt, int x)
{
    auto k = lower_bound(vInt.begin(), vInt.end(), x) - vInt.begin();
    if (k < N && vInt[k] == x) {
        cout << "Found: " << k << endl;
    }
}

void count_number(vector<int>& vInt, int x)
{
    auto a = lower_bound(vInt.begin(), vInt.end(), x);
    auto b = upper_bound(vInt.begin(), vInt.end(), x);
    cout << "b-a: " << (b-a) << endl;

    auto r = equal_range(vInt.begin(), vInt.end(), x);
    cout <<  "r.second-r.first: " << r.second-r.first << "\n";
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
    binarysearch_3(data, 7);
    count_number(data, 7);
    return 0;
}
