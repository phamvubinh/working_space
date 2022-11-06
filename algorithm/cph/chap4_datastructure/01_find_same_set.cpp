#include <bits/stdc++.h>

using namespace std;

int M;
int N;

set<int> s1;
set<int> s2;

void input()
{
    int tmp;
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        s1.insert(tmp);
    }

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        s2.insert(tmp);
    }
}

void check_same()
{
    int count = 0;
    for (auto it1: s1) {
        if(s2.count(it1)) {
            count ++;
        }
    }
    cout << "Result: " << count << endl;
}

int main()
{
    input();
    check_same();
    return 0;
}
