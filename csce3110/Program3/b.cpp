/*************** 
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 3
Due Date: 10/24/15
****************/

#include<cstdlib>
#include<iostream>
#include<string>
#include"BST.h"
using namespace std;

BST::BST()				//constructor
{
        root= NULL;			//initializing root
}
BST* BST::createleaf(int key)		//creating the bst
{
        BST* n = new BST;
        n->key = key;
        n->left = NULL;
        n->right = NULL;

        return n;
}

void BST::addleaf(int key)
{
        addleafprivate(key, root);
}

void BST::addleafprivate(int key, BST* ptr)
{
        if(root == NULL)			//checking for empty tree
        {
                root = createleaf(key);		//calling the createleaf function to make a tree
        }
        else if(key< ptr->key)			//checking for smaller number
        {
                if(ptr->left != NULL)		//checking for empty spot
                {
                        addleafprivate(key, ptr->left);	//recursive call to move left one
                }
                else
                {
                        ptr->left = createleaf(key);	//if empty spot place here
                }
        }
        else if(key > ptr->key)				//checking for empty tree
        {
                if(ptr->right != NULL)		//checking for empty spot
                {
                         addleafprivate(key, ptr->right); //recursive call to move right one
                }
                else
                {
                        ptr->right = createleaf(key);   //if empty spot place here
                }
        }
        else
        {
                cout<< "the key "<<key<< " has already been added"<<endl; //if the key is already in the tree
        }
}

void BST::print()
{
        printprivate(root);
}

void BST::printprivate(BST *ptr)
{
        if(root != NULL)				//checking for a non empty tree
        {
                if(ptr->left != NULL)			//checking for an item in left node
                {
                        printprivate(ptr->left);	//if item recursively call
                }
		
                cout<<ptr->key<< " ";			//print node smallest to largest

                if(ptr->right != NULL)			//checking for an item in left node
                {
                        printprivate(ptr->right);	//if item recursively call
                }
        }
        else
        {
                cout<<"empty tree"<<endl;		//else for empty tree
        }
}

BST* BST::returnnode(int key)
{
	return returnnodeprivate(key, root);
}

BST* BST::returnnodeprivate(int key, BST* ptr)		//this is a helper function
{
	if(ptr != NULL)				//checking for a node
	{
		if(ptr->key == key)		//checking for node found
		{
			return ptr;		//return a pointer to that position
		}
		else
		{
			if(key< ptr->key)	//checking if the number is less than the current postition number
			{
				return returnnodeprivate(key, ptr->left);	//recursive call with left pointer
			}
			else
			{
				return returnnodeprivate(key, ptr->right);	//recursive call with right pointer
			}
		}
	}
	else
	{
		return NULL;		//no node found
	}
}

int BST::returnrootkey()	//helper function used to move from the root to other nodes in the tree
{
	if(root != NULL)
	{
		return root->key;
	}
	else
		return -1000;
}

void BST::printchildren(int key)
{
	BST* ptr = returnnode(key);		//creating a pointer with the node

	if(ptr != NULL)
	{
		cout<<"Parent node = "<<ptr->key<<endl;		//printing the parent node
		
		if(ptr->left == NULL)				//checking
		{
			cout<<"left child is NULL"<<endl;	
		}
                if(ptr->right == NULL)				//checking
                {
                        cout<<"right child is NULL"<<endl;             
                }
		if(ptr->left != NULL)					//now that i got rid of the else ifs here it is kinda working
		{
			cout<<"Left child = "<< ptr->left->key<<endl;
//			printchildren(ptr->left->key);
		}
		if(ptr->right != NULL)					//and here
		{       
		        cout<<"right child = "<< ptr->right->key<<endl;
//			printchildren(ptr->right->key);
		}
	}
		
	else
	{
		cout<<"the node "<<key<<"is not in the tree"<<endl;
	}
}

int BST::findsmallest()
{
	return findsmallestprivate(root);
}

