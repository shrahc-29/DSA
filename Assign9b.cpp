#include <iostream>
#include <string>

using namespace std;

class CQ
{
        int *arr;
        int currsize, cap;
        int f=0;
        int r=-1;

        public:

            CQ(int size)
            {
                cap=size;
                currsize=0;
                arr=new int[cap];
                f=0;
                r=-1;
            }

            void enqueue(int data)
            {
                if(currsize==cap)
                {
                    cout<<"Full"<<endl;
                    return;
                }
                r=(r+1)%cap;
                arr[r]=data;
                currsize++;
            }


            void dequeue()
            {
                if(empty()==true)
                {
                    cout<<"Empty"<<endl;
                    return;
                }
                f=(f+1)%cap;
                currsize--;

            }

            int front()
            {
                return arr[f];
            }


            bool empty()
            {
                if(currsize==0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            void display()
            {
                for(int i=0;i<cap;i++)
                {
                    cout<<arr[i]<<" "<<endl;

                }
            }
};

int main()
{
    CQ cq(4);
    int data;



}

