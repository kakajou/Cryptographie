#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char const *argv[])
{

	char char_table [26]  = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char Alis_message [100];
	FILE* Alis_file ;
	int i=0,j=0;

	
	Alis_file = fopen ("Alis.txt","r");
	fgets (Alis_message , 100 , Alis_file);
	fclose (Alis_file);


	printf("\n message de Alis avant le décryptage : ");
	printf("\" %s \" \n",Alis_message);


	for (i = 0; i < strlen(Alis_message); ++i)
	{
		for ( j = 0; j < 26; ++j)
		{
			if (Alis_message[i] == char_table[j])
			{
				Alis_message[i] = char_table[(j+23)%26]; break;
			}
		}
	}
	printf("\n =============================================== \n");
	printf(  " ==             ... déCryptage                == ");
	printf("\n =============================================== \n");

	printf("\n \n message de Alis apris le déccryptage : ");
	printf("\" %s \" \n",Alis_message);

	return 0;
}