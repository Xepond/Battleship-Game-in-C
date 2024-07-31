#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// This game is coded on Embarcadero Dev-C++ 6.3 . If there is any problem with the code, please change your ide.
// AI is not used on this code.

void welcome_rules_interface(); // Hoşgeldiniz diyen ve kuralları anlatan fonksiyon.
void printGameboard(); // Oyun tahtasının boyutunu alan fonksiyon.
void designGameboard(); // Oyun tahtasının tasarımını yaptığım fonksiyon.
void placeShip(); // Gemileri rastgele ama kurallarına göre yerleştirecek fonskiyon.
void canPlaceShip1(); // 1. oyuncunun gemi yerleştirip yerleştiremediğini değerlendiren fonksiyon.
void canPlaceShip2(); // 2. oyuncunun gemi yerleştirip yerleştiremediğini değerlendiren fonksiyon.
void printMove1(); // Her hamleden sonra 1. oyuncu için tahtanın güncel halini gösteren fonksiyon.
void printMove2(); // Her hamleden sonra 2. oyuncu için tahtanın güncel halini gösteren fonksiyon.
void gameBoardsBeginning(); // Oyunun başında gemilerin yerleşmiş olduğu halini gösteren fonskiyon.
int shotPlayer1(); // 1. oyuncunun atış yaptığı fonksiyon.
int shotPlayer2(); // 2. oyuncunun atış yaptığı fonksiyon.
void endgame(); // Oyun sonu fonksiyonu.

int isitplaceable=1, xlength, ylength, i, j, a, sayi1, sayi2, yon, turn=1, counter=0, counter1=0, counter2=0;
char ship;
char gameBoard1[1000][1000];
char gameBoard2[1000][1000];
char p1=1,g1=2,o1=3,s1=4,a1=5,p2=1,g2=2,o2=3,s2=4,a2=5,f1=15,f2=15;

