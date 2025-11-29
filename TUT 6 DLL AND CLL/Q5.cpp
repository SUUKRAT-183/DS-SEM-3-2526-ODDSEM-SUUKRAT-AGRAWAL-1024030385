#include <iostream>
using namespace std;

class LList{
public:
    struct Node{ int data; Node *next; }*head=NULL;
    void insert(int x){
        Node *t=new Node,*p=head;
        t->data=x; t->next=NULL;
        if(!head){ head=t; return; }
        while(p->next) p=p->next;
        p->next=t;
    }
    int isCircular(){
        Node *p=head;
        if(!head) return 0;
        while(p && p->next && p->next!=head) p=p->next;
        return p->next==head;
    }
};

int main(){
    LList l;
    l.insert(1); l.insert(2); l.insert(3);
    if(l.isCircular()) cout<<"Circular"<<endl;
    else cout<<"Not Circular"<<endl;
    LList::Node *p=l.head;
    while(p->next) p=p->next;
    p->next=l.head;
    if(l.isCircular()) cout<<"Circular"<<endl;
    else cout<<"Not Circular"<<endl;
}
