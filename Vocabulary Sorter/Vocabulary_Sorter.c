#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 1000

/*
This program will take in 2 file names from the command-line arguments, get the unique words in the input file, and then it will write each unique word
into the output file and enumerate them.
*/

void selection_sort(char vocab[][LEN + 1], int num);

int main(int argc, char *argv[]){

	char vocab[LEN + 1][LEN + 1];
	char ret[LEN + 1][LEN + 1];
	FILE *rFile, *wFile;
	int i = 0, j = 0, num = 0, count = 0;
	
	/*Will run if theres more than one command-line argument*/
	if(argc > 1){

		/*Opens the files given for reading and writing*/
		rFile = fopen(argv[1], "r");
		wFile = fopen(argv[2], "w");

		/*If the files do not exist/were not created then it will print a message and end the program*/
		if((rFile == NULL) || (wFile == NULL)){
			printf("Error opening file\n");
			return 1;
		}
		
		/*This will read all the values in rFile until there's an error or it reaches the end of the file, all strings will be appended to vocab*/
		while(!feof(rFile) && !ferror(rFile)){
		
			/*If the amount of arguments found is equal to one then it will add one to the number of elements on the list*/
			if(fscanf(rFile, "%s", vocab[i]) == 1)
				num++;			
			i++;

		}

		/*This nested loop will set all the strings in the array to their upper case equivalent*/
		for(i = 0; i < num; i++){
			for(j = 0; vocab[i][j] != '\0'; j++)
				vocab[i][j] = toupper(vocab[i][j]);	
		}
		
		selection_sort(vocab, num);
		
		/*Adds the first value in the sorted vocab array to the return array*/
		strcpy(ret[count++], vocab[0]);

		/*This loop will append the first instance of each value into the array to be returned(eliminating duplicates)*/
		for(i = 1; i < num; i++){
			if(strcmp(vocab[i], vocab[i-1]) == 0)
				continue;
			else{
				/*If the value is not a duplicate it appends it to the ret array*/
				strcpy(ret[count], vocab[i]);
				count++;
			}
			
		}

		/*This loop will write all the values in ret to the new file, it will also enumerate them*/
		for(i = 0; i < count; i++){
			
			fprintf(wFile, "%d %s\n", i+1, ret[i]);

		}		
			
	}
	
	/*If there was less than one command-line argument it will print a message*/
	else printf("Invalid Input");

	fclose(rFile);

	fclose(wFile);

	return 0;
}

/*This function will organize all the strings in the vocab array alphabetically*/
void selection_sort(char vocab[][LEN + 1], int num){

	int i, largest = 0;
	char temp[LEN + 1];

	if(num == 1)
		return;

	/*Loop will find if the difference between the current strings and the string with index largest, if the difference is greater than 0 then it will save it's index*/ 
	for(i = 1; i < num; i++){
		if(strcmp(vocab[i], vocab[largest]) > 0)
			largest = i;	
	}

	/*Will swap the positions of the strings if largest is not at the last value of the array*/
	if(largest < num - 1){
		strcpy(temp, vocab[num - 1]);
		strcpy(vocab[num - 1], vocab[largest]);
		strcpy(vocab[largest], temp);
	}

	selection_sort(vocab, num - 1);
}
































