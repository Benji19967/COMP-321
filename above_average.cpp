#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {

    int C;
    cin >> C;

    for(int i = 0; i < C; i++) {
        int n;
        cin >> n;

        vector<int> g;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            g.push_back(x);
        }

        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += g[j];
        }

        double avg = sum / n;

        int count = 0;
        for(int j = 0; j < n; j++) {
            if(g[j] > avg) count++;
        }

        double perc = count / (double)n * 100;

        cout << std::fixed;
        cout << std::setprecision(3);
        cout << perc << "%" << endl;

    }

}