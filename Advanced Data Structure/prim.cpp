#include<iostream>
#define INF 99999
using namespace std;

class prim
{
	int adj_matrix[30][30];
	int num_city;
	string city_name[20];
	public:
	prim()
	{
		num_city=0;
	}
	void insert();
	void intadj_matrix();
	void display();
	int graph(prim &);
	void run(); 
};

void prim::insert()
{
	cout<<"\nENTER THE NUMBER OF CITIES : " ;
	cin>>num_city;
	cout<<"\nENTER THE NAME OF CITIES : ";
	for(int i=0;i<num_city;i++)
	{	
		cout<<"\nCITY "<<i+1<<" : ";
		cin>>city_name[i];
	}
	intadj_matrix();
	int cost;
	char ch;
	for(int i=0;i<num_city;i++)
	{
		for(int j=i+1;j<num_city;j++)
		{
			cout<<"\nIS "<<city_name[i]<<" connected to "<<city_name[j]<<" via phone line ?(Y/N) : ";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				cout<<"ENTER THE COST : ";
				cin>>cost;
				adj_matrix[i][j]=adj_matrix[j][i]=cost;
			}
		}
	}
	cout<<"\n\t\tADJACENCY MATRIX : ";
	display();
	
}
void prim::intadj_matrix()
{
	for(int i=0;i<num_city;i++)
	{
		for(int j=0;j<num_city;j++)
		{
			adj_matrix[i][j]=0;
		}
	}
}

void prim::run()
{
	prim spanning;
	int total_cost=graph(spanning);
	cout<<"\n MIN COST : "<<total_cost;
	cout<<"\n\t\tSPANNING GRAPH : ";
	spanning.display();
}
int prim::graph(prim &spanning)
{
	int cost[20][20];

	for(int i=0;i<num_city;i++)
	{
		for(int j=0;j<num_city;j++)
		{
			if(adj_matrix[i][j]==0)
				cost[i][j]=INF;
			else
				cost[i][j]=adj_matrix[i][j];
			spanning.adj_matrix[i][j]=0;
		}
	}
	int distance[30];
	int visited[30];
	int from[30];
	
	cout<<"\nORDER OF CITIES : "<<endl;
	cout<<city_name[0];
	
	distance[0]=0;
	visited[0]=1;
	for(int i=1;i<num_city;i++)
	{
		distance[i]=cost[0][i];
		visited[i]=0;
		from[i]=0;
	}	
	int min_cost,min_dist;
	int edges=num_city-1;
	int v,u;
	while(edges>0)
	{
		min_dist=INF;
		for(int i=1;i<num_city;i++)
		{
			if(visited[i]==0 && distance[i]<min_dist)
			{
				v=i;
				min_dist=distance[i];
			}
		}
		u=from[v];
		spanning.adj_matrix[u][v]=spanning.adj_matrix[v][u]=distance[v];
		edges--;
		cout<<"-->"<<city_name[v];
		visited[v]=1;
		for(int i=1;i<num_city;i++)
		{
			if(visited[i]==0 && cost[i][v]<distance[i])
			{	
				distance[i]=cost[i][v];
				from[i]=v;
			}
		}
		min_cost=min_cost+cost[u][v];
	}
	return min_cost;
}
void prim::display()
{
	for(int i=0;i<num_city;i++)
	{
		for(int j=0;j<num_city;j++)
		{
			cout<<"\t"<<adj_matrix[i][j];
		}
		cout<<endl;
	}
}

int main()
{
	prim p;
	p.insert();
	p.run();
	return 0;
}
