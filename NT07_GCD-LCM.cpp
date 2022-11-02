/*
	Author	 	:Palash
	Topic 		:Number Theory
	Problem 	:GCD & LCM Generator.
	Complexity	:O( log(min(a, b)) ) 
*/

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

long long gcd (long long a, long long b){
	return __gcd(a, b);
}

long long lcm (long long a, long long b){
	return a* (b / gcd (a,b) );
}

int main(){
	optimize();

	long long GCD = gcd( 12, 30);
	long long LCM = lcm (12, 30);

	cout<< "GCD = "<< GCD << endl;
	cout<< "LCM = "<< LCM << endl;


	
	
}

/*
Input: 
	12 30

Output:
	GCD = 6
	LCM = 60
*/