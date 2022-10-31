/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:UVa - 583 - Prime Fcators
	Link 		:https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=524
*/
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 1e5+123;
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
	primeGenerator(1e5);
	
	long long n;
	
	while(cin>>n){
		if(n==0)
			break;
		long long x = abs(n);
		vector<long long>factors = primeFactorization(x);
		cout<< n << " = ";
		if(n <0 )
			cout<<"-1 x ";
		for(int i=0; i<factors.size()-1; i++)
			cout<<factors[i]<< " x ";
		cout<<factors[factors.size()-1]<<endl;
	}


}

/*
Input: 
	-190
	-191
	-192
	-193
	-194
	195
	196
	197
	198
	199
	200
	0

Output:
	-190 = -1 x 2 x 5 x 19
	-191 = -1 x 191
	-192 = -1 x 2 x 2 x 2 x 2 x 2 x 2 x 3
	-193 = -1 x 193
	-194 = -1 x 2 x 97
	195 = 3 x 5 x 13
	196 = 2 x 2 x 7 x 7
	197 = 197
	198 = 2 x 3 x 3 x 11
	199 = 199
	200 = 2 x 2 x 2 x 5 x 5
*/