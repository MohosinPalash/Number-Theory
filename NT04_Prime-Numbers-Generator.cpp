/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:Generate Prime Numbers.
	Complexity	:O( n*ln(n) )
*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e7+123;
bool isPrime[mx];
vector<int>primes;

void primeGenerator( int n){
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[1]=0;

	for(int i=2; i<=n; i++){
		for(int j=i+i; j<=n; j+=i){
			isPrime[j] = 0;
		}
	}

	for(int i=2; i<=n; i++){
		if(isPrime[i] == 1)
			primes.push_back(i);
	}
}

int main(){
	optimize();
	int n;
	cin>>n;
	primeGenerator(n);

	for(auto u : primes){
		cout<< u << " ";
	}
	cout<<endl;

	
}

/*
Input: 
	100

Output:
	2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97  
*/