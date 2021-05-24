#include "weekly.h"
using namespace std;

// Nicole Kurtz


///////* WNODE CLASS *////////

// This class manages a doubly linked node that points
// to an item. Each node contains a day object that names
// what day of the week it is. 

// default constructor
wnode::wnode(): next(NULL), prev(NULL)
{
}

// copy constructor
wnode::wnode(const wnode *& tocopy)
{
	day = new char[strlen(tocopy->day) + 1];
	strcpy(day, tocopy->day);

	head = new node(tocopy->head);
}

// deconstructor
wnode::~wnode()
{
	if(day)
		delete [] day;
	if(head)
		delete_list(head);
}

// find item in list
bool wnode::find_item(char * name)
{
	if(!head) return false;
	
	bool found = false;
	if(find_item(head, name, found))
	{
		if(found)
			return true;
		else
			return false;
	}
	return false;
}

// recursive function to find item in list
bool wnode::find_item(node *& head, char * name, bool & found)
{
	bool check = false;

	if(!head) return true;

	if(head->find_item(name, check))
	{
		found = true;

		// check to amke sure this wasn't a todo that was deleted
		if(!check)
		{
			node * hold = head->get_next();
			delete head;
			head = hold;
			cout << "The item was deleted on " << day << endl;
			return find_item(head, name, found);
		}

		else
			cout << "The item was deleted on " << day << endl;
	}

	return find_item(head->get_next(), name, found);
}

// delete wnode list
void wnode::delete_list(node *& head)
{
	if(!head)
		return;

	node * hold = head->get_next();
	delete head;
	head = hold;

	return delete_list(head);
}

// set next node to connection 
void wnode::set_next(wnode *& connection)
{
	next = connection;
}

// set previous node to connection
void wnode::set_prev(wnode *& connection)
{
	prev = connection;
}

// display day contents
bool wnode::display()
{
	cout << endl << endl << day << endl;
	cout << "--------" << endl;

	if(display_item())
		return true;

	return false;
}

// display items 
bool wnode::display_item()
{
	if(!head)
		return false;
	return display_item(head);
}

// display item recursively
bool wnode::display_item(node * head)
{
	if(!head)
		return false;

	if(!head->display())
		return false;

	return display_item(head->get_next());
}

// add calendar item to DLLL
bool wnode::set_down(item *& ptr)
{
	node * temp = new node(ptr);
	
	// if it's an empty list, make head temp
	if(!head)
	{
		head = temp;
		return true;
	}

	// otherwise, set temp to head
	else
	{
		temp->set_down(head);
		head = temp;
		return true;
	}
	return false;

}

// add day to each node
void wnode::add_day(int counter)
{
	day = new char[11];

	if(counter == 1)
		strcpy(day, "Monday");
	if(counter == 2)
		strcpy(day, "Tuesday");
	if(counter == 3)
		strcpy(day, "Wednesday");
	if(counter == 4)
		strcpy(day, "Thursday");
	if(counter == 5)
		strcpy(day, "Friday");
	if(counter == 6)
		strcpy(day, "Saturday");
	if(counter == 7)
		strcpy(day, "Sunday");
}

// return the next node
wnode *& wnode::get_next()
{
	return next;
}

// return the prev node
wnode *& wnode::get_prev()
{
	return prev;
}

// compare day data to user input
bool wnode::compare_day(char * tofind)
{
	if(strcmp(day, tofind) == 0)
		return true;
	return false;
}

// clear item in node
bool wnode::clear_items()
{
	if(!head)
		return false;
	return clear_items(head);
}

// clear items in node recursively
bool wnode::clear_items(node *& head)
{
	if(!head) return true;

	node * hold = head->get_next();
	delete head;
	head = hold;

	return clear_items(head);
}


////////* WEEKLY FUNCTION *////////

// This class manages the functions of a doubly linked list
// of days of the week. 
// It has a wnode that points to a lll of nodes

// default constructor
weekly::weekly(): head(NULL)
{
	int counter = 1;
	create_week(head, counter);
}

// copy constructor
weekly::weekly(const weekly & to_copy)
{
}

// deconstructor 
weekly::~weekly()
{
	if(head)
		delete_calendar_items(head);
}

// create a week of linear items
void weekly::create_week(wnode *& head, int & counter)
{
	if(counter == 8)
		return;
	
	wnode * temp = new wnode;
	temp->add_day(counter);
	
	// if there's no head, set temp to head
	if(!head)
	{
		head = temp;
		++counter;
		return create_week(head, counter);
	}

	// otherwise add before head and rename head
	else
	{
		head->set_next(temp);
		temp->set_prev(head);
	}

	++counter;
	return create_week(head->get_next(), counter);
}

// add calendar item
bool weekly::add_calendar_item(wnode *& toadd)
{
	int response;


	cout << endl << "---calendar types---" << endl;
	cout << "1 -- class lecture" << endl;
	cout << "2 -- to do list" << endl;
	cout << "3 -- work" << endl;
	cout << "-----------" << endl;

	cout << "enter the number of the calendar item you would like to create: ";
	cin >> response;
	cin.ignore(100, '\n');

	switch(response)
	{
		// create a lecutre item
		case 1:
		{
			item * ptr = new lecture();
			ptr->add_item();
			toadd->set_down(ptr);
			delete ptr;
			return true;
		}
	
		// create todo item
		case 2:
		{
			item * ptr = new todo();
			ptr->add_list();
			toadd->set_down(ptr);
			delete ptr;
			return true;
		}
		
		// create work item
		case 3:
		{
			item * ptr = new work;
			ptr->add_item();
			toadd->set_down(ptr);
			delete ptr;
			return true;
		}
	}

	return false;
}

