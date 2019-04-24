#include <stdio.h>

int
main ()
{
  char crackrotation[] = {
    "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU."
  };
  char message[1000], characters;	//declares message array, characters
  char plain[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };	//declares plain key for substitution cipher
  char key[] = { "QWERTYUIOPASDFGHJKLZXCVBNM" };	//default key for substitution cipher
  int i, userdefinedkey, tasknumber;	//declare integers i, userdefinedkey, tasknumber


  printf ("Enter Number For Corresponding Task\n");	//display message for user to enter corresponding task
  printf ("Task 1: Rotation Cipher Encrption\n");	//display message for rotation cipher 1 encryption
  printf ("Task 2: Rotation Cipher Decryption\n");	//display message for rotation cipher 2 decyption
  printf ("Task 3: Substitution Cipher Encryption\n");	//display message for substitution cipher encryption
  printf ("Task 4: Substitution Cipher Decryption\n");	//display message for cipher decrytion
  printf ("Task 5: Rotation Cipher Decryption, Text Only\n");	//display message for cipher encryption, text only provided
  printf ("Task 6: Substitution Cipher Decryption, Text Only\n");	//display message for cipher decryption, text only provided
  printf ("Exit 7: Exit Program\n");	//display message for exit condition of program
  printf ("Enter Task Number Here: ");	//prints message to enter in task number

  scanf ("%d", &tasknumber);	//scans for task number entered
  if (tasknumber < 1 || tasknumber > 7)	//checks if number entered is less than 1 or greater than 7
    {
      return main ();
    }				//loops back to main if number is out of range
  stdin = freopen (NULL, "r", stdin);	//resets stdin memory , without this the switch case will not work properly
  switch (tasknumber)
    {
    case 1:
      printf ("Rotation Encryption\n");
      printf ("Enter A Message To Encrypt: ");
      scanf ("%[^\n]s", message);
      stdin = freopen (NULL, "r", stdin);
      printf ("Enter Key: ");
      scanf ("%d", &userdefinedkey);

      for (i = 0; message[i] != '\0'; i++)
	{
	  if (message[i] >= 'a' && message[i] <= 'z')
	    {
	      message[i] = message[i] - 32;
	    }
	  else if (message[i] >= 'A' && message[i] <= 'Z')
	    {
	      if (message[i] > 'Z')
		{
		  message[i] = message[i] - 26;
		  message[i] = message[i] + userdefinedkey % 26;
		}
	    }
	  else
	    {
	      message[i] = message[i];
	    }
	}

      printf ("Encrypted Message: %s \n", message);
      return main ();
    case 2:
      printf ("Rotation Decryption\n");
      printf ("Enter A Message To Decrypt: ");
      scanf ("%[^\n]s", message);
      stdin = freopen (NULL, "r", stdin);
      printf ("Enter Key: ");
      scanf ("%d", &userdefinedkey);

      for (i = 0; message[i] != '\0'; i++)
	{
	  if (message[i] >= 'a' && message[i] <= 'z')
	    {
	      message[i] = message[i] - 32;
	    }
	  if (message[i] >= 'A' && message[i] <= 'Z')
	    {
	      message[i] = message[i] - userdefinedkey % 26;
	      if (message[i] < 'A')
		{
		  message[i] = message[i] + 26;
		}
	    }
	  else
	    {
	      message[i] = message[i];
	    }
	}


      printf ("Encrypted Message: %s \n", message);
//a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
      printf ("Decrypted Message: %s \n", message);
      return main ();
    case 3:
      printf ("Substitution Encryption\n");
      printf ("Enter Message To Encrypt: \n");
      scanf ("%[^\n]s", message);
      stdin = freopen (NULL, "r", stdin);
      printf ("Enter A Key: \n");
      scanf ("%[^\n]s", key);

      for (int i = 0; i < 25; i++)
	if (key[i] >= 'a' && key[i] <= 'z')
	  {
	    key[i] = key[i] - 32;
	  }

      for (int i = 0; i < 30; i++)
	{

	  if (message[i] >= 'a' && message[i] <= 'z')
	    {
	      message[i] = message[i] - 32;
	    }
	  else if (message[i] == ' ')
	    {
	      message[i] = ' ';
	    }
	  else
	    {
	      int a = message[i] - 65;
	      message[i] = key[a];
	    }
	}
      printf ("Encrypted Message: %s \n\n", message);
      return main ();
    case 4:
      printf ("Substitution Decryption\n");
      printf ("Enter A Message To Decrypt: \n");
      scanf ("%[^\n]s", message);
      stdin = freopen (NULL, "r", stdin);
      printf ("Enter A Key: \n");
      scanf ("%[^\n]s", key);
      for (int i = 0; i < 1000; i++)
	{
	  if (message[i] == ' ')
	    {
	      message[i] = ' ';
	    }
	  else if (message[i] == 'Q')
	    {
	      message[i] = plain[0];
	    }
	  else if (message[i] == 'W')
	    {
	      message[i] = plain[1];
	    }
	  else if (message[i] == 'E')
	    {
	      message[i] = plain[2];
	    }
	  else if (message[i] == 'R')
	    {
	      message[i] = plain[3];
	    }
	  else if (message[i] == 'T')
	    {
	      message[i] = plain[4];
	    }
	  else if (message[i] == 'Y')
	    {
	      message[i] = plain[5];
	    }
	  else if (message[i] == 'U')
	    {
	      message[i] = plain[6];
	    }
	  else if (message[i] == 'I')
	    {
	      message[i] = plain[7];
	    }
	  else if (message[i] == 'O')
	    {
	      message[i] = plain[8];
	    }
	  else if (message[i] == 'P')
	    {
	      message[i] = plain[9];
	    }
	  else if (message[i] == 'A')
	    {
	      message[i] = plain[10];
	    }
	  else if (message[i] == 'S')
	    {
	      message[i] = plain[11];
	    }
	  else if (message[i] == 'D')
	    {
	      message[i] = plain[12];
	    }
	  else if (message[i] == 'F')
	    {
	      message[i] = plain[13];
	    }
	  else if (message[i] == 'G')
	    {
	      message[i] = plain[14];
	    }
	  else if (message[i] == 'H')
	    {
	      message[i] = plain[15];
	    }
	  else if (message[i] == 'J')
	    {
	      message[i] = plain[16];
	    }
	  else if (message[i] == 'K')
	    {
	      message[i] = plain[17];
	    }
	  else if (message[i] == 'L')
	    {
	      message[i] = plain[18];
	    }
	  else if (message[i] == 'Z')
	    {
	      message[i] = plain[19];
	    }
	  else if (message[i] == 'X')
	    {
	      message[i] = plain[20];
	    }
	  else if (message[i] == 'C')
	    {
	      message[i] = plain[21];
	    }
	  else if (message[i] == 'V')
	    {
	      message[i] = plain[22];
	    }
	  else if (message[i] == 'B')
	    {
	      message[i] = plain[23];
	    }
	  else if (message[i] == 'N')
	    {
	      message[i] = plain[24];
	    }
	  else if (message[i] == 'M')
	    {
	      message[i] = plain[25];
	    }
	}
      printf ("Decrypted Message: %s \n\n", message);
      return main ();
    case 5:
      printf ("Rotation Decryption, Text Only\n");
      //printf("Enter A Message To Decrypt: ");
      //scanf("%[^\n]s", message);
      //stdin = freopen(NULL,"r",stdin);
      //printf("Enter key: ");
      //scanf("%d", &userdefinedkey);
      userdefinedkey = 1;
      for (i = 0; crackrotation[i] != '\0'; i++)
	{
	  characters = crackrotation[i];
	  if ((message[i] < 'A') || (message[i] > 'Z' && message[i] < 'a')
	      || (message[i] > 'z'))
	    {
	      message[i] = message[i];
	    }
	  if (characters >= 'a' && characters <= 'z')
	    {
	      characters = characters - 97;
	      characters = (characters - userdefinedkey) % 26;
	      if (characters < 'a')
		{
		  characters = characters + 'z' - 'a' + 1;
		}
	      characters = characters + 97;
	      crackrotation[i] = characters;
	    }
	  if (characters >= 'A' && characters <= 'Z')
	    {
	      characters = characters - 65;
	      characters = (characters - userdefinedkey) % 26;
	      if (characters < 'A')
		{
		  characters = characters + 'Z' - 'A' + 1;
		}
	      characters = characters + 65;
	      crackrotation[i] = characters;
	    }
	}
      printf ("Decrypted Message: %s \n", crackrotation);
      return main ();
    case 6:
      printf ("Substitution Decryption, Text Only\n");
      break;
    case 7:
      return 0;
      break;
    default:
      printf ("enter a number\n");
    }
}
