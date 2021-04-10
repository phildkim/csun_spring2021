# Project objective

## Due Date: **Apr 25 by 11:59pm**

***

### **Implement and experiment with the Banker's algorithm presented in the section titled Dynamic deadlock avoidance.**

[Resource](https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/)

***

### **Description:**

_The Banker's algorithm uses a claim graph consisting of processes, multi-unit resources, request edges, allocation edges, and claim edges._

`The graph can be represented by a set of arrays:`
> The number of units of each resource is represented as a one-dimensional array R[m], where m is the number of resources and each entry R[j] records the number of units of resource Rⱼ. The maximum claims are represented as a two-dimensional array P[n][m] where each entry P[i][j] contains an integer that records the maximum number of units of resource Rⱼ that process pᵢ will ever request. The allocation edges and the request edges are represented using analogous arrays.

```c
int m;// number of resources
int i,j;// pᵢ and Rⱼ
int n,m;// max claims P[n][m]
/**
 * The allocation edges and the request edges
 * are represented using analogous arrays.
 */
int R[m]; // Number of units of each resource.
int R[j]; // Records the number of units of resources Rⱼ.
int P[n][m]; // max claims.
int P[i][j]; // max number of Rⱼ that process pᵢ requests.
```

### **Assignment:**

Develop an interactive program that **_first reads the description of a system_** from the command line or from a file. The description consists of the _**number of processes**_, the _**number of resources**_, the _**numbers of units within each resource**_, and the _**maximum claims of each process**_.

`Using the given information, the program creates the current representation of the system (the set of arrays).
The program then enters an interactive session during which the user inputs commands of the form:`

```c
/**
 *  i = process number
 *  j = resource number
 *  k = # of units of Rⱼ
 *      the process Pᵢ is
 *      requesting or releasing
 * For each operation, the program
 * responds whether the request has
 * been granted or denied.
 */
void request(int i, int j, int k);
void release(int i, int j, int k);
```
