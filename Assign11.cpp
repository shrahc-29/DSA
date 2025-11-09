#include<iostream>
#include<string>
using namespace std;

class HashTable
{
private:
	int tableSize;
	int* empID;
	string* empName;
public:
	int hashFunction(int key)
	{
		return key%tableSize;
	}

	HashTable(int size)
	{
		tableSize=size;
		empID=new int[tableSize];
		empName=new string[tableSize];
		for(int i=0;i<tableSize;i++)
		{
			empID[i]=-1;
			empName[i]=" ";
		}
	}

	void insert(int id,string name)
	{
		int index=hashFunction(id);
		int startIndex=index;
		while(empID[index]!=-1)
		{
			index=(index+1)%tableSize;
			if(index==startIndex)
			{
				cout<<"Hash table full."<<id<<endl;
				return;
			}
		}
		empID[index]=id;
		empName[index]=name;
		cout<<"Employee input successful."<<endl<<endl;
	}

	void search(int id)
	{
		int index=hashFunction(id);
		int startIndex=index;
		while(empID[index]!=-1)
		{
			if(empID[index]==id)
			{
				cout<<"Employee Found: ID="<<empID[index]<<", Name="<<empName[index]<<endl<<endl;
				return;
			}
			index=(index+1)%tableSize;
			if(index==startIndex)
				break;
		}
		cout<<"Employee ID "<<id<<" not found."<<endl<<endl;
	}

	void display()
	{
		cout<<"Hash Table:"<<endl;
		for(int i=0;i<tableSize;i++)
		{
			if(empID[i]!=-1)
				cout<<"Index "<<i<<": ID="<<empID[i]<<", Name="<<empName[i]<<endl;
			else
				cout<<"Index "<<i<<": Empty"<<endl;
		}
		cout<<endl;
	}
};

int main()
{
	int size;
	cout<<"Enter size of hash table:";
	cin>>size;

	HashTable ht(size);
	int choice;

	do
	{
		cout<<"Employee Hash Table Menu"<<endl;
		cout<<"1. Insert Employee"<<endl;
		cout<<"2. Search Employee by ID"<<endl;
		cout<<"3. Display Hash Table"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		cout<<"Enter your choice:";
		cin>>choice;

		switch(choice)
		{
		case 1:
		{
			int id;
			string name;
			cout<<"Enter Employee ID:";
			cin>>id;
			cin.ignore();
			cout<<"Enter Employee Name:";
			getline(cin,name);
			ht.insert(id,name);
			break;
		}

		case 2:
		{
			int id;
			cout<<"Enter Employee ID to search:";
			cin>>id;
			ht.search(id);
			break;
		}

		case 3:
			ht.display();
			break;

		case 4:
			cout<<"Exiting program."<<endl;
			break;

		default:
			cout<<"Invalid choice."<<endl;
		}

	}
	while(choice!=4);

	return 0;
}

