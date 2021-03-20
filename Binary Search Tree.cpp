#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
};
node* root=NULL;
void insert(node *tree, node *leaf)
{
    if (root == NULL)
    {
        root = new node;
        root->data = leaf->data;
        root->left = NULL;
        root->right = NULL;
        cout<<"Added at root"<<endl;
        return;
    }
    if (tree->data == leaf->data)
    {
        cout<<"Number already in the tree"<<endl;
        return;
    }
    if (tree->data > leaf->data)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, leaf);	
    	}
    	else{
            tree->left = leaf;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Number Added To Left"<<endl;
            return;
        }
    }
    else{
        if (tree->right != NULL)
        {
            insert(tree->right, leaf);
        }
        else
        {
            tree->right = leaf;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Number Added To Right"<<endl;
            return;
        }	
    }
}




void display(node *ptr, int lvl)
{
    int i;
    if (ptr != NULL){
        display(ptr->right, lvl+1);
        cout<<endl;
           if (ptr == root)
            cout<<"Root->:  ";
           else
           {
            for (i = 0;i < lvl;i++)
            cout<<"     ";
	        }
        cout<<ptr->data;
        display(ptr->left, lvl+1);
    }
}


int main(){
    node *temp;
    int choice, num;

     while (1)
    {
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node;
            cout<<"Enter the number to be inserted : ";
	        cin>>temp->data;
            insert(root, temp);
            break;
        case 2:
            cout<<"Display:"<<endl;
            display(root,1);
            cout<<endl;
            break;
        case 3:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
return 0;
}
