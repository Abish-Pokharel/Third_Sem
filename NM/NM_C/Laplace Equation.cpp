#include <stdio.h>
#include <math.h>

int main() {
    int n,i, j, k;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10];
    
    printf("Enter the dimension of plate (n,n): ");
    scanf("%d", &n);

    printf("Enter temperatures at left, right, top, and bottom: ");
    float tL, tR, tT, tB;
    scanf("%f %f %f %f", &tL, &tR, &tT, &tB);
    
    // Initialize matrix
    for ( i = 0; i <= n; i++){
    	a[i][i] = -4;
	}
	for(i = 0; i <= n ; i++){
		a[i][n-i] = 0;
	}

    for (i = 0; i < n; i++) {
    	for(j=0;j<=n;j++){
    		if(i != j && j != (n-i)){
    			a[i][j] = 1;
			}
    		
		}
    }
    for(i=0;i<=n;i++){
    	b[i] = 0;
    	k=0;
	}
	for(i = 1;i<n;i++){
		for(j=1;j<n;j++){
			if((i-1) == 0){
				b[k] = b[k] - tL;
			}
			if((i+1) == 0){
				b[k] = b[k] - tR;
			}
			if((j-1) == 0){
				b[k] = b[k] - tB;
			}
			if((j+1) == n){
				b[k] = b[k] - tT;
			}
			k++;
		}
	}
    
    // Accuracy limit
    printf("Enter accuracy limit: ");
    scanf("%f", &error);
    
    // Iterative calculation
    while (1) {
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) 
                sum -= a[i][j] * old_x[j];

            new_x[i] = sum / a[i][i];
            E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
        }

        // Check if error is within the limit
        for (i = 0; i < n; i++) {
            if (E[i] > error)
                break;
        }

        if (i == n) 
            break;
        
        for (i = 0; i < n; i++)
            old_x[i] = new_x[i];
    }

    // Output solution
    printf("Solution:\n");
    for (i = 0; i < n; i++)
        printf("x[%d] = %.6f\n", i, new_x[i]);
        
        return 0;
}

