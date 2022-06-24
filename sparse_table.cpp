template <typename T>
struct SparseTable
{
    ll n, m;
    vector <vector <T> > st;

    SparseTable(ll nn, ll mm)
    {
        n = nn; m = mm;
        st.assign(n + 1, vector <T> (m, 0));
    }

    inline T Function(T &x, T &y)
    {
        return min(x, y);
    }

    void Build(ll a[], ll n, string op)
    {
        for(ll i = 0; i < n; ++i)
            st[i][0] = a[i];

        for(ll k = 1; k < m; ++k)
            for(ll i = 0; i + (1 << k) - 1 < n; ++i)
                st[i][k] = Function(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
    }

    T Query(ll l, ll r, string op)
    {
        ll len = r - l + 1;
        ll log = 0;
        while((1 << (log + 1)) <= len)
            log++;

        return Function(st[l][log], st[r - (1 << log) + 1][log]);
    }
};
