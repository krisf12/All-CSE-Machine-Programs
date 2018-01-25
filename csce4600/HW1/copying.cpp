#include<iostream>
#include<cstdlib>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>

using namespace std;

int main(void)
{
	char file_r[150], file_w[150];
	char buff[1]={0};
	int readed, written, wcount=0;
	clock_t begin, end;
	double time;
	
	cout<<"file to be read from: ";
	cin>>file_r;
	cout<<endl;
	cout<<"file to be written to: ";
	cin>>file_w;
	cout<<endl;

	readed = open(file_r, O_RDONLY);
	written = open(file_w, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR); 

	begin = clock();	

	while(read(readed, buff, 1) >0)
	{
		wcount = write(written, buff, 1);
	}

	end = clock();
	time = (double)(end-begin)/CLOCKS_PER_SEC;
	cout<<"execution time: "<<time<<endl;


	close(readed);

return 0;
}
