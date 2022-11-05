#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }

    //Destructor
    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free from node with data: "<<val<<endl;
    }
};

void insertAtHead(Node* &head,int d);
void insertAtTail(Node* &tail,int d);
void insertAtMiddle(Node* &head,Node* &tail,int position,int d);
void deleteNode(Node* &head,Node* &tail,int position);
void print(Node* &head);
void reverse(Node* &head);
int main()
{   
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtHead(head,20);
    print(head);
    insertAtTail(tail,30);
    print(head);
    insertAtMiddle(head,tail,3,22);
    print(head);
    deleteNode(head,tail,3);
    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    reverse(head);
    print(head);
    reverse(head);
    print(head);
    return 0;
}

void insertAtHead(Node* &head,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d)
{
    Node* temp= new Node(d);
    tail->next=temp;
    tail=temp;
}
void print(Node* &head)
{
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<endl;
}
void insertAtMiddle(Node* &head,Node* &tail,int position,int d)
{
    if(position==1)
    {
        insertAtHead(head,d);
        return;
    }

    Node* temp=head;
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
    return;
}
void deleteNode(Node* &head,Node* &tail,int position)
{
    //delete first node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;  
        Node* prev=NULL;
        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }

        prev->next=curr->next;
        if(curr->next==NULL)
        {
            tail=prev;
        }
        else curr->next=NULL;
        delete curr;
    }
}
void reverse(Node* &head)
{
    if(head==NULL)
    {
        cout<<"List is empty!"<<endl;
    }
    Node* prev=NULL;
    Node* current=head;
    Node* further=NULL;
    
    while(current!=NULL)
    {
    further=current->next;
    current->next=prev;
    prev=current;
    current=further;
    }
    head=prev;
}
