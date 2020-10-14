/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <string.h>

using namespace std;

int findStart(char arr[], int start, int len);
int getNumOfSubset(char arr[], int len);

int main() {
	char arr[500000];
	cin >> arr;
	int len = strlen(arr);
	char finalArr[len];
	int start = 0;

	//Getting Starting index of actual correct sequence
	start = findStart(arr, 0, len);
	cout<<len<<endl;
     cout<<arr<<" tbr: "<<endl;
	//copying correct sequence to another array
	for(int i=0, j=start; i < len; i++)
	{
		finalArr[i] = arr[j];
		if((++j) == len)
			j=0;

		cout<<" array: "<<finalArr<<"i="<<i<<" j="<<j<< endl;

	}
	
	//counting total numbers of subsets of ()
	cout << getNumOfSubset(finalArr,len) << endl;

}

int findStart(char arr[], int start, int len)
{
//whenever sum is negative start counting again from next 		index by caling same function. when sum is non negative and 	reached to array's end, value of start will be the index from 	where actual "correct sequence" starts. returning value of start.
	
	int sum = 0;

	cout<<"TBR "<<arr<<" start: "<<start<<" len: "<<len<<endl;
	for(int i=start; i<len; i++)
	{
		if(arr[i] == '(')
			sum++;
		else
			sum--;
		
		if( sum < 0)
			return findStart(arr,i+1, len);

	}

	return start;
}

int getNumOfSubset(char arr[], int len)
{
	int count = 0, sum = 0;
	for(int i = 0; i< len; i++)
	{
		if(arr[i] == '(')
			sum++;
		else
			sum--;
		
		if(sum == 0)
			count++;

	}
	return count;
}

