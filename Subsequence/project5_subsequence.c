#include <stdio.h>
#include <ctype.h>
#define LEN 200
/*
Sebastian Infante Murguia U04743487
This program will take in 2 strings of at most 200 characters(+1 to account for the null character) and it will append them to str1 and str2. It will then set pointers p and q equal to str1 and str2 respectively. 
It will then iterare over the values of *p using a for loop and it will set the values of pointers p and q to their lower case equivalent each run of the loop. Then it will use a  while loop to check if the 
character in *p is not equal to *q, if they are not equal and if pointer *q is not at the null character it will iterate over the lower case value of pointer *q until it is equal to pointer *p or it reaches the 
end of the string. Then it will check if pointer *p is at the null value, if it is then it will return yes, if not then it will return no.
*/
/*Initializes the main function*/
int main(){
	/*Initializes the arrays for the strings to 200 + 1 in case the string is of 200 characters to ensure that there is space for the null value*/
	char str1[LEN + 1];
	char str2[LEN + 1];
	/*Prompts the user to enter the first word and appends it to str1*/
	printf("Enter first word: ");
	scanf("%s", str1);
	/*Prompts the user to enter the second word and appends it to str2*/
	printf("Enter second word: ");
	scanf("%s", str2);
	/*Initializes pointers p and q*/
	char *p, *q;
	/*Sets pointers p and q to strings str1 and str2 respectively*/
	p = str1;
	q = str2;
	/*This loop will run until pointer p reaches its null value*/
	for(p = str1; *p != '\0'; p++){
		/*Sets the values in pointer p and pointer q to their lower case equivalent at the start of each loop*/
		*p = tolower(*p);
		*q = tolower(*q);
		/*If pointer q is at the end of the string then it will break out of the loop*/
		if(*q == '\0')
			break;
		/*This nested loop will run until the character in pointer p is equal to the character in pointer q**/
		while(*q != *p){
			/*If pointer q is not at the null value, moves pointer q to the next value in str2 and sets the value in *q to its lower case equivalent*/
			if(*q != '\0'){
				q++;
				*q = tolower(*q);
			}	
			/*If pointer q is at the null value it breaks out of the while loop*/
			if(*q == '\0')
				break;
		}
		/*If there is a value in pointer q that is equal to the value in pointer p it moves pointer q to the next value and continues the for loop*/
		q++;
	}
	/*If pointer p is at the null value it means that the loop found values in pointer q that would make it a substring of p and it will return yes*/
	if(*p == '\0') printf("YES\n");
	/*If pointer q reached the end of the string and it didn't find characters in order that would make str1 a substring of str2 then it will return no*/
	else printf("NO\n");
	return 0;
}

