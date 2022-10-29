/*
	Author: 	Palash
	Topic: 		Number Theory
	Problem: 	AtCoder- Sum of Divisors
	Link: 		https://atcoder.jp/contests/abc172/tasks/abc172_d
*/
#include<bits/stdc++.h>
using namespace std;
int divisors[10000009];
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	optimize();
	
	int n;
	cin >> n;

	
	for(int i=1; i<=n; i++){
			
		for(int j=i; j<=n; j+=i){
			divisors[j]++;
		}

	}

	long long sum =0;
	for(int i=1; i<=n; i++){
		sum += (1LL* i* divisors[i]);
	}
	cout<<sum<<endl;
}

/*
Test case - 01:
	Input: 4
	Output: 23

Test case - 02:
	Input: 100
	Output: 26879

Test case - 03:
	Input: 10000000
	Output: 838627288460105  
*/