template <class T>
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

	void Make(int a)
	{
		parr[a] = a;
		size[a] = 1;
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
    	
    	if (a != b) 
    	{
        	if (size[a] < size[b])
            	swap(a, b);

        	parr[b] = a;
        	size[a] += size[b];
    	}		
	}

};
