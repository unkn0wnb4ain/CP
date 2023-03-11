function <void(ll)> bfs = [&](ll node)
{
    queue <ll> q;
    q.push(node);

    col[node] = 0;
    while(q.size())
    {
        ll node_ = q.front();
        q.pop();

        for(auto child : graph[node_])
        {
            if(col[child] == -1)
            {
                col[child] = 1 ^ col[node_];
                q.push(child);
            }

            else
                bipartite &= (col[node_] != col[child]);
        }
    }
};
