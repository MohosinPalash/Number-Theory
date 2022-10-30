/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:[Optimized - Sieve of Eratosthenes] Generate Prime Numbers .
	Complexity	:O( n*ln(n) ) but more optimized
*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e7+123;
bool isPrime[mx];
vector<int>primes;

void primeGenerator( int n){
	
	isPrime[1]=0;
	isPrime[2]=1;
	for(int i=3; i<=n; i+=2)
		isPrime[i] = 1;

	for(int i=3; i<=n; i+=2){
		if (isPrime[i] == 1){
			for(int j=i*i; j<=n; j+=(2*i)){
				isPrime[j] = 0;
			}
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
	150

Output:
	2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 
*/