int main()
{
	srand(time(0));
	welcome_rules_interface();
	printGameboard();
	designGameboard();
	placeShip();
	canPlaceShip1();
	canPlaceShip2();
	gameBoardsBeginning();
	
	do
	{  
		if(f1 == 0 || f2 == 0)
		{
			break;
		}
		shotPlayer1();
		shotPlayer2();
	}while (f1 > 0 || f2 > 0);
	
	endgame();
	
	return 0;
}
void welcome_rules_interface()
{
	printf("\033[0;32m");
	printf("WELCOME TO THE\n\n\n");
	printf("      XXXX   XX     XX   XX  XXXXXX    XXXX   XX    \n");
	printf("     XX  XX XX XX XX XX      XX   XX  XX  XX  XX    \n");
	printf("     XX  XX XX  XX   XX  XX  XXXXXX   XX  XX  XX    \n");
	printf("     XXXXXX XX       XX  XX  XX   XX  XXXXXX  XX    \n");
	printf("     XX  XX XX       XX  XX  XX    XX XX  XX  XXXXXX\n");
	printf("\n");
	printf("                       XXXXX    XXXX  XXXXXX XXXXXX XX\n");
	printf("                       XX  XX  XX  XX   XX     XX   XX\n");
	printf("                       XXXXX   XX  XX   XX     XX   XX\n");
	printf("                       XX  XX  XXXXXX   XX     XX   XX\n");
	printf("                       XXXXX   XX  XX   XX     XX   XX\n");
	printf("\n");
	printf("                                     XXXXX  XX   XX\t XXXXX    XXXXXX     XXXXXX   \n");
	printf("                                     XX  XX  XX XX \tXX        XX         XX   XX  \n");
	printf("                                     XXXXX    XX   \t XXXX     XXXX       XXXXXX   \n");
	printf("                                     XX  XX   XX   \t    XX    XX         XX       \n");
	printf("                                     XXXXX    XX   \tXXXXX  XX XXXXXX XX  XX     XX\n");
	printf("\033[0;31m");
	printf("\n\n");

	printf("Press \"Enter\" to read the rules.");
	getchar();
	system("cls");
	
	printf("RULES OF THE GAME: \n\n");
	printf("1- This game is designed for 2 player.\n\n");
	printf("2- All ships will be placed by the computer for both players.\n");
	printf("3- There are five types of ships:\nTCG Preveze (P) has 1 cell,\nTCG Gelibolu (G) has 2 cells,\n");
	printf("TCG Osman Gazi (O) has 3 cells,\nTCG Sancaktar (S) has 4 cells,\nand TCG Anadolu (A) has 5 cells.\n\n");
	printf("5- Player 1 will always play first.\n\n");
	printf("6- The game begins as each player tries to guess the location of the ships\n");
	printf("   of the opposing player's game board; [*] hit and [m] miss.\n\n");
	printf("7- If any player hit his/her, he/she will shot again.");
	printf("8- First player to guess the location of all ships wins.\n\n");
	printf("\033[0;32m");
	
	printf("Press \"Enter\" to start to the game!\n");
	getchar();
	system("cls");
	printf("\033[0;37m");
}
void printGameboard()
{
	printf("Enter the size of the gameboard like (x y). The size must be bigger than 5x5\n");
	scanf("%d %d", &xlength, &ylength);
	while (xlength < 6 && ylength < 6)
	{
		printf("You entered unvalid size. Please enter again according to the rules.\n");
		scanf("%d %d", &xlength, &ylength);
	}
}
void designGameboard()
{
	for (i = 0; i < xlength; i++)
	{
		for (j = 0; j < ylength; j++)
		{
			gameBoard1[i][j] = '~';
			gameBoard2[i][j] = '~';
		}
	}
}
void placeShip()
{
	system("cls");
	
	for (a = 1; a <= 5; a++)
	{
		do
		{
			sayi1 = rand() % (xlength);
			sayi2 = rand() % (ylength);
			yon = rand() % 4;
			canPlaceShip1();
		}while (isitplaceable == 0);
		
		for (i = 0; i < a; i++)
		{
			if (a == 1)
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard1[sayi1][sayi2 + i] = (char)(a + 79);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard1[sayi1 - i][sayi2] = (char)(a + 79);
					break;
				}
				case 2:  //batı
				{
					gameBoard1[sayi1][sayi2 - i] = (char)(a + 79);
					break;
				}
				case 3:  //güney
				{
					gameBoard1[sayi1 + i][sayi2] = (char)(a + 79);
					break;
				}
				}
			}
			else if (a == 2)
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard1[sayi1][sayi2 + i] = (char)(a + 69);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard1[sayi1 - i][sayi2] = (char)(a + 69);
					break;
				}
				case 2:  //batı
				{
					gameBoard1[sayi1][sayi2 - i] = (char)(a + 69);
					break;
				}
				case 3:  //güney
				{
					gameBoard1[sayi1 + i][sayi2] = (char)(a + 69);
					break;
				}
				}	
			}
			else if (a == 3)
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard1[sayi1][sayi2 + i] = (char)(a + 76);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard1[sayi1 - i][sayi2] = (char)(a + 76);
					break;
				}
				case 2:  //batı
				{
					gameBoard1[sayi1][sayi2 - i] = (char)(a + 76);
					break;
				}
				case 3:  //güney
				{
					gameBoard1[sayi1 + i][sayi2] = (char)(a + 76);
					break;
				}
				}
			}
			else if (a == 4)
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard1[sayi1][sayi2 + i] = (char)(a + 79);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard1[sayi1 - i][sayi2] = (char)(a + 79);
					break;
				}
				case 2:  //batı
				{
					gameBoard1[sayi1][sayi2 - i] = (char)(a + 79);
					break;
				}
				case 3:  //güney
				{
					gameBoard1[sayi1 + i][sayi2] = (char)(a + 79);
					break;
				}
				}
			}
			else
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard1[sayi1][sayi2 + i] = (char)(a + 60);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard1[sayi1 - i][sayi2] = (char)(a + 60);
					break;
				}
				case 2:  //batı
				{
					gameBoard1[sayi1][sayi2 - i] = (char)(a + 60);
					break;
				}
				case 3:  //güney
				{
					gameBoard1[sayi1 + i][sayi2] = (char)(a + 60);
					break;
				}
				}
			}
		}
	}
	for (a = 1; a <= 5; a++)
	{
		do
		{
			sayi1 = rand() % (xlength);
			sayi2 = rand() % (ylength);
			yon = rand() % 4;
			canPlaceShip2();
		}while (isitplaceable == 0);
		for (i = 0; i < a; i++)
		{
			if (a == 1)
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard2[sayi1][sayi2 + i] = (char)(a + 79);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard2[sayi1 - i][sayi2] = (char)(a + 79);
					break;
				}
				case 2:  //batı
				{
					gameBoard2[sayi1][sayi2 - i] = (char)(a + 79);
					break;
				}
				case 3:  //güney
				{
					gameBoard2[sayi1 + i][sayi2] = (char)(a + 79);
					break;
				}
				}
			}
			else if (a == 2)
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard2[sayi1][sayi2 + i] = (char)(a + 69);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard2[sayi1 - i][sayi2] = (char)(a + 69);
					break;
				}
				case 2:  //batı
				{
					gameBoard2[sayi1][sayi2 - i] = (char)(a + 69);
					break;
				}
				case 3:  //güney
				{
					gameBoard2[sayi1 + i][sayi2] = (char)(a + 69);
					break;
				}
				}
			}
			else if (a == 3)
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard2[sayi1][sayi2 + i] = (char)(a + 76);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard2[sayi1 - i][sayi2] = (char)(a + 76);
					break;
				}
				case 2:  //batı
				{
					gameBoard2[sayi1][sayi2 - i] = (char)(a + 76);
					break;
				}
				case 3:  //güney
				{
					gameBoard2[sayi1 + i][sayi2] = (char)(a + 76);
					break;
				}
				}
			}
			else if(a == 4)
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard2[sayi1][sayi2 + i] = (char)(a + 79);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard2[sayi1 - i][sayi2] = (char)(a + 79);
					break;
				}
				case 2:  //batı
				{
					gameBoard2[sayi1][sayi2 - i] = (char)(a + 79);
					break;
				}
				case 3:  //güney
				{
					gameBoard2[sayi1 + i][sayi2] = (char)(a + 79);
					break;
				}
				}
			}
			else
			{
				switch (yon)
				{
				case 0: //doğu
				{
					gameBoard2[sayi1][sayi2 + i] = (char)(a + 60);
					break;
				}
				case 1:  //kuzey
				{
					gameBoard2[sayi1 - i][sayi2] = (char)(a + 60);
					break;
				}
				case 2:  //batı
				{
					gameBoard2[sayi1][sayi2 - i] = (char)(a + 60);
					break;
				}
				case 3:  //güney
				{
					gameBoard2[sayi1 + i][sayi2] = (char)(a + 60);
					break;
				}
				}
			}
		}
	}
}
void canPlaceShip1()
{
	isitplaceable = 1;
	
	for (i = 0; i < a; i++)
	{
		switch (yon)
		{
		case 0: //doğu
		{
			if (sayi2 + i < 0 || sayi2 + i >= xlength || gameBoard1[sayi1][sayi2 + i] != '~')
			{
				isitplaceable = 0;
			}
			break;
		}
		case 1:  //kuzey
		{
			if (sayi1 - i < 0 || sayi1 - i >= ylength || gameBoard1[sayi1 - i][sayi2] != '~')
			{
				isitplaceable = 0;
			}
			break;
		}
		case 2:  //batı
		{
			if (sayi2 - i < 0 || sayi2 - i >= xlength || gameBoard1[sayi1][sayi2 - i] != '~')
			{
				isitplaceable = 0;
			}
			break;
		}
		case 3:  //güney
		{
			if (sayi1 + i < 0 || sayi1 + i >= ylength || gameBoard1[sayi1 + i][sayi2] != '~')
			{
				isitplaceable = 0;
			}
			break;
		}
		}		
	}
}
void canPlaceShip2()
{
	isitplaceable = 1;
	
	for (i = 0; i < a; i++)
	{
		switch (yon)
		{
		case 0: //doğu
		{
			if (sayi2 + i < 0 || sayi2 + i >= xlength || gameBoard2[sayi1][sayi2 + i] != '~')
			{
				isitplaceable = 0;
			}
			break;
		}
		case 1:  //kuzey
		{
			if (sayi1 - i < 0 || sayi1 - i >= ylength || gameBoard2[sayi1 - i][sayi2] != '~')
			{
				isitplaceable = 0;
			}
			break;
		}
		case 2:  //batı
		{
			if (sayi2 - i < 0 || sayi2 - i >= xlength || gameBoard2[sayi1][sayi2 - i] != '~')
			{
				isitplaceable = 0;
			}
			break;
		}
		case 3:  //güney
		{
			if (sayi1 + i < 0 || sayi1 + i >= ylength || gameBoard2[sayi1 + i][sayi2] != '~')
			{
				isitplaceable = 0;
			}
			break;
		}
		}
	}
}
void printMove1()
{
	system("cls");
	
	printf ("Player 1's total moves: %d\n",counter1);
	printf ("Total moves: %d\n",counter);
	printf ("\nPLAYER 2'S BOARD\n");
	printf("\nPlyr 2");
	for (i = 0; i < ylength; i++)
	{
		printf("\t%d", i);
	}
	for (i = 0; i < xlength; i++)
	{
		printf("\n\n%d  ", i);
		printf("\t");
		for (j = 0; j < ylength; j++)
		{
			if (gameBoard2[i][j] == 'P' || gameBoard2[i][j] == 'G' || gameBoard2[i][j] == 'O' || gameBoard2[i][j] == 'S' || gameBoard2[i][j] == 'A')
			{
				printf ("~\t");
			}
			else
			{
				printf("%c\t",gameBoard2[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}
void printMove2()
{
	system("cls");
	
	printf ("Player 2's total moves: %d\n",counter2);
	printf ("Total moves: %d\n",counter);
	
	printf ("\nPLAYER 1'S BOARD\n");
	printf("\nPlyr 1");
	for (i = 0; i < ylength; i++)
	{
		printf("\t%d", i);
	}
	for (i = 0; i < xlength; i++)
	{
		printf("\n\n%d  ", i);
		printf("\t");
		for (j = 0; j < ylength; j++)
		{
			if (gameBoard1[i][j] == 'P' || gameBoard1[i][j] == 'G' || gameBoard1[i][j] == 'O' || gameBoard1[i][j] == 'S' || gameBoard1[i][j] == 'A')
			{
				printf ("~\t");
			}
			else
			{
				printf("%c\t",gameBoard1[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}
void gameBoardsBeginning()
{
	printf ("Press enter to look player 1's board.");
	
	getch();
	system("cls");
	
	printf ("PLAYER 1'S BOARD\n");
	printf("\n\nPlyr 1");
	for (i = 0; i < ylength; i++)
	{
		printf("\t%d", i);
	}
	for (i = 0; i < xlength; i++)
	{
		printf("\n\n%d  ", i);
		printf("\t");

		for (j = 0; j < ylength; j++)
		{
			printf("%c\t",gameBoard1[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	
	printf ("Press enter to look player 2's board.");
	getch();
	system("cls");
	
	printf ("PLAYER 2'S BOARD\n");
	printf("\n\nPlyr 2");
	for (i = 0; i < ylength; i++)
	{
		printf("\t%d", i);
	}
	for (i = 0; i < xlength; i++)
	{
		printf("\n\n%d  ", i);
		printf("\t");

		for (j = 0; j < ylength; j++)
		{
			printf("%c\t",gameBoard2[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	
	printf ("Press \"Enter\" to player 1 to shoot.");
	getch();
	system("cls");
}
int shotPlayer1()
{
	if (turn == 2)
	{
		return 0;
	}
	else
	{	
		do
		{
			printf ("Player 1, Give Coordinates : \n");
			scanf ("%d %d",&i,&j);
		}while ( i >= xlength || j >= ylength || i < 0 || j < 0 );
		
		ship = gameBoard2[i][j];
		
		if (ship != '~')
		{
		 	switch (ship)
		 	{
		 		case 'P':
		 		{
		 			gameBoard2[i][j] = '*';
		 			
					counter++;
					counter1++;
					
					printMove1();
		 			
					printf ("SHOT !\n");
					printf ("Preveze ship (P) has sunk!");
					
					p2--;
					f2--;
					
					printf ("\nTotal ship cells for player 2: %d\n",f2);
		 			
					getch();	
		 			system("cls");
		 			
					turn = 1;
		 			break;
				}
				case 'G':
				{
		 			gameBoard2[i][j] = '*';
		 			
		 			counter++;
		 			counter1++;
		 			
		 			printMove1();
					
					printf ("SHOT !\n");
					
					g2--;
					f2--;
					
					printf ("\nTotal ship cells for player 2: %d\n",f2);
					
					if (g2 == 0)
						printf ("Gelibolu ship (G) has sunk!");
					
					getch();
					system("cls");
					
					turn = 1;
					break;
				}
				case 'O':
				{
		 			gameBoard2[i][j] = '*';
		 			
		 			counter++;
		 			counter1++;
		 			
		 			printMove1();
					
					printf ("SHOT !\n");
					
					o2--;				
					f2--;
					
					printf ("\nTotal ship cells for player 2: %d\n",f2);
					
					if (o2 == 0)
						printf ("Osman Gazi ship (O) has sunk!");
					
					getch();
					system("cls");
					
					turn = 1;
		 			break;
				}
				case 'S':
				{
		 			gameBoard2[i][j] = '*';
		 			
		 			counter++;
		 			counter1++;
		 			
					printMove1();
					printf ("SHOT !\n");
					
					s2--;
					f2--;
					
					printf ("\nTotal ship cells for player 2: %d\n",f2);
					
					if(s2 == 0)
						printf ("Sancaktar ship (S) has sunk!");
					
					getch();
					system("cls");
					
					turn = 1;
					break;
				}
				case 'A':
				{
					gameBoard2[i][j] = '*';
					
					counter++;
					counter1++;
					
		 			printMove1();
					
					printf ("SHOT !\n");
					
					a2--;
					f2--;
					
					printf ("\nTotal ship cells for player 2: %d\n",f2);
					
					if(a2 == 0)
						printf ("Anadolu ship (A) has sunk!");
					
					getch();
					system("cls");
					
					turn = 1;
					break;
				}
				case '*':
				{
					printf ("Unvalid shot. Try again.");
					turn = 1;
					break;
				}
				case 'm':
				{
					printf ("Unvalid shot. Try again.");
					turn = 1;
					break;
				}
			}
		}
		else
		{
			gameBoard2[i][j] = 'm';
			
			counter++;
			counter1++;
			
			printMove1();
				
			printf ("MISS !\n");
			printf ("\nTotal ship cells for player 2: %d\n",f2);
			
			getch();
			system("cls");
			
			turn = 2;
		}
	}
}
int shotPlayer2()
{
	if (turn == 1)
	{
		return 0;
	}
	else
	{
		int i, j;	
		do
		{
			printf ("Player 2, Give Coordinates : \n");
			scanf ("%d %d",&i,&j);
			
		}while ( i >= xlength || j >= ylength || i < 0 || j < 0 );
		
		ship = gameBoard1[i][j];
		
		if (ship != '~')
		{
		 	switch (ship)
		 	{
		 		case 'P':
		 		{
		 			gameBoard1[i][j] = '*';
		 			
		 			counter++;
		 			counter2++;
		 			
		 			printMove2();
		 			
					printf ("SHOT !\n");
					printf ("Preveze ship (P) has sunk!");
					
					p1--;
					f1--;
					
					printf ("\nTotal ship cells for player 1: %d\n",f1);
		 			
					getch();	
		 			system("cls");
		 			
					 turn = 2;
		 			break;
				}
				case 'G':
				{
		 			gameBoard1[i][j] = '*';
		 			
		 			counter++;
		 			counter2++;
		 			
		 			printMove2();
					
					printf ("SHOT !\n");
					
					g1--;
					f1--;
					
					printf ("\nTotal ship cells for player 1: %d\n",f1);
					
					if (g1 == 0)
						printf ("Gelibolu ship (G) has sunk!");
					
					getch();
					system("cls");
					
					turn = 2;
					break;
				}
				case 'O':
				{
		 			gameBoard1[i][j] = '*';
		 			
		 			counter++;
		 			counter2++;
		 			
		 			printMove2();
					
					printf ("SHOT !\n");
					
					o1--;				
					f1--;
					
					printf ("\nTotal ship cells for player 1: %d\n",f1);
					
					if (o1 == 0)
						printf ("Osman Gazi ship (O) has sunk!");
					
					getch();
					system("cls");
					
					turn = 2;
		 			break;
				}
				case 'S':
				{
		 			gameBoard1[i][j] = '*';
		 			
		 			counter++;
		 			counter2++;
		 			
		 			printMove2();
					
					printf ("SHOT !\n");
					
					s1--;
					f1--;
					
					printf ("\nTotal ship cells for player 1: %d\n",f1);
					
					if(s1 == 0)
						printf ("Sancaktar ship (S) has sunk!");
					
					getch();
					system("cls");
					
					turn = 2;
					break;
				}
				case 'A':
				{
					gameBoard1[i][j] = '*';
					
					counter++;
					counter2++;
					
		 			printMove2();
					
					printf ("SHOT !\n");
					
					a1--;
					f1--;
					
					printf ("\nTotal ship cells for player 1: %d\n",f1);
					
					if(a1 == 0)
						printf ("Anadolu ship (A) has sunk!");
					
					getch();
					system("cls");
					
					turn = 2;
					break;
				}
				case '*':
				{
					printf ("Unvalid shot. Try again.");
					turn = 2;
					break;
				}
				case 'm':
				{
					printf ("Unvalid shot. Try again.");
					turn = 2;
					break;
				}
			}
		}
		else
		{
			gameBoard1[i][j] = 'm';
			
			counter++;
			counter2++;
			
			printMove2();
			
			printf ("MISS !\n");
			printf ("\nTotal ship cells for player 1: %d\n",f1);
			
			getch();
			system("cls");
			
			turn = 1;
		}
	}
}
void endgame() 
{
	system("cls");
	
	if (f2 == 0)
	{
		printf ("Player 1 won!\n");
		printf ("Thanks for playing!");
	}
	else if (f1 == 0)
	{
		printf ("Player 2 won!\n");
		printf ("Thanks for playing!");
	}
	else
    {
        printf("Game ended unexpectedly.\n");
    }
}