#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int ticketNumber;
	struct Node* nextNode;
};

class WaitlistQueue
{
	public:
		Node* head;
		Node* tail;

		WaitlistQueue()
		{
			head=nullptr;
			tail=nullptr;
		}

		int isEmpty()
		{
			if(tail==nullptr)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		void addParty()
		{
			int ticket;
			cout<<"Enter the ticket number:";
			cin>>ticket;
			Node* newNode=new Node;
			newNode->ticketNumber=ticket;
			newNode->nextNode=nullptr;
			if(isEmpty()==1)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->nextNode=newNode;
				tail=newNode;
			}
		}


		void seatParty()
		{
			Node* temp=head;
			if(isEmpty()==1)
			{
				cout<<"The queue is empty."<<endl;
			}
			else if(head==tail)
			{
				cout<<"Seating ticket number:"<<temp->ticketNumber<<endl;
				head=nullptr;
				tail=nullptr;
				delete temp;
			}
			else
			{
				cout<<"Seating ticket number:"<<temp->ticketNumber<<endl;
				head=temp->nextNode;
				delete temp;
			}
		}


		void showWaitlist()
		{
			Node* temp=head;
			if(isEmpty()==1)
			{
				cout<<"The waitlist is empty."<<endl;
			}
			else
			{
				while(temp!=nullptr)
				{
					cout<<temp->ticketNumber<<endl;
					temp=temp->nextNode;
				}
			}
		}
};


int main()
{
	WaitlistQueue waitlist;
	int option;
	do
	{
		cout<<"\nRestaurant Waitlist:\n";
		cout<<"1. Add Party\n";
		cout<<"2. Seat Party\n";
		cout<<"3. Display Waitlist\n";
		cout<<"0. Exit\n";
		cout<<"Enter your choice:";
		cin>>option;
		
		switch(option)
		{
			case 1:
				waitlist.addParty();
				break;
			
			case 2:
				waitlist.seatParty();
				break;

			case 3:
				waitlist.showWaitlist();
				break;
			
			case 0:
				cout<<"Exiting..."<<endl;
				break;
	
			default:
				cout<<"Invalid choice!"<<endl;
		}
	}
	while(option!=0);
	return 0;
}

