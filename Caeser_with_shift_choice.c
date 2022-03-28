#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

main()
{
	int i,n,shift;
	char plainText[100],cipherText[100],cipherText2[100],tmp,choice;

	printf("Enter the plaintext:\n");
	gets(plainText);
	printf("Enter your choice: l for left shift r for right shift \n");
	scanf("%c",&choice);
	printf("How many character to shift: ");
	scanf("%d",&shift);
	n=strlen(plainText);

	for(i=0;i<n;i++)
	{
		if(isalpha(plainText[i]))
		{
			if(choice=='r')
			{
				tmp=plainText[i]+shift;
				if(islower(plainText[i]) && tmp>122) cipherText[i]=96+tmp-122;
				else if(isupper(plainText[i]) && tmp>90) cipherText[i]=64+tmp-90;
				else cipherText[i]=tmp;
			}
			if(choice=='l')
			{
				tmp=plainText[i]-shift;
				if(islower(plainText[i]) && tmp<97) cipherText[i]=123+tmp-97;
				else if(isupper(plainText[i]) && tmp<65) cipherText[i]=91+tmp-65;
				else cipherText[i]=tmp;
			}
		}
		else cipherText[i]=plainText[i];
	}
	cipherText[n]='\0';
	printf("The Corresponding cipherText is:\n%s",cipherText);

	for(i=0;i<n;i++)
	{
		if(isalpha(cipherText[i]))
		{
			if(choice=='l')
			{
				tmp=cipherText[i]+shift;
				if(islower(cipherText[i]) && tmp>122) cipherText2[i]=96+tmp-122;
				else if(isupper(cipherText[i]) && tmp>90) cipherText2[i]=64+tmp-90;
				else cipherText2[i]=tmp;
			}
			if(choice=='r')
			{
				tmp=cipherText[i]-shift;
				if(islower(cipherText[i]) && tmp<97) cipherText2[i]=123+tmp-97;
				else if(isupper(cipherText[i]) && tmp<65) cipherText2[i]=91+tmp-65;
				else cipherText2[i]=tmp;
			}
		}
		else cipherText2[i]=cipherText[i];

	}
	cipherText2[n]='\0';
	printf("\nThe Original plainText is:\n%s",cipherText2);

	getch();
	return 0;
}

