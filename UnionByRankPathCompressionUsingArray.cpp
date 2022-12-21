#include<iostream>
class DisjointSet
{
	private:
	int* parent;
	int* rank;
	public:
	void MAKE_SET(int);
	int  FIND_SET(int);
	int  UNION(int,int);
	bool IS_DISJOINT(int,int);
};
void DisjointSet::MAKE_SET(int n)
{
	this->parent = new int[n];
	this->rank   = new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i] = i;
		rank[i]   = 0;
	}
}
int DisjointSet::FIND_SET(int x)
{
	if(this->parent[x] != x)
	{
		this->parent[x] = FIND_SET(this->parent[x]);
	}
	return this->parent[x];
}
bool DisjointSet::IS_DISJOINT(int x,int y)
{
	return this->FIND_SET(x) != this->FIND_SET(y);
}
int DisjointSet::UNION(int x,int y)
{
	x = this->FIND_SET(x);
	y = this->FIND_SET(y);
	if(x != y)return 0;
	if(rank[x] > rank[y])
	{
		parent[y] = x;
	}
	else
	{
		parent[x] = y;
	}
	if(rank[x] == rank[y])
	{
		++rank[x];
	}
	return 1;
}
int main()
{
	return 0;
}
