# Project no.6 : Page replacement algorithms

## **Project objective**

Compare the performance of page replacement algorithms for fixed numbers of frames: Optimal, FIFO, LRU.

## **Description**

The simulation generates a stream of virtual page addresses  based on the following figure. The stream of virtual page addresses are then used to compare the performance of different algorithms in terms of the page faults generated.

***

* The virtual memory of a process consists of P pages, numbered 0 through P −1.
* A reference stream of virtual page addresses is a sequence of integers in the range [0 : P − 1]. Each element, p,  of stream represents one reference to virtual page p.
* The physical memory of the system is approximated as an integer array M[F], where F is the number of frames. Each element M[f] represents one frame and contains the number p of the page currently residing in the frame f.

***

### **Assignment**

* Implement the program to generate a stream of virtual page addresses  based on the above Figure.
* Implement three page replacement algorithms: Optimal, FIFO, LRU.
* Specify the number of page faults and compare the numbers of page faults generated by different algorithms.