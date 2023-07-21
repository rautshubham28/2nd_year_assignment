/*Convert given binary tree into threaded binary tree. Analyze time and space complexity of the algorithm.*/


#include<iostream>
using namespace std;

class node
{
    int data;
    bool  rbit,lbit;
    node *left,*right;
	public:
	    node(int x)
	    {
	        data = x;
	        rbit = 0;
	        lbit = 0;
	        left = NULL;
	        right = NULL;
	    }
	    node()
	    {
	        rbit = 0;
	        lbit = 0;
	        left = NULL;
	        right = NULL;
	    }
	    void setrbit1();
	    void setlbit1();
	    void setleft(node*);
	    void setright(node*);
	    int getdata();
	    int getrbit();
	    int getlbit();
	    node* getleft();
	    node* getright();
};

class tbt
{
    node *root,*head;
	public:
	    tbt()
	    {
	        root = NULL;
	    }
	    void create_tree(int);
	    node* init();
	    void insert_node(int);
	    node* makenode(int);
	    void inorder(node*);
	    node* inorder_succ(node*);
	    void print(int);
	    void in();
	    void inorder(node*,int);
};

void node::setrbit1()
{
    rbit = 1;
}
void node::setlbit1()
{
    lbit = 1;
}
void node::setleft(node* x)
{
    left = x;
}
void node::setright(node* x)
{
    right = x;
}
int node::getdata()
{
    return data;
}
int node::getrbit()
{
    return rbit;
}
int node::getlbit()
{
    return lbit;
}
node* node::getleft()
{
    return left;
}
node* node::getright()
{
    return right;
}

void tbt::create_tree(int n)
{
    int i=0,val;
    while(i<n)
    {
        cout<<"\nEnter value : ";
        cin>>val;
        insert_node(val);
        i++;
    }
}
node* tbt::init()
{
    node *head;
    head = new node();
    head->setleft(head);
    head->setright(head);
    return head;
}
void tbt::insert_node(int value)
{
    node *temp, *current;
    char direction;
    int insert_flag = 0;

    if(root == NULL)
    {
        head = init();
        root = makenode(value);
        root->setleft(head);
        root->setright(head);
        head->setleft(root);
        head->setlbit1();
        insert_flag = 1;
        cout<<"\n\n\t ROOT HAS BEEN INSERTED AS "<<value<<"\n\n";;
    }
    else
    {
        temp = root;
        do
        {
            cout<<"\n Press L to insert in left of "<<temp->getdata()<<" or R to insert in right :";
            cin>>direction;
            if(direction == 'L' || direction == 'l')
            {
                if(temp->getlbit() == 1)
                {
                    temp = temp->getleft();
                }
                else
                {
                    current = makenode(value);
                    current->setleft(temp->getleft());
                    current->setright(temp);
                    temp->setleft(current);
                    temp->setlbit1();
                    insert_flag = 1;
                }
            }
            else if(direction == 'R' || direction == 'r')
            {
                if(temp->getrbit()==1)
                {
                    temp = temp->getright();
                }
                else
                {
                    current = makenode(value);
                    current->setright(temp->getright());
                    current->setleft(temp);
                    temp->setright(current);
                    temp->setrbit1();
                    insert_flag = 1;
                }
            }
            else
                cout<<"\n ENTER A VALID OPTION\n";
        }while(insert_flag == 0);
    }
}
node* tbt::makenode(int value)
{
    node *temp;
    temp = new node(value);
    return temp;
}
void tbt::inorder(node *root)
{
    node *temp = root;
    if(root == NULL)
    {
        cout<<"\n EMPTY TREE !! \n";
        return;
    }
    else
    {
        cout<<endl;
        while(temp != head)
        {
            while(temp->getlbit() == 1)
            {
                temp = temp->getleft();
            }
            cout<<" "<<temp->getdata()<<"\t";
            while(temp->getrbit() == 0)
            {
                temp = temp->getright();
                if(temp == head)
                {
                    return;
                }
                cout<<" "<<temp->getdata()<<"\t";
            }
            temp = temp->getright();
        }
    }
}
node* tbt::inorder_succ(node *p)
{
    if (p->getrbit() == 0)
    {
        return p->getright();
    }
    p = p->getright();
    while( p->getlbit() == 1)
    {
        p = p->getleft();
    }
    return p;
}
void tbt::in()
{
    inorder(root);
}

int main()
{
	char ans;
    tbt tree;
    do
    {
        cout<<"\n\t\tMENU:\n\n\t\t1. CREATE TBT\n\t\t2. INSERT A DATA IN TBT\n\t\t3. TBT INORDER DISPLAY\\n";
        cout<<"\n\tChoice : ";
        char ch;
        cin>>ch;

        int n=0;
        switch(ch)
        {
        case '1' :
                cout<<"\n HOW MANY NODES DO YOU WANT: ";
                cin>>n;
                tree.create_tree(n);
            break;
        case '2' :
                cout<<"\n INSERT ELEMENT : ";
                int val;
                cin>>val;
                tree.insert_node(val);
                n++;
            break;
        case '3' :
                cout<<"\n INORDER TRAVERSAL : \n";
                tree.in();
            break;
        default :
            cout<<"\n PLZ ENTER A VALID OPTION !! \n";
        }

        cout<<"\n TO CONTINUE, PRESS (Y/y) : ";
        cin>>ans;
        cout<<endl;
    }while(ans == 'Y' || ans == 'y');
	cout<<"\n\n";
    return 0;
}




