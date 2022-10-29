/*
	Author: 	Palash
	Topic: 		Number Theory
	Problem: 	OPT-Find the divisors of all the elements of an array.
	Complexity: O( n*ln(n) )
*/
#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	optimize();
	
	int sz;
	cin >> sz;

	vector<int>divisors[sz+1];
	for(int i=1; i<=sz; i++){
			
		for(int j=i; j<=sz; j+=i){
			divisors[j].push_back(i);
		}

	}

	
	cout<< "Divisors:\n";
	for(int i=1; i<=sz; i++){
		cout<< i << " : ";
		for(auto d : divisors[i]){
			cout<< d << " ";
		}
		cout<<endl;
	}
	
}

/*
Input: 
	15

Output:
	Divisors:
	1 : 1 
	2 : 1 2 
	3 : 1 3 
	4 : 1 2 4 
	5 : 1 5 
	6 : 1 2 3 6 
	7 : 1 3 7 
	8 : 1 2 4 8 
	9 : 1 3 4 9 
	10 : 1 2 5 10
	11 : 1 11 
	12 : 1 2 3 4 6 12 
	13 : 1 13 
	14 : 1 2 7 14 
	15 : 1 3 5 15 
*/