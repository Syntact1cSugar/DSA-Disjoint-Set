#include<iostream>
//Forward Declaration of classes
class Set;
class SetMember;
//Class Declaration and Implementation
class SetMember
{
    public:
    SetMember* next;
    char data;
    Set* prev;
    SetMember(char data,SetMember* next = NULL,Set* prev = NULL)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
class Set
{
    public:
    SetMember* head;
    SetMember* tail;
    Set(SetMember* head,SetMember* tail)
    {
        this->head = head;
        this->tail = tail;
    }
};


//Implementation of Disjoint Set Operations
int MAKE_SET(SetMember* x)
{
    Set* s = new Set(x,x);
    x->prev = s;
    return 1;
}
int UNION(SetMember* x,SetMember* y)
{
    if(x->prev == y->prev)//If x and y belong to the same set
        return 0;
    //x->prev gives the header of set Sx
    Set *Sx = x->prev,*Sy = y->prev;
    Sx->tail->next = Sy->head;
    Sx->tail = Sy->tail;
    SetMember* aux = Sy->head;
    while(aux)
    {
        aux->prev = Sx;
        aux = aux->next;
    }
    delete Sy;
    return 1;
}
char FIND_SET(SetMember* x)
{
    return x->prev->head->data;
}
bool IS_DISJOINT(SetMember* x,SetMember* y)
{
    return !(FIND_SET(x) == FIND_SET(y));
}

int main()
{
    SetMember* a = new SetMember('a');
    SetMember* b = new SetMember('b');
    SetMember* c = new SetMember('c');
    SetMember* d = new SetMember('d');
    SetMember* e = new SetMember('e');
    SetMember* f = new SetMember('f');
    MAKE_SET(a);
    MAKE_SET(b);
    MAKE_SET(c);
    MAKE_SET(d);
    MAKE_SET(e);
    MAKE_SET(f);
    std::cout << UNION(b,a);
    std::cout << UNION(b,c);
    std::cout << UNION(d,e);
    std::cout << UNION(e,f);
    std::cout << UNION(a,f);
    std::cout << '\n';
    std::cout << FIND_SET(a);
    std::cout << FIND_SET(b);
    std::cout << FIND_SET(c);
    std::cout << FIND_SET(b);
    std::cout << FIND_SET(e);
    std::cout << FIND_SET(f);
    delete a,b,c,d,e,f;
    return 0;
    
}
