#include<iostream>
#include<string>
using namespace std;

class CircularQueue
{
    public:
        int customers[4];
        int front;
        int rear;

        CircularQueue()
        {
            front=-1;
            rear=-1;
        }

        int isEmpty()
        {
            if(rear==-1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int isFull()
        {
            if((rear+1)%4==front)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    
        void addCustomer()
        {
            int token;
            cout<<"Enter the token number:";
            cin>>token;
    
            if(isFull()==1)
            {
                cout<<"The queue is full.\n";
            }
            else if(isEmpty()==1)
            {
                front=(front+1)%4;
                rear=(rear+1)%4;
                customers[rear]=token;
            }
            else
            {
                rear=(rear+1)%4;
                customers[rear]=token;
            }
        }
    
        void serveCustomer()
        {
            if(isEmpty()==1)
            {
                cout<<"The queue is empty."<<endl;
            }
            else if(front==rear)
            {
                cout<<"Token no.:"<<customers[front]<<endl;
                front=-1;
                rear=-1;
            }
            else
            {
                cout<<"Token no.:"<<customers[front]<<endl;
                front=(front+1)%4;
            }
        }

        void closeCounter()
        {
            cout<<"Closing counter..."<<endl;
            while(!isEmpty())
            {
                serveCustomer();
            }
            cout<<"Counter closed.\n";
        }

        void viewQueue()
        {
            int pointer=front;
            while(pointer!=-1)
            {
                if(front==rear)
                {
                    cout<<"Token no.:"<<customers[pointer]<<endl;
                    pointer=-1;
                }
                else
                {
                    cout<<"Token no.:"<<customers[pointer]<<endl;
                    if(pointer==rear)
                    {
                        pointer=-1;
                    }
                    else
                    {
                        pointer=(pointer+1)%4;
                    }
                }
            }
            if(isEmpty()==1)
            {
                cout<<"The queue is empty."<<endl;
                pointer=-1;
            }
        }
};


int main()
{
    CircularQueue queue;
    int option;

    do
    {
        cout<<"\nSupermarket Checkout Counter:\n";
        cout<<"1.Customer arrival\n";
        cout<<"2.Customer checkout\n";
        cout<<"3.Close Checkout Counter\n";
        cout<<"4.View Counter\n";
        cout<<"0.Exit\n";

        cout<<"Enter your choice:";
        cin>>option;

        switch(option)
        {
            case 1:
                queue.addCustomer();
                break;

            case 2:
                queue.serveCustomer();
                break;
    
            case 3:
                queue.closeCounter();
                break;

            case 4:
                queue.viewQueue();
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


