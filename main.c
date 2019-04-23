#include <stdio.h>

int main(){
	//int a=0,b=1,c=2,d=3,e=4,f=5,g=6,h=7,i=8,j=9,k=10,l=11,m=12,n=13,o=14,p=15,q=16,r=17,s=18,t=19,u=20,v=21,w=22,x=23,y=24,z=25;
	//int A=26,B=27,C=28,D=29,E=30,F=31,G=32,H=33,I=34,J=35,K=36,L=37,M=38,N=39,O=40,P=41,Q=42,R=43,S=44,T=45,U=46,V=47,W=48,X=49,Y=50,Z=51;
	char message[1000], characters;				//declares message array, characters
	char plain[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};		//declares plain key for substitution cipher
	char key[] = {"QWERTYUIOPASDFGHJKLZXCVBNM"};		//default key for substitution cipher
        int i, userdefinedkey, tasknumber;			//declare integers i, userdefinedkey, tasknumber
	printf("Enter Number For Corresponding Task\n");	//display message for user to enter corresponding task
	printf("Task 1: Rotation Cipher Encrption\n");		//display message for rotation cipher 1 encryption
	printf("Task 2: Rotation Cipher Decryption\n");		//display message for rotation cipher 2 decyption
	printf("Task 3: Substitution Cipher Encryption\n");	//display message for substitution cipher encryption
	printf("Task 4: Substitution Cipher Decryption\n");	//display message for cipher decrytion
	printf("Task 5: Rotation Cipher Encryption, Text Only\n");//display message for cipher encryption, text only provided
	printf("Task 6: Substitution Cipher Decryption, Text Only\n");//display message for cipher decryption, text only provided
	printf("Exit 7: Exit Program\n");			//display message for exit condition of program
	printf("Enter Task Number Here: ");			//prints message to enter in task number
	scanf("%d", &tasknumber);				//scans for task number entered
	if (tasknumber < 1 || tasknumber > 7)			//checks if number entered is less than 1 or greater than 7
		{return main();}				//loops back to main if number is out of range
	stdin = freopen(NULL,"r",stdin); 			//resets stdin memory , without this the switch case will not work properly
	switch(tasknumber){					
		case 1:
			printf("Enter A Message To Encrypt: ");
			scanf("%[^\n]s", message);
			stdin = freopen(NULL,"r",stdin);
			printf("Enter Key: ");
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
       			printf("Encrypted Message: %s \n", message);
			return main();
       		break;
       		case 2:
			printf("Enter A Message To Decrypt: ");
			scanf("%[^\n]s", message);
			stdin = freopen(NULL,"r",stdin);
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
       			printf("Decrypted Message: %s \n", message);
			return main();
       		break;					
		case 3:
			printf("Enter Message To Encrypt: \n"); 
			scanf("%[^\n]s", message);
			stdin = freopen(NULL,"r",stdin);
			printf("Enter A Key: \n");
			scanf("%[^\n]s", key);
      			for(int i = 0; i < 30; i++)
          		 {
           		 if (message[i] == ' ')
      	     		  {
           		message[i] = ' ';
              		 }   
           		 else
           		    {
              		  int a = message[i] - 65;
                	message[i] = key[a];
               		}
          		 }
			printf("Encrypted Message: %s \n\n", message);
			return main();
		break;
		case 4:
			printf("Enter A Message To Decrypt: \n"); 
			scanf("%[^\n]s", message);
			stdin = freopen(NULL,"r",stdin);
			printf("Enter A Key: \n");
			scanf("%[^\n]s", key);
			for(int i = 0; i < 1000; i++)
			{
          		 if(message[i]== ' ')
				{message[i] = ' ';}
	 		 else if(message[i]== 'Q')
				{message[i] = plain[0];}
	 		 else if(message[i]== 'W')
				{message[i] = plain[1];}
	  		 else if(message[i]== 'E')
				{message[i] = plain[2];}
	  		 else if(message[i]== 'R')
				{message[i] = plain[3];}
	  		 else if(message[i]== 'T')
				{message[i] = plain[4];}
	  		 else if(message[i]== 'Y')
				{message[i] = plain[5];}
		  	 else if(message[i]== 'U')
				{message[i] = plain[6];}
	  		 else if(message[i]== 'I')
				{message[i] = plain[7];}
	  		 else if(message[i]== 'O')
				{message[i] = plain[8];}
	  		 else if(message[i]== 'P')
				{message[i] = plain[9];}
	  		 else if(message[i]== 'A')
				{message[i] = plain[10];}
	  		 else if(message[i]== 'S')
				{message[i] = plain[11];}
	  		 else if(message[i]== 'D')
				{message[i] = plain[12];}
	  		 else if(message[i]== 'F')
				{message[i] = plain[13];}
	  		 else if(message[i]== 'G')
				{message[i] = plain[14];}
	  		 else if(message[i]== 'H')
				{message[i] = plain[15];}
	  		 else if(message[i]== 'J')
				{message[i] = plain[16];}
	  		 else if(message[i]== 'K')
				{message[i] = plain[17];}
	  		 else if(message[i]== 'L')
				{message[i] = plain[18];}
	  		 else if(message[i]== 'Z')
				{message[i] = plain[19];}
	  		 else if(message[i]== 'X')
				{message[i] = plain[20];}
	 		 else if(message[i]== 'C')
				{message[i] = plain[21];}
	  		 else if(message[i]== 'V')
				{message[i] = plain[22];}
	  		 else if(message[i]== 'B')
				{message[i] = plain[23];}
	  		 else if(message[i]== 'N')
				{message[i] = plain[24];}
	  		 else if(message[i]== 'M')
				{message[i] = plain[25];}
      			}
		       printf("Decrypted Message: %s \n\n", message);
		       return main();
		break;
		case 5:
			printf("Enter A Message To Decrypt: ");
			scanf("%[^\n]s", message);
			userdefinedkey = 4;
			
	
			for (i = 0; message[i] != '\0'; i++){
	   			characters = message[i];
				 if(characters >= 'A' && characters <= 'Z'){
					characters = characters - 65;
						characters = (characters - userdefinedkey)%26;
							if (characters < 'A'){
								characters = characters + 'Z' - 'A' + 1;
							}
					characters = characters + 65;
					message[i] = characters;
				}
       			}
       			printf("Decrypted Message: %s \n", message);
			return main();
		break;
		case 6:
		break;
		case 7: return 0;
		break;	
		default: printf("enter a number\n");
	}
} 
