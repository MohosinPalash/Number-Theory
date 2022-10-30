/*
	Author: 	Palash
	Topic: 		Number Theory
	Problem: 	Codeforces- Almost Prime
	Link: 		https://codeforces.com/contest/26/problem/A
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
	cin >> n;
	primeGenerator(n);
	int cnt=0;

	vector<int>divisors[n+1];

	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j+=i){
			divisors[j].push_back(i);
		}
	}

	for(int i=1; i<=n; i++){
		int c=0;
		for( auto u : divisors[i]){
			if(isPrime[u] == 1)
				c++;
		}
		if (c == 2)
			cnt++;
	}
	cout<<cnt<<endl;
}

/*
Test case-01:
	Input: 10
	Output: 2

Test case-02:
	Input: 21
	Output: 8
*/