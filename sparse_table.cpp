template <typename T>
struct SparseTable
{
    ll n, m;
    vector <int> lg;
    vector <vector <T>> st;

    SparseTable(vector <T> &a)
    {
        n = a.size();

        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;

        m = lg[n] + 1;
        st.assign(n + 1, vector <T> (m, 0));

        for(ll i = 0; i < n; ++i)
            st[i][0] = a[i];

        for(ll k = 1; k < m; ++k)
            for(ll i = 0; i + (1 << k) - 1 < n; ++i)
                st[i][k] = func(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
    }

    T func(T &x, T &y)
    {
        return min(x, y);
    }

    T Query(ll l, ll r)
    {
        l--; r--;
        ll log = lg[r - l + 1];
        return func(st[l][log], st[r - (1 << log) + 1][log]);
    }
};
