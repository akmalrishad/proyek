// akmal
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct sudoku
	{
	char st;
	char value;
	};

char *level=NULL;

void checking_result(sudoku P[9][9],char *level);
void checking_resultb(sudoku P[6][6]);
void cursor(sudoku B[9][9]);
void cursorb();
void play_option();
void play(sudoku A[9][9],char *level);
void play_beginner();
void play_easy();
void play_medium();
void play_hard();
void exit();

sudoku P[6][6]={ {{'t','2'},{'f','0'},{'t','1'},{'t','6'},{'t','3'},{'t','4'}},
					  {{'f','0'},{'t','4'},{'t','6'},{'t','2'},{'t','5'},{'f','0'}},
					  {{'t','1'},{'t','2'},{'t','5'},{'f','0'},{'t','6'},{'t','3'}},
					  {{'t','4'},{'t','6'},{'t','3'},{'t','5'},{'f','0'},{'t','2'}},
					  {{'f','0'},{'t','1'},{'t','4'},{'f','0'},{'t','2'},{'t','6'}},
					  {{'t','6'},{'t','3'},{'t','2'},{'t','1'},{'f','0'},{'t','5'}}};

sudoku E[9][9]={ {{'t','3'},{'t','1'},{'t','2'},{'f','0'},{'t','9'},{'t','5'},{'f','0'},{'t','7'},{'t','6'}},
					  {{'f','0'},{'f','0'},{'t','9'},{'t','1'},{'f','0'},{'t','7'},{'f','0'},{'t','8'},{'t','2'}},
					  {{'t','4'},{'f','0'},{'t','7'},{'t','2'},{'t','6'},{'t','3'},{'t','5'},{'f','0'},{'f','0'}},
					  {{'t','9'},{'f','0'},{'f','0'},{'t','7'},{'f','0'},{'f','0'},{'t','2'},{'t','4'},{'f','0'}},
					  {{'f','0'},{'t','2'},{'t','8'},{'f','0'},{'t','1'},{'f','0'},{'f','0'},{'t','9'},{'t','3'}},
					  {{'f','0'},{'t','3'},{'f','0'},{'t','9'},{'t','8'},{'t','2'},{'f','0'},{'t','5'},{'t','7'}},
					  {{'f','0'},{'t','4'},{'t','5'},{'t','6'},{'f','0'},{'f','0'},{'f','0'},{'t','3'},{'t','1'}},
					  {{'t','1'},{'t','7'},{'f','0'},{'f','0'},{'t','5'},{'t','8'},{'t','9'},{'f','0'},{'t','4'}},
					  {{'t','8'},{'f','0'},{'t','3'},{'t','4'},{'t','2'},{'f','0'},{'t','7'},{'f','0'},{'t','5'}}};

sudoku H[9][9]={ {{'f','0'},{'f','0'},{'t','5'},{'f','0'},{'f','0'},{'f','0'},{'f','0'},{'f','0'},{'f','0'}},
					  {{'t','4'},{'f','0'},{'f','0'},{'t','5'},{'f','0'},{'f','0'},{'t','1'},{'f','0'},{'t','6'}},
					  {{'f','0'},{'t','2'},{'f','0'},{'t','6'},{'f','0'},{'f','0'},{'f','0'},{'t','4'},{'f','0'}},
					  {{'f','0'},{'t','9'},{'f','0'},{'f','0'},{'f','0'},{'t','3'},{'t','5'},{'t','1'},{'f','0'}},
					  {{'f','0'},{'f','0'},{'t','4'},{'f','0'},{'t','1'},{'f','0'},{'f','0'},{'f','0'},{'f','0'}},
					  {{'t','2'},{'f','0'},{'f','0'},{'t','9'},{'t','8'},{'f','0'},{'f','0'},{'f','0'},{'t','4'}},
					  {{'f','0'},{'t','8'},{'t','1'},{'f','0'},{'f','0'},{'t','4'},{'f','0'},{'t','9'},{'f','0'}},
					  {{'t','3'},{'f','0'},{'f','0'},{'t','8'},{'f','0'},{'f','0'},{'f','0'},{'f','0'},{'t','1'}},
					  {{'f','0'},{'f','0'},{'t','2'},{'f','0'},{'f','0'},{'t','7'},{'f','0'},{'t','6'},{'f','0'}}};

