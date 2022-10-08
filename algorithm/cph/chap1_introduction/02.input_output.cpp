#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    // associates standard input with input.txt
    freopen("input.txt", "r", stdin);
    // associates standard output with output.txt
    // (this will create a new file called output.txt if none exists)
    freopen("output.txt", "w", stdout);
    string s;
    // read the input.txt and stores in string s
    while(getline(cin, s))
    {
        // prints string s to output.txt file
        cout << s << endl;
    }

    return 0;
}
