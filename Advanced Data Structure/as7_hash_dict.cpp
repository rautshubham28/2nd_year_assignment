/*Implement all the functions of a dictionary (ADT) using hashing.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique
Standard Operations: Insert(key, value), Find(key), Delete(key)*/

#include<iostream>
#include<string.h>
using namespace std;

class node
{
	char data[30];
	char meaning[50];
	node *next;
	public:
		node()
		{
			next = NULL;
		}
		friend class dictionary;
};

class dictionary
{
	node* table[101];
	public:
		dictionary()
		{
			for(int i=0;i<101;i++)
			{
				table[i] = NULL;
			}
		}

		void create();
		void insert();
		node* search();
		void update_data();
		void delete_data();
		void display();
		int sum(char*);
};
void dictionary::create()
{
	int num;
	cout<<"\nEnter the number of words you want to Enter : ";
	cin>>num;
	for(int k = 0; k < num; k++)
	{
		insert();
	}
}
void dictionary::insert()
{
	char word[30],mean[50];
	cout<<"\nEnter Word to insert : ";
	cin>>word;
	cout<<"\nEnter meaning of "<<word<<" : ";
	cin>>mean;
	int ascii_sum;
	ascii_sum = sum(word);
	int key = ascii_sum % 101;
	node *nn = new node();
	strcpy(nn->data,word);
	strcpy(nn->meaning,mean);
	if(table[key] == NULL)
		table[key] = nn;
	else
	{
		node *temp;
		temp = table[key];
		while(temp->next != NULL)
			temp = temp->next;

		temp->next = nn;
	}
}
node* dictionary::search()
{
	char word[30];
	cout<<"\nEnter Word to Search : ";
	cin>>word;
	int ascii_sum;
	ascii_sum = sum(word);

	int key = ascii_sum % 101;

	if(table[key] == NULL)
	{
		cout<<"\nWord not found\n";
		return NULL;
	}
	else
	{
		node *temp = table[key];
		int flag = 0;
		while(temp != NULL)
		{
			if(strcmp(temp->data,word)==0)
			{
				flag = 1;
				cout<<"\nWord Found\n";
				cout<<temp->data<<"\t ->> "<<temp->meaning<<endl;
				return temp;
			}
			temp = temp->next;
		}

		if(flag == 0)
			cout<<"\nWord not found\n";
	}
	return NULL;
}
void dictionary::update_data()
{
	cout<<"\nSearch the data you want to update : \n";
	node* point = search();
	if(point == NULL)
		return;
	char mean[50];
	cout<<"\nEnter new meaning of "<<point->data<<" : ";
	cin>>mean;
	strcpy(point->meaning,mean);
	cout<<"\n Data updated Successfully\n";
}
void dictionary::delete_data()
{
	cout<<"\nSearch the data you want to delete : \n";
	char word[30];
	cout<<"\nEnter Word to Search : ";
	cin>>word;
	int ascii_sum;
	ascii_sum = sum(word);

	int key = ascii_sum % 101;

	if(table[key] == NULL)
	{
		cout<<"\nWord not found, can't be deleted\n";
		return;
	}
	else
	{
		node *temp = table[key],*prev = table[key];
		int flag = 0;
		while(temp != NULL)
		{
			if(strcmp(temp->data,word)==0)
			{
				flag = 1;
				cout<<"\nWord Found\n";
				cout<<temp->data<<"\t ->> "<<temp->meaning<<endl;
				if(temp == table[key])
                {
                    table[key] = temp->next;
                    delete(temp);
                    cout<<"\n Word Deleted Successfully ";
                    return;
                }
				while(prev->next != temp)
					prev = prev->next;
				break;
			}
			temp = temp->next;
		}

		if(flag == 0)
		{
			cout<<"\nWord not found,can't be deleted\n";
			return;
		}

		prev->next = temp->next;
		delete(temp);
		cout<<"\n Word Deleted Successfully ";
	}
}
void dictionary::display()
{
	for(int i=0;i<101;i++)
	{
		cout<<endl<<endl<<i<<endl;
		if(table[i] == NULL)
			cout<<"--------";
		else
		{
			node *temp = table[i];
			while(temp != NULL)
			{
				cout<<temp->data<<"\t"<<temp->meaning<<endl;
				temp = temp->next;
			}
		}
	}
	cout<<endl;
}
int dictionary::sum(char *word)
{
	int i=0,ascii_sum=0;

	while(word[i] != 0)
	{
		char temp = word[i];
		ascii_sum += (int)temp;
		i++;
	}
	return ascii_sum;
}

int main()
{
    dictionary d;
    char ans;
    do
    {
        char choice;
        cout<<"\n\tMENU: ";
        cout<<"\n\t\t1. CREATE DICTIONARY\n\t\t2. INSERT A WORD IN DICTIONARY\n\t\t3. SEARCH MEANING OF A WORD IN DICTIONARY";
        cout<<"\n\t\t4. UPDATE MEANING OF A WORD\n\t\t5. DELETE A WORD FROM DICTIONARY\n\t\t6. DISPLAY DICTIONARY\n";
        cout<<"\n\tEnter Your choice : ";
        cin>>choice;
        switch(choice)
        {
            case '1' :
                d.create();
                break;
            case '2' :
                d.insert();
                break;
            case '3' :
                node *t;
                t = d.search();
                break;
            case '4' :
                d.update_data();
                break;
            case '5' :
                d.delete_data();
                break;
            case '6' :
                d.display();
                break;
            default :
                cout<<"\n Please enter a valid choice \n";
        }
        cout<<"\n To continue press Y : ";
        cin>>ans;
        cout<<endl;
	}while(ans == 'y' || ans == 'Y');
	cout<<"\n\n";
	return 0;
}
