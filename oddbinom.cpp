// Theorem: The number of odd entries in row N of Pascal's Triangle is 2 raised to the number of 1's in the binary expansion of N.
// Example: Since 83 = 64 + 16 + 2 + 1 has binary expansion (1010011), then row 83 has 24 = 16 odd numbers.
// ^ Starting at row 0.

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

int one_bits(ull n) // Hamming Weight
{
    n -= (n >> 1) & 0x5555555555555555;
    n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
    n = (n + (n >> 4)) & 0x0f0f0f0f0f0f0f0f;
    return (int)((n * 0x0101010101010101) >> 56);
}

ull odd_binomials(ull n) { 
    if(n < 2) return n;
    else {
        ull x = 0;
        if(n % 2 == 1) {
            x = pow(2, one_bits(n-1));
        }
        return x + 3 * odd_binomials(n >> 1);
    }
}

int main() {
    ull n;

    cin >> n;
    cout << odd_binomials(n);
}

/* To help understand x + 3 * odd_binomials(n >> 1). Note that the number of ones is always one more on the right in the numbers below. 
Hence we have x + 2*x as the total number of ones. If the number is odd, we just add the number of ones in that row to the total.

odd_binomials(8) or odd_binomials(9)
one_bits(n-1):
1:0     5:100
2:1     6:101
3:10    7:110
4:11    8:111
9:1000 // note once we n >> 1, we get odd_binomials(8).

odd_binomials(10)
1:0     5:100 9:1000 10:1001
2:1     6:101
3:10    7:110
4:11    8:111
  
*/
