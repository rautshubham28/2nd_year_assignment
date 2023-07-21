/*A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.*/
#include<iostream>
#include<string.h>
using namespace std;

class node
{
 	node *left,*right;
  	char data[20];
  	public:
  	node()
  	{
   		strcpy(data,"\0");
   		left=NULL;
   		right=NULL;
  	}
    	void setdata(char* n)
	{
	  	strcpy(data,n);
	}
    	char* getdata()
	{
	  	return data;
	}
    	void setleft(node *y)
	{
	   	left=y;
	}
    	node* getleft()
	{
	   	return left;
	}
	void setright(node *z)
	{
	   	right=z;
	}
    	node* getright()
	{
	   	return right;
	}
};

class btree
{  
	  node* root;
	  public:
		btree()
	  	{
	    	     root=NULL;
	  	}
	  	node* getroot()
	  	{
	  	     return root;
	  	}
	  	void create();
	  	void insert(char*);
	  	void rpreorder(node*);
	  	void rinorder(node*);
	  	void rpostorder(node*);
	  	void preorder(node*);
	  	void inorder(node*);
	  	void postorder(node*);
};

class stacks
{ 
     friend class btree;
     public:
     		int top;
     		node* arr[30];
     		stacks()
     		{
     		  	top=-1;
     		}
     		int empty()
      		{
        		if(top==-1)
        			return 1;
        		else
         			return 0;
      		}
     		void push(node* x)
      		{
        		arr[++top]=x;
      		}
      		node* pop()
      		{
        		return arr[top--];
      		}
};  
     
void btree::create()
{
   	int i;
   	char nm[20];
   	cout<<"\n\t ENTER THE NAME OF THE BOOK: ";
	cin>>nm;
	insert(nm);
   	cout<<"\n\n\t ENTER THE CHAPTER NAMES ... ";
   	for(i=0;i<2;i++)
   	{
      		cout<<"\n\t ENTER THE NAME OF CHP"<<i+1<<": ";
      		cin>>nm;
      		insert(nm);
   	}
   	cout<<"\n\n\t ENTER THE SECTION NAMES ... ";
   	for(i=0;i<2;i++)
   	{
      		cout<<"\n\t ENTER THE NAME OF SECTION"<<i+1<<": ";
      		cin>>nm;
      		insert(nm);
   	}
}
 
void btree::insert(char* val)
{
   	char a;
   	node* nnode;
   	int f=0;
   
   	if(root==NULL)
   	{
   		nnode=new node();
   		nnode->setdata(val);
   		root=nnode;
   		cout<<"\n\t BOOK NAME HAS BEEN INSERTED "<<root->getdata()<<"\n";
   		f=1;
   	}
   	else
   	{
	      node* temp;
	      temp=root;
	      do
	      {
	      		cout<<"\n\n WHERE DO YOU WANT TO ENTER LEFT(l) OR RIGHT(r) OF "<<temp->getdata()<<" -> ";
	      		cin>>a;
	      		if(a=='l')
	      		{
	       			if(temp->getleft()==NULL)
	     			{
					nnode=new node();
             				nnode->setdata(val);
	       				temp->setleft(nnode);
	       				cout<<temp->getleft()->getdata()<<" IS SET TO THE LEFT OF "<<temp->getdata();
	       				f=1;
	     			}
	      			else
	      			{
	       				temp=temp->getleft();
	      			}
	     		}
	     		if(a=='r')
	      		{
	       			if(temp->getright()==NULL)
	     			{
					nnode=new node();
               				nnode->setdata(val);
	       				temp->setright(nnode);
	        			cout<<temp->getright()->getdata()<<" IS SET TO THE RIGHT OF "<<temp->getdata();
	       				f=1;
	     			}
	      			else
	      			{
	       				temp=temp->getright();
	      			}
	     		}
	   	}while(f==0);
    	} 
}
 
void btree :: rpreorder(node *temp)
{
	if(temp!=NULL)
 	{
 		cout<<temp->getdata()<<"->";
		rpreorder(temp->getleft());
 		rpreorder(temp->getright());
 	}
}

