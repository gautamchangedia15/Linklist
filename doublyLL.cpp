#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node* previous;
    Node* next;
        Node(int d)
        {
            this->data=d;
            this->previous=NULL; 
            this->next=NULL;
        }
        ~Node()
        {
            int val=this->data;
            if(this->previous!=NULL||this->next!=NULL)
            {
                delete next;
                delete previous;
                this->previous=NULL;
                this->next=NULL;
            }
            cout<<"Memory is free from "<<val<<endl;
        }
};
void print(Node* &head )
{
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
   
    cout<<endl;
}
void printReverse(Node* &tail )
{
    if(tail == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node*temp=tail;
    cout<<"Reverse linked list is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->previous;
    }
   
    cout<<endl;
}
int getLength(Node* head)
    {
        int length=0;
        Node* temp=head;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
void insertAtHead(Node* &head,Node* &tail,int d)
{
    //empty list
    if(head==NULL)
    {
        Node* temp=new Node(d);
        head=temp;
        tail=temp; 
    }
    else {
    Node* temp=new Node(d);
    temp->next=head;
    head->previous=temp;
    head=temp; 
   }
}
void insertAtTail(Node* &head, Node* &tail,int d)
{
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node*temp=new Node(d);
    tail->next=temp;
    temp->previous=tail;
    tail=temp;
    }
}
void insertAtMiddle(Node* &head,Node* &tail,int position,int d)
{
    if(position==1)
    {
        insertAtHead(head,tail,d);
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
        insertAtTail(head,tail,d);
        return;
    }
    Node* insert=new Node(d);
    insert->next=temp->next;
    temp->next->previous=insert;    //imp step
    temp->next=insert;
    insert->previous=temp;
} 
void deleteNode(int position, Node* &head,Node* &tail)
{
    //delete first node
    if(position==1)
    {
        Node*temp=head; 
        head=head->next;
        temp->next->previous=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<position)
            {
                prev=curr;
                curr=curr->next;
                count++;
            }
        if(curr->next==NULL)
        {
            tail=prev;
            curr->previous=NULL;
            prev->next=NULL;
            delete curr;
            return;
        }
        prev->next=curr->next;
        prev->next->previous=prev;
        curr->next=NULL;
        curr->previous=NULL;
        delete curr;
    
}
int main()
{
   // Node* node1=new Node(10);
    Node*head=NULL;
    Node* tail=NULL;
    print(head);
    insertAtHead(head,tail,20); 
    print(head);
    insertAtHead(head,tail,30); 
    print(head);
    insertAtTail(head,tail,50);
    print(head);
    insertAtTail(head,tail,60); 
    print(head);
    insertAtMiddle(head,tail,5,22);
    print(head);
    deleteNode(1,head,tail);
    print(head);
    deleteNode(4,head,tail);
    print(head);
    cout<<"Length: "<<getLength(head)<<endl;
    cout<<"Head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;

    printReverse(tail);
    return 0;
}