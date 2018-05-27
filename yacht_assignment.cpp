#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int rolladice();
int playhuman(int);
int playcomp();
int scoresheet(int,int,int,int,int,int);
int compstrat(int,int,int,int,int);

int main()
{
	
	static int totalhuman=0,totalcomp=0,ban1=0,ban1c=0,ban2=0,ban2c=0,ban3=0,ban3c=0,ban4=0,ban4c=0,ban5=0,ban5c=0,ban6=0,ban6c=0,ban7=0,ban7c=0,ban8=0,ban8c=0,ban9=0,ban9c=0,ban10=0,ban10c=0,ban11=0,ban11c=0,ban12=0,ban12c=0;
	int playerrand,machinerand,round=1;
	srand(time(NULL));
	printf("Welcome to the Yacht game.\nLets see who is lucky!\n");
	playerrand=rolladice();
	machinerand=rolladice();
	while(machinerand==playerrand)
		machinerand=rolladice();
	printf("Player: %d - Machine: %d",playerrand,machinerand);
	if (playerrand>machinerand)
		printf("\nPlayer is the lucky one, lets get started!");
	else 
		printf("\nMachine is the lucky one, lets get started!\n");
	if(machinerand>playerrand){
	while (round<=12)
	{
		printf("\nRound: %d\n======================================\n",round);
		
		playcomp();
		playhuman(3);
		round++;
	}	
}
else{
	while (round<=12)
	{
		printf("\nRound: %d\n======================================\n",round);
		playhuman(3);
		playcomp();
		round++;
	}	
}
	if (totalhuman>totalcomp) printf("\n You win !!!");
	else printf("\n Computer win !!");
	return 0;
}

int rolladice()
{
	return (rand()%5+1);
}

