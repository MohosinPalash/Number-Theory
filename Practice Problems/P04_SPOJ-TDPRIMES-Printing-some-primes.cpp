/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:SPOJ - TDPRIMES - Printing some primes
	Link 		:https://www.spoj.com/problems/TDPRIMES/
*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e8+123;
// bool isPrime[mx];
bitset<mx>isPrime;
vector<int>primes;

void primeGenerator( int n){
	

	isPrime[1]=0;
	isPrime[2]=1;
	for(int i=3; i<=n; i+=2)
		isPrime[i] = 1;

	int sq = sqrt(n);
	for(int i=3; i<=sq; i+=2){
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
	// int n;
	// cin>>n;
	primeGenerator(1e8);

	for(int i=0; i<primes.size(); i+=100){
		cout<< primes[i] <<endl;
	}
	cout<<endl;

	
}
