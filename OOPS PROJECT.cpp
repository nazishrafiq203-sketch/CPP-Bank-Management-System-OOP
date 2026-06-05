#include<iostream>
#include<string>
using namespace std;
class Bank{
	private:
		static int nextAccNumber;
		int Accnumber;
		int Accpassword;
		double balance;
	public:
		string name;
		Bank()
		{ 
		  Accpassword= 0;
		  balance = 0.0;
		  Accnumber= ++nextAccNumber;
		}
	    void createaccount()
	    {
	    	cout<<"Enter your name"<<endl;
	    	cin>>name;
	    	    while (true)
    {
        cout << "Enter 5 digit password" << endl;
        cin >> Accpassword;
        if (Accpassword >= 10000 && Accpassword <= 99999)
        {
            cout << "Password is accepted" << endl;
            break; 
        }
        else
        {
            cout << "Invalid! Please enter exactly 5 digits." << endl;
        }
    }
			cout<<"deposit amount "<<endl;
			cin>>balance;
		}
		void setnumber(int acc)
		{
			Accnumber=acc;
		}
		void Display()
		{
			cout<<"NAME: "<<name<<endl;
			cout<<"ACCOUNT NUMBER: "<<Accnumber<<endl;
			cout<<"PASSWORD: "<<Accpassword<<endl;
			cout<<"Your Balance: "<<balance<<endl;
		}
		bool verify()
		{
			int pass;
			cout<<"Enter your Password"<<endl;
			cin>>pass;
			if(pass == Accpassword)
			{
				return true;
			}
			else
			{
				cout<<"Incorrect Password"<<endl;
				return false;
			}
		}
		void Withdraw()
		{if(verify()){
			double amount;
			cout<<"How much money would you like to withdraw"<<endl;
			cin>>amount;
			if(amount>0 && amount <=balance)
			{   balance -= amount;
				cout<<"Withdrawal Successful"<<endl;
			}
			else
			{
				cout<<"Invalid Value"<<endl;
			}
			cout<<"Your Current Balance is "<<balance<<endl;
	}
		}
				void Deposit()
		{if(verify()){
			double amount;
			cout<<"How much money would you like to deposit"<<endl;
			cin>>amount;
			if(amount>0)
			{   balance += amount;
				cout<<"Deposit Successful"<<endl;
			}
			else
			{
				cout<<"Invalid Value"<<endl;
			}
			cout<<"Your Current Balance is "<<balance<<endl;
	}
		}
		void checkbalance()
		{
			cout<<"Your Current Balance is "<<balance<<endl;
		}		
};
int Bank ::nextAccNumber = 100000;
int main()
{
	Bank b;
	int choice;
	bool running = true;
	while(running){
		cout<<endl;
	cout<<"      WELCOME TO OUR BANK        "<<endl;
	cout<<"Press 1 to Create an Account"<<endl;
	cout<<"Press 2  if you already have an account"<<endl;
	cout<<"Press 0 to logout "<<endl;
	cout<<"Press 3 to check your balance"<<endl;
	cout<<"Enter your choice "<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			b.createaccount();
			b.Display();
			break;
		case 2:
			int action;
			cout<<"Press 1 for withdawal "<<endl;
			cout<<"Press 2 for Deposit "<<endl;
			cin>>action;
			switch(action){
				case 1:
					b.Withdraw();
					break;
				case 2:
					b.Deposit();
					break;
				default:
					cout<<"invalid value"<<endl;
			}
			break;
		case 3:
			b.checkbalance();
			break;
		case 0:
			cout<<"you have been logged out"<<endl;
			running = false;
			break;
		default:
			cout<<"invalid value "<<endl;
	}
}
	return 0;
}

