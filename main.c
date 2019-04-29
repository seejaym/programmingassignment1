#include <stdio.h>

int
main ()
{
  char crackrotation[] = {
    "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU."
  };

  //char crackrotation[] = {"SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"};       
  char message[500];		//declares message array, characters
  char plain[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };	//declares plain key for substitution cipher
  char key[] = { "QWERTYUIOPASDFGHJKLZXCVBNM" };	//default key for substitution cipher
  int i, userdefinedkey, tasknumber;	//declare integers i, userdefinedkey, tasknumber
  int fA = 0, fB = 0, fC = 0, fD = 0, fE = 0, fF = 0, fG = 0, fH = 0, fI = 0, fJ = 0, fK = 0, fL = 0, fM = 0, fN = 0, fO = 0, fP = 0, fQ = 0, fR = 0, fS = 0, fT = 0, fU = 0, fV = 0, fW = 0, fX = 0, fY = 0, fZ = 0;	//variables for each letter counter 
  int crackkey = 0;
  int totalLetters = fA + fB + fC + fD + fE + fF + fG + fH + fI + fJ + fK + fL + fM + fN + fO + fP + fQ + fR + fS + fT + fU + fV + fW + fX + fY + fZ;	//sums the total number of letters, stores value in totalLetters
  printf ("Enter Number For Corresponding Option\n");	//display message for user to enter corresponding task
  printf ("1 Rotation Cipher Encrption\n");	//display message for rotation cipher encryption
  printf ("2 Rotation Cipher Decryption\n");	//display message for rotation cipher decryption
  printf ("3 Substitution Cipher Encryption\n");	//display message for substitution cipher encryption
  printf ("4 Substitution Cipher Decryption\n");	//display message for cipher decrytion
  printf ("5 Rotation Cipher Decryption, No Key\n");	//display message for cipher decrytion
  printf ("6 Exit Program\n");	//display message for exit condition of program
  printf ("Enter Option Here: ");	//prints message to enter in task number

  scanf ("%d", &tasknumber);	//scans for task number entered and stores it in the tasknumber variable
  if (tasknumber < 1 || tasknumber > 6)	//checks if the number entered in taskvariable is less than one or greater than five
    {
      return main ();		//loops back to main menu if number is out of range
    }
  stdin = freopen (NULL, "r", stdin);	//resets stdin memory , without this the switch case will not work properly
  switch (tasknumber)		//this switchcase contains 5 options, 4 which are tasks and one which
    {
    case 1:			//this case is for the rotation encryption
      printf ("Rotation Encryption\nEnter A Message To Encrypt:\n");	// lets the user know that rotation encryption has been selected and a message to be encrypted can be typed
      scanf ("%[^\n]", message);	// scans for typed message from user
      stdin = freopen (NULL, "r", stdin);	// clears the std input memory so a key can be entered
      printf ("Enter Key: ");	// tells the user to enter in a key
      scanf ("%d", &userdefinedkey);	// scans for the key
      for (i = 0; message[i] != '\0'; i++)	//this loop runs character by character until the end of the string(NULL) is found
	{
	  if (message[i] >= 'a' && message[i] <= 'z')	//checks if the character ascii value is in the lower case range
	    {
	      message[i] = message[i] - 32;	//if lowercase is found the character is shifted to its uppercase 
	    }
	  if (message[i] >= 'A' && message[i] <= 'Z')	//checks if character ascii value is in the uppercase range
	    {
	      message[i] = message[i] + userdefinedkey % 26;	//if character is upper case the character positively shifted by the entered in key, the %26(modulus 26) returns the remainder of the key so if the rotation gets around the alphabet(0), it resets back to zero and starts again
	      if (message[i] > 'Z')	// condition checking if the shifted character is above the ascii value of Z
		{
		  message[i] = message[i] - 26;	//if the shifted character is greater than the value of Z, 26 is minused off to get it back in the character range of A-Z
		}
	      if (message[i] < 'A')	// condition checking if the shifted character is below the ascii value of A
		{
		  message[i] = message[i] + 26;	//if the shifted character is lower than the value o A, 26 is added on to get it back in the character range of A-Z 
		}
	    }
	  else			// this is executed when the character is not an uppercase character 
	    {
	      message[i] = message[i];	// if the character is not in the range A-Z, then the character remains the same, eg "?" = "?" 
	    }
	}
      printf ("Encrypted Message: %s \n", message);	//prints the rotated message to the user
      return main ();		//returns back to the main menu
    case 2:			//this case is for the rotation decryption
      printf ("Rotation Decryption\nEnter A Message To Decrypt:\n");	//tells user that rotation decryption has been selected and prompts user to enter in a message to decrypt
      scanf ("%[^\n]", message);	//scans for a entered message and stores it in the message string
      stdin = freopen (NULL, "r", stdin);	//clears the std input memory so a key can be entered
      printf ("Enter Key: ");	//prompts user to enter in a key
      scanf ("%d", &userdefinedkey);	//scans for an entered key integer and stores the value in userdefined key

      for (i = 0; message[i] != '\0'; i++)	//this loop runs character by character until the string ends (NULL, \0 is found)
	{
	  if (message[i] >= 'a' && message[i] <= 'z')	// checks if the message character is lower case
	    {
	      message[i] = message[i] - 32;	// if the messsage character is lower case, it is converted to its upper case
	    }
	  if (message[i] >= 'A' && message[i] <= 'Z')	// checks if the character is in the ascii range of A-Z
	    {
	      message[i] = message[i] - userdefinedkey % 26;	//if the character is in range, it is negatively shifted by the key, %26(modulus 26) returns the remainder of the key so that if the shift is greater than 26, the key returns back to 0
	      if (message[i] > 'Z')	//if the shifted character above the value of a, 26 is minused off to get the character back in the range of A-Z
		{
		  message[i] = message[i] - 26;
		}
	      else if (message[i] < 'A')	//if the shifted character is below the ascii value of A, 26 is minused off to get the character back in the range of A-Z
		{
		  message[i] = message[i] + 26;	//if the shifted character below the ascii value of A, 26 is added on to get the character back in the range of A-Z
		}
	    }
	  else			// this is executed when the character is not an uppercase character
	    {
	      message[i] = message[i];	// if the character is not in the range A-Z, then the character remains the same, eg "?" = "?"
	    }
	}
      printf ("Decrypted Message: %s \n", message);	//displays decrypted message to the user
      return main ();		//returns back to main menu
    case 3:			//this case is for the substition encryption
      printf ("Substitution Encryption\nEnter A Message To Encrypt:\n");	//displays message that substitution encryption has been selected, prompts the user to enter in message to encrypt 
      scanf ("%[^\n]", message);	//scans for entered in text and stores it in message
      printf ("The Encryption Key Is: %s \n", key);	//prints the key used for the substitution
      for (i = 0; i < 1000; i++)	//this loop goes through each character one by one until it reaches 1000 character counts
	{
	  if (key[i] >= 'a' && key[i] <= 'z')	//checks if key character is a lower case letter
	    {
	      key[i] = key[i] - 32;	//if character is a lowercase, it gets converted to uppercase
	    }
	  if (message[i] >= 'a' && message[i] <= 'z')	//checks if message character is a lower case letter
	    {
	      message[i] = message[i] - 32;	//if message is a lowercase it gets converted to uppercase
	    }
	  if (message[i] == 'A')	//checks if message character is A
	    {
	      message[i] = key[0];	//if message character is A, the new message is changed to the key character of position 1 in the key array
	    }
	  else if (message[i] == 'B')	//checks if message character is B
	    {
	      message[i] = key[1];	//if message character is A, the new message is changed to the key character of position 2 in the key array
	    }
	  else if (message[i] == 'C')	//checks if message character is C
	    {
	      message[i] = key[2];	//if message character is A, the new message is changed to the key character of position 3 in the key array
	    }
	  else if (message[i] == 'D')	//checks if message character is D
	    {
	      message[i] = key[3];	//if message character is A, the new message is changed to the key character of position 4 in the key array
	    }
	  else if (message[i] == 'E')	//checks if message character is E
	    {
	      message[i] = key[4];	//if message character is A, the new message is changed to the key character of position 5 in the key array
	    }
	  else if (message[i] == 'F')	//checks if message character is F
	    {
	      message[i] = key[5];	//if message character is A, the new message is changed to the key character of position 6 in the key array
	    }
	  else if (message[i] == 'G')	//checks if message character is G
	    {
	      message[i] = key[6];	//if message character is A, the new message is changed to the key character of position 7 in the key array
	    }
	  else if (message[i] == 'H')	//checks if message character is H
	    {
	      message[i] = key[7];	//if message character is A, the new message is changed to the key character of position 8 in the key array
	    }
	  else if (message[i] == 'I')	//checks if message character is I
	    {
	      message[i] = key[8];	//if message character is A, the new message is changed to the key character of position 9 in the key array
	    }
	  else if (message[i] == 'J')	//checks if message character is J
	    {
	      message[i] = key[9];	//if message character is A, the new message is changed to the key character of position 10 in the key array
	    }
	  else if (message[i] == 'K')	//checks if message character is K
	    {
	      message[i] = key[10];	//if message character is A, the new message is changed to the key character of position 11 in the key array
	    }
	  else if (message[i] == 'L')	//checks if message character is L
	    {
	      message[i] = key[11];	//if message character is A, the new message is changed to the key character of position 12 in the key array
	    }
	  else if (message[i] == 'M')	//checks if message character is M
	    {
	      message[i] = key[12];	//if message character is A, the new message is changed to the key character of position 13 in the key array
	    }
	  else if (message[i] == 'N')	//checks if message character is N
	    {
	      message[i] = key[13];	//if message character is A, the new message is changed to the key character of position 14 in the key array
	    }
	  else if (message[i] == 'O')	//checks if message character is O
	    {
	      message[i] = key[14];	//if message character is A, the new message is changed to the key character of position 15 in the key array
	    }
	  else if (message[i] == 'P')	//checks if message character is P
	    {
	      message[i] = key[15];	//if message character is A, the new message is changed to the key character of position 16 in the key array
	    }
	  else if (message[i] == 'Q')	//checks if message character is Q
	    {
	      message[i] = key[16];	//if message character is A, the new message is changed to the key character of position 17 in the key array
	    }
	  else if (message[i] == 'R')	//checks if message character is R
	    {
	      message[i] = key[17];	//if message character is A, the new message is changed to the key character of position 18 in the key array
	    }
	  else if (message[i] == 'S')	//checks if message character is S
	    {
	      message[i] = key[18];	//if message character is A, the new message is changed to the key character of position 19 in the key array
	    }
	  else if (message[i] == 'T')	//checks if message character is T
	    {
	      message[i] = key[19];	//if message character is A, the new message is changed to the key character of position 20 in the key array
	    }
	  else if (message[i] == 'U')	//checks if message character is U
	    {
	      message[i] = key[20];	//if message character is A, the new message is changed to the key character of position 21 in the key array
	    }
	  else if (message[i] == 'V')	//checks if message character is V
	    {
	      message[i] = key[21];	//if message character is A, the new message is changed to the key character of position 22 in the key array
	    }
	  else if (message[i] == 'W')	//checks if message character is W
	    {
	      message[i] = key[22];	//if message character is A, the new message is changed to the key character of position 23 in the key array
	    }
	  else if (message[i] == 'X')	//checks if message character is X
	    {
	      message[i] = key[23];	//if message character is A, the new message is changed to the key character of position 24 in the key array
	    }
	  else if (message[i] == 'Y')	//checks if message character is Y
	    {
	      message[i] = key[24];	//if message character is A, the new message is changed to the key character of position 25 in the key array
	    }
	  else if (message[i] == 'Z')	//checks if message character is Z
	    {
	      message[i] = key[25];	//if message character is A, the new message is changed to the key character of position 26 in the key array
	    }
	  else if (message[i] < 'A' || message[i] > 'Z')	//checks if message character out of range A-Z
	    {
	      message[i] = message[i];	//if the character is out of range, the character stays the same
	    }
	}
      printf ("Encrypted Message: %s \n", message);	//displays encrypted message to user
      return main ();		//returns to main
    case 4:			//this case decrypts a user entered message with a set key
      printf ("Substitution Decryption\nEnter A Message To Decrypt:");	//displays message that substution decryption has been selected and prmompts user to enter in message
      scanf ("%[^\n]", message);	//scans for entered in message
      printf ("The Encryption Key Is: %s \n", key);	//prints the key used to decode the message
      for (i = 0; i < 1000; i++)	//this loop goes through each character one by one until it reaches 1000 character counts
	{
	  if (message[i] >= 'a' && message[i] <= 'z')	//checks if the message character is a lower case letter
	    {
	      message[i] = message[i] - 32;	//if the message is a lower case letter it gets changed to its upper case
	    }
	  if (message[i] < 'A' || message[i] > 'Z')	//checks if the message character is not an upper case letter
	    {
	      message[i] = message[i];	//if the message character is not an upper case, the character stays the same
	    }
	  else if (message[i] == 'Q')	//checks if message character is Q
	    {
	      message[i] = plain[0];	//if message character is Q, the new message character is changed to the plain character of position 0 in the plain array
	    }
	  else if (message[i] == 'W')	//checks if message character is W
	    {
	      message[i] = plain[1];	//if message character is W, the new message character is changed to the plain character of position 1 in the plain array
	    }
	  else if (message[i] == 'E')	//checks if message character is E
	    {
	      message[i] = plain[2];	//if message character is E, the new message character is changed to the plain character of position 2 in the plain array
	    }
	  else if (message[i] == 'R')	//checks if message character is R
	    {
	      message[i] = plain[3];	//if message character is R, the new message character is changed to the plain character of position 3 in the plain array
	    }
	  else if (message[i] == 'T')	//checks if message character is T
	    {
	      message[i] = plain[4];	//if message character is T, the new message character is changed to the plain character of position 4 in the plain array
	    }
	  else if (message[i] == 'Y')	//checks if message character is Y
	    {
	      message[i] = plain[5];	//if message character is Y, the new message character is changed to the plain character of position 5 in the plain array
	    }
	  else if (message[i] == 'U')	//checks if message character is U
	    {
	      message[i] = plain[6];	//if message character is U, the new message character is changed to the plain character of position 6 in the plain array
	    }
	  else if (message[i] == 'I')	//checks if message character is I
	    {
	      message[i] = plain[7];	//if message character is I, the new message character is changed to the plain character of position 7 in the plain array
	    }
	  else if (message[i] == 'O')	//checks if message character is O
	    {
	      message[i] = plain[8];	//if message character is O, the new message character is changed to the plain character of position 8 in the plain array
	    }
	  else if (message[i] == 'P')	//checks if message character is P
	    {
	      message[i] = plain[9];	//if message character is P, the new message character is changed to the plain character of position 9 in the plain array
	    }
	  else if (message[i] == 'A')	//checks if message character is A
	    {
	      message[i] = plain[10];	//if message character is A, the new message character is changed to the plain character of position 10 in the plain array
	    }
	  else if (message[i] == 'S')	//checks if message character is S
	    {
	      message[i] = plain[11];	//if message character is S, the new message character is changed to the plain character of position 11 in the plain array
	    }
	  else if (message[i] == 'D')	//checks if message character is D
	    {
	      message[i] = plain[12];	//if message character is D, the new message character is changed to the plain character of position 12 in the plain array
	    }
	  else if (message[i] == 'F')	//checks if message character is F
	    {
	      message[i] = plain[13];	//if message character is F, the new message character is changed to the plain character of position 13 in the plain array
	    }
	  else if (message[i] == 'G')	//checks if message character is G
	    {
	      message[i] = plain[14];	//if message character is G, the new message character is changed to the plain character of position 14 in the plain array
	    }
	  else if (message[i] == 'H')	//checks if message character is H
	    {
	      message[i] = plain[15];	//if message character is H, the new message character is changed to the plain character of position 15 in the plain array
	    }
	  else if (message[i] == 'J')	//checks if message character is J
	    {
	      message[i] = plain[16];	//if message character is J, the new message character is changed to the plain character of position 16 in the plain array
	    }
	  else if (message[i] == 'K')	//checks if message character is K
	    {
	      message[i] = plain[17];	//if message character is K, the new message character is changed to the plain character of position 17 in the plain array
	    }
	  else if (message[i] == 'L')	//checks if message character is L
	    {
	      message[i] = plain[18];	//if message character is L, the new message character is changed to the plain character of position 18 in the plain array
	    }
	  else if (message[i] == 'Z')	//checks if message character is Z
	    {
	      message[i] = plain[19];	//if message character is Z, the new message character is changed to the plain character of position 19 in the plain array
	    }
	  else if (message[i] == 'X')	//checks if message character is X
	    {
	      message[i] = plain[20];	//if message character is X, the new message character is changed to the plain character of position 20 in the plain array
	    }
	  else if (message[i] == 'C')	//checks if message character is C
	    {
	      message[i] = plain[21];	//if message character is C, the new message character is changed to the plain character of position 21 in the plain array
	    }
	  else if (message[i] == 'V')	//checks if message character is V
	    {
	      message[i] = plain[22];	//if message character is V, the new message character is changed to the plain character of position 22 in the plain array
	    }
	  else if (message[i] == 'B')	//checks if message character is B
	    {
	      message[i] = plain[23];	//if message character is B, the new message character is changed to the plain character of position 23 in the plain array
	    }
	  else if (message[i] == 'N')	//checks if message character is N
	    {
	      message[i] = plain[24];	//if message character is N, the new message character is changed to the plain character of position 24 in the plain array
	    }
	  else if (message[i] == 'M')	//checks if message character is M
	    {
	      message[i] = plain[25];	//if message character is M, the new message character is changed to the plain character of position 25 in the plain array
	    }
	}
      printf ("Decrypted Message: %s \n", message);	//prints decrypted message to user
      return main ();		//returns back to main menu
    case 5:

      //note, case 5 did not work exactly how i planned on


      printf ("Rotation Decryption, Text Only\n");

      int crackrotationkey;


      for (i = 0; crackrotationkey < 27; crackrotationkey++)
	{
//check frequency of letters

	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'A')
		{
		  fA++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'B')
		{
		  fB++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'C')
		{
		  fC++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'D')
		{
		  fD++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'E')
		{
		  fE++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'F')
		{
		  fF++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'G')
		{
		  fG++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'H')
		{
		  fH++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'I')
		{
		  fI++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'J')
		{
		  fJ++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'K')
		{
		  fK++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'L')
		{
		  fL++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'M')
		{
		  fM++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'N')
		{
		  fN++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'O')
		{
		  fO++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'P')
		{
		  fP++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'Q')
		{
		  fQ++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'R')
		{
		  fR++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'S')
		{
		  fS++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'T')
		{
		  fT++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'U')
		{
		  fU++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'V')
		{
		  fV++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'W')
		{
		  fW++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'X')
		{
		  fX++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'Y')
		{
		  fY++;
		}
	    }
	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] == 'Z')
		{
		  fZ++;
		}
	    }

	  for (i = 0; crackrotation[i] != '\0'; i++)
	    {
	      if (crackrotation[i] < 'A' || crackrotation[i] > 'Z')
		{
		  crackrotation[i] = crackrotation[i];
		}
	      if (crackrotation[i] >= 'A' && crackrotation[i] <= 'Z')
		{
		  crackrotation[i] = crackrotation[i] + crackrotationkey % 26;
		  if (crackrotation[i] > 'Z')
		    {
		      crackrotation[i] = crackrotation[i] - 26;
		    }
		  if (crackrotation[i] < 'A')
		    {
		      crackrotation[i] = crackrotation[i] + 26;
		    }
		}
	    }
	  int totalLetters = fA + fB + fC + fD + fE + fF + fG + fH + fI + fJ + fK + fL + fM + fN + fO + fP + fQ + fR + fS + fT + fU + fV + fW + fX + fY + fZ;	//sums the total number of letters, stores value in totalLetters
