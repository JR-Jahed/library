#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct Matrix {

    int n, m;
    vector<vector<long long>> a;

    Matrix() : n(2), m(2) {
        a = vector<vector<long long>>(2, vector<long long>(2));
    }
    Matrix(int _n, int _m) : n(_n), m(_m) {
        a = vector<vector<long long>>(n, vector<long long>(m));
    }
    Matrix(vector<vector<long long>> _a) : a(_a) {
        n = (int) a.size();
        if(!a.empty()) {
            m = (int) a[0].size();
        }
    }

    inline void make_unit() {

        assert(n == m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = i == j;
            }
        }
    }

    inline Matrix operator+ (const Matrix& other) {
        assert(n == other.n && m == other.m);

        Matrix ans(n, m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans.a[i][j] = (a[i][j] + other.a[i][j]) % mod;
            }
        }
        return ans;
    }
    inline Matrix operator- (const Matrix& other) {
        assert(n == other.n && m == other.m);

        Matrix ans(n, m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans.a[i][j] = (a[i][j] - other.a[i][j]) % mod;
            }
        }
        return ans;
    }
    inline Matrix operator* (const Matrix& other) {
        assert(m == other.n);

        Matrix ans(n, other.m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < other.m; j++) {
                for(int k = 0; k < m; k++) {
                    ans.a[i][j] = (ans.a[i][j] + a[i][k] * other.a[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
    inline Matrix power(long long k) {

        assert(n == m);

        Matrix ans(n, n);
        Matrix b(this->a);
        ans.make_unit();

        while(k > 0) {
            if(k & 1) {
                ans = ans * b;
            }
            b = b * b;
            k >>= 1;
        }
        return ans;
    }

    inline Matrix& operator += (const Matrix& other) {return *this = (*this) + other;}
    inline Matrix& operator -= (const Matrix& other) {return *this = (*this) - other;}
    inline Matrix& operator *= (const Matrix& other) {return *this = (*this) * other;}
    inline bool operator == (const Matrix& other) {return a == other.a;}
    inline bool operator != (const Matrix& other) {return a != other.a;}
};

ostream& operator<< (ostream& os, Matrix& a) {

    for(int i = 0; i < a.n; i++) {
        for(int j = 0; j < a.m; j++) {
            os << a.a[i][j] << "  ";
        }
        os << '\n';
    }
    return os;
}

int main() {

    Matrix a;
    a.a[0][0] = a.a[0][1] = 2;
    a.a[1][0] = a.a[1][1] = 3;

    Matrix b = a.power(2);

    /*for(int i = 0; i < a.n; i++) {
        for(int j = 0; j < a.m; j++) {
            printf("%5lld  ", b.a[i][j]);
        }
        puts("");
    }*/

    cout << b;
}































