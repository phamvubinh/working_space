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

void binarysearch_2(vector<int>& vInt, int x)
{
    int endStep = 0;
    for(int jump = N/2; jump >= 1; jump /= 2) {
        while((endStep + jump < N) && (vInt[endStep+jump] <= x)) {
            endStep += jump;
            cout << "EndStep: " << endStep << endl;
        }
    }
    if (vInt[endStep] == x) {
        cout << "Found x at:" << endStep << endl;
    } else {
        cout << "X does not exist" << endl;
    }
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
    binarysearch_2(data, 7);
    return 0;
}
