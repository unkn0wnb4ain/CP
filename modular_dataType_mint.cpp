template <int64_t MOD = 1000000007>
class ModInt {
private:
    int64_t val;

    int64_t normalize(int64_t val) 
    {
        val %= MOD;
        if (val < 0) val += MOD;
        return val;
    }

public:

    ModInt () : val(0) {}
    ModInt (int64_t v) { val = normalize(v); }

    ModInt& operator ++ () 
    { 
        return *this += 1; 
    }

    ModInt& operator -- () 
    { 
        return *this -= 1; 
    }

    ModInt  operator ++ (int) 
    { 
        ModInt res(*this); 
        ++(*this); return res; 
    }

    ModInt  operator -- (int) 
    { 
        ModInt res(*this); 
        --(*this); return res; 
    }

    ModInt  operator + () const 
    { 
        return ModInt(val); 
    }

    ModInt  operator - () const 
    { 
        return ModInt(MOD - val); 
    }

    ModInt& operator += (const ModInt& rhs) 
    {
        val = normalize(val + rhs.val);
        return *this;
    }

    ModInt& operator -= (const ModInt& rhs) 
    {
        val = normalize(val - rhs.val + MOD);
        return *this;
    }

    ModInt& operator *= (const ModInt& rhs) 
    {
        val = val * rhs.val % MOD;
        return *this;
    }

    ModInt& operator /= (const ModInt& rhs) 
    {
        val = val * rhs.inv();
        return *this;
    }

    ModInt operator + (const ModInt& rhs) const 
    { 
        return ModInt(*this) += rhs; 
    }

    ModInt operator - (const ModInt& rhs) const 
    { 
        return ModInt(*this) -= rhs; 
    }

    ModInt operator * (const ModInt& rhs) const 
    { 
        return ModInt(*this) *= rhs; 
    }

    ModInt operator / (const ModInt& rhs) const 
    { 
        return ModInt(*this) /= rhs; 
    }

    ModInt inv() const 
    {
        assert (val != 0); 
        return power(MOD - 2); 
    }

    ModInt power(int64_t p) const 
    {
        ModInt res = 1, x = val;
        while (p > 0) 
        {
            if (p & 1) res *= x;
            x *= x; p >>= 1;
        }
        return res;
    }

    friend istream& operator >> (istream& is, ModInt& rhs) 
    {
        is >> rhs.val;
        return is;
    }

    friend ostream& operator << (ostream& os, const ModInt& rhs) 
    {
        return os << rhs.val;
    }

    friend bool operator > (const ModInt& lhs, const ModInt& rhs) 
    {
        return lhs.val > rhs.val;
    }

    friend bool operator < (const ModInt& lhs, const ModInt& rhs) 
    {
        return lhs.val < rhs.val;
    }

    friend bool operator == (const ModInt& lhs, const ModInt& rhs)  
    {
        return lhs.val == rhs.val;
    }

    friend bool operator != (const ModInt& lhs, const ModInt& rhs) 
    {
        return !(lhs == rhs);
    }

    friend bool operator <= (const ModInt& lhs, const ModInt& rhs) 
    {
        return lhs.val <= rhs.val;
    }

    friend bool operator >= (const ModInt& lhs, const ModInt& rhs) 
    {
        return lhs.val >= rhs.val;
    }
};
