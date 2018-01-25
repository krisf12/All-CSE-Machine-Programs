using namespace std;
class Menu
{
	public:
	void printmenu();
};


class Course
{
        private:
                int courseid;
                string coursename;
                Course *next;

        public:
                Course();
                void setcourse(int, string);
                void setnext(Course*);
		int getid();
		Course* getnext();
};


class Student
{
	private: 
		int studentid;
		string studentname;
		Student *next;

	public:
		Student();
		void setstudent(int, string);
		void setnext(Student*);
		int getid();
		Student* getnext();
};


class Enrollment
{
	private:
		int grade[20];
		int courseids;
		int studentids;
		Course* course;
		Student* student;
		string coursenames;
		Enrollment *next;

	public:
		Enrollment();
		void setenroll(int, int, string);
		void setnext(Enrollment*);
		int getstudentid();
		int getcourseid();
		
		Enrollment *getnext();
		void addgrades(int);
		void printgrades(int);
		void printstuincourse();
};
