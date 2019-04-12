// Finding the prime factors of a number and summing them up. Repeat until sum is a prime.

#include <iostream> 
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(int n) {

    if(n == 2) {
        return true;
    }
    if(n % 2 == 0) {
        return false;
    }

    int root = (int)sqrt(n);

    for(int i = 3; i <= root; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}


void reduce(int prime, int count) {

    count++;
    if(isPrime(prime)) {
        cout << prime << " " << count << endl;
        return;
    }

    int sum = 0;
    int i = 2;

    while(true) {
     
        if(prime % i == 0) {
            prime /= i;
            sum += i;

            if(isPrime(prime)) {
                sum += prime;
                break;
            }

            i = 1;
        }
        i++;
    }
    reduce(sum , count);
}


int main() {

    int n;

    while(cin >> n) {
        if(n == 4) break;

        reduce(n, 0);

    }

    return 0;
}