#include <stdio.h>
/*
Take in a input from the user in the range of 0 to 10^12, then send the input to sums
where the of digits will be obtained.
*/

/*Initializing the sums function*/
int sums(long int num);

int main(){
	long int input;
	int sum;
	/*Prompts the user for input*/
	printf("Input: ");
	scanf("%ld", &input);
	/*Giving sum function user input*/
	sum = sums(input);
	printf("Sum of digits: %d\n", sum);	
	return 0;
}

int sums(long int num){
	/*Prevents the functions from looping indefinitely*/
	if(num == 0){
		return 0;
	}
	/*Will calculate the sum of digits of the input given*/
	long int num_sum;
	num_sum = num%10;
	num_sum += sums(num/10);
	/*If the sum of digits is greater than a single digit it will run the funtion again until the sum is one digit*/
	if(num > 9){
		return sums(num_sum);
	}
	/*If the sum is one digit it will return the value of the sum*/
	else{
		return num_sum;
	}
}
