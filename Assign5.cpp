#include <iostream>
using namespace std;

struct node
{
	string data;
	struct node *next;
};

class LL
{
	node *head;
	
	public:

		LL() // Constructor to initialize head
		{
			head = NULL;
		}

		void display() // Display the circular linked list
		{
			if (head == NULL)
			{
				cout << "No routes available.\n\n";
				return;
			}

			cout << "The current route sequence is:\n";
			node *ptr = head;
			do
			{
				cout << ptr->data << " --> ";
				ptr = ptr->next;
			}
			while (ptr != head)
				cout << "(Back to start)\n\n";
		}


		void at_start(string data) // Adding a initial stop
		{
			node *newnode = new node;
			newnode->data = data;

			if (head == NULL)
			{
				head = newnode;
				newnode->next = head;
			}
			else
			{
				node *ptr = head;
				while (ptr->next != head)
				{
					ptr = ptr->next;
				}
		
				ptr->next = newnode;
				newnode->next = head;
				head = newnode;
			}
		}



		void at_end(string data) // Adding a stop at the end
		{
			node *newnode = new node;
			newnode->data = data;

			if (head == NULL)
			{
				head = newnode;
				newnode->next = head;
			}
			else
			{
				node *ptr = head;
				while (ptr->next != head)
				{
					ptr = ptr->next;
				}

				ptr->next = newnode;
				newnode->next = head;
			}
		}


		void at_any_pos(string data) // Insert a stop at a specific position
		{
			node *newnode = new node;
			newnode->data = data;
		
			int pos;
			cout << "Enter position at which stop is to be added: ";
			cin >> pos;

			if (pos == 1)
			{
				at_start(data);
			}
			else
			{
				node *ptr = head;
				for (int i = 1; i < pos - 1; i++)
				{
					ptr = ptr->next;
					if (ptr == head)
					{
						cout << "Position out of bounds.\n";
						return;
					}
				}

				newnode->next = ptr->next;
				ptr->next = newnode;
			}
		}


		void delete_at_pos(int pos) // Delete a node at a specific position
		{
			if (head == NULL)
			{
				cout << "No routes to delete.\n";
				return;
			}

			if (pos == 1)
			{
				if (head->next == head)
				{
					delete head;
					head = NULL;
					cout << "Route deleted from position 1.\n";
					return;
				}

				node* last = head;
				while (last->next != head)
				{
					last = last->next;
				}

				node* temp = head;
				head = head->next;
				last->next = head;
				delete temp;
	
				cout << "Route deleted from position 1.\n";
				return;
			}

			node* prev = head;
			node* curr = head->next;
			int count = 2;

			while (curr != head && count < pos)
			{
				prev = curr;
				curr = curr->next;
				count++;
			}

			if (count == pos && curr != head)
			{
				prev->next = curr->next;
				delete curr;
				cout << "Route deleted from position " << pos << "." << endl;
			}
			else
			{
				cout << "Invalid position. No such route." << endl;
			}
		}

};


int main()
{
	LL a;
	int m, pos;
	string x;

	do
	{
		cout << "Select your choice from Menu:  \n\t 1. Insert stop at the beginning \n\t 2. Insert stop at the end \n\t 3. Insert stop in between \n\t 4. Display the route \n\t 5. Exit Navigation Menu " << endl;
		cin >> pos;

		switch (pos)
		{
			case 1: // Add location at beginning
				cout << "Enter stop to add at the beginning: ";
				cin.ignore();
				getline(cin, x);
				a.at_start(x);
				cout << "Do you want to continue? (Yes = 1 / No = 0): ";
				cin >> m;
				cout << endl;
				break;


			case 2: // Add location at end
				cout << "Enter stop to add at the end: ";
				cin.ignore();
				getline(cin, x);
				a.at_end(x);
				cout << "Do you want to continue? (Yes = 1 / No = 0): ";
				cin >> m;
				cout << endl;
				break;

			case 3: // Add location at specific position
				cout << "Enter stop to add: ";
				cin.ignore();
				getline(cin, x);
				a.at_any_pos(x);
				cout << "Do you want to continue? (Yes = 1 / No = 0): ";
				cin >> m;
				cout << endl;
				break;

			case 4: // Display the route
				a.display();
				cout << "Do you want to continue? (Yes = 1 / No = 0): ";
				cin >> m;
				cout << endl;
				break;
		
			case 5: // Exit
				cout << "Exiting the navigation system.\n";
				m = 2;
				break;
	
			default:
				cout << "Invalid choice.\n";
		m = 1;
		}
	}
	while (m == 1 || m == 0);
	
	a.display();

	return 0;

}