sudoku M[9][9]={ {{'t','3'},{'t','5'},{'f','0'},{'t','2'},{'t','7'},{'f','0'},{'t','6'},{'t','8'},{'f','0'}},
					  {{'t','7'},{'f','0'},{'t','4'},{'f','0'},{'f','0'},{'t','8'},{'f','0'},{'f','0'},{'t','3'}},
					  {{'t','6'},{'t','8'},{'f','0'},{'f','0'},{'f','0'},{'t','5'},{'t','7'},{'f','0'},{'t','1'}},
					  {{'f','0'},{'t','6'},{'t','5'},{'f','0'},{'f','0'},{'t','1'},{'f','0'},{'f','0'},{'f','0'}},
					  {{'t','9'},{'t','3'},{'f','0'},{'f','0'},{'f','0'},{'f','0'},{'f','0'},{'t','4'},{'t','6'}},
					  {{'f','0'},{'f','0'},{'f','0'},{'t','6'},{'f','0'},{'f','0'},{'t','2'},{'t','9'},{'f','0'}},
					  {{'t','2'},{'f','0'},{'t','3'},{'t','7'},{'f','0'},{'f','0'},{'f','0'},{'t','1'},{'t','8'}},
					  {{'t','8'},{'f','0'},{'f','0'},{'t','3'},{'f','0'},{'f','0'},{'t','5'},{'f','0'},{'t','9'}},
					  {{'f','0'},{'t','1'},{'t','7'},{'f','0'},{'t','9'},{'t','4'},{'f','0'},{'t','6'},{'t','2'}}};


void play_option()
{
	char chse,eorb;

	gotoxy(30,4);printf("Select the game");
	gotoxy(32,6);printf("(b)eginner");
	gotoxy(32,7);printf("(e)asy");
	gotoxy(32,8);printf("(m)edium");
	gotoxy(32,9);printf("(h)ard");
	gotoxy(32,10);printf("(g)o exit");

	chse = getch();

	switch(chse)
	{
		case 'b':
		{
			clrscr();
			play_beginner();
			break;
		}
		case 'e':
		{
			clrscr();
			play_easy();
			break;
		}

		case 'm':
		{
			clrscr();
			play_medium();
			break;
		}

		case 'h':
		{
			clrscr();
			play_hard();
			break;
		}

		case 'g':
		{
			exit();
		}

		default:
		{
			clrscr();
			gotoxy(27,14);printf("sorry,it's didn't match");
			gotoxy(27,15);printf("(e)xit or (b)ack to menu?");
			eorb=getch();
			switch(eorb)
			{
				case 'e':
					exit();
					break;
				case 'b':
					play_option();
					break;
			}
		}
	}
}

void play_beginner()
{
	char z=' ';
	int i,j;

	clrscr();

	printf("\t--BEGINNER--\t\n\n");
	printf(" =======================\n");
	for (i=0;i<6;i++)
	{
		printf("| ");
		for (j=0;j<6;j++)
		{
			if(P[i][j].st == 'f')
			{
				printf("%c",z);
			}
			else
			{
				printf("%c",P[i][j].value);
			}
			printf(" | ");
		}
		printf("\n");
		printf(" =======================\n");
	}
	gotoxy(10,9);

	gotoxy(32,3);printf("use a to left");
	gotoxy(32,4);printf("use d to right");
	gotoxy(32,5);printf("use w to up");
	gotoxy(32,6);printf("use s to down");
	gotoxy(32,7);printf("use c to clear");
	gotoxy(32,8);printf("press enter to finish");

	cursorb();
}

void play_easy()
{
	level="EASY";
	play(E,level);
}

void play_medium()
{
	level="MEDIUM";
	play(M,level);
}

void play_hard()
{
	level="HARD";
	play(H,level);
}

