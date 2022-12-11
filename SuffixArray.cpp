class SuffixArray
{
private:
    int n;
    string s;
    vector <int> rank;

    vector <int> Sort_cyclic_shifts(string const& s) 
    {
        this -> n = s.size();
        const int alphabet = 256;
        vector <int> p(n), c(n), cnt(max(alphabet, n), 0);
        
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++)
            cnt[i] += cnt[i-1];
        for (int i = 0; i < n; i++)
            p[--cnt[s[i]]] = i;

        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[p[i]] != s[p[i-1]])
                classes++;
            c[p[i]] = classes - 1;
        }

        vector <int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) 
        {
            for (int i = 0; i < n; i++) 
            {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)
                    pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++)
                cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i-1];
            for (int i = n-1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];

            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) 
            {
                pair <int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair <int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
                if (cur != prev)
                    ++classes;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
        return p;
    }

    vector <int> Lcp_Build(string const& s, vector<int> const& p) 
    {
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            rank[p[i]] = i;

        int k = 0;
        lcp.assign(n - 1, 0);
        for (int i = 0; i < n; i++) 
        {
            if (rank[i] == n - 1) 
            {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[rank[i]] = k;
            if (k)
                k--;
        }
        return lcp;
    }

public:
    vector <int> lcp;
    vector <int> sorted_shifts;

    SuffixArray (string s) 
    {   
        s += "$";
        this -> s = s;
        sorted_shifts = Sort_cyclic_shifts(s);
        sorted_shifts.erase(sorted_shifts.begin());
        Lcp_Build(s, sorted_shifts);
    }
};
