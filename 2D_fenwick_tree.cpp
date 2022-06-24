template <class T>
class FenwickTree
{

private:
    ll n, m;
    vector <vector <T> > fen;

public:
    FenwickTree(ll nn, ll mm)
    {
        n = nn; m = mm;
        fen.assign(n + 1, vector <T> (m + 1, 0));
    }

    void update(ll x, ll y, ll val)
    {
        for(ll i = x; i < fen.size(); i += (i & -i))
        for(ll j = y; j < fen[0].size(); j += (j & -j))
            fen[i][j] += val;
    }

    void build(vector <vector <T> > &a)
    {
        for(ll i = 1; i < fen.size(); ++i)
        for(ll j = 1; j < fen[0].size(); ++j)
            update(i, j, a[i - 1][j - 1]);
    }

    T sum(ll x, ll y)
    {
        ll res = 0;

        for(ll i = x; i > 0; i -= (i & -i))
            for(ll j = y; j > 0; j -= (j & -j))
                res += fen[i][j];

        return res;
    }

    T query(ll x1, ll y1, ll x2, ll y2)
    {
        ll increment1 = sum(x2, y2);
        ll increment2 = sum(x1 - 1, y1 - 1);
        ll decrement1 = sum(x1 - 1, y2);
        ll decrement2 = sum(x2, y1 - 1);

        return increment1 + increment2 - decrement1 - decrement2;
    }

};
