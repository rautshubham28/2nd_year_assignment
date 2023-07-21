/*Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree –
    i. Insert new node
    ii. Find number of nodes in longest path
    iii. Minimum data value found in the tree
    iv. Change a tree so that the roles of the left and right pointers are swapped at every node
    v. Search a value*/
#include<iostream>
#include<string.h>
using namespace std;

class node
{
 	node *left,*right;
  	int data;
  	public:
  	node()
  	{
   		data=0;
   		left=NULL;
   		right=NULL;
  	}
    	void setdata(int n)
	{
	  	data=n;
	}
    	int getdata()
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

class bst
{  
	  node* root;

	  public:
		bst()
	  	{
	    	     root=NULL;
	  	}
	  	node* getroot()
	  	{
	  	     return root;
	  	}
	  	void create();
	  	void insert(int);
	  	void rpreorder(node*);
	  	void rinorder(node*);
	  	void rpostorder(node*);
	  	void preorder(node*);
	  	void inorder(node*);
	  	void postorder(node*);
	  	void mirror(node*);
	  	int longpath(node*);
	  	void search();
	  	void min();
	  	void max();
};

class stacks
{ 
     friend class bst;
     
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
     
void bst::create()
{
   	int n,i;
   	int no;
   	cout<<"\n\n\t ENTER THE NUMBER OF NODES TO ENTER: ";
   	cin>>n;
   	for(i=0;i<n;i++)
   	{
      		cout<<"\n\n\t ENTER THE VALUE: ";
      		cin>>no;
      		insert(no);
   	}
}
 
void bst::insert(int v)
{
   	node* nnode;
   
   	if(root==NULL)
   	{
   		nnode=new node();
   		nnode->setdata(v);
   		root=nnode;
   		cout<<"\n\t ROOT HAS BEEN INSERTED AS:  "<<root->getdata()<<"\n";
   
   	}
   	else
   	{
   		node *prev, *ptr, *cur;
   		prev=NULL;
   		cur=root;
   		while(cur!=NULL && cur->getdata()!=v)
   		{
   			prev=cur;
   			if(cur->getdata()>v)
   				cur=cur->getleft();
   			else
   				cur=cur->getright();
   		}
   		
   		if(cur!=NULL && cur->getdata()==v)
   			cout<<"\n\n\t\t NO DUPLICATION ALLOWED";
   		else
   		{
   			ptr=new node;
   			ptr->setdata(v);
   			
   			if(prev==NULL)
   				root=ptr;
   			else
   			{
   				if(prev->getdata()>v)
   					prev->setleft(ptr);
   				else
   					prev->setright(ptr);
   			}
   		}	
	}
}
 
void bst :: rpreorder(node *temp)
{
	if(temp!=NULL)
 	{
 		cout<<temp->getdata()<<"   ";
		rpreorder(temp->getleft());
 		rpreorder(temp->getright());
 	}
}

void bst :: rinorder(node *temp)
{
	if(temp!=NULL)
 	{
 		rinorder(temp->getleft());
 		cout<<temp->getdata()<<"   ";
 		rinorder(temp->getright());
 	}
}
 
void bst :: rpostorder(node *temp)
{
	if(temp!=NULL)
 	{
 		rinorder(temp->getleft());
 		rinorder(temp->getright());
 		cout<<temp->getdata()<<"   ";
 	}
}	

void bst :: inorder(node *p)
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
			cout<<temp->getdata()<<"   ";
			temp = temp->getright();
		}
	}
}

void bst :: preorder(node *p)
{
	node *temp;
	stacks s;
	s.push(p);
	
	while(!s.empty())
	{
		temp = s.pop();
		if(temp!=NULL)
		{
			cout<<temp->getdata()<<"   ";
			s.push(temp->getright());
			s.push(temp->getleft());
		}
	}
}
    
void bst :: postorder(node *p)
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
				cout<<p1->getdata()<<"    ";
				s.pop();
				prev=p1;
				p1=NULL;
			}
			else
				p1=p1->getright();
		}
	}while(!s.empty());
}

void bst :: mirror(node *root)
{
	node *temp;
	if(root!=NULL)
	{
		temp = root->getleft();
		root->setleft(root->getright());
		root->setright(temp);
		mirror(root->getleft());
		mirror(root->getright());
	}
}

