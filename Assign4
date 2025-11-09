#include <iostream>
using namespace std;

struct node
	{
		string data;
		node *next;
		node *prev;
	};

class LL
{
	node *head;
	
	public:

	LL() // constructor to initialize head pointer
	{
		head = NULL;
	}


	void display() // display the entire doubly linked list
	{
		cout << "The DLL thus created is: " << endl;
		node *ptr = head;
		while (ptr != NULL)
		{
			cout << ptr->data << " >> ";
			ptr = ptr->next;
		}
		cout << "NULL" << endl;
		cout << "  " << endl << endl;
	}


	void at_start(string data) // insert node at the beginning
	{
		node *newnode = new node;
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;

		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
	}


	void after_insert(string data) // insert node after a given position
	{
		int pos1;
		node *newnode = new node;
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
		cout << "Enter Position: ";
		cin >> pos1;
		if (head == NULL)
		{
			head = newnode;
		}	
		else
		{
			node *curr = head;
			for (int i = 1; i < pos1 && curr != NULL; i++)
			{
				curr = curr->next;
			}
			if (curr == NULL)
			return;
			newnode->prev = curr;
			newnode->next = curr->next;
			if (curr->next != NULL)
			curr->next->prev = newnode;
			curr->next = newnode;
		}
	}


	void before_insert(string data) // insert node before a given position
	{
		int pos1;
		node *newnode = new node;
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;

		if (head == NULL)
		{
			head = newnode;
			return;
		}
	
		cout << "Position: ";
		cin >> pos1;

		if (pos1 == 1)
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
		else
		{
			node *curr = head;
			for (int i = 1; i < pos1 && curr != NULL; i++)
			{
				curr = curr->next;
			}
			if (curr == NULL)
			return;
			newnode->next = curr;
			newnode->prev = curr->prev;
			if (curr->prev != NULL)
			curr->prev->next = newnode;
			curr->prev = newnode;
		}
	}


	void delete_end() // delete node from the end
	{
		node *curr = head, *ptr1 = NULL;
		if (head == NULL)
		{
			cout << "Empty";
			return;
		}
		else if (curr->next == NULL)
		{
			head = NULL;
			delete curr;
		}
		else
		{
			while (curr->next != NULL)
			{
				ptr1 = curr;
				curr = curr->next;
			}
			ptr1->next = NULL;
			delete curr;
		}
	}


	void delete_before() // delete node from the start (first node)
	{
		if (head == NULL)
		{
			cout << "Empty";
		}
		else
		{
			node *curr = head;
			head = curr->next;
			if (head != NULL)
			head->prev = NULL;
			delete curr;
		}
	}


	void delete_pos() // delete node from a specific position
	{
		int pos2;
		if (head == NULL)
		{
			cout << "Empty" << endl;
			return;
		}

		cout << "Enter Position to delete node: ";
		cin >> pos2;
		cin.ignore();

		if (pos2 == 1)
		{
			node *temp = head;
			head = head->next;
			if (head != NULL)
			head->prev = NULL;
			delete temp;
			return;
		}
	
		node *curr = head;
		for (int i = 1; i < pos2 && curr != NULL; i++)
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			cout << "Invalid position!" << endl;
			return;
		}
	
		if (curr->prev != NULL)
		curr->prev->next = curr->next;
		if (curr->next != NULL)
		curr->next->prev = curr->prev;

		delete curr;
	}
};



int main()
{
	LL a;
	int m, pos;
	string x;

	do
	{
	cout << "Select your choice from Menu: \n\t 1. Insert text at the beginning \n\t 2. Insert text after a given position \n\t 3. Insert text before a given position \n\t 4. Delete first text \n\t 5. Delete last text \n\t 6. Delete text from a given position \n\t 7. Display text \n\t 8. Exit text editor \n";
cin >> pos;

	switch (pos)
	{
		case 1: // Insert node at the beginning
			cout << "Enter text to add: ";
			cin >> x;
			a.at_start(x);
			cout << "Do you want to continue? (Yes = 1 and No = 0): ";
			cin >> m;
			cout << "  " << endl;
			break;

		case 2: // Insert node after a given position
			cout << "Enter text to add: ";
			cin >> x;
			a.after_insert(x);
			cout << "Do you want to continue? (Yes = 1 and No = 0): ";
			cin >> m;
			cout << "  " << endl;
			break;

		case 3: // Insert node before a given position
			cout << "Enter text to add: ";
			cin >> x;
			a.before_insert(x);
			cout << "Do you want to continue? (Yes = 1 and No = 0): ";
			cin >> m;
			cout << "  " << endl;
			break;

		case 4: // Delete node from the start
			cout << "Deleting first text" << endl;
			a.delete_before();
			cout << "Do you want to continue? (Yes = 1 and No = 0): ";
			cin >> m;
			break;

		case 5: // Delete node from the end
			cout << "Deleting text at end" << endl;
			a.delete_end();
			cout << "Do you want to continue? (Yes = 1 and No = 0): ";
			cin >> m;
			break;

		case 6: // Delete node at a given position
			cout << "Deleting text at given position" << endl;
			a.delete_pos();
			cout << "Do you want to continue? (Yes = 1 and No = 0): ";
			cin >> m;
			break;

		case 7: // Display current list
			a.display();
			cout << "Do you want to continue? (Yes = 1 and No = 0): ";
			cin >> m;
			break;

		case 8: // Exit the program
			cout << "Text editor exited. " << endl;
			m = 2;
			break;

		default: // Invalid menu option
			cout << "Invalid Choice. " << endl;
			cout << "Do you want to continue? (Yes = 1 and No = 0): ";
			cin >> m;
			break;
	}
	}
	while (m == 1 || m == 0);

	a.display();
	
	return 0;
}

