#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
    ~Node();
};
Node::~Node()
{
   int val=this->data;
    while(this->next!=NULL)
    {
        delete next;
        this->next=NULL;
    }
    cout<<"Memory is free from "<<val<<endl;
}
void insert(Node* &tail,int element, int d)
{
     //empty list
     if(tail==NULL)
     {
        Node* temp=new Node(d);
        temp->next=temp;
        tail=temp;
     }
     //Non empty case
     else{
        Node* curr= tail;
        while(curr->data!=element)
        {
            curr=curr->next;
            if(curr==tail)
            {
                cout<<"Element "<<element<<" not found"<<endl;
                return;
            }
        }
        //element found at curr
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
     }
}
void print(Node* &tail)
{
    if(tail==NULL)
    {
        cout<<"List is empty!"<<endl;
        return;
    }
    Node* temp=tail;
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (tail!=temp);
    
    cout<<endl;
}
void deleteNode(Node* &tail,int element)
{
    //empty list
   if(tail==NULL)
    {
        cout<<"List is empty!"<<endl;
        return;
    } 
    Node* prev=tail;
    if(prev->next==tail)
    {
        tail=NULL;
        delete tail;
        return;
    }
    Node* curr=prev->next; 
    Node*temp =prev->next;
    while(curr->data!=element)
    {
        prev=curr;
        curr=curr->next;
        
            if(curr==temp)   //if value not found
            {
            
                cout<<"Element "<<element<<" not found"<<endl;
                return;
                }

    }
    prev->next=curr->next;
    if(curr==prev)
    {
        tail==NULL;
    }
    else{
         tail=curr->next;
    }
    curr->next=NULL;
    delete curr;
}
int main() 
{
    
    Node* tail=NULL;

    insert(tail,5,10);
    print(tail);
    cout<<"Tail: "<<tail->data<<endl;
    deleteNode(tail,10);
    print(tail);
    insert(tail,5,20);
    print(tail);
    insert(tail,20,15);
    print(tail);
    insert(tail,15,30);
    print(tail);
    insert(tail,20,63);
    print(tail);
    insert(tail,20,105);
    print(tail);
    insert(tail,20,110);
    print(tail);
    deleteNode(tail,30);
    print(tail);
    deleteNode(tail,90);
    print(tail);
    deleteNode(tail,63);
    print(tail);
    cout<<"Tail: "<<tail->data<<endl;
    return 0;
}