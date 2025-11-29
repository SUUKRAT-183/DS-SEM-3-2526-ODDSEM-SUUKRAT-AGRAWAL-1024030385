#include <iostream>
using namespace std;

class DLL{
public:
    struct Node{ int data; Node *prev,*next; }*head=NULL;
    void insertFirst(int x){
        Node *t=new Node; t->data=x; t->prev=NULL; t->next=head;
        if(head) head->prev=t;
        head=t;
    }
    void insertLast(int x){
        Node *t=new Node,*p=head; t->data=x; t->next=NULL;
        if(!head){ t->prev=NULL; head=t; return; }
        while(p->next) p=p->next;
        p->next=t; t->prev=p;
    }
    void insertAfter(int key,int x){
        Node *p=head; while(p && p->data!=key) p=p->next;
        if(!p) return;
        Node *t=new Node; t->data=x; t->next=p->next; t->prev=p;
        if(p->next) p->next->prev=t;
        p->next=t;
    }
    void Delete(int key){
        Node *p=head; while(p && p->data!=key) p=p->next;
        if(!p) return;
        if(p->prev) p->prev->next=p->next; else head=p->next;
        if(p->next) p->next->prev=p->prev;
        delete p;
    }
    void search(int key){
        Node *p=head; while(p){ if(p->data==key){ cout<<"Found\n"; return;} p=p->next; }
        cout<<"Not Found\n";
    }
    void display(){
        Node *p=head; while(p){ cout<<p->data<<" "; p=p->next; }
        cout<<endl;
    }
};

class CLL{
public:
    struct Node{ int data; Node *next; }*head=NULL;
    void insertFirst(int x){
        Node *t=new Node,*p=head; t->data=x;
        if(!head){ head=t; t->next=t; return; }
        while(p->next!=head) p=p->next;
        t->next=head; p->next=t; head=t;
    }
    void insertLast(int x){
        Node *t=new Node,*p=head; t->data=x;
        if(!head){ head=t; t->next=t; return; }
        while(p->next!=head) p=p->next;
        t->next=head; p->next=t;
    }
    void insertAfter(int key,int x){
        Node *p=head; if(!head) return;
        do{ if(p->data==key) break; p=p->next;}while(p!=head);
        if(p->data!=key) return;
        Node *t=new Node; t->data=x; t->next=p->next; p->next=t;
    }
    void Delete(int key){
        if(!head) return;
        Node *p=head,*q;
        if(head->data==key){
            if(head->next==head){ delete head; head=NULL; return; }
            q=head; while(q->next!=head) q=q->next;
            q->next=head->next; q=head; head=head->next; delete q; return;
        }
        do{ q=p; p=p->next; }while(p!=head && p->data!=key);
        if(p==head) return;
        q->next=p->next; delete p;
    }
    void search(int key){
        Node *p=head; if(!head){ cout<<"Not Found\n"; return; }
        do{ if(p->data==key){ cout<<"Found\n"; return;} p=p->next;}while(p!=head);
        cout<<"Not Found\n";
    }
    void display(){
        Node *p=head; if(!head){ cout<<endl; return; }
        do{ cout<<p->data<<" "; p=p->next;}while(p!=head);
        cout<<endl;
    }
};

int main(){
    DLL d; CLL c;
    int ch,list,x,key;
    while(true){
        cout<<"1 DLL\n2 CLL\n3 Exit\n"; cin>>list;
        if(list==3) break;
        while(true){
            cout<<"1 Insert First\n2 Insert Last\n3 Insert After\n4 Delete\n5 Search\n6 Display\n7 Back\n";
            cin>>ch;
            if(ch==7) break;
            if(list==1){
                if(ch==1){ cin>>x; d.insertFirst(x); }
                else if(ch==2){ cin>>x; d.insertLast(x); }
                else if(ch==3){ cin>>key>>x; d.insertAfter(key,x); }
                else if(ch==4){ cin>>key; d.Delete(key); }
                else if(ch==5){ cin>>key; d.search(key); }
                else if(ch==6) d.display();
            }
            else if(list==2){
                if(ch==1){ cin>>x; c.insertFirst(x); }
                else if(ch==2){ cin>>x; c.insertLast(x); }
                else if(ch==3){ cin>>key>>x; c.insertAfter(key,x); }
                else if(ch==4){ cin>>key; c.Delete(key); }
                else if(ch==5){ cin>>key; c.search(key); }
                else if(ch==6) c.display();
            }
        }
    }
}