int BST::findsmallestprivate(BST* ptr)
{	
	if(root == NULL)			//checking for an empty tree
	{
		cout<<"Empty tree"<<endl;
		return -1000;
	}
	else if(check != true)
	{
		if(ptr->right != NULL)			// i want it to recursively call the function but look only in the right nodes of the left side
		{
			return findsmallestprivate(ptr->right);
 		}
		else
		{
			return ptr->key;		//return the largest number (right) in the left subtree of the root
			check = true;
		}
	}
	else if(check != false)
	{
                if(ptr->left != NULL)                  // i want it to recursively call the function but look only in the right nodes of the left side
                {
                        return findsmallestprivate(ptr->left);
                }
                else
                {
                        return ptr->key;                //return the largest number (right) in the left subtree of the root
                        check = false;
                }
	}
}

void BST::removenode(int key)
{
	removenodeprivate(key, root);
}

void BST::removenodeprivate(int key, BST* parent)
{
	if(root != NULL)
	{
		if(root->key == key)		//checking if the root is what the user wants to get rid of
		{
			removerootmatch();
		}
		else				//all other cases
		{
			if(key < parent->key && parent->left != NULL)	//checking if the user entered a number smaller than the root
			{
				parent->left->key == key ?
				removematch(parent, parent->left, true):
				removenodeprivate(key, parent->left);
			}
			else if(key > parent->key && parent->right != NULL)	//checking if the user entered a number greater than the root
			{
			        parent->right->key == key ?
			        removematch(parent, parent->right, false):
			        removenodeprivate(key, parent->right);
			}
			else
				cout<<"key not found in tree"<<endl;		//if the user entered a number not in the tree
		}
	} 
	else
		cout<<"empty tree"<<endl;
}

void BST::removerootmatch()			//this function basically deletes the root and calls a function which replaces the root and deletes that node
{
	if(root != NULL)		//checking for a non empty tree
	{
		BST* delptr = root;
		int rootkey= root->key;
		int largestinleftsubtree;

		if(root->left== NULL && root->right == NULL)		
		{
			root= NULL;
			delete delptr;
		}
		else if(root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delptr->right = NULL;
			delete delptr;
			cout<< rootkey<< " was deleted"<<endl;
			cout<<"the new root contains: "<< root->key <<endl;
		}
		else if(root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delptr->left = NULL; 
			delete delptr; 
			cout<< rootkey<< " was deleted"<<endl;
			cout<<"the new root contains: "<< root->key <<endl; 			
		}
		else if(check != true)									//if the root has two subtrees
		{
			largestinleftsubtree = findsmallestprivate(root->left);		//supposed to be findlargestprivate but too lazy to change name
			removenodeprivate(largestinleftsubtree, root);
			root->key = largestinleftsubtree;
			check = true;
		}	
		else if(check != false)                                                                  //if the root has two subtrees
		{
		        largestinleftsubtree = findsmallestprivate(root->right);         //supposed to be findlargestprivate but too lazy to change name
		        removenodeprivate(largestinleftsubtree, root);
		        root->key = largestinleftsubtree;
			check = false;
		}
	}
	else
		cout<<"empty tree"<<endl;
}

void BST::removematch(BST* parent, BST* match, bool left)	//this function does the same as the above function but for any subroots
{
	if(root != NULL)
	{
		BST* delptr;
		int matchkey = match->key;
		int largestinleftsubtree;

		if(match->left == NULL && match->right == NULL)
		{
			delptr= match;
			left == true ?
			parent->left=NULL:
			parent->right=NULL;
			delete delptr;
		}
		else if(match->left == NULL && match->right != NULL)
		{
			left==true ? 
			parent->left=match->right: 
			parent->right = match->right;
			match->right = NULL;
			delptr = match;
			delete delptr;
		}
		else if(match->left != NULL && match->right == NULL)
		{
			left==true ?
			parent->left=match->left: 
			parent->right = match->left;
			match->left=NULL;
			delptr = match;
			delete delptr;
		}
		else
		{
			largestinleftsubtree = findsmallestprivate(match->left);
			removenodeprivate(largestinleftsubtree, match);
			match->key = largestinleftsubtree;
			delete delptr;
		}
	}
	else
	{
		cout<<"the tree is empty"<<endl;
	}
}




