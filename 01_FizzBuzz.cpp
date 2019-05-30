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

