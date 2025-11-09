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
        LL()  // constructor to initialize head
        {
            head=NULL;
        }

        void display()  // display the linked list
        {
            cout<<"The Linked list thus created is: "<<endl;
            node *ptr = head;
            while (ptr != NULL)
            {
                cout<<ptr -> data << " >> ";
                ptr = ptr -> next;
            }
            cout<<"NULL"<<endl;
            cout<<"  "<<endl<<endl;
        }


        void at_end(string data)  // insert node at the end
        {
            node *newnode = new node;
            newnode-> data = data;
            newnode -> next = NULL;

            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                node *ptr = head;
                while (ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                }

                ptr -> next =newnode;
            }
        }

    
        void at_start(string data)     // insert node at the beginning
        {
            node *newnode = new node;
            newnode-> data = data;
            newnode -> next = NULL;

            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                newnode -> next = head;
                head = newnode;
            }
        }


        void at_any_pos(string data)      // insert node at any specific position
        {
            node *newnode = new node;
            newnode-> data = data;
            newnode -> next = NULL;
    
            int pos;

            cout << "Enter position: ";
            cin >> pos;
            if (pos == 1)
            {
                if (head == NULL)
                {
                    head = newnode;
                }
                else
                {
                    newnode -> next = head;
                    head = newnode;
                }
            }
            else
            {
                node *ptr = head;
                for (int i=1; i<pos-1;i++)
                {
                    ptr = ptr -> next;
                }
                    newnode -> next = ptr -> next;
                    ptr -> next = newnode;
            }
        }


        void delete_start()     // delete the first node
        {
            if ( head== NULL ) 
            {
                cout << "Empty"<< endl;
            }
            else
            {
                node *ptr = head;
                head = ptr -> next;
                delete (ptr);
            }
        }


        void delete_end()     // delete the last node
        {
            node *ptr = head;
            node *ptr1= head;
            if (head == NULL)
            {
                cout <<"Empty";
            }
            else if ( ptr -> next == NULL)
            {
                head == NULL;
                delete (ptr);
            }
            else
            {
                while (ptr -> next != NULL)
                {
                    ptr1 = ptr;
                    ptr = ptr -> next;
                }
                ptr1 -> next = NULL;
                delete(ptr);
            }
        }



        void delete_any()    // delete node at any specific position
        {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;

            if (head == NULL)
            {
                cout << "List is empty. Nothing to delete." << endl;
                return;
            }
            if (pos == 1)
            {
                node* temp = head;
                head = head->next;    
                delete temp;
                cout << "Node at position 1 deleted." << endl;
                return;
            }
            node* prev = head;
            for (int i = 1; i < pos - 1; ++i)    
            {
                if (prev == NULL || prev->next == NULL)        
                {
                    cout << "Invalid position." << endl;
                    return;
                }
                prev = prev->next;
            }

            node* temp = prev->next;

            if (temp == NULL)
            {
                cout << "Invalid position." << endl;
                return;
            }

            prev->next = temp->next;
            delete temp;
            cout << "Node at position " << pos << " deleted." << endl;
        }



        void search()     // search for a node by value
        {
            string key;
            int pos = 1;
            cout << "Enter key element to search: ";
            cin >> key;

            node* ptr = head;
            while (ptr != nullptr) 
            {    
                if (ptr->data == key) 
                {
                    cout << "Found at position: " << pos << endl << endl;
                    return;
                }
                ptr = ptr->next;
                pos++;
            }
            cout << "Not found." << endl << endl;
        }

};



int main()
{
    LL a; 
    int m, pos;
    string x; 

    do
    {
        cout<<"Select your choice from Menu:  \n\t 1. Insert song at the end \n\t 2. Insert song at the beginning \n\t 3. Insert song in between \n\t 4. Search song \n\t 5. Delete first song \n\t 6. Delete last song \n\t 7. Delete song at specific position \n\t 8. Display the updated Playlist \n\t 9. Exit Playlist Menu "<<endl;
cin>>pos;

    switch(pos)
    {
        case 1:  // Insert at the end
            cout<<"Enter song to add: ";
            cin.ignore();  // only once before the first getline
            getline(cin, x);

            a.at_end(x);
            cout<<"Do you want to continue? (Yes = 1 and No = 0): ";
            cin>>m;
            cout<<"  "<<endl;
            break;

        case 2:  // Insert at the beginning
            cout<<"Enter song to add: ";
            cin.ignore();  // only once before the first getline
            getline(cin, x);

            a.at_start(x);
            cout<<"Do you want to continue? (Yes = 1 and No = 0):  ";
            cin>>m;
            cout<<"  "<<endl;
            break;
    
        case 3:  // Insert in between
            cout<<"Enter song to add: ";
            cin.ignore();  // only once before the first getline
            getline(cin, x);

            a.at_any_pos(x);
            cout<<"Do you want to continue? (Yes = 1 and No = 0):  ";
            cin>>m;
            cout<<"  "<<endl;
            break;
        
        case 4:  // Search Node
            a.search();
            break;

        case 5:  // Delete first node
            cout << "Deleting first song" << endl;
            a.delete_start();
            break;

        case 6:  // Delete last node
            cout << "Deleting last song" << endl;
            a.delete_end();
            break;

        case 7:  // Delete node at specific position
            a.delete_any();
            break;

        case 8:  // Display the updated Linked List
            a.display();
            break;
    
        case 9:  // Exit Menu
            cout << "Playlist Menu exited. " << endl;
            m = 2;
            break;
    
        default:
            cout << "Invalid Choice. ";
    }
    }
    
    while (m==1 || m==0 );
    
    a.display();

    return 0;
}

