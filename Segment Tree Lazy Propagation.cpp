#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Node {
    T sum, prop;
    Node() : sum(0), prop(0) {}
    Node(T _sum, T _prop) : sum(_sum), prop(_prop) {}
};

template<typename T, typename U> class SegmentTree {

private:
    vector<T>& a;
    vector<Node<U>> st;
    int n;
public:

    SegmentTree(int _n) : n(_n) {
        st.resize(4 * n);
    }
    SegmentTree(vector<T>& _a) : a(_a) {
        n = (int) a.size();
        st.resize(4 * n);
        build(0, n - 1, 1);
    }

    void build(int l, int r, int idx) {
        if(l == r) {
            st[idx].sum = a[l];
        }
        else {
            build(l, (l + r) / 2, idx << 1);
            build((l + r) / 2 + 1, r, (idx << 1) + 1);
            st[idx].sum = st[(idx << 1)].sum + st[(idx << 1) + 1].sum;
        }
    }

    void update(int i, int j, T val) {
        update(i, j, 0, n - 1, val, 1);
    }
    void update(int i, int j, int l, int r, T val, int idx) {

        if(i > r || j < l) {
            return;
        }
        if(l >= i && r <= j) {
            st[idx].sum += (long long) (r - l + 1) * val;
            st[idx].prop += val;
            return;
        }

        update(i, j, l, (l + r) / 2, val, idx << 1);
        update(i, j, (l + r) / 2 + 1, r, val, (idx << 1) + 1);

        st[idx].sum = st[idx << 1].sum + st[(idx << 1) + 1].sum + (U) (r - l + 1) * st[idx].prop;
    }

    U get(int i, int j) {
        return get(i, j, 0, n - 1, 1, 0);
    }
    U get(int i, int j, int l, int r, int idx, long long carry) {

        if(i > r || j < l) {
            return 0;
        }
        if(l >= i && r <= j) {
            return st[idx].sum + carry * (r - l + 1);
        }

        return get(i, j, l, (l + r) / 2, idx << 1, carry + st[idx].prop) + get(i, j, (l + r) / 2 + 1, r, (idx << 1) + 1, carry + st[idx].prop);
    }
};

int main() {
    //            0  1  2  3   4  5
    vector<int> a{1, 5, 2, 9, 8, 6};

    SegmentTree<int, long long> st(a);

    while(true) {

        int type;
        cin >> type;

        if(type == 1) {
            // get

            int l, r;
            cin >> l >> r;

            cout << st.get(l, r) << '\n';
        }
        else if(type == 2) {
            // update

            int l, r, val;
            cin >> l >> r >> val;

            st.update(l, r, val);
        }
        else break;
    }
}




























