#include<stdio.h>

#include<math.h>
#define f(x) 3*(x)*(x)+2*(x)-5
int main(){
	float a,h,x0,xn,fx0,fxn,term,v;
	int i,k;
	
	printf("Enter Lower and Upper Limit : \n");
	scanf("%f %f",&x0,&xn);
	
	printf("Enter Number of Segments: \n");
	scanf("%d",&k);
	
	h =(xn-x0)/k;
	fx0 = f(x0);
	fxn = f(xn);
	term = f(x0)+f(xn);
	for(i=1;i<=k-1;i++){
		a = x0+i*h;
		term = term+2*(f(a));
	}
	v = h/2*term;
	
	printf("Value of  Integration: %f\n",v);
	getchar();
   getchar();
	

	return 0;	
}
