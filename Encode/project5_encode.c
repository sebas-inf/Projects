#include <stdio.h>
#include <ctype.h>
/*Sebastian Infante Murguia U04743487
This program will take in input from the command line arguments and then encode it. It will create an output array thats sized argc - 1 and a pointer p that will point at the output array.
Then it will check if there is more than 1 argument in the command line, if there is the program will run and encode the arguments, if there isn't the program will return Invalid Input.
Using a for loop the program will send every element in argv into the encode function and within the encode function the argument will be encoded and then append to the output array in
the address that pointer p is pointing at. After all the elements in argv have been encoded it will print out the encoded elements as a string */

/*Initializes the encode function*/
void encode(char *input, char *output);

/*Initializes the main function*/
int main(int argc, char *argv[]){
	/*Initializes the array output to argc - 1 spaces, pointer p, and i which will be used as a counter*/
	char output[1000 + 1], *p;
	int i;
	/*Sets pointer p to point into array output*/
	p = output;
	/*If there is more than one argument in argv the function will run*/
	if(argc > 1){
		/*Will run for all elements in argv and send them into the encode function*/
		for(i = 1; i < argc; i++){	
			encode(argv[i], p);
			/*This will move pointer p to the next null character in the array*/
			while(*p != '\0')
				p++;				
		}
		/*Prints the output array as a string*/
		printf("Output: %s\n", output);
		/*Ends the program*/
		return 0;		
	}
	/*If there was only one argument in the command line then it will print invalid input and end the program*/
	else printf("Invalid input!\n");
	
	return 0;
}
/*This function will encode the values it recives as input and append them to the array connected to output*/
void encode(char *input, char *output){
	/*Will run for all the characters in the input string*/
	while(*input != '\0'){
		/*Checks if the element in input is a letter*/
		if(isalpha(*input)){
			/*Checks if the element in input is a lower case letter*/
			if(islower(*input)){
				/*Encodes the input and sends it to the output array*/	
				*output = ((*input - 'a' + 6) % 26) + 'a';
			}	
			/*If the element in input is an upper case letter*/
			else{
				/*Encodes the input and appends it to output array*/
				*output = ((*input - 'A' + 6) % 26) + 'A';
			}
		}
		/*Checks if the input is a number*/
		else if(isdigit(*input)){
			/*Encodes the input and appends it to output*/
			*output = ((*input - '0' + 6) % 10) + '0';
		}
		/*If the code is anything other than a letter or number it will turn it into an '_'*/
		else	{	
			*output = '_';
		}
		/*Moves the pointers to the next value in the input string and to the next space for the encoded element*/
		output++;
		input++;
	}
	/*Sets the last value in the pointer to the null character*/
	*output = '\0';
		
}
