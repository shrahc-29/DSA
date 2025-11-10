#include <iostream>
#include <string>
using namespace std;

struct node{
	string browse;
	struct node* next;
};

class Stack{
	public:
	node* top;
	node* ptr;
	Stack(){
		top = nullptr;
	}
	
	node* createnode(string browse){
		node* newnode = new node;
		newnode -> browse = browse;
		newnode -> next = nullptr;
		return newnode;
	}
	
	void Push(string browse){
		node* newnode = new node;
		newnode->browse = browse;
		newnode->next = top;
		top = newnode;
    	}
	
	node* Pop() {
    		if (isempty() == true) {
        			return top;
    		}
		cout << top -> browse << endl;
    		ptr = top;
    		top = top->next;
    		delete ptr;
    		return top;
	}
	
	void Peak(){
		cout << top -> browse << endl;
	}
	
	bool isempty(){
		if (top == nullptr) {
        			return true;
    		}
    		return false;
    	}
};

int main() {
    Stack b1;
    int choice;
    string browse;

    do {
        cout << "\nHistory:\n";
        cout << "1. Add visited page\n";
        cout << "2. Navigate back\n";
        cout << "3. View current page\n";
        cout << "4. Check if history is empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter visited page: ";
            cin >> browse;
            b1.Push(browse);
            break;
        case 2:
            b1.Pop();
            break;
        case 3:
            b1.Peak();
            break;
        case 4:
            cout << b1.isempty() <<endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
