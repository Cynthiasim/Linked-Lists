//  Cynthia Simon
//  csimon2@leomail.tamuc.edu
//  Assignment #3
//  Linked Lists

#include <iostream>

using namespace std;

struct node //creating node
{
    int data;
    node *next, *prev;
};

class DLList //creating doubly linked list
{
private:
    struct node *head, *tail;
public:
    DLList() // constructor
    {
        head=NULL;
        tail=NULL;
    }
    
    void add(int value) //add function
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    
    void toString() // return string function
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->next != NULL){
                cout<<",";
            }
            temp=temp->next;
        }
    }
    void deleteNode(int el) //delete node function
    {
        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;
    }
    
    int find(int value) //find value function
    {
        int pos = 0;
        bool flag = false;
        if (head == NULL)
        {
            return -1;
        }
        
        struct node *temp;
        temp = head;
        while (temp != NULL)
        {
            pos++;
            if (temp->data == value)
            {
                flag = true;
                return pos;
            }
            temp = temp->next;
        }
         if (!flag)
          return -1;
    };
    
    int& operator[](int i)  //return address function
    {
        int j=1;
        struct node *temp;
        temp = head;
        for(j=0;j<i;j++){
            temp = temp->next;
        }
        return temp->data;
    }
};

class MySet  //create class MySet
{
private:
    DLList items;
    int size;
public:
    MySet()
    {
        size=0;
    }
    void add(int el)
    {
        if(items.find(el)==-1){
            items.add(el);
            size++;
        }
    }
    int getSize() const{
        return size;
    }
    bool isEmpty() const{
        if(size==0)
            return true;
        else
            return false;
    }
    void removeItem(int el)
    {
        items.deleteNode(el);
    }
    void toString()
    {
        cout<<"[";
        items.toString();
        cout<<"]\n";
    }
};


int main() //main function
{
    MySet s;
    s.add(5);
    s.add(6);
    s.add(7);
    s.toString();
    
    return 0;
}
