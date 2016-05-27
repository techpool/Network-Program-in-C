#include <stdio.h>

int main(){
	
	int i, n, a[10], b[10], carry = 0, carry1 = 0, temp, temp1, checksum[10], checksum1[10], sum[10], a1[10], b1[10], check = 0;

	// This portion of the code is executed in the server side

	// Inputing the number of bits each data will be
	printf("Enter the number of bits in each segment:\n");
	scanf("%d", &n);

	// Taking the first data from user

	// THIS IS IMPORTANT:
	// ALL INPUTS AND OUTPUTS SHOULD BE DONE IN REVERSE ORDER
	// SINCE WHILE INSERTING BINARY DATA WE WILL BE
	// INSETING IN THE FORM 1 0 1 1.
	// SO THEN IT IS IMPORTANT TO NOTE THAT THE LAST
	// DATA TAKES UP THE FIRST PLACE IN THE ARRAY
	
	printf("Enter the first data:\n");
	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		scanf("%d", &a[i]);
	}

	// Taking the second data from the user
	printf("Enter the second data:\n");
	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		scanf("%d", &b[i]);
	}

	// Finding the sum adding each bit in binary form
	for (i = 0; i < n; ++i)
	{
		sum[i] = (a[i] + b[i] + carry) % 2;
		carry = (a[i] + b[i] + carry) / 2;
	}

	printf("Sum: ");
	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		printf("%d", sum[i]);
	}
	printf("\n");


	// Finding the wrapped sum

	if (carry == 1)
	{
		for (i = 0; i < n; ++i)
		{
			temp = (sum[i] + carry) % 2;
			carry = (sum[i] + carry) / 2;
			sum[i] = temp;
		}
	}


	printf("Wrapped Sum: ");
	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		printf("%d", sum[i]);
	}
	printf("\n");


	// Finding the checksum

	for (i = 0; i < n; ++i)
	{
		if (sum[i] == 0)
		{
			checksum[i] = 1;
		}
		else
		{
			checksum[i] = 0;
		}
	}

	printf("Checksum: ");
	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		printf("%d", checksum[i]);
	}
	printf("\n");
	
	// This portion of the code is executed in the client side

	// Taking the first number from the user
	printf("Enter the first data:\n");

	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		scanf("%d", &a1[i]);
	}


	// Taking the second number from the user
	printf("Enter the second data:\n");

	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		scanf("%d", &b1[i]);
	}

	// Taking the checksum value
	printf("Enter the checksum value:\n");

	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		scanf("%d", &checksum1[i]);
	}

	// Finding the sum of the elements
	for (i = 0; i < n; ++i)
	{
		sum[i] = (a1[i] + b1[i] + checksum1[i] + carry1) % 2;
		carry1 = (a1[i] + b1[i] + checksum1[i] + carry1) / 2;
	}

	printf("Sum: ");
	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		printf("%d", sum[i]);
	}
	printf("\n");

	if (carry1 == 1)
	{
		// Finding the wrapped sum
		for (i = 0; i < n; ++i)
		{
			temp1 = (sum[i] + carry1) % 2;
			carry1 = (sum[i] + carry1) / 2;
			sum[i] = temp1;
		}
	}

	printf("Wrapped Sum: ");
	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		printf("%d", sum[i]);
	}
	printf("\n");

	// Finding the checksum
	for (i = 0; i < n; ++i)
	{
		if (sum[i] == 1)
		{
			sum[i] = 0;
		} 
		else
		{
			sum[i] = 1;
		}
	}

	printf("Checksum: ");
	for (i = n-1; i >= 0; --i) // Please note the loop is in reverse order
	{
		printf("%d", sum[i]);
	}
	printf("\n");

	// Checking whether the final complemented sum is zero or not
	
	for (i = 0; i < n; ++i)
	{
		check += sum[i];
	}

	if (check == 0)
	{
		printf("The data was NOT tampered.\n");
	}
	else
	{
		printf("The data was tampered\n");
	}
}