#include<stdio.h>
#include<conio.h>
int main(){
	int n,i,j,k;
	float a=0,b=0,x[10],y[10],Sx=0,Sy=0,Sxy=0,Sx2=0;
	printf("Enter the number of points: ");
	scanf("%d",&n);
	printf("Enter the value of x and fx \n");
	for(i=0;i<n;i++){
		scanf("%f %f",&x[i],&y[i]);
	}
	for(i=0;i<n;i++){
		Sx = Sx+x[i];
		Sy = Sy+y[i];
		Sxy = Sxy+x[i]*y[i];
		Sx2 = Sx2+x[i]*x[i];
	}
	b = ((n*Sxy) - (Sx*Sy)) / ((n*Sx2) - (Sx*Sx));
	a= (Sy/n) - (b*Sx/n);
	printf("Fitted line is : %f + %f x",a,b);
	getchar();
	getchar();
}
