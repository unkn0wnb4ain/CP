class CDTree 
{
private:
    class Lca
    {
    private:
        int n, L = 20, timer = 0; 
        vector <int> tin, tou, dep;
        vector <vector <int>> ancs;
    
        void Build (int u, int p, vector <vector <int>> &tree)
        {
            ancs[u][0] = p;
            tin[u] = timer++;
            for (int i = 1; i < L; ++i)
                ancs[u][i] = ancs[ancs[u][i - 1]][i - 1];
            for (auto child : tree[u])
            {
                if (child ^ p)
                {
                    dep[child] = dep[u] + 1;
                    Build (child, u, tree);
                }
            }
            tou[u] = timer;
        }
    
        bool isAncestor (int u, int v)
        {
            return tin[u] <= tin[v] && tou[u] >= tou[v];
        }
    
    public:
        void init (int n, vector <vector <int>> &tree)
        {
            this -> n = n;
            tin.assign(n, 0);
            tou.assign(n, 0);
            dep.assign(n, 0);
            ancs.assign(n, vector <int> (L));
            Build (1, 1, tree);
        }
    
        int lca (int u, int v)
        {
            if (isAncestor(u, v))
                return u;
            if (isAncestor(v, u))
                return v;
    
            for (int i = L - 1; i >= 0; i--)
                if (!isAncestor(ancs[u][i], v))
                    u = ancs[u][i];
    
            return ancs[u][0];
        }
    
        int dist (int u, int v)
        {
            return dep[u] + dep[v] - 2 * dep[lca(u, v)];
        }
    };

public:
    int n;
    Lca lca;
    vector <int> par; 
    vector <int> siz; 
    vector <int> dis;
    vector <int> vis;
    vector <vector <int>> adj;

    CDTree (int n, vector <vector <int>> &adj) 
    {
        this -> n = n;
        siz.resize(n);
        lca.init(n, adj);
        this -> adj = adj;
        par.assign(n, -1);
        vis.assign(n, +0);
        dis.assign(n, 1e9);
        init_centroid(1, 0);
    }
 
    int find_size(int node, int par) 
    {
        siz[node] = 1;
        for(auto next : adj[node]) 
            if(next != par && !vis[next]) 
                siz[node] += find_size(next, node);

        return siz[node];
    }
 
    int find_centroid(int node, int par, int n) 
    {
        for(auto next : adj[node]) 
            if(next != par && !vis[next] && siz[next] * 2 > n) 
                return find_centroid(next, node, n);

        return node;
    }
 
    void init_centroid(int node, int prev) 
    {
        find_size(node, prev);
        int c = find_centroid(node, node, siz[node]);
        vis[c] = true;
        par[c] = prev;
        for(auto next : adj[c]) 
            if(!vis[next]) 
                init_centroid(next, c);
    }

    int query (int node)
    {
        int curr = node;
        int ans = (int)1E9;
        while(curr >= 0) 
        {
            ans = min(ans, dis[curr] + lca.dist(node, curr));
            curr = par[curr];
        }
        return ans;
    }

    void update (int node)
    {
        int curr = node;
        while(curr >= 0) 
        {
            dis[curr] = min(dis[curr], lca.dist(node, curr));
            curr = par[curr];
        }
    }
};
