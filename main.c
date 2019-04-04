#include <stdio.h>

int main(){
	char message[100000], characters;
        int i, userdefinedkey, tasknumber;
	printf("Enter Number For Corresponding Task\n");
	printf("Task 1: Rotation Cipher Encrption\n");
	printf("Task 2: Rotation Cipher Decryption\n");
	printf("Enter Task Number Here: ");
	scanf("%d", &tasknumber);
	stdin = freopen(NULL,"r",stdin); //resets stdin, without this the switch case will not work properly
	switch(tasknumber){
		case 1:
		printf("Enter a message to encrypt: ");
		scanf("%[^\n]s", message);
		printf("Enter key: ");
		scanf("%d", &userdefinedkey);
	
		for (i = 0; message[i] != '\0'; i++){
	   		characters = message[i];

			if (characters >= 'a' && characters <= 'z'){
	   			characters = characters + userdefinedkey;
	  
			if (characters > 'z'){
	  			characters = characters - 'z' + 'a' - 1;
				}

	message[i] = characters;
	}
	else if(characters >= 'A' && characters <= 'Z'){
		characters = characters + userdefinedkey;
	if (characters > 'Z'){
		characters = characters - 'Z' + 'A' - 1;
	}
	message[i] = characters;
	}
       }
       printf("Encrypted message: %s \n", message);
       break;
       default: printf("enter a number\n");
	}
} 
