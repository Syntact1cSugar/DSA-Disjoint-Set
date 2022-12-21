//Disjoint-Set Forests


#include<iostream>
class Node
{
	public:
	Node* p;//Holds Reference to predecessor/parent
	char data;
	Node(char data,Node* p = NULL)
	{
		this->data = data;
		this->p = p;
	}
};

Node* MAKE_SET(char x)//Creates a new node that points to itself
{
	Node* n = new Node(x);
	n->p = n;
	return n;	
}

char FIND_SET(Node* x)
{
	while(x->p != x)
	{
		x = x->p;
	}
	return x->data;
}

int UNION(Node* x,Node* y)
{
	if(FIND_SET(x) == FIND_SET(y))return 0;
	//Make root of set Sy to point to the root of set Sx
	while(x->p != x)
	{
		x = x->p;
	}
	while(y->p != y)
	{
		y = y->p;
	}
	y->p = x;
	return 1;
}
//Driver Code
int main()
{
	Node* d = MAKE_SET('d');
	Node* b = MAKE_SET('b');
	Node* c = MAKE_SET('c');
	Node* e = MAKE_SET('e');
	Node* f = MAKE_SET('f');
	Node* g = MAKE_SET('g');
	Node* h = MAKE_SET('h');
	UNION(f,d);
	UNION(d,g);
	UNION(h,b);
	UNION(c,e);
	UNION(e,h);
	UNION(e,d);
	std::cout << FIND_SET(c) << FIND_SET(b) << FIND_SET(e) << FIND_SET(h);
	std::cout << FIND_SET(f) << FIND_SET(d) << FIND_SET(g);
	delete d;
	delete b;
	delete c;
	delete e;
	delete f;
	delete g;
	delete h;
	return 0;
}
