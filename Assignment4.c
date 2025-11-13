#include <stdio.h> 

int main() 
{ 
	// P0, P1, P2, P3, P4 are the names of Process



	int cust, resource, i, j, k; 

	//Customer/Processes
	printf("Enter the number of customers (processes): ");
	scanf("%d", &cust); //Indicates the Number of customers

	//Resources
	printf("Enter the number of resources: " );
	scanf("%d", &resource); //Indicates the Number of resources
	
	//Number of instances of each resource type
	int instances[resource]; //the total amount of each resource
	printf("Enter number of instances of each resource (%d values): ", resource);
	for (i = 0; i < resource; i++) {
		scanf("%d", &instances[i]);
	}
	
	//Available Resources
	int avail[resource]; //the available amount of each resource
	printf("Enter avaialable resources (%d values): ", resource);
	for (i = 0; i < resource; i++) {
		scanf("%d", &avail[i]);
	}

	//Maximum Demand Matrix
	int max[cust][resource]; //the maximum demand of each customer
	printf("Enter maximum demand matrix(%d x %d):\n", cust, resource);
	for (i = 0; i < cust; i++) {
		printf("Customer %d: ", i);
		for (j = 0; j < resource; j++) {
			scanf("%d", &max[i][j]);
		}
	}
	
	//Allocation Matrix
	int alloc[cust][resource]; // the amount currently allocated to each customer  
	printf("Enter current allocation matrix(%d x %d):\n", cust, resource);
	for (i = 0; i < cust; i++) {
		printf("Customer %d: ", i);
		for (j = 0; j < resource; j++) {
			scanf("%d", &alloc[i][j]);
		}
	}
	

	//Need Matrix
	int need[cust][resource]; //the remaining need of each customer
	for (i = 0; i < cust; i++) { 
		for (j = 0; j < resource; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 

	//Resource Request Algorithm
	int request[resource]; //Request array
	int req_cust; //Customer making the request
	printf("\n\nEnter Resource Request (e.g., for Customer1 enter 1 and then requests 1 0 2): ");
	scanf("%d", &req_cust);
	for (i = 0; i < resource; i++) {
		scanf("%d", &request[i]);
	}

	
	
	//Mark all customers as not finished
	int f[cust]; //Finish array
	int ans[cust]; //Safe sequence array
	int ind = 0; //Index for safe sequence
	for (k = 0; k < cust; k++) { 
		f[k] = 0; 
	} 

	
	
	//Find the safe sequence
	int y = 0; 
	for (k = 0; k < cust; k++) { 
		for (i = 0; i < cust; i++) { 
			if (f[i] == 0) { 
				//Check if need is less than available
				int flag = 0; 
				for (j = 0; j < resource; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				//If need is less than available, add to safe sequence
				if (flag == 0) { 
					ans[ind++] = i;  //Add customer to safe sequence
					for (y = 0; y < resource; y++) 
						avail[y] += alloc[i][y];  //Release resources
					f[i] = 1; //Mark customer as finished
				} 
			} 
		} 
	} 

	//If not all customers could be allocated, state is unsafe
	if (ind < cust) { 
		printf("State Unsafe\n"); 
		return (0); 
	}

	//If safe, print the safe sequence
	else {
		printf("State Safe\n"); 
		//print the safe sequence
		for (i = 0; i < cust - 1; i++) 
			printf("C%d ", ans[i]); 

		//print last customer
		printf("C%d", ans[cust - 1]); 
	}
	

	

	return (0); 

}
