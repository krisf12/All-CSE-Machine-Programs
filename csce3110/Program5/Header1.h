/*************** 
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 5
Due Date: 12/3/15
****************/

#include<cstdlib>
#include<iostream>
using namespace std;

struct node{
    int stuff;
    node *next;
};

class Queue{

	private:
        	node *front;
        	node *back;

	public:
        	Queue();
        	bool isEmpty();
        	void enqueue(int);
        	int dequeue();
};

class Graph{

        private:
                int n;
                int **arr;
        public:
                Graph(int size = 2);
                bool Connected(int, int);
                void addEdge(int u, int v);
                void BFS(int);
};

Queue::Queue() 
{
	front = NULL;
	back = NULL;
}

void Queue::enqueue(int data) 
{
	node *no = new node();
	no->stuff = data;
	no->next = NULL;
	if(front == NULL)
	{
       		front = no;
    	}
	
	else
	{
        	back->next = no;
    	}
    	back = no;
}

int Queue::dequeue() 
{
    node *qu = new node();
    int val;

	if(front == NULL)
	{
        	cout<<"\nQueue is Empty\n";
    	}
	
	else
	{
        	qu = front;
        	val = qu->stuff;
        	front = front->next;
        	delete qu;
    	}
    	return val;
}

bool Queue::isEmpty() 
{
	return(front == NULL);
}

Graph::Graph(int size) 
{
	int i, j;
    	if (size < 2) 
		n = 2;
    	else 
		n = size;

    		arr = new int*[n];

    	for(i = 0; i < n; ++i)
    	    	arr[i] = new int[n];

    	for(i = 0; i < n; ++i)
    	    for(j = 0; j < n; ++j)
    	        arr[i][j] = 0;
}

bool Graph::Connected(int u, int v) 
{
	return(arr[u-1][v-1] == 1);
}

void Graph::addEdge(int u, int v) 
{
	arr[u-1][v-1] = arr[v-1][u-1] = 1;
}

void Graph::BFS(int s) 
{	
	Queue Q;
 
	bool *explored = new bool[n+1];
	bool connected;
 
    	for(int i = 1; i <= n; ++i)
    	explored[i] = false;
 
    	Q.enqueue(s);
    	explored[s] = true; /** mark it as explored */
    	cout<<"Breadth first Search starting from vertex ";
    	cout<<s<<" : "<<endl;
 
    	while(!Q.isEmpty()) 
	{
        	int v = Q.dequeue();
 
        	cout<<v<< " ";
 
        	for (int w = 1; w <= n; ++w)
 
            	if (Connected(v, w) && !explored[w]) 
		{
                	Q.enqueue(w);
                	explored[w] = true;
			connected = true;
            	}
    	}
	
	if(connected == true)
	{
		cout<<" the graph is connected";
	}
    cout<<endl;
    delete[]explored;
}
