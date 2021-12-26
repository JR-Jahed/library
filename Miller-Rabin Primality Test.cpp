#include <bits/stdc++.h>
using namespace std;

long long power(long long b, long long p, long long mod) {

    long long ans = 1;
    b %= mod;

    while(p > 0) {
        if(p & 1) {
            ans = (__int128) ans * b % mod;
        }
        p >>= 1;
        b = (__int128) b * b % mod;
    }
    return ans;
}

bool check_composite(long long n, long long a, long long d, int s) {

    long long x = power(a, d, n);

    if(x == 1 || x == n - 1) return false;

    for(int r = 1; r < s; r++) {
        x = (__int128) x * x % n;
        if(x == n - 1) {
            return false;
        }
    }

    return true;
}

bool isPrime(long long n, long long k) {

    if(n <= 4) return n == 2 || n == 3;

    int s = 0;
    long long d = n - 1;

    while(d % 2 == 0) {
        d >>= 1;
        s++;
    }

    for(int i = 1; i <= k; ++i) {
        long long a = 2 + rand() % (n - 3);

        if(check_composite(n, a, d, s)) {
            return false;
        }
    }
    return true;
}

int main() {

    long long n, k = 5;

    while(scanf("%lld", &n), n) {
        printf("%d\n", isPrime(n, k));
    }
}
//489133282872437279


























