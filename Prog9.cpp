#include "Stack.h"
#include <string>

using namespace std;

int main()
{
	string messege;
	char choice;
	TUStack<string> A(5);
	cout<< "Testing String Stack:" << endl;
	// print size
	cout << "Max Size of the Array is: " << A.Size() << endl;
	// print position of pinter
	cout << "The current position of stack pointer: " << A.Position() << endl;
	cout << endl;
	// ***TESTING STRING***
	while (messege != "q")
	{
		try
		{	
			
				cout << "Enter string you want to store (enter q to exit): ";
				getline(cin, messege) ; 
				A.Push(messege);
				cout << endl;
				cout << "Do you want to Pop the value (Y/N)" << endl;
				cin>> choice;
				if (choice == 'Y' || choice == 'y')
				{
					A.Pop();
				}
				cin.ignore();
		}
		catch (TUStack<string>::NotInBounds st)
		{	
			cout << "-Error Report- " << endl ;
			cout << "input index is: " << st.index << endl ;
			cout << "array size is: " << st.size << endl ;
			cout << "exception nature: " << st.message << endl ;
		}
	}
	

	// print the content of the array
	for (int i = 0 ; i <= 4 ; i ++)
	{
		cout << "index " << i << ", value " << A[i] << endl ;
	}
	cout<< endl;
	cout << "Testing the copy constructor: " << endl ;
	TUStack<string> B(A) ;
	for (int i = 0 ; i <= 4 ; i ++)
	{
		cout << "index " << i << ", value " << B[i] << endl ;
	}
	cout << endl;
	
	// ***Testing Integer***
	cout << "Testing Integer Stack:" << endl;
	
	int number = 0;
	char inpute;
	TUStack<int> C(3);
	// print size
	cout << "Max Size of the Array is: " << C.Size() << endl;
	// print position of pinter
	cout << "The current position of stack pointer: " << C.Position() << endl;
	cout << endl;
	while (number >= 0)
	{
		try

		{	
			{	
				cout << "Enter the integer you want to store (enter negetive number to exit): ";
				cin>> number;
				C.Push(number);
				cout << "Do you want to Pop the value (Y/N)" << endl;
				cin>> inpute;
				if (inpute == 'Y' || inpute == 'y')
				{
					C.Pop();
				}
				cin.ignore();
			}
		}
		catch (TUStack<int>::NotInBounds st)
		{	
			cout << "-Error Report- " << endl ;
			cout << "input index is: " << st.index << endl ;
			cout << "array size is: " << st.size << endl ;
			cout << "exception nature: " << st.message << endl ;
			cout << endl;
		}
	}

	// print the content of the array
	for (int i = 0 ; i <= 2 ; i ++)
	{
		cout << "index " << i << ", value " << C[i] << endl ;
	}
	// print and test = operator
	cout<< "Testing the = operator" << endl;
	TUStack<int> D(3);
	D = C;
	for (int i = 0 ; i <= 2 ; i ++)
	{
		cout << "index " << i << ", value " << D[i] << endl ;
	}
	cout << endl;

	// testing operator [] 
	cout << "Tesing operator [] " << endl;
	char provide;
	
	
	TUStack<string> F(5);
	int index =0;
	string away = F[index];
	while ( away != " end")
	{
		
		try
		{		
				cout << "Enter an index seperateted by space and a string, enter (index then end) to exit: ";
				cin >> index;
				getline(cin, away) ;
				F[index] = away;
				cout << "Index is " << index << "; Its stored information is " << F[index] << endl << endl ;
				cout << "Do you want to Pop the value (Y/N)" << endl;
				cin>> provide;
				if (provide == 'Y' || provide == 'y')
				{
					F.Pop();
				}
				cin.ignore();
		}
		catch (TUStack<string>::NotInBounds er)
		{	
			cout << "Error Report --------------------------------------" << endl ;
			cout << "input index is: " << er.index << endl ;
			cout << "array size is: " << er.size << endl ;
			cout << "exception nature: " << er.message << endl ;
		}
	}

	system("pause");
	return 0;
}