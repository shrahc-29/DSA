#include<iostream>
using namespace std;

struct node
{
    int pow;
    int coeff;

    node* next;
};

class Poly
{
    node* head;
public:
    Poly(){
        head=NULL;
    }

    void display()
    {
        node *term = head;
        while(term!=NULL)
      {
            cout<<term->coeff<<"x^"<<term->pow<< " + ";
            term = term->next;
        }
    }

    void insertAtEnd(int p,int c)
    {
        node* nn = new node();
        nn->pow=p;
        nn->coeff = c;
        nn->next = NULL;

        if(head==NULL)
            head = nn;
        else
       {
            node * term = head;
            while(term->next!=NULL)
                term = term->next;
            term->next = nn;
        }
    }
    void add(Poly* obj2, Poly* result)
    {
        node* t1 = this->head;
        node* t2 = obj2->head;
        while(t1 && t2){
                if(t1->pow == t2->pow)
                {
                    result->insertAtEnd(t1->pow, (t1->coeff+t2->coeff));

                    t1 = t1->next;
                    t2 = t2->next;
                }
                else if(t1->pow > t2->pow)
                {
                    result->insertAtEnd(t1->pow, t1->coeff);
                    t1 = t1->next;

                }
                else if(t2->pow > t1->pow)
                {

                    result->insertAtEnd(t2->pow, t2->coeff);
                    t2 = t2->next;

                }

        }
        while(t1)
        {
            result->insertAtEnd(t1->pow,t1->coeff);
            t1 = t1->next;
        }
        while(t2)
         {
            result->insertAtEnd(t2->pow,t2->coeff);
            t2 = t2->next;
        }


        return;
    }
};

int main()
{
    Poly obj1,obj2;
    Poly result;

    int n, coeff,pow;
    cout<<"Enter number of terms in Polynomial 1: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>coeff;
        cin>>pow;
        obj1.insertAtEnd(pow,coeff);
    }

    cout<<"Enter number of terms in polynomial 2: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>coeff;
        cin>>pow;
        obj2.insertAtEnd(pow,coeff);
    }
    cout<<"Polynomial 1 is: ";
    obj1.display();
    cout<<endl;
    cout<<"Polynomial 2 is: ";
    obj2.display();
    cout<<endl;
    obj1.add(&obj2,&result);
    cout<<"Answer: ";
    result.display();
    cout<<endl;

    return 0;
}

