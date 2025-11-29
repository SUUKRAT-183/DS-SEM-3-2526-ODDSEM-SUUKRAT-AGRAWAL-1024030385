#include <iostream>
using namespace std;

class CLL{
public:
    struct Node{ int data; Node *next; }*head=NULL;
    void insert(int x){
        Node *t=new Node,*p=head; t->data=x;
        if(!head){ head=t; t->next=t; return; }
        while(p->next!=head) p=p->next;
        p->next=t; t->next=head;
    }
    void display(){
        if(!head) return;
        Node *p=head;
        do{ cout<<p->data<<" "; p=p->next;}while(p!=head);
        cout<<head->data<<endl;
    }
};

int main(){
    CLL c;
    c.insert(20);
    c.insert(100);
    c.insert(40);
    c.insert(80);
    c.insert(60);
    c.display();
}
