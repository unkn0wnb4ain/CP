vector <vector <ll>> mat_mult (vector <vector <ll>> &a, vector <vector <ll>> &b, ll mod)
{
    ll n = a.size();
    vector <vector <ll>> res(n, vector <ll> (n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                (res[i][j] += a[i][k] * b[k][j]) %= mod;

    return res;
}

vector <vector <ll>> mat_expo (vector <vector <ll>> &a, ll p, ll mod)
{   
    ll n = a.size();
    vector <vector <ll>> res(n, vector <ll> (n));
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;

    while (p)
    {
        if (p & 1)
            res = mat_mult(res, a, mod);
        a = mat_mult(a, a, mod);
        p >>= 1;
    }

    return res;
}
