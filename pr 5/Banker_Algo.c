#include <stdio.h> 
int main() {
int n, r,m; 
n = 5; //  Number of processes 
m = 3; // Number of resources 
int Allocation[5][3] = { { 0, 2, 1 }, 
			  { 3, 1, 0 },  
		          { 0, 2, 1 },  
			  { 4, 3, 2 },  
			  { 1, 1, 0 } }; 
int Max[5][3] = { { 5, 7, 6 }, 
		   { 4, 2, 9 },  
		   { 6, 7, 5 }, 
		   { 4, 10, 3 },  
		   { 3, 1, 5 } };  
int Available[3] = { 4, 4, 8 }; 
int Finish[n], Result[n], idx = 0; //initally all the processes are unfinished
for (int k = 0; k < n; k++) { 
	Finish[k] = 0; // unfinished process
} // 2D Array for need matrix
int Need[n][m];// calculate the need matrix for every process
for (int i = 0; i < n; i++) { 
	for (int j = 0; j < m; j++) 
		Need[i][j] = Max[i][j] - Allocation[i][j]; 
} 
int y = 0; 
for (int k = 0; k < 5; k++) { 
for (int i = 0; i < n; i++) { 
	if (Finish[i] == 0) { 
		int flag = 0; 
		for (int j = 0; j < m; j++) { 
			if (Need[i][j] > Available[j]){ 
			flag = 1; 
			break; 
			} 
			} 
		if (flag == 0) { 
		Result[idx++] = i; 
		for (int y = 0; y < m; y++) 
		Available[y] += Allocation[i][y]; 
		Finish[i] = 1; 
		} 
	} 
} 
} 
printf("Th SAFE Sequence is \n"); 
for (int i = 0; i < n - 1; i++) 
	printf(" P%d ->", Result[i]); 
printf(" P%d", Result[n - 1]); 
return (0); 
} 
