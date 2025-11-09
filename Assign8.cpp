#include<iostream>
#include<stack>
#include<string>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;

class Stack
{
	string arr[100];
	int max;

	public:
		void input()
		{
			cout<<"Enter number of elements required for size of array:";
			cin>>max;
			cout<<"Enter infix expression elements (space-separated):"<<endl;
			for(int i=0;i<max;i++)
			{
				cin>>arr[i];
			}
		}

		int precedence(string op)
		{
			if(op=="+"||op=="-")
				return 1;
			if(op=="*"||op=="/")
				return 2;
			if(op=="^")
				return 3;
			return 0;
		}
	
		bool isOperator(string token)
		{
			return(token=="+"||token=="-"||token=="*"||token=="/"||token=="^");
		}


		void convertToPostfix()         //Infix to Postfix 
		{
			stack<string>stk;
			string postfix[100];
			int pIndex=0;
			for(int i=0;i<max;i++)
			{
				string token=arr[i];
				if(isalnum(token[0]))
				{
					postfix[pIndex++]=token;
				}
				else if(token=="(")
				{
					stk.push(token);
				}
				else if(token==")")
				{
					while(!stk.empty()&&stk.top()!="(")
					{
						postfix[pIndex++]=stk.top();
						stk.pop();
					}
					if(!stk.empty())stk.pop();
				}
				else
				{
					while(!stk.empty()&&precedence(stk.top())>=precedence(token))
					{
						postfix[pIndex++]=stk.top();
						stk.pop();
					}
					stk.push(token);
				}
			}
			while(!stk.empty())
			{
				postfix[pIndex++]=stk.top();
				stk.pop();
			}
			cout<<"Postfix Expression:";
			for(int i=0;i<pIndex;i++)
			{
				cout<<postfix[i]<<" ";
			}
			cout<<endl;
		}


		void convertToPrefix()     //Infix to Prefix
		{
			string rev[100];
			for(int i=0;i<max;i++)
			{
				rev[i]=arr[max-i-1];
				if(rev[i]=="(")
					rev[i]=")";
				else if(rev[i]==")")
					rev[i]="(";
			}
			stack<string>stk;
			string prefix[100];
			int pIndex=0;
			for(int i=0;i<max;i++)
			{
				string token=rev[i];
				if(isalnum(token[0]))
				{
					prefix[pIndex++]=token;
				}
				else if(token=="(")
				{
					stk.push(token);
				}
				else if(token==")")
				{
					while(!stk.empty()&&stk.top()!="(")
					{
						prefix[pIndex++]=stk.top();
						stk.pop();
					}
					if(!stk.empty())stk.pop();
				}
				else
				{
					while(!stk.empty()&&precedence(stk.top())>precedence(token))
					{
						prefix[pIndex++]=stk.top();
						stk.pop();
					}
					stk.push(token);
				}
			}
			while(!stk.empty())
			{
				prefix[pIndex++]=stk.top();
				stk.pop();
			}
			cout<<"Prefix Expression:";
			for(int i=pIndex-1;i>=0;i--)
			{
				cout<<prefix[i]<<" ";
			}
			cout<<endl;
		}


		void evaluatePostfix()    //Evaluation of Postfix
		{
			stack<int>stk;
			cout<<"Enter postfix expression (space-separated):";
			string token;
			string expr[100];
			int n=0;
			while(cin>>token&&token!="#")
			{
				expr[n++]=token;
			}
			for(int i=0;i<n;i++)
			{
				token=expr[i];
				if(isdigit(token[0]))
				{
					stk.push(stoi(token));
				}
				else if(isOperator(token))
				{
					int val2=stk.top();stk.pop();
					int val1=stk.top();stk.pop();
					int res=0;
					if(token=="+")res=val1+val2;
					else if(token=="-")res=val1-val2;
					else if(token=="*")res=val1*val2;
					else if(token=="/")res=val1/val2;
					else if(token=="^")res=pow(val1,val2);
					stk.push(res);
				}
			}
			cout<<"Postfix Evaluation Result:"<<stk.top()<<endl;
		}


		void evaluatePrefix()
		{
			stack<int>stk;	
			cout<<"Enter prefix expression (space-separated):";
			string token;
			string expr[100];
			int n=0;
			while(cin>>token&&token!="#")
			{
				expr[n++]=token;
			}
			for(int i=n-1;i>=0;i--)
			{
				token=expr[i];
				if(isdigit(token[0]))
				{	
					stk.push(stoi(token));
				}
				else if(isOperator(token))
				{
					int val1=stk.top();stk.pop();
					int val2=stk.top();stk.pop();
					int res=0;
					if(token=="+")res=val1+val2;
					else if(token=="-")res=val1-val2;
					else if(token=="*")res=val1*val2;
					else if(token=="/")res=val1/val2;
					else if(token=="^")res=pow(val1,val2);
					stk.push(res);
				}
			}
			cout<<"Prefix Evaluation Result:"<<stk.top()<<endl;
		}
};


int main()
{
	Stack s;
	int m=1,opt;
	while(m==1)
	{
		cout<<"\nSelect your choice:\n"<<"\t1. Enter infix expression\n"<<"\t2. Convert Infix to Postfix\n"<<"\t3. Convert Infix to Prefix\n"<<"\t4. Evaluate Postfix Expression\n"<<"\t5. Evaluate Prefix Expression\n"<<"\t6. Exit\n";
		cin>>opt;
		switch(opt)
		{
			case 1:
				s.input();
				break;

			case 2:
				s.convertToPostfix();
				break;
	
			case 3:
				s.convertToPrefix();
				break;
			
			case 4:
				s.evaluatePostfix();
				break;

			case 5:
				s.evaluatePrefix();
				break;

			case 6:
				m=0;
				break;
			
			default:
				cout<<"Invalid choice!"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
