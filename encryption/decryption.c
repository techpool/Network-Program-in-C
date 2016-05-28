#include <stdio.h>

// GLOBAL VARIABLES
// The souorce array much like the encryption program contains the sequence of
// the english alphabets
char source[26] = { "abcdefghijklmnopqrstuvwxyz" };

// The destionation array is going to contain the same alphabets but in a jumbled
// fashion.
// ***** THIS IS IMPORTANT THAT THE SAME JUMBLED SEQUENCE OF CHARACTERS SHOULD BE 
// USED IN BOTH THE ENCRYPTION AND DECRYPITON PROCESS ELSE YOU WONT BE GETTING THE
// PROPER OUTPUT *****
char destination[26] = { "efdvtmlxnzqgurakjwbcyhoips" };

int main(){

	// FILE pointers for the same purpose which will help handling of the two file
	// which will be of use
	FILE *fs, *fd;

	int val, i;
	char ch;

	// fs and fd are the file handlers for the two files
	// the 'cipher.txt' file is going to contain the file with cipher text
	// and the 'result.txt' file is going to contain the file with the decyphered
	// text
	fs = fopen("cipher.txt", "r");
	fd = fopen("result.txt", "w");

	// This loop will continue until we get a EOF character in the file
	while(1){
		
		// This function retrieves one character from the file at a time
		ch = fgetc(fs);

		// This is a flag variable which will help us to check later whether the
		// retrived character is there in our destination arrray or not
		val = -1;
		
		// If we encounter a EOF flag which indicated that it has reached the End Of File
		// Then it will exit the loop
		if (ch == EOF)
		{
			break;
		}

		// This for loop scans through the destination array for a match from
		// the character that was retrieved from the fgetc function
		for (i = 0; i < 26; ++i)
		{
			// If a match is found then the position of the character is stored in
			// the val variable
			if (ch == destination[i])
			{
				val = i;
				break;
			}
		}

		// Now here we check whether the val variable is having a value or -1
		// If it is -1 it means no match was foound for the retieved character in the
		// destination array and so we store the same character in the file as well
		if (val == -1)
		{
			fprintf(fd, "%c", ch);
		}

		// In case we have a position for that character in the destination array
		// then we match the same location with the source array and store the result
		// in the destination file.
		else
		{
			fprintf(fd, "%c", source[val]);
		}
	}
	fclose(fs);
	fclose(fd);
}