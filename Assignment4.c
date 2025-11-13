#include <stdio.h> 

// Function to read an array of integers
void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

// Function to read a matrix of integers
void readMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("Customer %d: ", i);
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
    }
}

// Function to compute the need matrix
void computeNeed(int cust, int res, int max[cust][res], int alloc[cust][res], int need[cust][res]) {
    for (int i = 0; i < cust; i++)
        for (int j = 0; j < res; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; //Calculate need
}


int main() 
{ 
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
	readArray(instances, resource);
	
	//Available Resources
	int avail[resource]; //the available amount of each resource
	printf("Enter avaialable resources (%d values): ", resource);
	readArray(avail, resource);

	//Maximum Demand Matrix
	int max[cust][resource]; //the maximum demand of each customer
	printf("Enter maximum demand matrix(%d x %d):\n", cust, resource);
	readMatrix(cust, resource, max);
	
	//Allocation Matrix
	int alloc[cust][resource]; // the amount currently allocated to each customer  
	printf("Enter current allocation matrix(%d x %d):\n", cust, resource);
	readMatrix(cust, resource, alloc);
	

	//Need Matrix
	int need[cust][resource]; //the remaining need of each customer
	computeNeed(cust, resource, max, alloc, need);

	//Resource Request Algorithm
	int request[resource]; //Request array
	int req_cust; //Customer making the request
	printf("Enter Resource Request: ");
	scanf("%d", &req_cust);
	readArray(request, resource);
	
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
		printf("\nState Unsafe\n"); 
		return (0); 
	}

	//If safe, print the safe sequence
	else {
		printf("\nState Safe\n"); 
		//print the safe sequence
		for (i = 0; i < cust - 1; i++) 
			printf("C%d ", ans[i]); 

		//print last customer
		printf("C%d", ans[cust - 1]); 
	}
	
	return (0); 
}

/*
CODE EXECUTION RESULT:

Sample Input 1:
Enter the number of customers (processes): 5
Enter the number of resources: 3
Enter number of instances of each resource (3 values): 10 5 7
Enter avaialable resources (3 values): 3 3 2
Enter maximum demand matrix(5 x 3):
Customer 0: 7 5 3
Customer 1: 3 2 2
Customer 2: 9 0 2
Customer 3: 2 2 2
Customer 4: 4 3 3
Enter current allocation matrix(5 x 3):
Customer 0: 0 1 0
Customer 1: 2 0 0
Customer 2: 3 0 2
Customer 3: 2 1 1
Customer 4: 0 0 2
Enter Resource Request: 1 1 0 2

Sample Output 1:
State Safe
C1 C3 C4 C0 C2
--------------------------------------------------------------------------------------
Sample Input 2:
Enter the number of customers (processes): 5
Enter the number of resources: 3
Enter number of instances of each resource (3 values): 10 5 7
Enter avaialable resources (3 values): 2 3 0
Enter maximum demand matrix(5 x 3):
Customer 0: 7 5 3
Customer 1: 3 2 2
Customer 2: 9 0 2
Customer 3: 2 2 2
Customer 4: 4 3 3
Enter current allocation matrix(5 x 3):
Customer 0: 0 1 0
Customer 1: 2 0 0
Customer 2: 3 0 2
Customer 3: 2 1 1
Customer 4: 0 0 2
Enter Resource Request: 2 0 2 0

Sample Output 2:
State Unsafe
*/