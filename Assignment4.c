#include <stdio.h> 

int main() 
{ 
	// P0, P1, P2, P3, P4 are the names of Process

	int cust, resource, i, j, k; 
	cust = 5; // Indicates the Number of processes/customers 
	resource = 4; //Indicates the Number of resources 

	int avail[resource] = { 2, 3, 2 }; // the available amount of each resource
	
	int max[cust][resource] = { { 7, 6, 3 }, // P0 // the maximum demand of each customer
					{ 3, 2, 2 }, // P1 
					{ 8, 0, 2 }, // P2 
					{ 2, 1, 2 }, // P3 
					{ 5, 2, 3 } }; // P4 
	
	int alloc[cust][resource] = { { 0, 0, 1 }, // P0 // the amount currently allocated to each customer  
						{ 3, 0, 0 }, // P1 
						{ 1, 0, 1 }, // P2 
						{ 2, 3, 2 }, // P3 
						{ 0, 0, 3 } }; // P4 
	
	//the remaining need of each customer
	int need[cust][resource]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < r; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	

	int f[cust], ans[cust], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < cust; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < resource; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < resource; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	printf("Th SAFE Sequence is as follows\n"); 
	for (i = 0; i < cust - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[cust - 1]); 

	return (0); 

}
