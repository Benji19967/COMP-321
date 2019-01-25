#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
  int n;
  while(scanf("%d", &n) == 1) {

    int N = n;
    bool isSt = 1, isQ = 1, isPq = 1; // Flags

    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    while(N--){
      int a, b;
      scanf("%d %d", &a, &b);

      if(a == 1) {              // Add 
        if(isSt) s.push(b);
        if(isQ) q.push(b);
        if(isPq) pq.push(b);
      }
      if(a == 2) {              // Pop
        if(s.empty() || s.top() != b) {
          isSt = 0;
        } else s.pop();
        if(q.empty() || q.front() != b) {
          isQ = 0;
        } else q.pop();
        if(pq.empty() || pq.top() != b) {
          isPq = 0;
        } else pq.pop();
      }
    }
    if(isSt == 1 && isQ == 0 && isPq == 0) cout << "stack" << endl;
    else if(isSt == 0 && isQ == 1 && isPq == 0) cout << "queue" << endl;
    else if(isSt == 0 && isQ == 0 && isPq == 1) cout << "priority queue" << endl;
    else if(isSt == 0 && isQ == 0 && isPq == 0) cout << "impossible" << endl;
    else cout << "not sure" << endl;
  }
    return 0;
}
