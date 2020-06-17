#include<iostream>
using namespace std;
void appendatmid();
void deleteatmid();
void display();
struct node
{
    int data;
    struct node *link;
};
struct node *start=NULL;
int main()
{
    int ch;
    while(1)
    {
    printf("Enter your choice\n");
    cin>>ch;
    switch(ch)
    {
        case 1: appendatmid();
                break;
        case 2: deleteatmid();
                break;
        case 3: display();
                break;
        case 4: exit(1);
                break;
    }
    }
    return 0;
}
void appendatmid()
{
    struct node *p,*t,*q;
    int k,pos=1;
    p=(struct node*)malloc(sizeof(struct node));
    cin>>p->data;
    p->link=NULL;
if(start==NULL)
    start=p;
else{
    cout<<"Enter the position where you want to enter\n ";
    cin>>k;
    t=start;
    while((t!=NULL) && (pos<k))
    {
        pos++;
        q=t;
        t=t->link;
    }
    q->link=p;
    p->link=t;
}
}
void deleteatmid()
{
    struct node *p,*q;
    int pos,k=1;
    cout<<"Enter the position \n";
    cin>>pos;
    p=start;
    if(start==NULL)
        cout<<"Empty\n";
    if(pos==1)
    {
        p=p->link;
        free(p);
    }
    while((p!=NULL) && (pos>k))
    {
        k++;
        q=p;
        p=p->link;
    }
    q->link=p->link;
    free(p);
}
void display()
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->\t";
        temp=temp->link;
    }
}
