// https://open.kattis.com/problems/orders

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void eval(int total, vector<int> costs, vector<int> &dp) {
    vector<int> res;
    
    if(dp[total] == -2) {
        cout << "Impossible" << endl;
        return;
    }

    if(dp[total] == -1) {
        cout << "Ambiguous" << endl;
        return;
    }

    while(total > 0) {
        res.push_back(dp[total]+1);
        total -= costs[dp[total]];
    }
    
    sort(res.begin(), res.end());
    for(int i : res) {
        cout << i << " ";
    }
    cout << endl;
}

int main() { 

    vector<int> dp(31001, -2);
    dp[0] = 0;

    int n;
    cin >> n;
    vector<int> costs(n);
    for(int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    for(int i = 0; i < n; i++) { // Fill dp table. Keep track of last item. -2: "Impossible", -1: "Ambiguous".
        int cost = costs[i];
        for(int j = 0; j <= 30000; j++) {
            if(dp[j] >= 0) {
                if(dp[j+cost] == -2) {
                    dp[j+cost] = i;
                } 
                else {
                    dp[j+cost] = -1;
                }
            }
            if(dp[j] == -1) {
                dp[j+cost] = -1;
            }
        }
    }

    int o;
    cin >> o;

    for(int i = 0; i < o; i++) { // Evaluate the orders
        int order;
        cin >> order;
    
        eval(order, costs, dp);
    }
}