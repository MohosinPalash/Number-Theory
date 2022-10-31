/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:Generating Prime factors.
	Complexity	:O( ( sqrt(n)/ln(n) ) + lg(n) ) 
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

vector<long long> primeFactorization(long long n){
	vector<long long> pFactors;

	for(auto u : primes){
		if(1LL * u *u  > n)
			break;

		if(n%u == 0){
			while(n%u == 0){
				pFactors.push_back(u);
				n/=u;
			}
		}
	}
	if(n>1)
		pFactors.push_back(n);
	return pFactors;
}

int main(){
	optimize();
	primeGenerator(1e6);
	
	int n;
	cin>>n;
	
	vector<long long>factors = primeFactorization(n);
	for(auto u : factors){
		cout<< u << " ";
	}
	cout<<endl;
}

/*
Input: 
	30

Output:
	2 3 5

Input: 
	120

Output:
	2 2 2 3 5
*/