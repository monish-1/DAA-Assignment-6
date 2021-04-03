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
int diffDigits(int a,int b){
    int diff = 0;
    while(a>0){
        int r1 = a%10;
        int r2 = b%10;
        diff+=(r1!=r2);
        a/=10;
        b/=10;
    }
    return (diff);
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
void shortestDistance(int a,int b){
    queue<int>q;
    q.push(a);
    vector<int>dist(100009,0);
    vector<bool>vis(100009,0);
    vector<int>parent(100009);
    parent[a] = a;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto & child : graph[u]){
            if(!vis[child]){
                parent[child]=u;
                vis[child] = true;
                dist[child] = dist[u]+1;
                if(child==b){
                    break;
                }
                q.push(child);
            }
        }
    }
    vector<int>path;
    int x = b;
    while(parent[b]!=a){
        path.push_back(b);
        b = parent[b];
    }
    path.push_back(b);
    path.push_back(a);
    reverse(path.begin(),path.end());
    cout<<"Shortest Distance : "<<dist[x]<<"\n";
    cout<<"Path\n";
    cout<<a<<" ";
    for(int i=0;i<path.size();++i)cout<<"-> "<<path[i];
    cout<<'\n';
}
bool isValid(int a,int b){
    int i1 = lower_bound(primes.begin(),primes.end(),a) - primes.begin();
    int i2 = lower_bound(primes.begin(),primes.end(),b) - primes.begin();
    return (i1<primes.size() && i2<primes.size() && primes[i1]==a && primes[i2]==b);
}
int main(){
    sieve();
    makeGraph();
    // 1033 8179
    // 1373 8017
    // 1033 1033
    cout<<"Enter two 4 digit prime numbers\n";
    int a,b;
    cin>>a>>b;
    // a = 1373;
    // b = 8017;
    while(!isValid(a,b)){
        cout<<"Invalid input, Please enter two prime numbers between 1000 and 9999 (ex. 1373 8017)\n";
        cin>>a>>b;
    }
    if(a==b){
        cout<<"0\n";
    }
    else{
        shortestDistance(a,b);
    }
}