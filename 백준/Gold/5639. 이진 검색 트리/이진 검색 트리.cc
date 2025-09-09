#pragma once
#include <iostream>
#include<stack>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* MakeNode(int n)
{
	node* nd = new node;
	nd->data = n;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
node* root = NULL;

void Insert(node* r, node* node)
{
	if (root == NULL) root = node;
	else if (r->data < node->data)
	{
		if (r->right == NULL)
		{
			r->right = node;
		}
		else
		{
			Insert(r->right, node);
		}
	}
	else if (r->data > node->data)
	{
		if (r->left == NULL)
		{
			r->left = node;
		}
		else
		{
			Insert(r->left, node);
		}
	}
}

void PreOrder(node* nd)
{
	if (nd == NULL) return;

	if (nd->left != NULL)
	{
		PreOrder(nd->left);

	}
	if (nd->right != NULL)
	{
		PreOrder(nd->right);
	}

	cout << nd->data << "\n";


}

int main()
{
	int value;
	while (cin >> value)
	{
		Insert(root, MakeNode(value));
	}
	PreOrder(root);
}