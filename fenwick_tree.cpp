template <class T>
class FenwickTree
{
    
private:
    ll n;
    vector <T> fen;

public:
    FenwickTree (ll nn)
    {
        n = nn;
        fen.assign(n + 1, 0);
    }

    void Update (ll id, ll del)
    {    
        while(id < fen.size())
        {
            fen[id] += del;
            id += (id & -id);
        }     
    }

    void Build (ll a[], ll n)
    {
        for (int i = 1; i < n + 1; ++i)
        {
            Update(i, a[i - 1]);
        }
    }    

    T PrefixSum (ll id)
    {
        ll sum = 0;
        while(id)
        {
            sum += fen[id];
            id -= (id & -id);
        }
        return sum;
    }

    T Query (ll l, ll r)
    {
        return PrefixSum(r) - PrefixSum(l - 1);
    }
};
