#include<stdio.h>
#include<math.h>

int main(){
	int n,i,j,k,p,q;
	float pivot,term,a[10][10];
	printf("Enter Dimension of System of equations \n");
	scanf("%d",&n);
	printf("Enter coefficients Matrix \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			if(i==j-n){
				a[i][j] = 1;
			}else{
				a[i][j] = 0;
			}
		}
	}
	for(k=0;k<n;k++){
		pivot = a[k][k];
		for(p=0;p<2*n;p++){
			a[k][p] = a[k][p] /pivot;	
		}
		for(i=0;i<n;i++){
			term = a[i][k];
			if(k!=i)
			for(j=0;j<2*n;j++){
				a[i][j] = a[i][j] - a[k][j]*term;
			}
		}
	}
	printf("Matrix Inverse is: \n");
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++)
		printf("%f\t",a[i][j]);
		printf("\n");
	}
	  getchar();
    getchar();
	return 0;
}
