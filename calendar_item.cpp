// Nicole Kurtz
#include "calendar_item.h"
using namespace std;

/*
	char * name; // name of calendar item
	char * time; // time of calendar item
	char * description; // description of calendar item
	char * zoom; // zoom id if applicable
*/

// default constructor
item::item(): name(NULL), description(NULL)
{
}

// deconstructor
item::~item()
{
	if(name)
		delete [] name;
	if(description)
		delete [] description;
	name = description = NULL;
}

// copy constructor
item::item(const item * to_copy)
{
	if(to_copy->name)
	{
		name = new char[strlen(to_copy->name) + 1];
		strcpy(name, to_copy->name);
	}
	
	if(to_copy->description)
	{
		description = new char[strlen(to_copy->description) + 1];
		strcpy(description, to_copy->description);
	}

}

// copy constructor
item::item(const item *& to_copy)
{
	if(to_copy->name)
	{
		name = new char[strlen(to_copy->name) + 1];
		strcpy(name, to_copy->name);
	}
	
	if(to_copy->description)
	{
		description = new char[strlen(to_copy->description) + 1];
		strcpy(description, to_copy->description);
	}

}

// add constuctor
item::item(char * name_tocopy, char * description_tocopy)
{
	name = new char[strlen(name_tocopy) + 1];
	strcpy(name, name_tocopy);
	
	description = new char[strlen(description_tocopy) +1];
	strcpy(description, description_tocopy);

}

// virtual display
bool item::display()
{
	if(!name || !description) return false;

	if(name)
		cout << endl << "Name: " << name << endl;
	if(description)
		cout << "Description: " << description << endl;
	return true;
}

// virtual function to add to list
bool item::add_list()
{
	return true;
}
/*
// display list of todos
bool item::display_list()
{
	return true;
}
*/

