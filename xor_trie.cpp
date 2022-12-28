struct node 
{
    node* next[2];
    int f[2]{};

    node () 
    {
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

void insert(node* &root, int num) 
{
    node* curr = root;
    for (int bit = 30; bit >= 0; bit--)
    {
        int mask = (1 << bit);
        int _bit = ((mask & num) > 0);
        if (curr -> next[_bit] == nullptr)
            curr -> next[_bit] = new node();
        curr -> f[_bit]++;
        curr = curr -> next[_bit];
    }
}

void remove (node* &root, int num)
{
    node* curr = root;
    for (int bit = 30; bit >= 0; bit--)
    {
        int mask = (1 << bit);
        int _bit = ((mask & num) > 0);
        curr -> f[_bit]--;
        if (curr -> f[_bit] == 0)
            curr -> next[_bit] = nullptr;
        curr = curr -> next[_bit];
        if (curr == nullptr)
            break;
    }
}

int find (node* &root, int num) 
{
    int ans = 0;
    node* curr = root;
    for (int bit = 30; bit >= 0; bit--) 
    {
        int mask = (1 << bit);
        int _bit = ((mask & num) ? 1 : 0);
        ans |= (curr -> next[_bit] == nullptr) ^ _bit ? mask : 0;
        if (curr -> next[_bit] != nullptr) 
            curr = curr -> next[_bit];
        else 
            curr = curr -> next[_bit ^ 1];
        if (curr == nullptr)
            break;
    }
    return ans;
}
