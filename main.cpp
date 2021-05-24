// nicole kurtz
#include "weekly.h"
using namespace std;

// protypes
void create_user(user & new_user);

int main()
{
	int response;
	user new_user;
	
	create_user(new_user);
	new_user.welcome();
	do{
	new_user.menu(response);
	}while(response != 7);
	//add_item();
	return 0;
};

// create user for calendar
void create_user(user & new_user)
{
	char name[100];
	char birthdate[100];

	cout << endl << "----Create User Profile----" << endl;

	cout << "Enter User Name: ";
	cin.get(name, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Enter User Birth Date: ";
	cin.get(birthdate, 100, '\n');
	cin.ignore(100, '\n');
	
	if(new_user.create_user(name, birthdate))
		cout << endl << "User profile created!" << endl;
	else
		cout << endl << "User Profile Creation Failed" << endl;
}



