#include <stdio.h>
/*
Sebastian Infante Murguia  U04743487
This program will take in a input from the user in the range of 0 to 10^12, it will then take the input into the checksum
function where the sum of digits will be obtained, the sum of the digits has to be a single digit number, after the sum
is a single digit it will be returned to the main funtion and printed for the user
*/

/*Initializing the check sum function*/
int checksum(long int num);

int main(){
	/*Long int for the input as the value can be from 0 to 10^12*/
	long int input;
	/*Regular int for the sum since it will be 1 digit*/
	int sum;
	/*Prompts the user for input*/
	printf("Input: ");
	scanf("%ld", &input);
	/*Calling the checksum function and giving it the user input*/
	sum = checksum(input);
	/*Printing the checksum for the user*/
	printf("Checksum: %d\n", sum);	
	return 0;
}

int checksum(long int num){
	/*Prevents the functions from looping indefinitely*/
	if(num == 0){
		return 0;
	}
	/*Will calculate the sum of digits of the input given*/
	long int num_sum;
	num_sum = num%10;
	num_sum += checksum(num/10);
	/*If the sum of digits is greater than a single digit it will run the funtion again until the sum is one digit*/
	if(num > 9){
		return checksum(num_sum);
	}
	/*If the sum is one digit it will return the value of the sum*/
	else{
		return num_sum;
	}
}
