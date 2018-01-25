#include<iostream>
#include<fstream>

using namespace std;

class heap{

	public:
		heap();

		int Minheap[500];
		int Minheap2[500];
		int number;

		void insert();
		void change();
		void sortheap();
		void deleteitem();
		void printheap(ofstream &myfile);
};
