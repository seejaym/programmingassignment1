#include <stdio.h>

int main(){
	//int a=0,b=1,c=2,d=3,e=4,f=5,g=6,h=7,i=8,j=9,k=10,l=11,m=12,n=13,o=14,p=15,q=16,r=17,s=18,t=19,u=20,v=21,w=22,x=23,y=24,z=25;
	//int A=26,B=27,C=28,D=29,E=30,F=31,G=32,H=33,I=34,J=35,K=36,L=37,M=38,N=39,O=40,P=41,Q=42,R=43,S=44,T=45,U=46,V=47,W=48,X=49,Y=50,Z=51;
	char message[100000], characters;			//declares message array, characters	
        int i, userdefinedkey, tasknumber;			//declare integers i, userdefinedkey, tasknumber
	printf("Enter Number For Corresponding Task\n");	//display message for user to enter corresponding task
	printf("Task 1: Rotation Cipher Encrption\n");		//display message for rotation cipher 1 encryption
	printf("Task 2: Rotation Cipher Decryption\n");		//display message for rotation cipher 2 decyption
	printf("Task 3: Substitution Cipher Encryption\n");	//display message for substition cipher encryption
	printf("Task 4: Substitution Cipher Decryption\n");	//display message for cipher decrytion
	printf("Task 5: Rotation Cipher Encryption, Text Only\n");//display message for cipher encryption, text only provided
	printf("Task 6: Substitution Cipher Decryption, Text Only\n");//display message for cipher decryption, text only provided
	printf("Exit 7: Exit Program\n");			//display message for exit condition of program
	printf("Enter Task Number Here: ");			//prints message to enter in task number
	scanf("%d", &tasknumber);				//scans for task number entered
	if (tasknumber < 1 || tasknumber > 7)			//checks if number entered is less than 1 or greater than 7
		{return main();}				//loops back to main if number is out of range
	stdin = freopen(NULL,"r",stdin); 			//resets stdin(memory), without this the switch case will not work properly
	switch(tasknumber){
		case 1:
			printf("Enter a message to encrypt: ");
			scanf("%[^\n]s", message);
			printf("Enter key: ");
			scanf("%d", &userdefinedkey);
	
			for (i = 0; message[i] != '\0'; i++){
	   			characters = message[i];
				if (characters >= 'a' && characters <= 'z'){
					characters = characters - 97;
	   				characters = (characters + userdefinedkey)%26;
	  					if (characters > 'z'){
	  						characters = characters - 'z' + 'a' - 1;
						}
					characters = characters + 97;
					message[i] = characters;
				}
				else if(characters >= 'A' && characters <= 'Z'){
					characters = characters - 65;
					characters = (characters + userdefinedkey)%26;
							if (characters > 'Z'){
								characters = characters - 'Z' + 'A' - 1;
							}
					characters = characters + 65;
					message[i] = characters;
				}
       			}
       			printf("Encrypted message: %s \n", message);
			return main();
       		break;
       		case 2:
			printf("Enter a message to decrypt: ");
			scanf("%[^\n]s", message);
			printf("Enter key: ");
			scanf("%d", &userdefinedkey);
	
			for (i = 0; message[i] != '\0'; i++){
	   			characters = message[i];
				if (characters >= 'a' && characters <= 'z'){
					characters = characters - 97;
	   				characters = (characters - userdefinedkey)%26;
	  					if (characters < 'a'){
	  						characters = characters + 'z' - 'a' + 1;
						}
					characters = characters + 97;
					message[i] = characters;
				}
				else if(characters >= 'A' && characters <= 'Z'){
					characters = characters - 65;
						characters = (characters - userdefinedkey)%26;
							if (characters < 'A'){
								characters = characters + 'Z' - 'A' + 1;
							}
					characters = characters + 65;
					message[i] = characters;
				}
       			}
       			printf("decrypted message: %s \n", message);
			return main();
       		break;					
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		case 6:
		break;
		case 7: return 0;
		break;	
		default: printf("enter a number\n");
	}
} 
