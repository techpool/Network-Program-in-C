#include <stdio.h>

// GLOBAL VARIABLES
// The source is the original sequence of characters in the english 
// alphabet series

char source[26] = { "abcdefghijklmnopqrstuvwxyz" };

// The destination is the the mapping which will be done for the encryption
// procedure in order to form the cipher text
// For example:
// 'a' --> 'e'
// 'b' --> 'f'

// and so on in the cipher text
char destination[26] = { "efdvtmlxnzqgurakjwbcyhoips" };

int main()
{

	// Two file pointers which will be used to handle two files
	FILE *fs, *fd;
	int i, val;
	char ch;

	// Openning of two files, one the plain text file
	// which will contain the messages and the other is the
	// cipher text which will contain the cipher text

	// Opened in read mode since we only need to read plain text file
	fs = fopen("plain.txt", "r");

	// Opened in write mode since we only need to write cipher text file
	fd = fopen("cipher.txt", "w"); 

	// Read the file unless we encounter a EOF flag
	while(1){

		// Retrieving the character from the source or plaint text file
		ch = fgetc(fs);

		// Setting a flag variable which will help us to check whether the
		// character recieved from the file is there in our source alphabet array
		val = -1;

		// If the character retrieved is a EOF flag then we have reached the end
		// of the file and we exit the loop
		if (ch == EOF)
		{
			break;
		}

		// We take the character and we scan for the character in our array for a match
		for (i = 0; i < 26; ++i)
		{

			// In case we find a match we we break out of the loop
			// and store the position of the character in the variable val
			if (ch == source[i])
			{
				val = i;
				break;
			}
		}

		// If the val is -1 or we did not get a matching character in the array
		// then we print the file with the same character in the source file
		if (val == -1)
		{
			fprintf(fd, "%c", ch);
		}

		// else we match the character in the source character and destination
		// character and we print the value in the destination file
		else
		{
			fprintf(fd, "%c", destination[val]);
		}
	}
	fclose(fs);
	fclose(fd);
}