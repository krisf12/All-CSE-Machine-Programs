/*************** 
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 3
Due Date: 10/24/15
****************/

#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

class BST{
        private:
		
		int key;
		BST* left;
               	BST* right;
               	BST* root;

		void addleafprivate(int key, BST* ptr);
		void printprivate(BST* ptr);
		BST* returnnodeprivate(int key, BST* ptr);
		int findsmallestprivate(BST* ptr);
		void deleteleafprivate(int key, BST* ptr);
		void removenodeprivate(int key, BST* parent);
		void removerootmatch();
		void removematch(BST* parent, BST* match, bool left);
		
        public:
                BST();
                BST* createleaf(int key);
                void addleaf(int key);
		void print();
		void deleteleaf(int key);
		BST* returnnode(int key);
		int returnrootkey();
		void printchildren(int key);
		int findsmallest();
		void removenode(int key);
		bool check;	
};

