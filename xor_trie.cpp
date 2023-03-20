template<int bits>
class Trie 
{
private:
    template<int bt>
    struct node 
    {
        int cnt;
        node <bt>* bit[2];
        node(): cnt(0), bit{nullptr, nullptr} {}
    };
    node <bits>* root;
 
public:
    Trie(): root(new node <bits>()) {}
 
    void insert(ll x) 
    {
        auto curr = root;
        for (int i = bits - 1; i >= 0; --i) 
        {
            ll b = (x >> i) & 1;
            if (!curr->bit[b])
                curr->bit[b] = new node<bits>();
 
            curr = curr->bit[b];
            curr->cnt++;
        }
    }
 
    void remove(ll x) 
    {
        auto curr = root;
        for (int i = bits - 1; i >= 0; --i) 
        {
            ll b = (x >> i) & 1;
            curr = curr->bit[b];
            curr->cnt--;
        }
    }
 
    ll min_xor(ll x) const 
    {
        ll res = 0;
        auto curr = root;
        for (int i = bits - 1; i >= 0; --i) 
        {
            ll b = (x >> i) & 1;
            if (curr->bit[b] && curr->bit[b]->cnt > 0) 
                curr = curr->bit[b]; 
            else 
            {
                res |= 1ll << i;
                b ^= 1;
                curr = curr->bit[b];
            }
        }
        return res;
    }
 
    ll max_xor(ll x) const 
    {
        ll res = 0;
        auto curr = root;
        for (int i = bits - 1; i >= 0; --i) 
        {
            int b = ((x >> i) & 1) ^ 1;
            if (curr->bit[b] && curr->bit[b]->cnt > 0) 
            {
                res |= 1ll << i;
                curr = curr->bit[b];
            } 
            else
                curr = curr->bit[b ^ 1];
        }
        return res;
    }
};
