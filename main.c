#include <stdio.h>

int
main ()
{
  //char crackrotation[] = {"TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU."
  //};
  char crackrotation[] =
    {
"SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"
};
  char message[500], characters;	//declares message array, characters
  char plain[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };	//declares plain key for substitution cipher
  char key[] = { "QWERTYUIOPASDFGHJKLZXCVBNM" };	//default key for substitution cipher
  int i, userdefinedkey, tasknumber;	//declare integers i, userdefinedkey, tasknumber
  int fA = 0, fB = 0, fC = 0, fD = 0, fE = 0, fF = 0, fG = 0, fH = 0, fI = 0, fJ = 0, fK = 0, fL = 0, fM = 0, fN = 0, fO = 0, fP = 0, fQ = 0, fR = 0, fS = 0, fT = 0, fU = 0, fV = 0, fW = 0, fX = 0, fY = 0, fZ = 0;	//variables for each letter counter 

  int zero = 0;
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
      return main ();		//loops back to main if number is out of range
    }
  stdin = freopen (NULL, "r", stdin);	//resets stdin memory , without this the switch case will not work properly
  switch (tasknumber)
    {
    case 1:
      printf ("Rotation Encryption\nEnter A Message To Encrypt:\n");
      scanf ("%[^\n]", message);
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
	      message[i] = message[i] + userdefinedkey % 26;
	      if (message[i] > 'Z')
		{
		  message[i] = message[i] - 26;
		}
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
      return main ();
    case 2:
      printf ("Rotation Decryption\nEnter A Message To Decrypt:\n");
      scanf ("%[^\n]", message);
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
	      if (message[i] > 'Z')
		{
		  message[i] = message[i] - 26;
		}
	      else if (message[i] < 'A')
		{
		  message[i] = message[i] + 26;
		}
	    }
	  else
	    {
	      message[i] = message[i];
	    }
	}
      printf ("Decrypted Message: %s \n", message);
      return main ();
    case 3:
      printf ("Substitution Encryption\nEnter A Message To Encrypt:\n");
      scanf ("%[^\n]", message);
      printf ("The Encryption Key Is: %s \n", key);
      for (i = 0; i < 1000; i++)
	{
	  if (key[i] >= 'a' && key[i] <= 'z')
	    {
	      key[i] = key[i] - 32;
	    }
	  if (message[i] >= 'a' && message[i] <= 'z')
	    {
	      message[i] = message[i] - 32;
	    }
	  if (message[i] == 'A')
	    {
	      message[i] = key[0];
	    }
	  else if (message[i] == 'B')
	    {
	      message[i] = key[1];
	    }
	  else if (message[i] == 'C')
	    {
	      message[i] = key[2];
	    }
	  else if (message[i] == 'D')
	    {
	      message[i] = key[3];
	    }
	  else if (message[i] == 'E')
	    {
	      message[i] = key[4];
	    }
	  else if (message[i] == 'F')
	    {
	      message[i] = key[5];
	    }
	  else if (message[i] == 'G')
	    {
	      message[i] = key[6];
	    }
	  else if (message[i] == 'H')
	    {
	      message[i] = key[7];
	    }
	  else if (message[i] == 'I')
	    {
	      message[i] = key[8];
	    }
	  else if (message[i] == 'J')
	    {
	      message[i] = key[9];
	    }
	  else if (message[i] == 'K')
	    {
	      message[i] = key[10];
	    }
	  else if (message[i] == 'L')
	    {
	      message[i] = key[11];
	    }
	  else if (message[i] == 'M')
	    {
	      message[i] = key[12];
	    }
	  else if (message[i] == 'N')
	    {
	      message[i] = key[13];
	    }
	  else if (message[i] == 'O')
	    {
	      message[i] = key[14];
	    }
	  else if (message[i] == 'P')
	    {
	      message[i] = key[15];
	    }
	  else if (message[i] == 'Q')
	    {
	      message[i] = key[16];
	    }
	  else if (message[i] == 'R')
	    {
	      message[i] = key[17];
	    }
	  else if (message[i] == 'S')
	    {
	      message[i] = key[18];
	    }
	  else if (message[i] == 'T')
	    {
	      message[i] = key[19];
	    }
	  else if (message[i] == 'U')
	    {
	      message[i] = key[20];
	    }
	  else if (message[i] == 'V')
	    {
	      message[i] = key[21];
	    }
	  else if (message[i] == 'W')
	    {
	      message[i] = key[22];
	    }
	  else if (message[i] == 'X')
	    {
	      message[i] = key[23];
	    }
	  else if (message[i] == 'Y')
	    {
	      message[i] = key[24];
	    }
	  else if (message[i] == 'Z')
	    {
	      message[i] = key[25];
	    }
	  else if (message[i] < 'A' || message[i] > 'Z')
	    {
	      message[i] = message[i];
	    }
	}
      printf ("Encrypted Message: %s \n\n", message);
      return main ();
    case 4:
      printf ("Substitution Decryption\nEnter A Message To Decrypt:");
      scanf ("%[^\n]", message);
      printf ("The Encryption Key Is: %s \n", key);

      for (i = 0; i < 20; i++)
	{
	  if (message[i] >= 'a' && message[i] <= 'z')
	    {
	      message[i] = message[i] - 32;
	    }
	  if (message[i] < 'A' || message[i] > 'Z')
	    {
	      message[i] = message[i];
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
      //return main ();
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
