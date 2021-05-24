// Nicole Kurtz
#include "calendar_item.h"

// DLL node that points to an item
class wnode
{
	public:
		wnode(); // constructor
		wnode(const wnode *& tocopy); // copy constructor
		~wnode(); // deconstructor
		void set_next(wnode *& connection); // set the next node in the list
		bool display(); // display the contents of the node
		wnode *& get_next(); // move forward
		void add_day(int counter); // add day to node
		void set_prev(wnode *& connection); // set previous pointer
		wnode *& get_prev(); // get previous
		bool compare_day(char * tofind); // compare day to user input
		bool set_down(item *& ptr); // add linear linked list to day
		bool display_item(); // display info of item
		bool find_item(char * name); // wrapper function to display item
		bool clear_items(); // wrapper function to clear items

	private:
		bool clear_items(node *& head); // recursive clear items
		bool display_item(node * head);  // display item located in node
		void delete_list(node *& head); // delete LLL associated with node
		bool find_item(node *& head, char * name, bool & found); // recursive function to find item

		wnode * next;
		wnode * prev;

		node * head; // node pointer to list of items

		char * day; // day of the week
};

// This class manages a doubly linked list of calendar weeks
class weekly
{
	public:
		weekly(); // constructor
		weekly(const weekly & to_copy); // copy constructor
		~weekly(); // deconstructor
		bool find_day(); // find calendar item
		bool find_item(); // wrapper function to find calendar item
		bool display(); // display week
		bool clear_items(); // clear items in calendar
		bool delete_day(); // delete day of the week

	protected:
		wnode * head; 

	private:
		bool add_calendar_item(wnode *& head); // add calendar item to weekly list
		bool delete_day(wnode *& head, char * day); // delete day of the week
		bool clear_items(wnode *& head); // clear items in calendar
		bool find_day(wnode *& head, char * to_find); // find day in DLL
		bool display(wnode * head); // recursive function to display 
		void delete_calendar_items(wnode *& head); // delete calendar item in weekly list
		void create_week(wnode *& head, int & counter); // create week
		bool find_item(wnode * head, char * name); // recursive function to find calendar item
};

// this class manages a user of a weekly calendar
class user: public weekly
{
	public:
		user(); // constructor
		user(const user & to_copy); // copy constructor
		~user(); // deconstructor
		bool create_user(char * name_tocopy, char * birthdate_tocopy); // create user associated with weekly calendar
		bool edit_username(); // change the name of the user associated with calendar
		void welcome(); // change the birthday of the user associated with calendar
		void menu(int & response); // menu	

	protected:
		char * name; // name of user
		char * birthdate; // birthday of user

	private:
};
