/*
	Author: Nidhi Bothra
	Created On: 2019-06-05
	Description:	Calculate number of 1's in the binary representation of an integer
*/

#include<iostream>

using namespace std;

int onesInBinary(int n) {
	int sum = 0;
	while (n>0) {
		sum += n & 1;
		n >>= 1;
	}
	
	return sum;
}

int main() {
	int n, NoOfOnes = 0;
	cout<<"Enter a number: ";
	cin>>n;
	NoOfOnes = onesInBinary(n);
	cout<<"Number of 1's in binary representation of "<<n<<" is "<<NoOfOnes<<endl;
	return 0;
}
