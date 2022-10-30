/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:Codeforces- Noldbach problem
	Link 		:https://codeforces.com/problemset/problem/17/A
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
	int n, k;
	cin>>n >> k;
	primeGenerator(n);

	int cnt=0;
	for(int i=1; i<primes.size(); i++){

		int x = primes[i-1] + primes[i] +1;
		// cout<<x<<endl;
		if(isPrime[x] == 1 && x<=n){
			cnt++;
		}
	}
	// cout<<cnt<<endl;

	if(k <= cnt)
		cout<<"YES\n";
	else
		cout<<"NO\n";

	
}

/*
Test Case-01:
	Input: 27 2
	Output: YES

Test Case-02:
	Input: 45 7
	Output: NO
*/