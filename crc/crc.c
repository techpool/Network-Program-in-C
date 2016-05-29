#include <stdio.h>
#include <string.h>

int main(){

	int i, j, keylen, msglen;
	char data[30], key[30], tempkey[30], temp[30], remainder[30], quotient[30];
	// Taking input for the original data
	printf("Enter the data: \n");
	gets(data);

	// Taking input for the key with which the whole
	// number will be devided
	printf("Enter the Key: \n");
	gets(key);

	// Finding the length of the messege length
	msglen = strlen(data);

	// Finding the length of the key
	keylen = strlen(key);

	// Copying the key in a temporary variable
	strcpy(tempkey, key);

	// Stuffing the end of the original data with the number of zeros
	// equal to the length of the key
	// Ex: 
	// Data: 1 1 0 0 0
	// Key : 1 1 0
	// Then the stuffed data becomes:
	// Data: 1 1 0 0 0 0 0 0 <-- Notice the last three zeros
	// which were originally not there
	for (i = 0; i < keylen; ++i)
	{
		data[msglen + i] = '0';
	}

	// Storing the number of bits equal to the keylength which will
	// be used to do the devision.
	// Like: If, 
	// Data: 1 0 1 0 0
	// Key : 1 1 0
	// Then,
	// Temp: 1 0 1
	for (i = 0; i < keylen; ++i)
	{
		temp[i] = data[i];
	}

	// In this for loop the original division will be performed
	// between the two numbers, the key and the data (which is
	// the original message)

	for (i = 0; i < msglen; ++i)
	{
		// Now the quotient will actually depend on the first
		// bit that we want to divide
		// Like if we are dividing 1100 by 100 then obviously
		// the quotient will be 1 since 1 x 100 will be 100
		// and 0 x 100 will be 000, and there cant be any other
		// possibility there can only be these two possibility
		// So if the the number starts with 0 the corresponding
		// quotient should also be 0, and vice versa
		quotient[i] = temp[0];

		// Now if the quotient bit is 0,
		// after multiplying with it we will get all zeros
		// in the result, and this we store all zeros in the
		// key array. Which we will use later to divide
		if (quotient[i] == '0')
		{
			for (j = 0; j < keylen; ++j)
			{
				key[j] = '0';
			}
		}
		// Now if the quotient bit is 1,
		// after multiplying with it we will get all same
		// elements. Thus we will get the same value as the entered
		// key and we retrieve that from the tempkey that we made a 
		// copy of in line number 22
		else
		{
			for (j = 0; j < keylen; ++j)
			{
				key[j] = tempkey[j];
			}
		}
		// 	keylen = 3
		// 	keylen - 1 = 2
		// 	j =		0 1 2 3
		// --------------------
		// temp =	1 0 1 1
		// key =	1 1 0
		// --------------------
		// rem =	0 1 1 1
		// -------------------- 
		// rem[pos]   0 1 2
		// Here we perform the subtraction operation during the
		// division which is nothing but a XOR operation
		for (j = keylen - 1; j > 0; --j)
		{
			// If the both the bits are same then 0 should be saved
			// in remainder
			if (temp[j] == key[j])
			{
				remainder[j-1] = '0';
			}

			// If there are different bits present then 1 should be
			// stored in the remainder
			else
			{
				remainder[j-1] = '1';
			}
		}

		// We bring down the next from the original message
		remainder[keylen - 1] = data[keylen + i];

		// The remainder is copied in the array temp again so that
		// the next division operation can be performed when the 
		// for loop rotates again
		strcpy(temp, remainder);
	}

	// Copying the final remainder from the temp variable to
	// the remainder variable
	strcpy(remainder, temp);

	// Printing the quotient (which is basically of no use)
	printf("\nQuotient is: \n");
	for (i = 0; i < msglen; ++i)
	{
		printf("%c", quotient[i]);
	}

	// Printing the remainder (which is of prime importance)
	printf("\nRemainder is: \n");
	for (i = 0; i < keylen - 1; ++i)
	{
		printf("%c", remainder[i]);
	}

	// Printing the final data (which is a combo of the original
	// data that was entered by the user and the remainder that 
	// we just generated)
	printf("\nFinal data: \n");
	for (i = 0; i < msglen; ++i)
	{
		printf("%c", data[i]);
	}
	for (i = 0; i < keylen-1; ++i)
	{
		printf("%c", remainder[i]);
	}
	printf("\n");
}