// add calendar item
bool item::add_item()
{
	char name_tocopy[100];
	char description_tocopy[100];
	
	cout << "Name: ";
	cin.get(name_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Description: ";
	cin.get(description_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	name = new char[strlen(name_tocopy) + 1];
	strcpy(name, name_tocopy);
	
	description = new char[strlen(description_tocopy) + 1];
	strcpy(description, description_tocopy);
	
	if(!name || !description)
		return false;
	return true;
}

/*
bool item::edit_calendar_item()
{
	char name_toadd[100];
	char description_toadd[100];

	cout << "Please type the new item name: ";
	cin.get(name_toadd, 100, '\n');
	cin.ignore(100, '\n');
	
	cout << "Please type the new description for " << name_toadd << ": ";
	cin.get(description_toadd, 100, '\n');
	cin.ignore(100, '\n');

	// delete current data
	delete [] name;
	delete [] description;

	name = new char[strlen(name_toadd) + 1];
	strcpy(name, name_toadd);

	description = new char[strlen(description_toadd) + 1];
	strcpy(description, description_toadd);
	
	if(!name || !description)
		return false;
	return true;
}
*/

// find item
bool item::find_item(char * compare, bool & check)
{
	if(strcmp(name, compare) == 0)
	{
		char response;

		display();
		//display_list();

		return true;
	}
	return false;
}
/*
// find item in list
bool item::find_item_list(char * compare)
{
	return true;
}
*/

///////* NODE CLASS *//////

// default constructor
node::node(): next(NULL)
{
}

// copy constructor
node::node(const node *& tocopy)
{

	const todo * ptr = dynamic_cast<const todo*>(tocopy->a_item);
	if(ptr)
	{
		a_item = new todo(ptr);
		next = NULL;
	}
	

	const lecture * ptr1 = dynamic_cast<const lecture*>(tocopy->a_item);
	if(ptr1)
	{
		a_item = new lecture(ptr1);
		next = NULL;
	}

	const work * ptr2 = dynamic_cast<const work*>(tocopy->a_item);
	if(ptr2)
	{
		a_item = new work(ptr2);
		next = NULL;
	}

}

// copy constructor
node::node(const node * tocopy)
{
	//item * temp = tocopy->a_item;
	//temp->display();

	const todo * ptr = dynamic_cast<const todo*>(tocopy->a_item);
	if(ptr)
	{
		a_item = new todo(ptr);
		next = NULL;
	}
	

	const lecture * ptr1 = dynamic_cast<const lecture*>(tocopy->a_item);
	if(ptr1)
	{
		a_item = new lecture(ptr1);
		next = NULL;
	}

	const work * ptr2 = dynamic_cast<const work*>(tocopy->a_item);
	if(ptr2)
	{
		a_item = new work(ptr2);
		next = NULL;
	}

}

// deconstructor
node::~node()
{
	next = NULL;
	if(a_item)
		delete a_item;
}

// add item to node
node::node(const item * tocopy)
{

	const todo * ptr = dynamic_cast<const todo*>(tocopy);
	if(ptr)
	{
		a_item = new todo(ptr);
		next = NULL;
	}

	const lecture * ptr1 = dynamic_cast<const lecture*>(tocopy);
	if(ptr1)
	{
		a_item = new lecture(ptr1);
		next = NULL;
	}

	const work * ptr2 = dynamic_cast<const work*>(tocopy);
	if(ptr2)
	{
		a_item = new work(ptr2);
		next = NULL;
	}
}

// add item to node
node::node(const item *& tocopy)
{

	const todo * ptr = dynamic_cast<const todo*>(tocopy);
	if(ptr)
	{
		a_item = new todo(ptr);
		next = NULL;
	}

	const lecture * ptr1 = dynamic_cast<const lecture*>(tocopy);
	if(ptr1)
	{
		a_item = new lecture(ptr1);
		next = NULL;
	}

	const work * ptr2 = dynamic_cast<const work*>(tocopy);
	if(ptr2)
	{
		a_item = new work(ptr2);
		next = NULL;
	}
}

// set next node
void node::set_next(node *& connection)
{
	next = connection;
}

bool node::display_list_item()
{
	if(!a_item)
		return false;
	if(a_item->display())
		return true;
	return false;
}

// display contents of node
bool node::display()
{
	const todo * ptr = dynamic_cast<const todo*>(a_item);
	if(ptr)
	{
		todo * temp = new todo(ptr);
		temp->display_list();
		delete temp;
		return true;
	}
	if(a_item->display())
		return true;
		
	return false;
}

node *& node::get_next()
{
	return next;
}

node *& node::get_down()
{
	return down;
}

void node::set_down(node *& connection)
{
	next = connection; 
}

bool node::find_item(char * name, bool & check)
{
	if(a_item->find_item(name, check))
		return true;
	return false;
}

bool node::find_item_list(char * compare)
{
	const todo * ptr = dynamic_cast<const todo*>(a_item);
	if(ptr)
	{
		todo * temp = new todo(ptr);
		if(temp->find_item_list(compare))
		{
			delete temp;
			return true;
		}
		delete temp;
		return false;
	}
	/*
	if(a_item->find_item_list(compare))
		return true;
	*/
	return false;
}


/////* LIST CLASS *//////

// default constructor
list::list(): head(NULL)
{
}

// copy constructor
list::list(const list * tocopy)
{
	if(tocopy->head)
	{
		copy_list(head, tocopy->head);
	}
}

// copy list recursively
void list::copy_list(node *& head, node * tocopy)
{
	if(!tocopy) return;
	head = new node(tocopy);

	return copy_list(head->get_next(), tocopy->get_next());
}

// destructor
list::~list()
{
	if(head)
		delete_list(head);
	head = NULL;
}

// remove all items in the list
void list::delete_list(node *& head)
{
	if(!head) return;

	node * hold = head->get_next();
	delete head;
	head = hold;

	return delete_list(head);
}

// wrapper function to find item in list
bool list::find_item(char * name)
{
	bool check = false;
	if(!head)
		return false;
	if(find_item(head, name, check))
	{
		if(check)
			return true;
		else 
			return false;
	}
	return false;
}

// recursive function to find item in list
bool list::find_item(node *& head, char * name, bool & check)
{
	if(!head) return true;

	if(head->find_item_list(name))
	{
		node * hold = head->get_next();
		delete head;
		head = hold;
		check = true;
		return find_item(head, name, check);
	}

	return find_item(head->get_next(), name, check);
}

// add item to list
bool list::add_todo()
{
	char response;
	do{
		item * ptr = new todo();
		ptr->add_item();
		//ptr->display();

		if(!head)
		{
			head = new node(ptr); 
			//head->display();
		}
		else
		{
			node * temp = new node(ptr);
			temp->set_next(head);
			head = temp;
		}

		cout << endl << "Would you like to add another to do? (y or n): ";
		cin >> response;
		cin.ignore(100, '\n');
		
		delete ptr;

	}while(response != 'n');
	return true;
}

// wrapper function to display an item
bool list::display()
{
	if(!head)
		return false;

	if(display(head))
		return true;

	return false;
}

// recursive call to display an item
bool list::display(node * head)
{
	if(!head)
	{
		return true;
	}

	head->display_list_item();
	//head->display();

	return display(head->get_next());
}



/////* LECTURE VIDEOS */////

// constructor
lecture::lecture(): zoom(NULL), time(NULL)
{
}

// copy constructor
lecture::lecture(const lecture * to_copy): item(to_copy)
{
	zoom = new char[strlen(to_copy->zoom) + 1];
	strcpy(zoom, to_copy->zoom);

	time = new char[strlen(to_copy->time) + 1];
	strcpy(time, to_copy->time);
}

// deconstructor
lecture::~lecture()
{
	if(zoom)
		delete [] zoom;
	if(time)
		delete [] time;

	zoom = time = NULL;
}

// add calendar item
bool lecture::add_item()
{
	char name_tocopy[100];
	char time_tocopy[100];
	char description_tocopy[100];
	char zoom_tocopy[100];
	
	cout << "Name: ";
	cin.get(name_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Time: ";
	cin.get(time_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Description: ";
	cin.get(description_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Zoom ID: ";
	cin.get(zoom_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	name = new char[strlen(name_tocopy) + 1];
	strcpy(name, name_tocopy);

	time = new char[strlen(time_tocopy) + 1];
	strcpy(time, time_tocopy);

	description = new char[strlen(description_tocopy) +1];
	strcpy(description, description_tocopy);

	zoom = new char[strlen(zoom_tocopy) + 1];
	strcpy(zoom, zoom_tocopy);

	return true;
}

// display function
bool lecture::display()
{
	if(!name) return false;
	
	cout << endl << "---Lecture Video Info---";

	if(name)
		cout << endl << "Name: " << name << endl;

	if(time)
		cout << "Time: " << time << endl;

	if(description)
		cout << "Description: " << description << endl;

	if(zoom)
		cout << "Zoom ID: " << zoom << endl;

	return true;
}

// find item and display
bool lecture::find_item(char * compare)
{
	if(strcmp(name, compare) == 0)
	{
		char response;

		display();

		return true;
	}
	return false;
}


///////* TO DO LIST ITEM *////////

// This calendar item has a list of todos
// which represent a to do list. 
// this calendar item is dervied from the calendar item base class

// default constructor
todo::todo()
{
	todos = new list;
}

// copy constructor
//todo::todo(const todo *& tocopy): item(tocopy)
todo::todo(const todo * tocopy): item(tocopy)
{
	if(tocopy->todos)
	{
		todos = new list(tocopy->todos);
	}
}

// deconstructor
todo::~todo()
{
	if(todos)
		delete todos;
}

// creates new todo item
bool todo::add_item()
{
	char name_tocopy[100];
	char description_tocopy[100];
	
	cout << "Name: ";
	cin.get(name_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Description: ";
	cin.get(description_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	name = new char[strlen(name_tocopy) + 1];
	strcpy(name, name_tocopy);

	description = new char[strlen(description_tocopy) +1];
	strcpy(description, description_tocopy);

	if(!name || !description)
		return false;
	return true;
}

// add item to list of items
bool todo::add_list()
{
	if(todos->add_todo())
		return true;
	return false;
}

// display todo items
bool todo::display_list()
{
	if(!todos)
		return false;

	if(todos->display())
		return true;

	return false;
}

// find item and display
bool todo::find_item(char * compare, bool & check)
{
	if(todos->find_item(compare))
	{
		check = true;
		return true;
	}
	return false;
}

// find item in list and display
bool todo::find_item_list(char * compare)
{
	if(strcmp(name, compare) == 0)
	{
		display();
		return true;
	}
	return false;
}

// display todo item
bool todo::display()
{
	if(!name || !description) return false;
	
	cout << endl << "----TODO ITEM----" << endl;
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;

	return true;
}


////////* WORK ITEM */////////

// This calendar item represents a work schedule
// it is dervied from a calendar item class

// default constructor
work::work(): start(NULL), end(NULL)
{
}

// copy constructor
work::work(const work * tocopy): item(tocopy)
{
	start = new char[strlen(tocopy->start) + 1];
	strcpy(start, tocopy->start);

	end = new char[strlen(tocopy->end) + 1];
	strcpy(end, tocopy->end); 
}
	
// copy constructor
work::work(const work & tocopy): item(tocopy)
{
	start = new char[strlen(tocopy.start) + 1];
	strcpy(start, tocopy.start);

	end = new char[strlen(tocopy.end) + 1];
	strcpy(end, tocopy.end); 
}

// deconstructor
work::~work()
{
	if(start)
		delete [] start;
	if(end)
		delete [] end;
}

// add calendar item
bool work::add_item()
{
	char name_tocopy[100];
	char description_tocopy[100];
	char start_time[100];
	char end_time[100];
	
	cout << "Name: ";
	cin.get(name_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Description: ";
	cin.get(description_tocopy, 100, '\n');
	cin.ignore(100, '\n');

	cout << "Start Time: ";
	cin.get(start_time, 100, '\n');
	cin.ignore(100, '\n');

	cout << "End Time: ";
	cin.get(end_time, 100, '\n');
	cin.ignore(100, '\n');

	name = new char[strlen(name_tocopy) + 1];
	strcpy(name, name_tocopy);

	description = new char[strlen(description_tocopy) +1];
	strcpy(description, description_tocopy);

	start = new char[strlen(start_time) + 1];
	strcpy(start, start_time);

	end = new char[strlen(end_time) + 1];
	strcpy(end, end_time);

	if(!name || !description || !start || !end)
		return false;
	return true;
}

// display work item
bool work::display()
{
	if(!name || !description || !start || !end)
		return false;

	cout << endl << "----Work Item----" << endl;
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;
	cout << "Start Time: " << start << endl;
	cout << "End Time: " << end << endl;

	return true;
}

// find item and display
bool work::find_item(char * compare, bool & check)
{
	if(strcmp(name, compare) == 0)
	{
		display();
		return true;
	}
	return false;
}