int bst :: longpath(node *root)		
{
	int hl,hr;
	if(root == NULL)
		return 0;
	hl = longpath(root->getleft());
	hr = longpath(root->getright());
	
	if(hr>hl)
		return (hr+1);
	return (hl+1);
}

void bst :: search()
{
	int val;
	cout<<"\n\n\t ENTER THE VALUE TO SEARCH: ";cin>>val;
	node *temp;
	
	temp = root;
	while(temp!=NULL && temp->getdata()!=val)
	{
		if(temp->getdata()>val)
			temp = temp->getleft();
		else
			temp = temp->getright();
	}
	if(temp == NULL)
		cout<<"\n\n\t\t NO SUCH ELEMENT IS PRESENT!! ";
	else
		cout<<"\n\n\t\t ELEMENT FOUND!! ";
}

void bst :: min()
{
	node *temp = root;
	while(temp->getleft()!=NULL)
	{
		temp = temp->getleft();
	}
	cout<<"\n\n\t THE MINIMUM VALUE OF THE BST IS: "<<temp->getdata();
}

void bst :: max()
{
	node *temp = root;
	while(temp->getright()!=NULL)
	{
		temp = temp->getright();
	}
	cout<<"\n\n\t THE MAXIMUM VALUE OF THE BST IS: "<<temp->getdata();
}

int main()
{
   int ch,v,n;
   bst t;
   do
   {
    	cout<<"\n\n\t\t\t ********** MENU **********";
    	cout<<"\n\t\t\t 1.CREATE ";
    	cout<<"\n\t\t\t 2.INSERT ";
    	cout<<"\n\t\t\t 3.INORDER WITH RECURSION ";
    	cout<<"\n\t\t\t 4.PREORDER WITH RECURSION ";
    	cout<<"\n\t\t\t 5.POSTORDER WITH RECURSION ";
    	cout<<"\n\t\t\t 6.INORDER ";
    	cout<<"\n\t\t\t 7.PREORDER ";
    	cout<<"\n\t\t\t 8.POSTORDER ";
    	cout<<"\n\t\t\t 9.MINIMUM ELEMENT IN BST ";
    	cout<<"\n\t\t\t 10.MAXIMUM ELEMENT IN BST ";
    	cout<<"\n\t\t\t 11.LONGEST PATH NODES";
    	cout<<"\n\t\t\t 12.SEARCH";
    	cout<<"\n\t\t\t 13.MIRROR";
    	cout<<"\n\t\t\t 14.EXIT ";
    	cout<<"\n\t\t ENTER YOUR CHOICE: ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
   			t.create();
   			break;
   		case 2:
   			cout<<"\n\n\t ENTER THE VALUE TO ENTER IN THE NODE: ";cin>>v;
   			t.insert(v);
   			break;
   		case 3:
   			cout<<"\n\n\t INORDER SEQUENCE IS WITH RECURSION.... "; 
   			t.rinorder(t.getroot());
   			break;
   		case 4:
   			cout<<"\n\n\t PREORDER SEQUENCE IS WITH RECURSION.... ";
   			t.rpreorder(t.getroot());
   			break;
   		case 5:
    			cout<<"\n\n\t POSTORDER SEQUENCE IS WITH RECURSION.... ";
    			t.rpostorder(t.getroot());
   			break;
   		case 6:
   			cout<<"\n\n\t INORDER SEQUENCE IS.... "; 
   			t.inorder(t.getroot());
   			break;
   		case 7:
   			cout<<"\n\n\t PREORDER SEQUENCE IS.... ";
   			t.preorder(t.getroot());
   			break;
   		case 8:
    			cout<<"\n\n\t POSTORDER SEQUENCE IS.... ";
    			t.postorder(t.getroot());
   			break;
   		case 9:
    			t.min();
   			break;
   		case 10:
    			t.max();
   			break;
   		case 11:
    			n = t.longpath(t.getroot());
    			cout<<"\n\n\t\t THE NODES IN LONGEST PATH ARE: "<<n;
    			break;
    		case 12:
    			t.search();
   			break;
   		case 13:
    			t.mirror(t.getroot());
    			cout<<"\n\n\t THE BST HAS BEEN MIRRORED ";
   			break;
   		case 14:
   			cout<<"\n\n\n\t\t\t *******THANK YOU******* ";
   			break;
  
   		default :
   			cout<<"\n\n\t\t INVALID CHOICE ENTER AGAIN!!";
   	}
   }while(ch!=14);
   
   cout<<"\n\n";
   return 0;
}

