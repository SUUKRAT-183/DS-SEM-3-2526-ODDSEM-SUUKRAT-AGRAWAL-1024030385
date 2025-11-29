#include <iostream>
using namespace std;

class DLL{
public:
    struct Node{ char data; Node *prev,*next; }*head=NULL;
    void insert(char x){
        Node *t=new Node,*p=head;
        t->data=x; t->next=NULL;
        if(!head){ t->prev=NULL; head=t; return; }
        while(p->next) p=p->next;
        p->next=t; t->prev=p;
    }
    int palindrome(){
        Node *l=head,*r=head;
        if(!head) return 1;
        while(r->next) r=r->next;
        while(l!=r && r->next!=l){
            if(l->data!=r->data) return 0;
            l=l->next; r=r->prev;
        }
        return 1;
    }
};

int main(){
    DLL d;
    d.insert('M'); d.insert('A'); d.insert('D'); d.insert('A'); d.insert('M');
    if(d.palindrome()) cout<<"Palindrome";
    else cout<<"Not Palindrome";
}
