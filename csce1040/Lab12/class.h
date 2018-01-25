class Bank
{

private:
int Account[10];  //the accounts must be private

public:  //the functions are public 
Bank();
void deposit(int num, int value);
void withdraw(int num, int value);
void balance(int num);
void transfer(int num1, int num2, int value);

};