/*float pA = (fA / totalLetters)*100;
float pB = (fB / totalLetters)*100;
float pC = (fC / totalLetters)*100;
float pD = (fD / totalLetters)*100;
float pE = (fE / totalLetters)*100;
float pF = (fF / totalLetters)*100;
float pG = (fG / totalLetters)*100;
float pH = (fH / totalLetters)*100;
float pI = (fI / totalLetters)*100;
float pJ = (fJ / totalLetters)*100;
float pK = (fK / totalLetters)*100;
float pL = (fL / totalLetters)*100;
float pM = (fM / totalLetters)*100;
float pN = (fN / totalLetters)*100;
float pO = (fO / totalLetters)*100;
float pP = (fP / totalLetters)*100;
float pQ = (fQ / totalLetters)*100;
float pR = (fR / totalLetters)*100;
float pS = (fS / totalLetters)*100;
float pT = (fT / totalLetters)*100;
float pU = (fU / totalLetters)*100;
float pV = (fV / totalLetters)*100;
float pW = (fW / totalLetters)*100;
float pX = (fX / totalLetters)*100;
float pY = (fY / totalLetters)*100;
float pZ = (fZ / totalLetters)*100;*/
//printf("%f\n", pE);
//if (fE>0 && fA>0 &&fT>0){
	  if (fE < fZ)
	    {
	      printf ("crackrotation %d %s \n", crackrotationkey,
		      crackrotation);
	    }
	  for (i = 0; crackrotationkey < 27; crackrotationkey++)
	    {
//check frequency of letters

	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'A')
		    {
		      fA++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'B')
		    {
		      fB++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'C')
		    {
		      fC++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'D')
		    {
		      fD++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'E')
		    {
		      fE++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'F')
		    {
		      fF++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'G')
		    {
		      fG++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'H')
		    {
		      fH++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'I')
		    {
		      fI++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'J')
		    {
		      fJ++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'K')
		    {
		      fK++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'L')
		    {
		      fL++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'M')
		    {
		      fM++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'N')
		    {
		      fN++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'O')
		    {
		      fO++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'P')
		    {
		      fP++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'Q')
		    {
		      fQ++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'R')
		    {
		      fR++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'S')
		    {
		      fS++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'T')
		    {
		      fT++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'U')
		    {
		      fU++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'V')
		    {
		      fV++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'W')
		    {
		      fW++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'X')
		    {
		      fX++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'Y')
		    {
		      fY++;
		    }
		}
	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] == 'Z')
		    {
		      fZ++;
		    }
		}

	      for (i = 0; crackrotation[i] != '\0'; i++)
		{
		  if (crackrotation[i] < 'A' || crackrotation[i] > 'Z')
		    {
		      crackrotation[i] = crackrotation[i];
		    }
		  if (crackrotation[i] >= 'A' && crackrotation[i] <= 'Z')
		    {
		      crackrotation[i] =
			crackrotation[i] + crackrotationkey % 26;
		      if (crackrotation[i] > 'Z')
			{
			  crackrotation[i] = crackrotation[i] - 26;
			}
		      if (crackrotation[i] < 'A')
			{
			  crackrotation[i] = crackrotation[i] + 26;
			}
		    }
		}
