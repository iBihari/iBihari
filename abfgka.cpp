#include<iostream>
using namespace std;


struct node{
    int data;
    struct node *next;
};
typedef struct node node ;

node* makeNode(int x){
    node *newNode = new node();
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}


int size(node *head)
{
    int dem = 0;
    while ( head != NULL)
    {
        ++dem;
        head = head -> next ;
    }
}

void duyet(node *head)
{
    while(head != NULL)
    {
        cout << head -> data << ' ';
        head = head -> next;
    }
}

void pushFront(node *&head, int x)
{
    node* newNode = makeNode(x);
    newNode ->next = head;
    head = newNode;
}

void pushBack(node *&head, int x)
{
    node* newNode = makeNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    node* temp = head;
    while( temp -> next != NULL )
    {
        temp = temp -> next;
    }
    temp-> next = newNode;
}

viod insert(node *&head,int k, int x)
{
    
}



int main()

{
    node *head = NULL;
    for (int i =1; i<=5;i++)
    {
        int x;
        cout << "nhap vao so x: ";
        cin >> x;
        pushBack(head,x);
    }
    duyet(head);
    return 0;
}