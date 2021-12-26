#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U> class SegmentSum {
private:
    vector<T>& a;
    vector<U> st;
    int n;

public:
    SegmentSum(int _n) : n(_n) {
        st.resize(4 * n);
    }
    SegmentSum(vector<T> &_a) : a(_a) {
        n = (int) a.size();
        st.resize(4 * n);
        build(0, n - 1, 1);
    }

    void build(int l, int r, int idx) {
        if(l == r) {
            st[idx] = a[l];
        }
        else {
            build(l, (l + r) / 2, idx << 1);
            build((l + r) / 2 + 1, r, (idx << 1) + 1);

            st[idx] = st[idx << 1] + st[(idx << 1) + 1];
        }
    }

    U get(int l, int r, int i, int j, int idx) {
        if(i > r || j < l) {
            return 0;
        }
        if(l >= i && r <= j) {
            return st[idx];
        }

        return get(l, (l + r) / 2, i, j, idx << 1) + get((l + r) / 2 + 1, r, i, j, (idx << 1) + 1);
    }
    U get(int i, int j) {
        return get(0, n - 1, i, j, 1);
    }

    U update(int l, int r, int i, int idx) {
        if(i > r || i < l) {
            return st[idx];
        }
        if(i == l && i == r) {
            return st[idx] = a[i];
        }
        return st[idx] = update(l, (l + r) / 2, i, idx << 1) + update((l + r) / 2 + 1, r, i, (idx << 1) + 1);
    }
    void update(int i) {
        update(0, n - 1, i, 1);
    }
};

int main() {
//                0  1  2  3  4  5  6  7  8  9  10
    vector<int> a{1, 2, 3, 3, 3, 4, 4, 3, 4, 2, 1};

    SegmentSum<int, long long> st(a);

    while(true) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%lld\n", st.get(l, r));
    }



}




























