#include<stdio.h>
#include<string.h>

int main()
{
	char string1[30];
	int i,length;
	int flag=0;
	printf("Enter a string: ");
	scanf("%s",string1);
	
	//Calculate the string length
	length=strlen(string1);
        
	//Compare each character of the string
	//Stop if a mismatch is found
	
	for(i=0;i<length/2;i++)
	{

		if(string1[i]!=string1[length-i-1])
		{
			flag=1;
		break;
		}
	}

	//The Result
	//If flag value is 1 then it is not a palindrome
	//if flag value is 0 then it is a palindrome

	if(flag)
	{
		printf("%s is not a palindrome.\n",string1);
	}
	else
	{
		printf("%s is a palindrome.\n",string1);
	}


}
