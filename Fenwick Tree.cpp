#include <bits/stdc++.h>
using namespace std;

template<typename T> class Fenwick {
private:
    int n;
    vector<T> fen;
public:
    Fenwick(int _n) : n(_n) {
        fen.resize(n);
    };
    template<typename U> Fenwick(vector<U>& a) {
        n = (int) a.size();
        fen.resize(n);
        build(a);
    }
    template<typename U> void build(vector<U>& a) {
        for(int i = 0; i < n; i++) {
            fen[i] += a[i];

            int j = (i & (i + 1)) - 1;
            if(j < n) {
                fen[j] += fen[i];
            }
        }
    }
    template<typename U> void update(int i, U v) {
        while(i < n) {
            fen[i] += v;
            i |= (i + 1);
        }
    }
    T get(int i) {
        T sum = 0;

        while(i >= 0) {
            sum += fen[i];
            i = (i & (i + 1)) - 1;
        }
        return sum;
    }
    T get(int i, int j) {
        return get(j) - get(i - 1);
    }
    template<typename U> void range_update(int i, int j, U v) {
        update(i, v);
        update(j + 1, -v);
    }
};

int main() {

    vector<int> a = {0,0,1,0,1,2,3,2,1,1,0};
    Fenwick<int> ft(a);

    while(true) {

        int l, r;
        cin >> l >> r;

        printf("%d\n", ft.get(l, r));
    }
}


























