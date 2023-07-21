/*Consider telephone book database of N clients. Make use of a hash1 table implementation to quickly look up client‘s telephone number.*/

#include<iostream>
#include<string.h>
using namespace std;

class client
{
	char name[15];
	unsigned int id;
	long int tele;
	int chain;
	public:
	client()
	{
		strcpy(name,"------");
		id = 000000;
		tele = 00000000;
		chain = -1;
	}
	friend class hash1;
};

class hash1
{
	int n;
	client *c;
	public:
	hash1()
	{
		cout<<"\n\tEnter the max amount of clients: ";
			 cin>>n;
		c = new client[n];
	}
	void create();
	void insert(int x);
	int search(int x);
	void delclient(int x);
	void update(int x);
	void display();
	int hash1fn(int x)
	{
		return x % n;
	}
};
void hash1::create()
{
	int k,x;
	cout<<"\n\tEnter the number of client information you want to add: ";
	cin>>k;
	while(k > 0)
	{
		cout<<"\n\tEnter the new client ID: ";
		cin>>x;
		k--;
	insert(x);
	}	
}

void hash1::insert(int x)
{
	int z, chn = 0, y = hash1fn(x), flag = 0;
	for(z = 0; z < n; z++)
	{
		if(c[y].id == 0)
		{
			c[y].id = x;
			cout<<"\tEnter the name of the client: ";
			cin>>c[y].name;
			cout<<"\tEnter the telephone number of the client: ";
			cin>>c[y].tele;
			break;
		}
		else
		{
			if(hash1fn(c[y].id) == hash1fn(x)) //c[y].id != 0 && 
			{	
				flag = 1;
				chn = y;
			}
			y = hash1fn(y + 1);
		}
	}
	if(z == n)
		cout<<"\n\tClient table is completely filled\n\t*Either delete an old client or update the client list*\n";
	else
	{
		cout<<"\n\tNew client info has been successfully added\n";
		if(flag == 1)
			c[chn].chain = y;
	}
		
}

int hash1::search(int x)
{
	int y,z;
	y = hash1fn(x);
	for(z=0;z<n;z++)
	{
		if(c[y].id == x)
		{
			cout<<"\n\tThe requested client exists\n";
			return y;
		}	
		else if(c[y].id != 0)
		{
			
			if(c[y].chain != -1 && hash1fn(c[y].id) == hash1fn(x))
			{
				y = c[y].chain;
			}
			else if(c[y].chain==-1 && hash1fn(c[y].id) == hash1fn(x))
				z=n-1;
			else
				y = hash1fn(y + 1);
		}
		else if(c[y].id == 0)
		{
			z=n-1;
		}
	}
	if(z==n)
	{
		cout<<"\n\tThe requested client does not exist";
		return -1;
	}
}

void hash1::delclient(int x)
{	
	int flag;
	flag = search(x);
	if(flag != -1)
	{
		for(int i = hash1fn(x); ;)
		{
			if(c[i].chain == -1)
				break;
				
			else if(c[i].chain == flag)
			{
				c[i].chain = c[flag].chain;
				break;
			}
			else if(c[i].chain != -1 && c[i].chain != -1)
				i = c[i].chain;	
		}
		c[flag].id = 0;
		c[flag].chain = -1;
		c[flag].tele = 0;
		strcpy(c[flag].name, "------");
	}
}

void hash1::display()
{
	for(int i = 0; i < n; i++)
		cout<<"\t"<<i<<":\t "<<c[i].id<<"\t "<<c[i].name<<"\t "<<c[i].tele<<"\t\t\t "<<c[i].chain<<endl;
}
	
void hash1::update(int x)
{	
	int flag;
	flag = search(x);
	if(flag != -1)
	{
		
		cout<<"\n\tEnter the change in the previous telephone number ("<<c[flag].tele<<") if any: ";
		cin>>c[flag].tele;
		cout<<"\n\tEnter new name if there is change ("<<c[flag].name<<") if any: ";
		cin>>c[flag].name;
	}
}	

int main()
{	
	int z;
	hash1 h1;
	char y;
	do{
		cout<<"\n\tSelect an action to be performed\n\t\t1:Add new clients\n\t\t2:Insert new clients";
		cout<<"\n\t\t3:Search for an existing client\n\t\t4:Update client information";
		cout<<"\n\t\t5:Delete client\n\t\t6:Display client table\n\tENTER CHOICE: ";
		cin>>z;
		switch(z)
		{
			case 1:	h1.create();
				break;
			
			case 2: cout<<"\n\tEnter the new client ID: ";
				cin>>z;
				h1.insert(z);
				break;
			
			case 3:	cout<<"\n\tEnter the ID of client you want to search: ";
				cin>>z;
				z = h1.search(z);
				break;
					
			case 4:	cout<<"\n\tEnter the ID of client you want to update: ";
				cin>>z;
				h1.update(z);
				break;
			
			case 5:	cout<<"\n\tEnter the ID of client you want to delete: ";
				cin>>z;
				h1.delclient(z);
				break;
				
			case 6:h1.display();
		}
		cout<<"\n\tDo you want to proceed further(Press Y): ";
		cin>>y;
	}while(y == 'Y' || y == 'y');
	return 0;
}

