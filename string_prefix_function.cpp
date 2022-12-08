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
