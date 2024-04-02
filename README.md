# LBYARCH-S14-Grp14
This is the repository for the x86-to-C interface programming project of LBYARCH MP Group 14 Section 14.
- Prepared By Serrato, Nico Andrei R. and Exconde, Isiah Reuben C.

## Introduction
This project contains two kernels in a (1) C program and (2) an x86-64 assembly language that performs 1-D stencil of vector X and places the result in vector Y with both X and Y being *double-precision float*. It takes in a scalar value N as the length of the vector, performs the process ( *Y[i]=X[i-3]+X[i-2]+X[i-1]+X[i]+X[i+1]+X[i+2]+X[i+3]* ), and stores the result in vector Y. For each kernel version, the program then outputs the first 10 elements vector Y for all versions of kernel (i.e., C and x86-64) and the time the kernels took to finish the process. These are done for vector sizes N = {2<sup>20</sup>, 2<sup>24</sup>, and  2<sup>30</sup>} 30 times each to get the average execution time.

## Outputs
### Debug mode Vector size N = 2<sup>20</sup>

### Release mode Vector size N = 2<sup>20</sup>

### Debug mode Vector size N = 2<sup>24</sup>

### Release mode Vector size N = 2<sup>24</sup>

### Debug mode Vector size N = 2<sup>30</sup>

### Release mode Vector size N = 2<sup>30</sup>

## Comparative Analysis of Results
