#include<stdio.h>
#include<string.h>
//zad_1
int return_element(int a[10], int index);
//zad_2
void change_element(int a[10], int index, int n);
//zad_3
int vowel_count(char*);
//zad_4
int divider(int,int);
//zad_5
int divide_all(int a[10],int div);
//zad_6
float average(float*);
//zad_7
int smallest(int*);


int len(int*);
int main(){
	int a[] = {10, 14, 2, 4, 82, -46, 98, 34, 26, 72};
	float g[] = {5.50,5.1,6.30,5.6,5.3}; 
	char c[] = "Hello worldo";
	printf("%d\n", return_element(a,3)); 
	change_element(a,3, 68); 
	printf("%d\n", return_element(a,3)); 
	printf("%s\n", c); 
	printf("%d\n", vowel_count(c)); 
	printf("%d\n", divide_all(a,2)); 
	printf("%d\n", divide_all(a,3));
	printf("%.2f\n", average(g)); 
	printf("%d\n", smallest(a));
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
	float sum = 0;
	for(int i = 0; i < 5; ++i)
		sum += f[i];
	return sum/5.0;
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
	for(int i = 0;i < 10;++i)
		if(divider(a[i], div))
			return 0;
	return 1;
}

int smallest(int a[10]){
	int min = a[0];
	for(int i = 0; i < 10; i++)
		if(a[i] < min) min = a[i];
	return min;
}



