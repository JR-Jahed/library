#include <bits/stdc++.h>
using namespace std;

class Sieve {
private:

    int n;
    bitset<1000000> bs;
    vector<int> prime;

public:
    Sieve(int _n) {
        n = _n;
        sieve();
    }
    void sieve() {

        bs.set();
        bs[0] = bs[1] = 0;

        for(long long i = 2; i <= n; i++) {
            if(bs[i]) {
                for(long long j = i * i; j <= n; j += i) {
                    bs[j] = 0;
                }
                prime.push_back(i);
            }
        }
    }

    bool is_prime(long long n) {
        if(n <= this->n) {
            return bs[n];
        }
        return is_prime2(n);
    }
    bool is_prime2(long long n) {

        for(int i = 0; i < int(prime.size()) && prime[i] * prime[i] <= n; i++) {
            if(n % prime[i] == 0) {
                return false;
            }
        }
        return true;
    }

    int numPrimeDiv(long long n) {

        int i = 0, ans = 0;

        while(n > 1 && prime[i] * prime[i] <= n) {
            while(n % prime[i] == 0) {
                n /= prime[i];
                ans++;
            }
            i++;
        }
        return ans + (n > 1);
    }
    int numDiffPrimeDiv(long long n) {

        int i = 0, ans = 0;

        while(n > 1 && prime[i] * prime[i] <= n) {
            if(n % prime[i] == 0) {
                ans++;
                while(n % prime[i] == 0) {
                    n /= prime[i];
                }
            }
            i++;
        }
        return ans + (n > 1);
    }
    long long sumDiv(long long n) {

        int i = 0;
        long long ans = 0;

        while(n > 1 && prime[i] * prime[i] <= n) {
            while(n % prime[i] == 0) {
                n /= prime[i];
                ans += prime[i];
            }
            i++;
        }
        return ans + (n > 1) * n;
    }
};

int main() {

    int n = 100000;

    Sieve s(n);

    printf("%d    %d\n", s.is_prime(100000000), s.numPrimeDiv(100));
}




























