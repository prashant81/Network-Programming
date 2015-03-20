#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int intValueOfChar(unsigned char, int);

int main()
{

	//unsigned char type_buffer;

	
	uint8_t type_buffer;

	uint8_t type_zero_amount_buffer;
	uint8_t type_zero_number;

	unsigned char type_one_amount;
	unsigned char type_one_number;
	unsigned char comma;
	


	

	FILE *infileptr;

	infileptr = fopen("/home/prashantthapa/Downloads/practice_project_test_file_1","rb");

	if (infileptr == NULL){

		perror("Error while opening the file. \n");
		return (-1);
	}

	while(1){

		fread(&type_buffer, 1,1,infileptr);
		printf("%d ", type_buffer);

		if(type_buffer == 0){

			fread(&type_zero_amount_buffer,1,1, infileptr);
			printf("%d ", type_zero_amount_buffer);
				
				int z_number;
				while(type_zero_amount_buffer > 0){

					if(type_zero_amount_buffer > 1){
						fread(&type_zero_number, 1, 1, infileptr);
						z_number = type_zero_number << 8;
						fread(&type_zero_number, 1, 1, infileptr);
						z_number = z_number + type_zero_number;
						printf("%d,", z_number);
						type_zero_amount_buffer--;

					}

					else {

						fread(&type_zero_number, 1, 1, infileptr);
						z_number = type_zero_number << 8;
						fread(&type_zero_number, 1, 1, infileptr);
						z_number = z_number + type_zero_number;
						printf("%d", z_number);
						type_zero_amount_buffer--;

					}

				}

				//printf("\n");	

		}


		else {

			int i;
			int asc_to_intAmt = 0;

			for (i=0; i<3; i++){
				
				fread(&type_one_amount, 1,1,infileptr);
				printf("%c", type_one_amount);
				asc_to_intAmt = asc_to_intAmt + intValueOfChar(type_one_amount, i);
				//printf("Equivalent integeramount %d", asc_to_intAmt);
			}
				//printf("EI %d", asc_to_intAmt);
				printf(" ", type_one_amount);

			int j;
			for (j=0; j<asc_to_intAmt; j++)
			{
			
					
				while (1)
				{
					fread(&type_one_number,1,1,infileptr);
					//printf("%c", type_one_number);
					if (type_one_number >47 && type_one_number <58)
						printf("%c", type_one_number);
					else if (type_one_number == 44)
						printf("%c", type_one_number);
					else
						break;
				}
				

			}

			//printf("\n");
		}

		printf("\n");
		if(feof(infileptr))
			break;
	}

	
	return 0;
}

int intValueOfChar(unsigned char ascValue, int index)
{
	int intValue = ascValue - 48;
	if (index==0)
		return (intValue*100);
	else if (index==1)
		return (intValue*10);
	else
		return (intValue);
}
