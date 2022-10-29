/*
	Author: 	Palash
	Topic: 		Number Theory
	Problem: 	Find the divisors of a number.
	Complexity: O( sqrt(n) )
*/
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	optimize();
	
	int n;
	cin >> n;

	vector<int>divisors;

	int sq = sqrt(n);

	for(int i=1; i<=sq; i++){
		if(n%i == 0)
			divisors.push_back(i);

		if(i != n/i)
			divisors.push_back(n/i);
	}

	sort(divisors.begin(), divisors.end());

	cout<< "Divisors of "<< n << " are:\n";
	for(auto d : divisors){
		cout<< d << " ";
	}
	cout<<endl;
}

/*
Input: 
	10

Output:
	Divisors of 12 are:
	1 2 3 4 6 12 
*/