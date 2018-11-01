#include<bits/stdc++.h>
using namespace std;

struct node
{

int data;
node * left;
node * right;
};

node * newnode(int data)
{
	node * temp = new node;
		
	temp->data  = data;
	temp->left  = NULL;
	temp->right = NULL;
	return temp;
}

node * add(node * head , int data)
{
	if(head==NULL)
	{
		head = newnode(data);
		return head;
	}
	
	
	else if ( data <= head->data)
	{
		head->left = add(head->left , data);
	}
	
	else if(data > head->data)
	{
		head->right = add(head->right , data);
	}
	
	return head;
}

void search(node * head, int query)
{
	if(head == NULL)
	{
	
		exit(1);
	}
	
	if(query==head->data)
	{
		cout << "FOUND" << endl;
		exit(2);
	}
	
	else if(query < head->data)
	{
	  head = head->left;	
	  search(head , query);
	}
	
	else if ( query > head->data)
	{
		head = head ->right;
		search(head , query);
    }
}


int main()
{
	node * head = NULL;
	head = add(head , 10);
	head = add(head , 20);
	head = add(head , 300);
	
	search(head , 10);	
	
	search(head , 20);
}
