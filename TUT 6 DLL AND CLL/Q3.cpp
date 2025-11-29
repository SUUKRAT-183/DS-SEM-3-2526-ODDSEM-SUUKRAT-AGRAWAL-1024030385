#include <iostream>
using namespace std;

class DLL{
public:
    struct Node{ int data; Node *prev,*next; }*head=NULL;
    void insert(int x){
        Node *t=new Node,*p=head;
        t->data=x; t->next=NULL;
        if(!head){ t->prev=NULL; head=t; return; }
        while(p->next) p=p->next;
        p->next=t; t->prev=p;
    }
    int size(){
        int c=0; Node *p=head;
        while(p){ c++; p=p->next; }
        return c;
    }
};

class CLL{
public:
    struct Node{ int data; Node *next; }*head=NULL;
    void insert(int x){
        Node *t=new Node,*p=head;
        t->data=x;
        if(!head){ head=t; t->next=t; return; }
        while(p->next!=head) p=p->next;
        p->next=t; t->next=head;
    }
    int size(){
        if(!head) return 0;
        int c=0; Node *p=head;
        do{ c++; p=p->next;}while(p!=head);
        return c;
    }
};

int main(){
    DLL d; CLL c;
    d.insert(1); d.insert(2); d.insert(3);
    c.insert(10); c.insert(20); c.insert(30); c.insert(40);
    cout<<"Size of Doubly Linked List = "<<d.size()<<endl;
    cout<<"Size of Circular Linked List = "<<c.size()<<endl;
}
