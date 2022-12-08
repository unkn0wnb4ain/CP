vector <int> prefix_function (string s)
{
    int n = (int)s.size();
    vector <int> pi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int len = pi[i - 1];
        while (len > 0 and s[i] != s[len])
            len = pi[len - 1];
        if (s[i] == s[len])
            len++;
        pi[i] = len;
    }
    return pi;
}

vector <int> z_function(string s) 
{
    int n = (int)s.size();
    vector <int> z(n, 1 * 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) 
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
