// Nicole Kurtz

#include <iostream>
#include <cctype>
#include <cstring>

// The following is a hierarchy for a calendar item
// A lecture, todo and work class is a calendar item

// base class for calendar items
class item
{
	public:
		item(); // default constructor
		virtual ~item(); // deconstructor
		item(const item * to_copy); // copy constructor
		item(const item *& to_copy); // copy constructor
		item(char * name_tocopy, char * description_tocopy); // add constructor
		virtual bool add_list(); // add items to list
		virtual bool add_item(); // virtual add calendar item
		virtual bool display(); // virtual display
		virtual bool find_item(char * compare, bool & check); // find item and delete

	protected:
		char * name; // name of calendar item
		char * description; // description of calendar item

	private:
};

// this class manages a node that points to an item
class node
{
	public:
		node(); // default constructor
		node(const node *& tocopy); // copy constructor
		node(const node * tocopy); // copy constructor
		~node(); // deconstructor
		node(const item * toadd); // add item to node
		node(const item *& toadd); // add item to node
		void set_next(node *& connection); // set the next node in the list
		void set_down(node *& connection); // set the down pointer to connection
		bool display(); // display the contents of the node
		bool display_list_item(); // display item of list
		bool find_item(char * name, bool & check); // find item 
		bool find_item_list(char * compare); // find item in todo list
		node *& get_next(); // move forward
		node *& get_down(); // move downward

	private:
		node * next;
		node * down;
		item * a_item;
};


// this class manages a linear linked list of items
class list
{
	public:
		list(); // default constructor
		list(const list * tocopy); // copy constructor
		bool add_item(item * to_copy); // add an item to the list
		bool add_todo(); // add a todo to the list class
		bool display(); // wrapper function to display list
		bool find_item(char * name); // find item wrapper function
		~list(); // deconstructor

	private:
		bool display(node * head); // recursive function to display
		bool find_item(node *& head, char * name, bool & check); // recursive call to find item
		void copy_list(node *& head, node * tocopy); // copy list 
		void delete_list(node *& head); // recursive function to delete list
		node * head;
};

// this class manages a calendar item that is a class lecture
// this class allows you to add, display and edit the class lecture informatoin
class lecture: public item
{
	public:
		lecture(); // default constructor
		lecture(const lecture * to_copy); // copy constructor
		~lecture(); // deconstructor
		bool add_item(); // add lecture item
		bool display(); // display lecture information
		bool find_item(char * name); // find item

	protected:
		char * zoom; // zoom id if applicable
		char * time; // time of calendar item

	private:
};

// this class manages a calendar item that is a todo list
// this class manages adding, displaying and editing the todo information
class todo: public item
{
	public:
		todo(); // default constructor
		todo(const todo * tocopy); // copy constructor 
		todo(char * name, char * description); // create todo 
		bool add_list(); // add item to list
		~todo(); // deconstructor
		bool add_item(); // create todo object
		bool display_list(); // display items in a list
		bool display(); // display item info 
		bool find_item_list(char * compare); // find item in list
		bool find_item(char * name, bool & check); // find item

	protected:
		list * todos; // list of todo items

	private:
};

// this class manages a calendar item that is a work schedule item
// this class manages adding, displaying and editing a work item
class work: public item
{
	public:
		work(); // default constructor
		work(const work * tocopy); // copy constructor
		work(const work & tocopy); // copy constructor
		~work(); // deconstructor
		bool display(); // display lecture information
		bool find_item(char * name, bool & check); // find item
		bool add_item(); // add calendar item of class work

	protected:
		char * start;
		char * end;

	private:
};


