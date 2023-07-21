/*Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.*/

#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
//=============== MAX HEAP =====================
class max_heap
{
    int last_pos,marks[100];
    string name[100];
public:
    max_heap()
    {
        last_pos = -1;
    }
    void insert_data(int,string);
    void reHeapUp(int);
    void swap_data(int,int);
    void display_max();
};
void max_heap::insert_data(int val,string n)
{
    last_pos++;
    marks[last_pos] = val;
    name[last_pos] = n;
    reHeapUp(last_pos);
}
void max_heap::reHeapUp(int child)
{
    int parent = (child-1)/2;
    if(parent >= 0)
    {
        if(marks[parent]<marks[child])
        {
            swap_data(parent,child);
            reHeapUp(parent);
        }
    }
}
void max_heap::swap_data(int x,int y)
{
    int temp;
    string temp2;
    temp = marks[x];
    marks[x] = marks[y];
    marks[y] = temp;
    temp2 = name[x];
    name[x] = name[y];
    name[y] = temp;
}
void max_heap::display_max()
{
    cout<<endl;
    if(last_pos<0)
    {
        cout<<"\nNo data to display\n";
        return;
    }
    cout<<"\n\tMaximum marks obtained by :\n\n\t\t"<<name[0]<<" :: "<<marks[0]<<" marks";
}
//================= MIN HEAP =====================
class min_heap
{
    int last_pos,marks[100];
    string name[100];
public:
    min_heap()
    {
        last_pos = -1;
    }
    void insert_data(int,string);
    void reHeapUp(int);
    void swap_data(int,int);
    void display_min();
};
void min_heap::insert_data(int val,string n)
{
    last_pos++;
    marks[last_pos] = val;
    name[last_pos] = n;
    reHeapUp(last_pos);
}
void min_heap::reHeapUp(int child)
{
    int parent = (child-1)/2;
    if(parent >= 0)
    {
        if(marks[parent]>marks[child])
        {
            swap_data(parent,child);
            reHeapUp(parent);
        }
    }
}
void min_heap::swap_data(int x,int y)
{
    int temp;
    string temp2;
    temp = marks[x];
    marks[x] = marks[y];
    marks[y] = temp;
    temp2 = name[x];
    name[x] = name[y];
    name[y] = temp;
}
void min_heap::display_min()
{
    cout<<endl;
    if(last_pos<0)
    {
        cout<<"\nNo data to display\n";
        return;
    }
    cout<<"\n\tMinimum marks obtained by :\n\n\t\t"<<name[0]<<" :: "<<marks[0]<<" marks";
}

int main()
{
    int ans;
    max_heap h_max;
    min_heap h_min;
    do
    {
    	cout<<"\n\t\t SYSTEM FOR S.E. ONLINE EXAMINATION\n";
        cout<<"\n\t\t********MENU********* ";
        cout<<"\n\t\t1.Insert Marks\n\t\t2.Display maximum and minimum marks";
        int choice;
        cout<<"\nEnter choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1 :
        {
            int n=0;
            cout<<"\nEnter number of data to insert : ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                int data;
                string name;
                cout<<"\n\nRoll no. : "<<i+1;
                cout<<"\nEnter name : ";
                cin>>name;
                cout<<"Enter marks : ";
                cin>>data;
                h_max.insert_data(data,name);
                h_min.insert_data(data,name);
            }
            break;
        }
        case 2:
            h_max.display_max();
            h_min.display_min();
            break;
        default :
            cout<<"\nPlease enter a valid option\n";
        }
        cout<<"\n To continue, press 1 : ";
        cin>>ans;
    }while(ans == 1);

    return 0;
}

