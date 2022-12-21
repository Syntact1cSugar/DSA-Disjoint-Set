//Disjoint-Set Forests with Union Rank and Path Compression Heuristic
#include<iostream>
class Node
{
	public:
	int data;
	int rank;
	Node* p;
	Node(int data,int rank=0,Node* p = NULL)
	{
		this->data = data;
		this->rank = rank;
		this->p = p;
	}
};
class DisjointSet
{
	public:
	Node* MAKE_SET(int);
	Node* FIND_SET(Node*);
	int UNION(Node*,Node*);
	bool isDisjoint(Node*,Node*);
};

Node* DisjointSet::MAKE_SET(int data)
{
	Node* n = new Node(data);
	n->p = n;
	n->rank = 0;
	return n;
}
Node* DisjointSet::FIND_SET(Node* x)//Returns a reference to the set representative
{
	if(x->p != x)
		x->p = FIND_SET(x->p);
	return x->p;
}

int   DisjointSet::UNION(Node* x,Node* y)
{
	
	x = this->FIND_SET(x);
	y = this->FIND_SET(y);
	if(x == y)return 0;//The two sets are not disjoint
	if(x->rank > y->rank)
	{
		y->p = x;
	}
	x->p = y;
	if(x->rank == y->rank)
	{
		++(x->rank);
	}
	return 1;
}

bool DisjointSet::isDisjoint(Node* x,Node* y)
{
	return !(this->FIND_SET(x) == this->FIND_SET(y));
}

int main()
{
	DisjointSet ds;
	Node* a = ds.MAKE_SET(0);
	Node* b = ds.MAKE_SET(1);
	Node* c = ds.MAKE_SET(2);
	Node* d = ds.MAKE_SET(3);
	ds.UNION(a,b);
	ds.UNION(c,d);
	ds.UNION(a,c);
	delete a;
	delete b;
	delete c;
	delete d;
	return 0;
}
