/*Write a function to get the number of vertices in an undirected graph and its edges. You may assume that no edge is input twice.
    i. Use adjacency list representation of the graph and find runtime of the function
    ii. Use adjacency matrix representation of the graph and find runtime of the function*/
#include<iostream>
#include<queue>
using namespace std;

class graph
{
   int g[20][20],visited[20],v1,v2,n,e;
   char type;
   public:
	      void insert(int ,int );
	      void create();
	      void display();
	      void init();
	      void DFT(int );
};
void graph::init()
{
     for(int i=0;i<20;i++)
     {
         visited[i]=0;
     }

}
void graph::create()
{

      cout<<"enter the num of vertices:"<<endl;
      cin>>n;

      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
          {
             g[i][j]=0;
          }
      }

      cout<<"is graph is directed or not:(press d for directed)"<<endl;
      cin>>type;

      cout<<"enter total num of edges:"<<endl;
      cin>>e;

      for(int i=0;i<e;i++)
      {
          cout<<"enter end vertices of an egde:"<<endl;
          cin>>v1>>v2;

          insert(v1,v2);
      }
}
void graph::insert(int v1,int v2)
{
       if(type=='d'||type=='D')
       {
           g[v1][v2]=1;
       }
       else
       {
           g[v1][v2]=g[v2][v1]=1;
       }
}
void graph::display()
{
      for(int i=0;i<n;i++)
       cout<<"\t"<<i;
        cout<<"\n";
      for(int i=0;i<n;i++)
      {
          cout<<"\n"<<i;
          for(int j=0;j<n;j++)
          {

             cout<<"\t"<<g[i][j];
          }
          cout<<"\n";
      }

}
void graph::DFT(int i)
{
   	int j;
   	cout<<"\t"<<i;
   	visited[i]=1;
   	for(int j=0;j<n;j++)
   	{
   		if(!visited[j]&&g[i][j]==1)
   		DFT(j);
   	}
}
// ADJACENCY LIST
class node
{
	friend class graph_node;
	int data;
	node* next;
	public:
		   node(int v)
		   {
		      data=v;
		      next=0;
		   }
};
class graph_node
{
	node* head[20];
	int visited[20],nv,ne,vj;
	public:
			graph_node()
			{
				for(int i=0;i<20;i++)
				{
					head[i]=NULL;
				}
			}
			void create();
			void insert(int ,int );
			void init1();
			void bfs(int);
};
void graph_node::init1()
{
	for(int i=0;i<20;i++)
	{
		visited[i]=0;
	}
}
void graph_node::create()
{
    cout<<"enter total num of vertices:"<<endl;
    cin>>nv;
    for(int i=0;i<nv;i++)
    {
        cout<<"enter total edges connected with:"<<i<<endl;
        cin>>ne;
        for(int j=0;j<ne;j++)
        {
        	cout<<"enter vertex from which the edge is connected:"<<i<<"(to vj): ";
            cin>>vj;
            insert(i,vj);
        }
    }
}
void graph_node::insert(int i,int vj)
{
        node  *p,*q;
    	p=new node(vj);
        if(head[i]==NULL)
        {
            head[i]=p;
        }
        else
        {
            q=head[i];
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=p;
        }
}
void graph_node::bfs(int v0)
{
	int i,j;
	node* first;
	queue<int>q;
	q.push(v0);
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		if(!visited[i])
		{
			cout<<"\t"<<i;
			visited[i]=1;
		}
		first=head[i];
		while(first!=NULL)
		{
			j=first->data;
			if(!visited[j])
			{
				q.push(j);
			}
			first=first->next;
		}
	}
}
int main()
{
       int choice,ch,ch1,v;
       char ans,ans1,ans2;
       do
       {
	       cout<<"\nPRESS\n1.adjacency matrix\n2.Adjacency list\n";
	       cin>>choice;
	       switch(choice)
	       {
	           case 1:
		            graph g;
		            do
		            {
			            cout<<"\nPRESS\n1.create\n2.display\n";
			            cin>>ch;
			            switch(ch)
			            {
			            case 1:
								g.init();
			                    g.create();
			                    break;
			            case 2:
								g.display();
			            		cout<<"\n\t ENTER THE VERTEX FOR DFS: ";
			            		cin>>v;
			            		g.DFT(v);
			                    break;
			            }
			            cout<<"\npress y to continue";
			            cin>>ans;
		           }while(ans=='y'||ans=='Y');
		            break;
	           case 2:
		            graph_node g1;
		            do
		            {
		            cout<<"\nPRESS\n1.create\n2.display\n";
		            cin>>ch1;
		            switch(ch1)
		            {
		            case 1:g1.init1();
		                    g1.create();
		                    break;
		            case 2:int i=0;
		                	g1.bfs(i);
		                    break;
		            }
		            cout<<"\npress y to continue";
		            cin>>ans1;
		           }while(ans1=='y'||ans1=='Y');
		           break;
	       }
	       cout<<"\nDo You want to continue?(y/n)";
	       cin>>ans2;
      }while(ans2=='y'||ans2=='Y');
}
