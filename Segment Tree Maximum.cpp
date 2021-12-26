#include <bits/stdc++.h>
using namespace std;

template<typename T> class SegmentMax {
private:
    int n;
    vector<int> st;
    vector<T>& a;

public:
    SegmentMax(vector<T>& _a) : a(_a) {
        n = (int) a.size();
        st.resize(4 * n);
        build(0, n - 1, 1);
    }

    void build(int l, int r, int idx) {
        if(l == r) {
            st[idx] = l;
        }
        else {
            build(l, (l + r) / 2, idx << 1);
            build((l + r) / 2 + 1, r, (idx << 1) + 1);

            st[idx] = a[st[idx << 1]] > a[st[(idx << 1) + 1]] ? st[idx << 1] : st[(idx << 1) + 1];
        }
    }

    int get(int l, int r, int i, int j, int idx) {

        if(i > r || j < l) {
            return -1;
        }

        if(l >= i && r <= j) {
            return st[idx];
        }

        int x = get(l, (l + r) / 2, i, j, idx << 1);
        int y = get((l + r) / 2 + 1, r, i, j, (idx << 1) + 1);

        if(x == -1) {
            return y;
        }
        if(y == -1) {
            return x;
        }

        return a[x] > a[y] ? x : y;
    }
    int get(int i, int j) {
        return get(0, n - 1, i, j, 1);
    }

    int update(int l, int r, int i, int idx) {
        if(i > r || i < l) {
            return st[idx];
        }
        if(i == l && i == r) {
            return st[idx] = i;
        }
        int x = update(l, (l + r) / 2, i, idx << 1);
        int y = update((l + r) / 2 + 1, r, i, (idx << 1) + 1);

        if(x == -1) {
            return st[idx] = y;
        }
        if(y == -1) {
            return st[idx] = x;
        }

        return st[idx] = a[x] > a[y] ? x : y;
    }
    void update(int i) {
        update(0, n - 1, i, 1);
    }
};

int main() {






//                0  1  2  3  4  5  6  7  8  9  10
    //vector<int> a{1, 2, 3, 3, 3, 4, 4, 3, 4, 2, 1};
    vector<int> a{2, 1, 3};

    SegmentMax<int> st(a);

    while(true) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", st.get(l, r));
    }

}





























