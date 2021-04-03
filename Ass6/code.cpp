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
vector<vector<int>>graph;
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
bool diffDigits(int a,int b){
    int diff = 0;
    while(a>0){
        int r1 = a%10;
        int r2 = b%10;
        diff+=(r1!=r2);
        a/=10;
        b/=10;
    }
    return (diff==1);
}
void makeGraph(){
    graph = vector<vector<int>>(maxn+1);
    for(int i=0;i<primes.size();++i){
        for(int j=i+1;j<primes.size();++j){
            int p1 = primes[i];
            int p2 = primes[j];
            if(diffDigits(p1,p2)!=1){
                continue;
            }
            graph[p1].push_back(p2);
            graph[p2].push_back(p1);
        }
    }
}

int main(){
    sieve();
    makeGraph();
}