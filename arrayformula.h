#include <stdio.h>

int sum3(int a, int b, int c){
	int sum=0;
	sum= a+b+c;
	return sum;
}
int swap(int *first, int *second, int *third) {
	if(!first || !second || !third)
		return -1;
	int buffer;
	buffer = *first;
	*first = *third;
	*third = *second;
	*second = buffer;
	return 0;
}
int naturalSquare(int n, int * result){
	int buffer = n;
	*result = 0;
	while(buffer!=0) {
		*result = *result + (buffer*buffer);
		buffer--;
	}
	return 0;
}
int fibonacci(int n) {
	int fib[n];
	int i = 2;
	fib[0] = 1;
	fib[1] = 1;
	while(i<n) {
		fib[i] = fib[i-1] + fib[i-2];
		printf("%d, ", fib[i]);
		i++;
	}
	return 0;
}
int copyArray(int * a, int * b, int length) {
	if(!a|| !b) {
		return -1;
	}
	int i;
	for(i=0;i<length;i++) {
		b[i]=a[i];
	}
	return 0;
}
int sumArray(int * a, int len, int *sum) {
	if(!a) return -1;
	int i;
	for(i=0;i<len;i++){
		*sum = *sum + a[i];
		//printf("iteration number: %d, sum is: %d\n", i, *sum);
	}
	return 0;
}
int dotProduct(int x[], int y[], int n, int * dp) {
	if(!x||!y||!dp) return -1;
	if(n<=0) return -2;
	int i;
	*dp = 0;
	for(i=0;i<n;i++){
		*dp = x[i]*y[i];
	}
	return 0;
}
int vectorSum(int x[], int y[], int n, int sum[]) {
	if(!x||!y||!sum) return -1;
	if(n<=0) return -2;
	int i;
	for(i=0;i<n;i++) {
		sum[i]=x[i] + y[i];
	}
	return 0;
}
int minmax(int *a, int n, int * min, int *max) {
	if(!a) return -1;
	if(n<=0) return -2;
	int i;
	for(i=0;i<n-1;i++){
		*min=a[i];
		*max=a[i];
		if(*min>a[i+1]) *min=a[i+1];
		if(*max<a[i+1]) *max=a[i+1];
	}
	return 0;
}
