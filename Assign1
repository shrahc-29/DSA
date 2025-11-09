#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class student 
{
	private:		//Private access specifier
		int Roll_no;
		char name[30];
		float SGPA;

	public:			//Public access specifier for functions


		void create()		//Takes input from user
		{
			cout << "Enter Student name: ";
			cin >> name;
			cout << "Enter roll_no: ";
			cin >> Roll_no;
			cout << "Enter SGPA: ";
			cin >> SGPA;
			cout << endl;
		}


		void display()		//Displays information
		{
			cout << "Student Name: " << name << endl;
			cout << "Roll No. : " << Roll_no << endl;
			cout << "SGPA: " << SGPA << endl;
			cout << endl;
		}


		void search(student stud[15], int n, int key)		//Searches acc to Roll no.
		{
			for (int i = 0; i < n; i++) 
			{
				if (key == stud[i].Roll_no) 
				{
				cout << "Student found: " << endl;
				stud[i].display();
				}
			}
			cout << "Student not found." << endl;
		}



		void insertion_sort(student *stud, int n)	//Sorts acc to Roll no. using insertion sort
		{
			for (int i = 1; i < n; i++) 
			{
				student key = stud[i];
				int j = i - 1;

				while (j >= 0 && stud[j].Roll_no > key.Roll_no) 
				{
					stud[j + 1] = stud[j];
					j--;
				}
				stud[j + 1] = key;
			}
		}


		void shell_sort(student *stud, int n)		//Sorts acc to name using shell sort
		{
			for (int gap = n / 2; gap > 0; gap /= 2) 
			{
				for (int i = gap; i < n; i++) 
				{
					student temp = stud[i];
					int j;
					for (j = i; j >= gap && strcmp(stud[j - gap].name, temp.name) > 0; j -= gap) 
					{
						stud[j] = stud[j - gap];
					}
					stud[j] = temp;
				}
			}
		}


		int getMaxSGPA(student stud[], int n)		//Finds max SGPA
		{
			int max = (int)(stud[0].SGPA * 1000);
			for (int i = 1; i < n; i++) 
			{
				int sg = (int)(stud[i].SGPA * 1000);
				if (sg > max)
				max = sg;
			}
			return max;
		}


		void countSort(student stud[], int n, int exp)		//Count sort for each digit in an element
		{
			student output[15];
			int count[10] = {0};
			for (int i = 0; i < n; i++)
			{
				count[((int)(stud[i].SGPA * 1000) / exp) % 10]++;
			}
			for (int i = 8; i >= 0; i--)
			{
				count[i] += count[i + 1]; // For descending order
			}
			for (int i = n - 1; i >= 0; i--) 
			{
				int idx = ((int)(stud[i].SGPA * 1000) / exp) % 10;
				output[count[idx] - 1] = stud[i];
				count[idx]--;
			}
			for (int i = 0; i < n; i++)
			{
				stud[i] = output[i];
			}    
		}

		void radix_sort(student *stud, int n)		//Sorts acc to SGPA using radix sort
		{
			int max = getMaxSGPA(stud, n);
	
			for (int exp = 1; max / exp > 0; exp *= 10)
			{
				countSort(stud, n, exp);
			}
			cout << "\nTop 10 students by SGPA (descending):" << endl;
			for (int i = 0; i < min(n, 10); i++) 
			{
				stud[i].display();
			}
		}
};


int main() 
{
	const int MAX = 15;
	int n;
	
	cout << "Enter number of students (max 15): ";
	cin >> n;
	
	if (n > MAX) 
	{
		cout << "Exceeded maximum student limit!" << endl;
		return 1;
	}

	student stud[MAX];		//Array of objects of class 'student' 

	int choice;
	do 
	{
		cout << "Enter your choice:\n\t1. Create\n\t2. Display\n\t3. Search\n\t4. Insertion sort (Roll No)\n\t5. Shell sort (Name)\n\t6. Radix sort (Top 10 SGPA)\n";
		cin >> choice;

		switch (choice) 
		{
			case 1:
				for (int i = 0; i < n; i++) 
				{
					stud[i].create();
				}
				break;

			case 2:
				cout << "\nStudent Data:\n";
				for (int i = 0; i < n; i++) 
				{
					stud[i].display();
				}
				break;

			case 3: 
				int key;
				cout << "Enter roll no to be searched: ";
				cin >> key;
				stud[0].search(stud, n, key);
				break;

			case 4:
				stud[0].insertion_sort(stud, n);
				cout << "\nStudents sorted by Roll Number:\n";
				for (int i = 0; i < n; i++)
				{
					stud[i].display();
				}
				break;

			case 5:
				stud[0].shell_sort(stud, n);
				cout << "\nStudents sorted by Name:\n";
				for (int i = 0; i < n; i++) 
				{
					stud[i].display();
				}
				break;

			case 6:
				stud[0].radix_sort(stud, n);
				break;

			default:
			cout << "Invalid choice." << endl;
		}

		cout << "\nDo you want to continue? (1 for Yes, 0 for No): ";
		cin >> choice;
	
	} 

	while (choice == 1);

	return 0;
}


