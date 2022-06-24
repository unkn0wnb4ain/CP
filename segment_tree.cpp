template <class T>
class SegmentTree
{

private:
    ll n;
    const ll k = 0;
    vector <T> tree;
    vector <T> v;

public:
    SegmentTree(vector <T> &arr)
    {
        n = (ll)arr.size();
        v = arr;
        tree.assign(4 * n, 0);
        Build(1, 0, n - 1);
    }

    inline T Function(ll x, ll y)
    {
        return x + y;
    }

    void Build(ll node, ll start, ll end)
    {
        if(start == end)
            tree[node] = start;

        else
        {
            ll mid = (start + end) / 2;
            ll left = 2 * node;
            ll right = 2 * node + 1;

            Build(left, start, mid);
            Build(right, mid + 1, end);

            tree[node] = Function(tree[left], tree[right]);
        }
    }

    T Get_query(ll node, ll start, ll end, ll l, ll r)
    {
        if(start > r || end < l)
            return k;

        if(l <= start && end <= r)
            return tree[node];

        ll mid = (start + end) / 2;
        ll left_query = Get_query(2 * node, start, mid, l, r);
        ll right_query = Get_query(2 * node + 1, mid + 1, end, l, r);

        return Function(left_query, right_query);
    }    

    T query(ll l, ll r)
    {
        return Get_query(1, 0, n - 1, l, r);
    }

    void Get_update(ll node, ll start, ll end, ll pos, T val)
    {
        if(start == end)
            v[start] = val,
            tree[node] = val;

        else
        {
            ll mid = (start + end) / 2;
            if(start <= pos && pos <= mid)
                Get_update(2 * node, start, mid, pos, val);
            else
                Get_update(2 * node + 1, mid + 1, end, pos, val);

            tree[node] = Function(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(ll pos, T val)
    {
        Get_update(1, 0, n - 1, pos, val);
    }

};
