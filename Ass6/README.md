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
First We first find out all 4 digit prime numbers till 9999.

Then using those numbers formed the graph using adjacency list.

After forming the adjacency list, we used simple Breadth First Search to solve the problem.

---

### Analysis

**Time Complexity**


**Space Complexity**

----

### References

https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/
