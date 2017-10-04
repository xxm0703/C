#include<stdio.h>
#include<string.h>
float average(float*);
int divide_all(int a[10],int div);
void change_element(int a[10], int index, int n);
int return_element(int a[10], int index);
int divider(int,int);
int len(int*);
int vowel_count(char*);
int main(){
	int a[] = {10,14,2,4,82,46, 98};
	float g[] = {5.50,4.20,6.30}; 
	char c[] = "Hello worldo";
	printf("%d\n", return_element(a,3)); 
	change_element(a,3, 68); 
	printf("%d\n", return_element(a,3)); 
	printf("%s\n", c); 
	printf("%d\n", vowel_count(c)); 
	printf("%d\n", divide_all(a,2)); 
	printf("%d\n", divide_all(a,3));
	printf("%f\n", average(g)); 
return 0;
}

int vowel_count(char c[]){
	int count = 0;
	for(int i = 0;i < strlen(c);i++){
		if(c[i] == 'a'
		||c[i] == 'e'
		||c[i] == 'o'
		||c[i] == 'u'
		||c[i] == 'i') count++;
	}
	return count;
}
float average(float f[]){
	int len = (int)(sizeof(&f)/sizeof(float))-1;
	int sum = 0;
	for(int i = 0; i < len; ++i)
		sum += f[i];
	return sum/len;
}
int divider(int num,int div){
	return (num % div);
}
int len(int a[]){
	return (int)(sizeof(&a)/sizeof(int));
}
int return_element(int a[], int index){
	return a[index];
}
void change_element(int a[], int index, int n){
	a[index] = n;
}
int divide_all(int a[],int div){
	for(int i = 0;i < len(a);++i)
		if(divider(a[i], div))
			return 0;
	return 1;
}
	






