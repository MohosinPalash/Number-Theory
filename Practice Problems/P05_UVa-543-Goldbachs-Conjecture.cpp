/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:UVa - 543 - Goldbach's Conjecture
	Link 		:https://codeforces.com/problemset/problem/17/A
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
	// cin>>n;
	primeGenerator(1e6);

	while(cin >> n){
		
		if(n==0)
			break;
		int a =-1, b=-1, f=0;
		for(auto u: primes){
			if(u > n) break;
			a=u;
			b= n-u;
			if(isPrime[b] == 1 && b>2){
				f=1;
				break;
			}
		}
		if(f==1)
			cout<< n << " = "<< a << " + "<< b<<endl;
		else
			cout<< "‘Goldbach's conjecture is wrong."<<endl;

	}

	
}

/*
Test case - 01:
Input: 
	8
	20
	42
	0

Output:
	8 = 3 + 5
	20 = 3 + 17
	42 = 5 + 37
*/