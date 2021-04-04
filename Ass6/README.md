# Design and Analysis of Algorithms

## Problem Statement
Shortest path to reach one prime to other by changing single digit at a time. Given
two four-digit prime numbers, suppose 1033 and 8179, we need to find the shortest
path from 1033 to 8179 by altering only single digit at a time such that every number
that we get after changing a digit is prime. For example, a solution is 1033, 1733,
3733, 3739, 3779, 8779, 8179

---
## Running the Code 

```
Download project
git clone https://github.com/KantSurya/DAA-Assignment-6.git
```
Initialisation: 
```
Go to assignment folder
cd DAA-Assignment/Assignement-06
```
---

Sample Input and Output
```
Input : 
1373 8017

Output : 
Shortest Distance : 7
Path
1373 -> 1303-> 1301-> 3301-> 3001-> 3011-> 8011-> 8017
----------------------------
```
**Test cases**
```
Test Case 1 : 
Input : 
1373 8017

Output : 
Shortest Distance : 7
Path
1373 -> 1303-> 1301-> 3301-> 3001-> 3011-> 8011-> 8017
-------------------------------------
Test Case 2 : 
Input : 
1033 8179

Output : 
Shortest Distance : 6
Path
1033 -> 1031-> 1051-> 1151-> 1171-> 8171-> 8179
-------------------------------------
Test Case 3 : 
Input : 
1033 1033

Output : 
Shortest Distance : 0
-------------------------------------
```

---

### Theory
Following is step by step approach of algorithm(s) used inour program :
01. Find  and  store  all  the  prime  numbers  of  4  digit  using Sieve of Eratosthenes
02. Make a graph using those prime numbers. Vertex will bethe prime numbers and two primes u,v will have an edge if  they  can  be  converted  into  one  another  by  changinga  single  digit.  Ex.  1373  and  1303  will  have  an  edgeconnecting both the nodes in our graph.
03. If we have to find the shortest distance between a and b, then  we  will  root  our  graph  at  node  a  and  initialize  itsdistance as 0.
04. Then apply bfs on our graph to find the shortest distancebetween given two prime numbers. The relation used willbe distance[child] = distance[parent] + 1, where child andparent have a direct edge and parent has a height smallerthan child

---

### Analysis

**Time Complexity**

We need three functions to solve this problem :- 
01. sieve() :  to  generate  prime  numbers  up  to  N.  it  take O( N(log(log(N))) )time.
02. makeGraph() : to  add  edges  in  our  graph.  It  takes O(P^2)time.
03. bfs : to find shortest distance between given two 4 digitprimes. It takes O( N+P^2 )time.

Therefore,  the  time  complexity  of  our  program  will  be : O( N(log(log(N))) +P^2)

**Space Complexity**
01. sieve() :  to store prime numbers up to N. it take  O(N) space.
02. makeGraph() : to add edges in our graph. At max we will have P*(P-1)/2  edges. So storing N nodes and P^2 edges Which is  O(N + P^2) space.
03. bfs : In bfs, our queue can have a maximum of P values at a time. So, It takes $O(P)$ time.

Therefore, the space complexity of our program will be : O(N + P^2)\\

----

### References

01. https://en.wikipedia.org/wiki/Breadth-first_search 
02. Cormen, Leiserson, Rivest, and Stein (2009). Introduction to Algorithms, 3rd edition.
03. https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/
