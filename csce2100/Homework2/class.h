class Node{               //this is the node class  
        public:
                int data;
                Node *next;
                Node *prev;
        public:
                Node();
		void addleft(int num);  //function to addleft
		void addright(int num); //function to addright
        };


class List{               //this is the list class
        public:
                Node* tail;      //pointer to tail of list
                Node* head;      //pointer to head
                Node* id;	 //pointer to current 
		Node* print;     //print pointer
		Node* search;    //search pointer
		Node* temp;	 //temporary pointer
		Node* left;      //left pointer
        public:
                List();
        };
