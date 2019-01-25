// https://open.kattis.com/problems/sortofsorting

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string a, string b) {                  // Only compare first 2 letters when sorting
    return a.substr(0, 2) < b.substr(0, 2);
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        string arr[200] = {};
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        stable_sort(arr, arr + n, cmp);
        for(int i = 0; i < n; i++) {
            cout << arr[i] << endl;
        }
    }
    return 0;
}

