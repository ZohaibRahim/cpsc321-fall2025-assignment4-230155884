# **CPSC 321 – Assignment 4: Banker’s Algorithm**  
**University of Northern British Columbia**  
**Course:** Operating Systems – Fall 2025  
**Instructor:** Dr. Sajal Saha  
**Student:** Zohaib Rahim  
**File:** `assignment4.c`

---

## **Overview**
This program implements the **Banker's Algorithm** to determine whether a system state is **safe** or **unsafe**.  
It accepts the following input:

- Number of customers  
- Number of resource types  
- Total instances of each resource  
- Available resources  
- Maximum demand matrix  
- Current allocation matrix  
- A new resource request  

The program computes the **Need** matrix, runs the **Safety Algorithm**, and outputs:

- `State Safe` + safe sequence  
- or  
- `State Unsafe`

The formatting and prompts match the assignment specification exactly.

---

## **Concepts Implemented**
- Resource allocation model (Available, Maximum, Allocation, Need)  
- Safety Algorithm for deadlock avoidance  
- Request validation logic  
- Dynamic variable-length arrays (C99)  
- Modular input helper functions  

---

## **File Structure**
Assignment4.c
Assignment4.exe
README.md

---

## **How to Compile and Run**

### **Compile**
```bash
gcc assignment4.c -o assignment4
```
### **Run**
```bash
./assignment4
```
---
## **Program Flow**
- Read number of customers and resources
- Read instances, available resources
- Read Maximum matrix
- Read Allocation matrix
- Compute Need = Maximum - Allocation
- Read new resource request
- Execute Safety Algorithm
- Output safe/unsafe result
- If safe, print the safe sequence

---
## **Functions Included**
```
read_array(arr, n)
```
Reads a 1D array (instances, available, request).

```
read_matrix(cust, resource, matrix)
```
Reads a customer-by-resource matrix (maximum, allocation).
```
compute_need(max, alloc, need)
```
Computes the Need matrix.

These help reduce repetition while keeping the exact same I/O behavior.
