/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:Codeforces - Sherlock and his girlfriend
	Link 		:https://codeforces.com/contest/776/problem/B
*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e7+123;
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
	int n;
	cin>>n;
	primeGenerator(1e5);

	int color =1;
	if(n>2)
		color=2;
	vector<int>v(n);
	for(int i=0; i<n; i++){
		if(isPrime[i+2] == 1)
			v[i] = 1;
		else
			v[i] = 2;
	}
	cout<<color<<endl;
	for(int i=0; i<n; i++){
		cout<<v[i]<< " ";
	}

	
}

/*
Test case - 01:
Input: 
	3
Output:
	2
	1 1 2 

Test case - 02:
Input: 
	4
Output:
	2
	1 1 2 1 
*/