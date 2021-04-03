/*
    Shortest path to reach one prime to other by changing single digit at a time. 
    Given two four-digit prime numbers, suppose 1033 and 8179, 
    we need to find the shortest path from 1033 to 8179 by altering only single digit at a time 
    such that every number that we get after changing a digit is prime. 
    For example, a solution is 1033, 1733, 3733, 3739, 3779, 8779, 8179


*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100009;
vector<int>primes;

void sieve(){
    vector<bool>isPrime(maxn+1,1);
    for(int i=2;i*i<=maxn;++i){
        if(isPrime[i]){
            for(int j=i*i;j<=maxn;j+=i){
                isPrime[j] = 0;
            }
        }
    }
    for(int i=1000;i<=9999;++i){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    sieve();
    for(auto & x : primes)cout<<x<<" ";
}