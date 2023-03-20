template<typename T>
class SegmentTree 
{
private:
    int n;
    vector <T> tree, lazy;

    void build (int v, int st, int en, const vector<T>& a) 
    {
        if (st == en) 
            tree[v] = a[st]; 
        else 
        {
            int mid = (st + en) / 2;
            build (v << 1, st, mid, a);
            build (v << 1 | 1, mid + 1, en, a);
            tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
        }
    }

    void propagate(int v, int st, int en) 
    {
        if (lazy[v] != 0) 
        {
            tree[v] += lazy[v] * (en - st + 1);
            if (st != en) 
            {
                lazy[v << 1] += lazy[v];
                lazy[v << 1 | 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void update (int v, int st, int en, int l, int r, T val) 
    {
        propagate (v, st, en);
        if (r < st || en < l) 
            return;

        if (l <= st && en <= r) 
        {
            lazy[v] += val;
            propagate (v, st, en);
        }
        else 
        {
            int mid = (st + en) / 2;
            update (v << 1, st, mid, l, r, val);
            update (v << 1 | 1, mid + 1, en, l, r, val);
            tree[v] = merge (tree[v << 1], tree[v << 1 | 1]);
        }
    }

    T query (int v, int st, int en, int l, int r) 
    {
        propagate (v, st, en);
        if (r < st || en < l) 
            return T(0); 

        if (l <= st && en <= r) 
            return tree[v];

        int mid = (st + en) / 2;
        T lefft = query(v << 1, st, mid, l, r);
        T right = query(v << 1 | 1, mid + 1, en, l, r);
        return merge (lefft, right);
    }

    T merge (T x, T y) const {
        return (x + y); 
    }

public:
    SegmentTree() = default;
    explicit SegmentTree (const vector<T>& a)
    {
        n = a.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void update (int l, int r, T val) 
    {
        update(1, 0, n - 1, l, r, val);
    }

    T query (int l, int r) 
    {
        return query(1, 0, n - 1, l, r);
    }
};
