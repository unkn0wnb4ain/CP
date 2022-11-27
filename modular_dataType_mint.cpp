const uint p = 1000000007;

template<uint mod = p> struct mint 
{ 
    uint val = 0;

    mint(ll val) 
    {
        val %= mod;
        if (val < 0) 
            val += mod;
        this -> val = val;
    }

    mint& operator += (const mint &a) 
    {
        val += a.val;
        if (val >= mod)
            val -= mod;
        return *this;
    }

    mint& operator -= (const mint &a) 
    {
        val += mod - a.val;
        if (val >= mod)
            val -= mod;
        return *this;
    }

    mint& operator *= (const mint &a) 
    {
        val = (ull)val * a.val % mod;
        return *this;
    }

    mint pow(ll pw) const 
    {
        mint res = 1;
        mint cur = *this;
        while(pw) 
        {
            if (pw & 1) 
                res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }

    mint inv() const 
    {
        //val != 0
        uint t = val;
        uint res = 1;
        while(t != 1) 
        {
            uint z = mod / t;
            res = (ull)res * (mod - z) % mod;
            t = mod - t * z;
        }
        return res;
    }

    mint& operator /= (const mint &a) 
    {
        return *this *= a.inv();
    }

    mint operator + (const mint &a) const 
    {
        return mint(*this) += a;
    }

    mint operator - (const mint &a) const 
    {
        return mint(*this) -= a;
    }

    mint operator * (const mint &a) const 
    {
        return mint(*this) *= a;
    }

    mint operator / (const mint &a) const 
    {
        return mint(*this) /= a;
    }

    bool operator == (const mint &a) const 
    {
        return val == a.val;
    }

    bool operator != (const mint &a) const 
    {
        return val != a.val;
    }

    bool operator < (const mint &a) const 
    {
        return val < a.val;
    }

    friend ostream& operator << (ostream &os, const mint &m) 
    {
        os << m.val;
        return os;
    }
};

using Mint = mint <p>;