//int totalLetters = fA+fB+fC+fD+fE+fF+fG+fH+fI+fJ+fK+fL+fM+fN+fO+fP+fQ+fR+fS+fT+fU+fV+fW+fX+fY+fZ;//sums the total number of letters, stores 

//if (fE<fZ){
	      printf ("crackrotation %d %s \n", crackrotationkey,
		      crackrotation);
//{return main();}
//printf("%d\n", crackrotationkey);
//printf ("crackrotation %s \n", crackrotation);
	    }
	}
/*
c
}
if(fZ <5)
	{printf ("crackrotation %s \n", crackrotation);
	return main();}

}

/*printf("frequency of A %d\n", fA);
printf("frequency of B %d\n", fB);
printf("frequency of C %d\n", fC);
printf("frequency of D %d\n", fD);
printf("frequency of E %d\n", fE);
printf("frequency of F %d\n", fF);
printf("frequency of G %d\n", fG);
printf("frequency of H %d\n", fH);
printf("frequency of I %d\n", fI);
printf("frequency of J %d\n", fJ);
printf("frequency of K %d\n", fK);
printf("frequency of L %d\n", fL);
printf("frequency of M %d\n", fM);
printf("frequency of N %d\n", fN);
printf("frequency of O %d\n", fO);
printf("frequency of P %d\n", fP);
printf("frequency of Q %d\n", fQ);
printf("frequency of R %d\n", fR);
printf("frequency of S %d\n", fS);
printf("frequency of T %d\n", fT);
printf("frequency of U %d\n", fU);
printf("frequency of V %d\n", fV);
printf("frequency of W %d\n", fW);
printf("frequency of X %d\n", fX);
printf("frequency of Y %d\n", fY);
printf("frequency of Z %d\n", fZ);
printf("total letters %d\n", totalLetters);
*/
      //return main (); break;
    case 6:
      return 0;
    default:;
    }
}
