// https://open.kattis.com/problems/walls

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

double distance(double x_cr, double y_cr, double x_w, double y_w) { 
    return sqrt(pow(x_cr - x_w, 2.0) + pow(y_cr - y_w, 2.0));
}

bool reachable(int cr, int w, double r, double (&locs)[30][2], double (&walls)[4][2]) {
    if(r - distance(locs[cr][0], locs[cr][1], walls[w][0], walls[w][1]) >= 0) {
        return true;
    } 
    return false;
}

int main() {
    int n;
    double l, w, r;
    cin >> l >> w >> n >> r;

    double walls[4][2] = {{-l/2, 0}, {l/2, 0}, {0, -w/2}, {0, w/2}};
    double locs[30][2] = {0}; 
    vector<int> reaches[30];        // which walls can a crane reach

    for(int i = 0; i < n; i++) {
        cin >> locs[i][0] >> locs[i][1];
    }

    int reachable_walls[4] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            if(reachable(i, j, r, locs, walls)) {
                reaches[i].push_back(j);  // crane i can reach wall j
                reachable_walls[j] = 1;
            }
        }
    }

    if(count(reachable_walls, reachable_walls + 4, 1) != 4) { // not all walls reachable
        cout << "Impossible" << endl;
        return 0;
    }

    set<int> temp;
    int ans = 4;
    for(int i = 0; i < n; i++) {        // test all combinations of cranes up until a max of 4.
        if(reaches[i].size() == 4) {
            cout << 1 << endl;
            return 0;
        }
        for(int j = i + 1; j < n; j++) {
            temp.clear();
            for(int wl : reaches[i]) temp.insert(wl);
            for(int wl : reaches[j]) temp.insert(wl);
            if(temp.size() == 4) ans = min(ans, 2);

            for(int k = j + 1; k < n; k++) {
                temp.clear();
                for(int wl : reaches[i]) temp.insert(wl);
                for(int wl : reaches[j]) temp.insert(wl);
                for(int wl : reaches[k]) temp.insert(wl);
                if(temp.size() == 4) ans = min(ans, 3);
            }
        }
    }
    cout << ans << endl;
}