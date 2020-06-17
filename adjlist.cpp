#include <iostream>//Adjacency list graph
using namespace std;
struct node
{
    int vertex;
    struct node *next;
};
struct graph
{
    int v;
    int e;
    struct node *adj;
};
struct graph *adjlist()
{
    struct graph *g;
    int i,x,y;
    g=(struct graph *)malloc(sizeof(struct graph));
    cin>>g->v;
    cin>>g->e;
    g->adj=(struct node*)malloc(g->v*sizeof(struct node));
    for(i=0;i<g->v;i++)
    {
        g->adj[i].vertex=i;    //adj[i] is doing dereferencing of pointer so adj[i] is a non pointer type variable
        g->adj[i].next=NULL;
    }
    for(i=0;i<g->e;i++)
    {
        struct node *temp,*ptr;
        temp=(struct node*)malloc(sizeof(struct node));
        cin>>x>>y;
        temp->vertex=y;
        temp->next=NULL;
        ptr=&g->adj[x];    //g->adj[x] is dereferenced, so we add address of operator '&'
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return g;
};
void display(graph *g)
{
    cout<<g->v<<endl;
    cout<<g->e<<endl;
    int i;
    struct node *temp;
    for(i=0;i<g->e;i++)
    {
        temp=&g->adj[i];
        while(temp!=NULL)
        {
            cout<<g->adj[i].vertex<<"->"<<temp->vertex<<"\t"<<endl;
            temp=temp->next;
        }
    }
}
int main()
{

struct graph *G;
G=(struct graph*)malloc(sizeof(struct graph));
G=adjlist();
display(G);
}