void play(sudoku A[9][9],char *level)
{
	char z=' ';
	int i,j;

	clrscr();

	printf("\t\t---%s---\t\t\n\n",level);
	printf(" =================================== \n");
	for (i=0;i<9;i++)
	{
		printf("| ");
		for (j=0;j<9;j++)
		{
			if(A[i][j].st == 'f')
			{
				printf("%c",z);
			}
			else
			{
				printf("%c",A[i][j].value);
			}
			printf(" | ");
		}
		printf("\n");
		printf(" =================================== \n");
	}
	gotoxy(10,9);

	gotoxy(46,3);printf("use a to left");
	gotoxy(46,4);printf("use d to right");
	gotoxy(46,5);printf("use w to up");
	gotoxy(46,6);printf("use s to down");
	gotoxy(46,7);printf("use c to clear");
	gotoxy(46,8);printf("press enter to finish");

	cursor(A);
}


void cursorb()
{
	char curs,play;
	int x=3,y=4,a=0,b=0;
	char z=' ';

	gotoxy(x,y) ;
	play = 'n';
	while (play == 'n')
	{
		curs=getch();
		switch(curs)
		{
			case 's' : {y=y+2;a=a+1;break;}
			case 'a' : {x=x-4;b=b-1;break;}
			case 'w' : {y=y-2;a=a-1;break;}
			case 'd' : {x=x+4;b=b+1;break;}
			case '1' :
			{
				if(P[a][b].st == 'f')
				{
					P[a][b].value = '1';
					printf("1");
				}
				break;
			}
			case '2' :
			{
				if(P[a][b].st == 'f')
				{
					P[a][b].value = '2';
					printf("2");
				}
				break;
			}
			case '3' :
			{
				if(P[a][b].st == 'f')
				{
					P[a][b].value = '3';
					printf("3");
				}
				break;
			}
			case '4' :
			{
				if(P[a][b].st == 'f')
				{
					P[a][b].value = '4';
					printf("4");
				}
				break;
			}
			case '5' :
			{
				if(P[a][b].st == 'f')
				{
					P[a][b].value = '5';
					printf("5");
				}
				break;
			}
			case '6' :
			{
				if(P[a][b].st == 'f')
				{
					P[a][b].value = '6';
					printf("6");
				}
				break;
			}
			case 'c' :
			{
				if (P[a][b].st=='f')
				{
					P[a][b].value='0';
					printf("%c",z);
				}
				break;
			}
			case 13:
			{
				gotoxy(35,12);
				printf("are you sure?(y/n)..");
				scanf("%s",&play);
			} break;

			default  : {x=3;y=4;a=0;b=0;}
		}
		if (x>24 || y==16 || x<2 || y<3)
		{
			x=3;y=4;a=0;b=0;
		}
		gotoxy(x,y);
	}



	checking_resultb(P);
}

void cursor(sudoku B[9][9])
{
	char curs,play;
	int x=3,y=4,a=0,b=0;
	char z=' ';

	gotoxy(x,y) ;
	play = 'n';
	while (play == 'n')
	{
		curs=getch();
		switch(curs)
		{
			case 's' : {y=y+2;a=a+1;break;}
			case 'a' : {x=x-4;b=b-1;break;}
			case 'w' : {y=y-2;a=a-1;break;}
			case 'd' : {x=x+4;b=b+1;break;}
			case '1' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '1';
					printf("1");
				}
				break;
			}
			case '2' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '2';
					printf("2");
				}
				break;
			}
			case '3' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '3';
					printf("3");
				}
				break;
			}
			case '4' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '4';
					printf("4");
				}
				break;
			}
			case '5' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '5';
					printf("5");
				}
				break;
			}
			case '6' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '6';
					printf("6");
				}
				break;
			}
			case '7' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '7';
					printf("7");
				}
				break;
			}
			case '8' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '8';
					printf("8");
				}
				break;
			}
			case '9' :
			{
				if(B[a][b].st == 'f')
				{
					B[a][b].value = '9';
					printf("9");
				}
				break;
			}
			case 'c' :
			{
				if (B[a][b].st=='f')
				{
					B[a][b].value='0';
					printf("%c",z);
				}
				break;
			}
			case 13 :
			{
				gotoxy(46,12);
				printf("are you sure?(y/n)..");
				scanf("%s",&play);
			}
			break;

			default  : {x=3;y=4;a=0;b=0;}
		}
		if (x>36 || x<2 || y<3 || y>20)
		{
			x=3;y=4;a=0;b=0;
		}
		gotoxy(x,y);
	}

	checking_result(B,level);
}

