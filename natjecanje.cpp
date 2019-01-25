// https://open.kattis.com/problems/natjecanje

#include <iostream>
using namespace std;

int main() {
    int n, s, r; // kayaks, damaged, reserves
    int kay[10] = {};
    int count = 0;
    scanf("%d %d %d", &n, &s, &r);
    
    for(int i = 0; i < s; i++) {        // indicate damaged kayaks
        int idx_dmg;
        cin >> idx_dmg;
        kay[idx_dmg - 1] = 1;
    }

    for(int i = 0; i < r; i++) {        // indicate reserve kayaks
        int idx_res;
        cin >> idx_res;
        if(kay[idx_res - 1] == 1) kay[idx_res - 1] = 0;
        else kay[idx_res - 1] = 2;
    }

    for(int i = 0; i < n; i++) {        // Check if neighbour teams have reserve kayak
        if(i == 0 && kay[i] == 1) {
            if(kay[i+1] == 2) {
                kay[i] = 0;
                kay[i+1] = 0;
            } 
        } 
        else if(i == n - 1 && kay[i] == 1) {
            if(kay[i-1] == 2) {
                kay[i] = 0;
                kay[i-1] = 0;
            } 
        }
        else if(kay[i] == 1 && kay[i-1] == 2) {
            kay[i] = 0;
            kay[i-1] = 0;
        }
        else if(kay[i] == 1 && kay[i+1] == 2) {
            kay[i] = 0;
            kay[i+1] = 0;
        }
    }
    for(int i = 0; i < n; i++) {        // Count damaged and unreplaced kayaks
        if(kay[i] == 1) count++;
    }
    cout << count;
    return 0;
}