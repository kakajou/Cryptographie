#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char const *argv[])
{

	char char_table [26]  = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char Bob_message [100];
	FILE* Bob_file ;
	FILE* Alis_file ;
	int i=0,j=0;

	
	Bob_file = fopen ("Bob.txt","r");
	fgets (Bob_message , 100 , Bob_file);
	fclose (Bob_file);


	printf("\n message de Bob avant le cryptage : ");
	printf("\" %s \" \n",Bob_message);


	for (i = 0; i < strlen(Bob_message); ++i)
	{
		for ( j = 0; j < 26; ++j)
		{
			if (Bob_message[i] == char_table[j])
			{
				Bob_message[i] = char_table[(j+3)%26]; break;
			}
		}
	}
	printf("\n =============================================== \n");
	printf(" ==               Cryptage ...                == ");
	printf("\n =============================================== \n");

	printf("\n \n message de Bob apris le cryptage : ");
	printf("\" %s \" \n",Bob_message);

	Alis_file = fopen ("Alis.txt","w");
	fputs (Bob_message , Alis_file );
	fclose (Alis_file);	

	return 0;
}