void exit()
{
clrscr();gotoxy(35,12);printf("Thank You");exit(0);
}

void checking_result(sudoku P[9][9],char *level)
{
	int i,j,k,ketemu,ketemu2;
	char yorn,yorn1;
  //cek baris
	i=0;
	ketemu=0;
	while (i<9 && ketemu ==0)
	{
		j=0;
		while (j<9 && ketemu ==0)
		{
			k=0;
			while (k<j && ketemu ==0)
			{
				if (P[i][j].value==P[i][k].value)
				{
					ketemu=1;
				}
				else k++;
			}
			j++;
		}
		i++;
	}
	//cek kolom

	j=0;
	ketemu2=0;

	while (j<9 && ketemu2 ==0)
	{
		i=0;
		while (i<9 && ketemu2 ==0)
		{
			k=0;
			while (k<i && ketemu2 ==0)
			{
				if (P[i][j].value==P[k][j].value)
				{
					ketemu2=1;
				}
				else k++;
			}
			i++;
		}
		j++;
	}

	if ((ketemu==1)||(ketemu2==1))
	{
		clrscr();
		printf("you wrong,try again?(y/n)");
		yorn=getch();
		if (yorn == 'y')
		{
			clrscr();
			play(P,level);
		}
		else
		{
			clrscr();
			printf("do you want to exit?(y/n)");
			yorn1=getch();
			if(yorn1=='y')
			{
				exit();
			}
			else
			{
				clrscr();
				play_option();
			}






















		}
	}
	else
	{
		clrscr();
		printf("\nSelamaaaaat Anda Menaaaaaaaaaaang!!!!!!!!!!");
			printf("\n\nplay again?(y/n)");
			yorn1=getch();
			if(yorn1!='y')
			{
				exit();
			}
			else
			{
				clrscr();
				play_option();
			}
	}

}

void checking_resultb(sudoku P[6][6])
{
	int i,j,k,ketemu,ketemu2;
	char yorn,yorn1;
  //cek baris
	i=0;
	ketemu=0;
	while (i<6 && ketemu ==0)
	{
		j=0;
		while (j<6 && ketemu ==0)
		{
			k=0;
			while (k<j && ketemu ==0)
			{
				if (P[i][j].value==P[i][k].value)
				{
					ketemu=1;
				}
				else k++;
			}
			j++;
		}
		i++;
	}
	//cek kolom

	j=0;
	ketemu2=0;

	while (j<6 && ketemu2 ==0)
	{
		i=0;
		while (i<6 && ketemu2 ==0)
		{
			k=0;
			while (k<i && ketemu2 ==0)
			{
				if (P[i][j].value==P[k][j].value)
				{
					ketemu2=1;
				}
				else k++;
			}
			i++;
		}
		j++;
	}

	if ((ketemu==1)||(ketemu2==1))
	{
		clrscr();
		printf("you wrong,try again?(y/n)");
		yorn=getch();
		if (yorn == 'y')
		{
			clrscr();
			play_beginner();
		}
		else
		{
			clrscr();
			printf("do you want to exit?(y/n)");
			yorn1=getch();
			if(yorn1=='y')
			{
				exit();
			}
			else
			{
				clrscr();
				play_option();
			}
		}
	}
	else
	{
		clrscr();
		printf("\nSelamaaaaat Anda Menaaaaaaaaaaang!!!!!!!!!!");
			printf("\n\nplay again?(y/n)");
			yorn1=getch();
			if(yorn1=='n')
			{
				exit();
			}
			else
			{
				clrscr();
				play_option();
			}
	}

}


int main()
{
	char opt;

	gotoxy(30,1);printf("SIMPLE SUDOKU GAME");
	gotoxy(30,5);printf("do you want to play?");
	gotoxy(27,20);printf("(click y to play,e to exit)..");opt=getch();

	if (opt == 'y')
		{clrscr();
		play_option();}
		else if (opt == 'e')
		{exit();}
		else {clrscr();gotoxy(30,12);printf("please type right key");}

return 0;
}