int playhuman(int)
{
	int static b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11;
	int scrule,dice1,dice2,dice3,dice4,dice5,roundres;
	char yesno;
	printf("\nRolled the dice for you:");
	dice1=rolladice();
	dice2=rolladice();
	dice3=rolladice();
	dice4=rolladice();
	dice5=rolladice();
	printf("\nDice1: %d Dice2: %d Dice3: %d Dice4 %d Dice5: %d",dice1,dice2,dice3,dice4,dice5);
	printf("\nDo you want to roll or not (Y/N): ");
	fflush(stdin);
	scanf("%c",&yesno);
	while (yesno!='Y' && yesno!='N')
	{
		printf("You should enter Y for yes and N for no: ");
		fflush(stdin);
		scanf("%c",&yesno);
	}
	if (yesno=='Y')
	{
		dice1=rolladice();
		dice2=rolladice();
		dice3=rolladice();
		dice4=rolladice();
		dice5=rolladice();
		printf("\nDice1: %d Dice2: %d Dice3: %d Dice4 %d Dice5: %d",dice1,dice2,dice3,dice4,dice5);
		printf("\nDo you want to roll or not (Y/N): ");
		fflush(stdin);
		scanf("%c",&yesno);
		if (yesno=='Y')
		{
			dice1=rolladice();
			dice2=rolladice();
			dice3=rolladice();
			dice4=rolladice();
			dice5=rolladice();
			printf("\nDice1: %d Dice2: %d Dice3: %d Dice4 %d Dice5: %d",dice1,dice2,dice3,dice4,dice5);
		}
	}
	printf("\n1: ones\n2: twos\n3: threes\n4:fours\n5: fives\n6: sixes\n7: full house\n8: four_of_a_kind\n9: littlestraight\n10: big straight\n11: choice\n12: yacht\nWhich scoring rule(from above) you would like to use:");
	scanf("%d",&scrule);
	while(scrule<1 || scrule>12 || scrule==b1 ||scrule==b2 || scrule==b3 ||scrule==b4 || scrule==b5 || scrule==b6 || scrule==b7 || scrule==b8 || scrule==b9 ||scrule==b10|| scrule==b11){
		printf("%INVALID RULE\n");
		scanf("%d",&scrule);
	}
	switch(scrule){
		case 1:b1=scrule;break;
		case 2:b2=scrule;break;
		case 3:b3=scrule;break;
		case 4:b4=scrule;break;
		case 5:b5=scrule;break;
		case 6:b6=scrule;break;
		case 7:b7=scrule;break;
		case 8:b8=scrule;break;
		case 9:b9=scrule;break;
		case 10:b10=scrule;break;
		case 11:b11=scrule;break;
	}
	roundres=scoresheet(scrule,dice1,dice2,dice3,dice4,dice5);
	int static totalhuman=0;
	totalhuman+=roundres;
	printf("Your score is : %d and you total is %d",roundres,totalhuman);
}
int playcomp()
{
	int scrule,dice1,dice2,dice3,dice4,dice5,roundres;
	char yesno;
	printf("\n\n\nRolled the dice for computer:");
	dice1=rolladice();
	dice2=rolladice();
	dice3=rolladice();
	dice4=rolladice();
	dice5=rolladice();
	printf("\nDice1: %d Dice2: %d Dice3: %d Dice4 %d Dice5: %d",dice1,dice2,dice3,dice4,dice5);
	printf("\nRule %d is used!",compstrat(dice1,dice2,dice3,dice4,dice5));
	roundres=scoresheet(compstrat(dice1,dice2,dice3,dice4,dice5),dice1,dice2,dice3,dice4,dice5);
	int static totalcomp=0;
	totalcomp+=roundres;
	printf("\nComputer score is : %d and computer total is %d",roundres,totalcomp);
}
int scoresheet(int scrulez,int dice1z,int dice2z,int dice3z,int dice4z,int dice5z)
{
	int dicesum;
	if (scrulez<=6)
	{
		if (scrulez!=dice1z)
			dice1z=0;
		if (scrulez!=dice2z)
			dice2z=0;
		if (scrulez!=dice3z)
			dice3z=0;
		if (scrulez!=dice4z)
			dice4z=0;
		if (scrulez!=dice5z)
			dice5z=0;
		dicesum=dice1z+dice2z+dice3z+dice4z+dice5z;
		return dicesum;
	}
    if(scrulez==7)
	{
		int check1=1,check2=1;
		if(dice1z==dice2z) check1++;
		else
			{
			if(dice2z==dice3z)check2++;
			if(dice2z==dice4z)check2++;
			if(dice2z==dice5z)check2++;
			}
		if(dice1z==dice3z)check1++;
		else
		{
			if(dice3z==dice4z)check2++;
			if(dice3z==dice5z)check2++;
		}
		if(dice1z==dice4z)check1++;
		else
		{
			if(dice4z==dice5z)check2++;
		}
		if(dice1z==dice5z)check1++;
		if((check1==3 &&check2==2) || (check2==3 && check1==2))
		{
			return dice1z+dice2z+dice3z+dice4z+dice5z;
		}
		else 
		{
			return 0;
		}
	}
	if (scrulez==8)
	{
		if (dice1z!=dice2z)
		{
			if (dice2z==dice3z && dice3z==dice4z && dice4z==dice5z) return dice2z+dice3z+dice4z+dice5z ;
			else if (dice1z==dice3z && dice1z==dice4z && dice1z==dice5z) return dice1z+dice3z+dice4z+dice5z ;		
			else return 0;		
		}
			else if (dice2z!=dice3z)
		{
			if (dice1z==dice3z && dice3z==dice4z && dice4z==dice5z) return dice1z+dice3z+dice4z+dice5z ;
			else if (dice2z==dice1z && dice2z==dice4z && dice2z==dice5z) return dice1z+dice2z+dice4z+dice5z ;		
			else return 0;				
		}
		else if (dice3z!=dice4z)
		{
			if (dice1z==dice3z && dice2z==dice3z && dice3z==dice5z) return dice1z+dice3z+dice2z+dice5z ;
			else if (dice4z==dice1z && dice2z==dice4z && dice4z==dice5z) return dice1z+dice2z+dice4z+dice5z ;		
			else return 0;				
		}
		else if (dice4z!=dice5z)
		{
			if (dice4z==dice2z && dice2z==dice1z && dice4z==dice3z) return dice1z+dice3z+dice4z+dice2z ;
			else if (dice5z==dice1z && dice2z==dice1z && dice5z==dice3z) return dice1z+dice2z+dice3z+dice5z ;		
			else return 0;				
		}
	}
	if (scrulez==9)
	{		
		if (dice1z!=dice2z!=dice3z!=dice4z!=dice5z)
			if((dice1z+dice2z+dice3z+dice4z+dice5z)==15)
				dicesum=30;
	}
	if (scrulez==10)
	{
		if (dice1z!=dice2z!=dice3z!=dice4z!=dice5z)
			if((dice1z+dice2z+dice3z+dice4z+dice5z)==20)
				dicesum=30;
		
	}
	if (scrulez==11)

		dicesum=dice1z+dice2z+dice3z+dice4z+dice5z;
	if (scrulez==12)
	{
		if (dice1z==dice2z==dice3z==dice4z==dice5z)
			dicesum=50;
	}
	return dicesum;		
}
int compstrat(int dice1z,int dice2z,int dice3z,int dice4z,int dice5z)
{
	int static b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11;
	int i,x=0,m;
	for (i=0;i<=12;i++)
	{	
		if(i!=b1 && i!=b2 &&i!=b3&&i!=b4&&i!=b5&&i!=b6&& i!=b7 &&i!=b8&&i!=b9&&i!=b10&&i!=b11){
		
		if (x<scoresheet(i,dice1z,dice2z,dice3z,dice4z,dice5z))
		{
			x=scoresheet(i,dice1z,dice2z,dice3z,dice4z,dice5z);
			m=i;
		}
	}
	}
	switch(m){
		case 1:b1=m;break;
		case 2:b2=m;break;
		case 3:b3=m;break;
		case 4:b4=m;break;
		case 5:b5=m;break;
		case 6:b6=m;break;
		case 7:b7=m;break;
		case 8:b8=m;break;
		case 9:b9=m;break;
		case 10:b10=m;break;
		case 11:b11=m;break;
	}
	return m;	
}
