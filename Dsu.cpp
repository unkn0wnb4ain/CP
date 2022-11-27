class Dsu
{

private:
    int n;
    vector <int> parr;
    vector <int> size;

public:
    Dsu(int n)
    {
        this -> n = n;
        parr.assign(n + 1, 0);
        size.assign(n + 1, 0);
    }

    void Build()
    {
        for(int i = 0; i <= n; ++i)
        {
            parr[i] = i;
            size[i] = 1;
        }
    }

    int Find(int a)
    {
        if(parr[a] == a)
            return a;

        parr[a] = Find(parr[a]);
        return parr[a];
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if(a != b)
        {
            if(size[a] < size[b])
                swap(a, b);

            parr[b] = a;
            size[a] += size[b];
        }    
    }

    int Components()
    {
        int comps = 0;

        for(int i = 1; i <= n; ++i)
            comps += parr[i] == i;

        return comps;
    }

};