// delete calendar item
void weekly::delete_calendar_items(wnode *& head)
{
	if(!head) return;

	wnode * hold = head->get_next();
	delete head;
	head = hold;

	return delete_calendar_items(head);
}

// display calendar item
bool weekly::display()
{
	if(!head) return false;

	return display(head);
}

// recursive display calendar item
bool weekly::display(wnode * head)
{
	if(!head) return true;

	head->display();

	return display(head->get_next());
}

// find calendar item
bool weekly::find_item()
{
	char name[100];
	cout << endl << "Type name of calendar item: ";
	cin.get(name, 100, '\n');
	cin.ignore(100, '\n');
	
	// check to see that calendar item is found
	if(!(find_item(head, name)))
	{
		cout << endl << "Calendar Item not found!" << endl;
		return false;
	}
	return true;
}

// delete day of the week
bool weekly::delete_day()
{
	char day[100];

	if(!head) return false; 
	
	cout << "What day of the week would you like to delete: "; 
	cin.get(day, 100, '\n');
	
	return delete_day(head, day);
}

// recursive call to delete day of the week
bool weekly::delete_day(wnode *& head, char * day)
{
	if(!head) return false;
	
	if(head->compare_day(day))
	{
		wnode * hold = head->get_next();
		delete head;
		head = hold; 
		return delete_day(head, day);
	}

	return delete_day(head->get_next(), day);
}

// recursive find calendar item
bool weekly::find_item(wnode * head, char * name)
{
	if(!head) return false;

	if(head->find_item(name))
		return true;
	
	return find_item(head->get_next(), name);
}

// clear calendar of calendar items
bool weekly::clear_items()
{
	if(clear_items(head))
	{
		cout << endl << "Calendar Cleared!" << endl;
		return true;
	}
	else
	{
		cout << endl << "ERROR! Calendar couldn't clear!" << endl;
		return false;
	}
}

// recursive function clean claendar items
bool weekly::clear_items(wnode *& head)
{
	if(!head) return true;

	head->clear_items();

	return clear_items(head->get_next());
}

// find item in DLL
bool weekly::find_day()
{
	char response[15];

	cout << endl << "Type the day of the week you would like to add a calendar event to (ex: Monday, Tuesday, etc): ";
	cin.get(response, 100, '\n');
	cin.ignore(100, '\n');
	
	// find location of day of the week and add calendar item
	if(find_day(head, response))
		return true;
	else
	{
		cout << endl << response << " is not a valid day of the week." << endl;
		return false;
	}
}

// find item in DLLL
bool weekly::find_day(wnode *& head, char * to_find)
{
	if(!head) return false;
	
	// if match is found for day
	if(head->compare_day(to_find))
	{
		// add calendar item
		if(add_calendar_item(head))
		{
			return true;
		}
		return false;
	}

	return find_day(head->get_next(), to_find);
}


///////* USER FUNCTIONS *//////////

// This class manages the functions to do with a user profile
// You can add, display and edit the user data
// It is a derived class from the weekly base

// constructor
user::user(): name(NULL), birthdate(NULL)
{
}

// copy constructor
user::user(const user & to_copy): weekly(to_copy)
{
	name = new char[strlen(to_copy.name) + 1];
	strcpy(name, to_copy.name);

	birthdate = new char[strlen(to_copy.birthdate) + 1];
	strcpy(birthdate, to_copy.birthdate);
}

// deconstructor
user::~user()
{
	if(name)
		delete [] name;
	if(birthdate)
		delete [] birthdate;
}

// create user associated with weekly calendar
bool user::create_user(char * name_tocopy, char * birthdate_tocopy)
{
	name = new char[strlen(name_tocopy) + 1];
	strcpy(name, name_tocopy);

	birthdate = new char[strlen(birthdate_tocopy) + 1];
	strcpy(birthdate, birthdate_tocopy);

	if(!name || !birthdate)
		return false;
	return true;
}

// menu 
void user::menu(int & response)
{
	cout << endl << "-----CALENDAR MENU------" << endl;
	cout << "1 - Add Calendar Item" << endl;
	cout << "2 - Display Week" << endl;
	cout << "3 - Change Username" << endl;
	cout << "4 - Find & Delete Item" << endl;
	cout << "5 - Clear Calendar" << endl;
	cout << "6 - Delete Day of the Week" << endl;
	cout << "7 - End Program" << endl;
	
	cout << "Select Menu Choice: "; 
	cin >> response;
	cin.ignore(100, '\n');

	switch(response)
	{
		case 1:
			find_day();
			break;

		case 2:
			display();
			break;

		case 3:
			edit_username();
			break;

		case 4:
			find_item();
			break;

		case 5:
			clear_items();
			break;
		case 6:
			delete_day();
			break;

		case 7:
			cout << endl << "Thank you for using Calendar Application" << endl;
			break;
	}
}

// change the name of the user
bool user::edit_username()
{
	char name_toadd[100];

	cout << "Please type the new username: ";
	cin.get(name_toadd, 100, '\n');
	cin.ignore(100, '\n');
	
	// delete current data
	delete [] name;

	name = new char[strlen(name_toadd) + 1];
	strcpy(name, name_toadd);

	if(!name)
		return false;
	
	// display information about user
	welcome();

	return true;
}

// display user information
void user::welcome()
{
	cout << endl << "Hi " << name << "! Welcome Back!" << endl;
	cout << "Birthdate: " << birthdate << endl;
}
