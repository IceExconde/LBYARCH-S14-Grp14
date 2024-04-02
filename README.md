# LBYARCH-S14-Grp14
This is the repository for the x86-to-C interface programming project of LBYARCH MP Group 14 Section 14.
- Prepared By Serrato, Nico Andrei R. and Exconde, Isiah Reuben C.

## Introduction
This project contains two kernels in a (1) C program and (2) an x86-64 assembly language that performs 1-D stencil of vector X and places the result in vector Y with both X and Y being *double-precision float*. It takes in a scalar value N as the length of the vector, performs the process ( *Y[i]=X[i-3]+X[i-2]+X[i-1]+X[i]+X[i+1]+X[i+2]+X[i+3]* ), and stores the result in vector Y. For each kernel version, the program then outputs the first 10 elements vector Y for all versions of kernel (i.e., C and x86-64) and the time the kernels took to finish the process. These are done for vector sizes N = {2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>28</sup>} 30 times each to get the average execution time.

## Outputs
### Debug mode for Vector sizes N = {2<sup>20</sup>, 2<sup>24</sup>, and  2<sup>28</sup>}
![image](https://github.com/IceExconde/LBYARCH-S14-Grp14/assets/120188260/87350cd1-15b3-4309-a5d1-f0867123039f)

### Release mode for Vector sizes N = {2<sup>20</sup>, 2<sup>24</sup>, and  2<sup>28</sup>}
![image](https://github.com/IceExconde/LBYARCH-S14-Grp14/assets/120188260/80ac6a05-85c5-42b8-9ab0-eedc9fa1b533)

## Comparative Analysis of Results
Both C and x86-64 kernels ran 30 times for each vector size N of 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>28</sup>, the largest size of N that the machine could handle. They were also checked for both "Release" and "Debug" mode. It can be seen that as the size of N increases, the average time for the kernels to finish also increases. This means that the value of N and the averaage time are positively correlated.


