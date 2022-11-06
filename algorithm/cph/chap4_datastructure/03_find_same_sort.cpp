#include <bits/stdc++.h>

using namespace std;

int M;
int N;

vector<int> s1;
vector<int> s2;

void input()
{
    int tmp;
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        s1.push_back(tmp);
    }

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        s2.push_back(tmp);
    }
}

void check_same()
{
    int count = 0;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(int i=0; i<s1.size(); i++) {
        for (int j=i; j<s2.size(); j++) {
            if(s1[i] <= s2[j]) {
                while(s1[i] <= s2[j] && i<s1.size()) {
                    i++;
                }
                cout << "i: " << i << " j: " << j << endl;
                cout << "s1[i-1]: " << s1[i-1] << "s2[j]: " << s2[j] << endl;
                if(s1[i-1] == s2[j]) {
                    count++;
                }
            } else {
                while(s1[i] > s2[j] && j<s2.size()) {
                    j++;
                }
                cout << "i: " << i << " j: " << j << endl;
                cout << "s1[i]: " << s1[i] << "s2[j-1]: " << s2[j-1] << endl;
                if(s1[i] == s2[j-1]) {
                    count++;
                }
            }
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