void btree :: rinorder(node *temp)
{
	if(temp!=NULL)
 	{
 		rinorder(temp->getleft());
 		cout<<temp->getdata()<<"->";
 		rinorder(temp->getright());
 	}
}
 
void btree :: rpostorder(node *temp)
{
	if(temp!=NULL)
 	{
 		rinorder(temp->getleft());
 		rinorder(temp->getright());
 		cout<<temp->getdata()<<"->";
 	}
}	

void btree :: inorder(node *p)
{
	node *temp;
	stacks s;
	temp = p;
	while(!s.empty() || temp!=NULL)
	{
		if(temp!=NULL)
		{
			s.push(temp);
			temp = temp->getleft();
		}
		else
		{
			temp = s.pop();
			cout<<temp->getdata()<<"->";
			temp = temp->getright();
		}
	}
}

void btree :: preorder(node *p)
{
	node *temp;
	stacks s;
	s.push(p);
	while(!s.empty())
	{
		temp = s.pop();
		if(temp!=NULL)
		{
			cout<<temp->getdata()<<"->";
			s.push(temp->getright());
			s.push(temp->getleft());
		}
	}
}
    
void btree :: postorder(node *p)
{
	stacks s;
	node *prev=NULL;
	node *p1;
	p1 = p;				
	do
	{
		while(p1!=NULL)
		{
			s.push(p1);
			p1 = p1->getleft();
		}
		while(p1 == NULL && !s.empty())
		{
			p1 = s.arr[s.top];
			if(p1->getright() == NULL || p1->getright() == prev)
			{
				cout<<p1->getdata()<<"->";
				s.pop();
				prev=p1;
				p1=NULL;
			}
			else
				p1=p1->getright();
		}
	}while(!s.empty());
}
      
int main()
{
   char v[20];
   int ch;
   btree t;
   do
   {
    	cout<<"\n\n ********** MENU **********";
    	cout<<"\n 1.CREATE ";
    	cout<<"\n 2.INSERT ";
    	cout<<"\n 3.INORDER WITH RECURSION ";
    	cout<<"\n 4.PREORDER WITH RECURSION ";
    	cout<<"\n 5.POSTORDER WITH RECURSION ";
    	cout<<"\n 6.INORDER ";
    	cout<<"\n 7.PREORDER ";
    	cout<<"\n 8.POSTORDER ";
    	cout<<"\n 9.EXIT ";
    	cout<<"\n\t ENTER YOUR CHOICE: ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
   			t.create();
   			break;
   		case 2:
   			cout<<"\n\n ENTER THE NAME TO ENTER IN THE NODE: ";cin>>v;
   			t.insert(v);
   			break;
   		case 3:
   			cout<<"\n\n CONTENTS OF BOOK INORDER SEQUENCE WITH RECURSION.... \n\n\t"; 
   			t.rinorder(t.getroot());
   			break;
   		case 4:
   			cout<<"\n\n CONTENTS OF BOOK PREORDER SEQUENCE WITH RECURSION.... \n\n\t";
   			t.rpreorder(t.getroot());
   			break;
   		case 5:
    			cout<<"\n\n CONTENTS OF BOOK POSTORDER SEQUENCE WITH RECURSION.... \n\n\t";
    			t.rpostorder(t.getroot());
   			break;
   		case 6:
   			cout<<"\n\n CONTENTS OF BOOK IN INORDER SEQUENCE .... \n\n\t"; 
   			t.inorder(t.getroot());
   			break;
   		case 7:
   			cout<<"\n\n CONTENTS OF BOOK IN PREORDER SEQUENCE .... \n\n\t";
   			t.preorder(t.getroot());
   			break;
   		case 8:
    			cout<<"\n\n CONTENTS OF BOOK IN POSTORDER SEQUENCE .... \n\n\t";
    			t.postorder(t.getroot());
   			break;
   		case 9:
   			cout<<"\n\n\n\t *****THANK YOU***** ";
   			break;
   		default :
   			cout<<"\n\n\t INVALID CHOICE ENTER AGAIN ";
   	}
   }while(ch!=9);
   cout<<"\n\n";
   return 0;
}
