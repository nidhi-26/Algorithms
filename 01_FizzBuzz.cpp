/* 	
	Author: Nidhi Bothra
	Created On: 30-05-2019
	Description:	Takes a number as input upto which a series needs to be printed
					Prints series from 1 to n  
				if a number is divisible by 3 then print "Fizz" instead of that number
				if a number is divisible by 5 then print "Buzz" instead of that number
				if a number is divisible by 3 and 5 then print "FizzBuzz" instead of that number
				else print the number
*/


#include<iostream>

using namespace std;

int main() {
	int n;
	cout<<"Enter a natural number: ";
	cin>>n;
	if (n<=0) {
		cout<<"Invalid Entry!";
	}
	else {
		for (int i=1; i<=n; i++) {
			if (i%3==0 && i%5==0)
				cout<<"FizzBuzz"<<endl;
			else if (i%5==0)
				cout<<"Buzz"<<endl;
			else if (i%3==0)
				cout<<"Fizz"<<endl;
			else
				cout<<i<<endl;
		}	
	}
	
	return 0;
}
