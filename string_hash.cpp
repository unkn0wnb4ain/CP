struct SHash 
{
    string input;
    long long n, prime, mod;
    vector <long long> hash, inv, pow;

    SHash (string input, long long prime, long long mod)
    {
        n = input.length();
        this -> mod = mod;
        this -> prime = prime;
        this -> input = input;

        inv = vector <long long> (n + 1, 1);
        pow = vector <long long> (n + 1, 1);
        hash = vector <long long> (n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            pow[i] = (pow[i - 1] * prime) % mod;
            inv[i] = power(pow[i], mod - 2);
        }

        hash[0] = (input[0] - 'a' + 1);
        for (int i = 1; i < n; ++i)
            hash[i] = (hash[i - 1] + ((input[i] - 'a' + 1) * pow[i]) % mod) % mod; 
    }

    long long power (long long a, long long b)
    {
        long long ans = 1;
        while(b)
        {
            if(b & 1)
                ans = (ans * a) % mod;
            b >>= 1ll;
            a = (a * a) % mod;
        }
        return ans;
    }

    long long Substr_hash(int l, int r)
    {
        long long result = hash[r];
        if (l > 0)
            result = (result - hash[l - 1] + mod) % mod;
        result = (result * inv[l]) % mod;
        return result;
    }
};
