class Combinatz
{
private:
    long long n, mod;
    vector <long long> inv;
    vector <long long> fact;
    vector <long long> invfact;

public:
    Combinatz (long long n, long long mod)
    {
        this -> n = n;
        this -> mod = mod;
        inv.assign(n + 1, 1);
        fact.assign(n + 1, 1);
        invfact.assign(n + 1, 1);

        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % mod;

        invfact[n] = Power(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; --i)
            invfact[i] = invfact[i + 1] * (i + 1) % mod; 

        for (int i = 1; i <= n; ++i)
            inv[i] = fact[i - 1] * invfact[i] % mod;
    }

    long long Power (long long a, long long b)
    {
        ll ans = 1;
        while (b) 
        {
            if(b & 1)
                ans = (ans * a) % mod;
            b >>= 1ll;
            a = (a * a) % mod;
        }
        return ans;
    }   

    long long Ncr (long n, long r)
    {
        if (n < 0 || r > n)
            return 0ll;

        return fact[n] * invfact[r] % mod * invfact[n - r] % mod; 
    }

    long long Get (long long i, int id)
    {
        if (id == 1)
            return inv[i];
        if (id == 2)
            return fact[i];
        if (id == 3)
            return invfact[i];
    }
};
