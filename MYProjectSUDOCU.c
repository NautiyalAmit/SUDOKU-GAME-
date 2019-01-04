#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
	
void display(int a[9][9],int rw[40],int col[40],int l,int n,int moves)
	{
		int i,j,k,flag=0;
		system("cls");
		printf("================================================================================\n");
		printf("\t\t\t    \" WELCOME TO SUDOKU \"\n\n");
		printf(" Developed by   AMIT NAUTIYAL \n\n");
		printf("================================================================================\n");
	
		printf("\n\n________________________________________________________________________________\n");
		//printf(" \t\t\tYou have opt for %dx%d sudoku...\n",n,n);
		printf(" HOW TO PLAY:\n---------------");
		printf("\nFill the grid so that every horizontal row,every vertical column and every %dx3 box contains the digit 1-%d,without repeating the numbers in the same row,column or box.You can't change the digits already given in the grid.Every puzle has one solution.",(n/3),n);
			
		printf(" \n\n GAME INSTRUCTIONS:\n--------------------\n-> Press numbers between 1 to 9 to enter elemnts in sudoku \n-> Press 0 to delete a number at a desired position \n-> Press Q to quit the game\n");
		
		printf("\n________________________________________________________________________________\n");
		printf("\n \t\t\t\t\t\t\tTOTAL MOVES: %d",moves);
		
		
		printf("\n\n\n\n\n");	
		for(i=0;i<((n*4)+1);i++)// display 
		{
			printf("%c",220);
		}
		printf("\n");
			
		for(i=0;i<n;i++)
		{
			printf("%c ",219);
			for(j=0;j<n;j++)
			{
				flag=0;
				if(a[i][j]==0) // printing spaces in place of 0
				{
					if((j+1)%3==0)	// printing |(vertical)character
						{
							printf("  %c ",219);
						}
					else
						printf("  %c ",179);
				}
				else	// printing |(vertical)character
				{
					if((j+1)%3==0)
					{
						for(k=0;k<l;k++)
						{	
							if(i==rw[k]&&j==col[k])
							{
								flag=1;
								break;
							}
						}
						if(flag==1)
							printf("%d.%c ",a[i][j],219);
						else
							printf("%d %c ",a[i][j],219);
					}
					else
					{
						for(k=0;k<l;k++)
						{	
							if(i==rw[k]&&j==col[k])
							{
								flag=1;
								break;
							}
						}
						if(flag==1)
							printf("%d.%c ",a[i][j],179);
						else
							printf("%d %c ",a[i][j],179);
					}		
				}	
			}
		
			printf("\n");
		
			if((i+1)%(n/3)==0) // printing - symbol(horizontally)
			{
				for(k=0;k<((n*4)+1);k++)
				{
					printf("%c",220);
				}
				printf("\n");
			}
			else
			{
				for(k=0;k<((n*4)+1);k++)
				{
					printf("%c",22);
				}
				printf("\n");
			}
		}
	}

int row(int a[9][9],int i,int j,int num,int n)
{
	int k;
	for(k=0;k<n;k++)
	{
		if(k==j)
			continue;
		else if(a[i][k]==num)
			return 0;
	}
		return 1;
}

int column(int a[9][9],int i,int j,int num,int n)
{
	int l;
	for(l=0;l<n;l++)
	{
		if(l==i)
			continue;
		else if(a[l][j]==num)
			return 0;
	}
		return 1;
	
}

int grid(int a[9][9],int i,int j,int num,int n)
{
	int r,c,k,l,ch;
	r=ceil((i+1)/(n/3.0));
	c=ceil((j+1)/3.0);	
	for(k=(r-1)*(n/3);k<((r-1)*(n/3))+(n/3);k++)
	{
		for(l=(c-1)*3;l<((c-1)*3)+3;l++)
		{
			if(i==r&&j==c)
				continue;
			else if(a[k][l]==num)
				return 0;
		}
	}
		return 1;
}

void check(int a[9][9],int n)
{
	int i,j,flag=0,num,ch;

	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			{
				num=a[i][j];
				if(num==0)
				{
						flag=0;
						break;
				}				
				else
				{
					if(row(a,i,j,num,n) && column(a,i,j,num,n) && grid(a,i,j,num,n))
						flag=1;
						
					else
					{
						flag=0;
						break;
					}		
				}
			}
			if(flag==0)
			break;
	}
		if (flag==1)
		{
				printf("\n\n--------------------------------\n");
				printf("Congo...The sudoku is solved");
				printf("--------------------------------\n");
				printf("\n\nHope you have enjoyed the game\n\n");
				ch=getch();
				exit(0);
		}
}

void getdata(int a[9][9],int rw[40],int col[40],int l,int n)
{
	int r,c,num,i,flag=0,moves=0;
					
	while(1)
	{
		aa:
		printf("\n\nEnter the number:");
		num=(getche()-48);
		
		if(num==33||num==65)
		exit(0);
		
		if(num<0||num>n)
		{
			printf("\n\n------------------------------------------\n");
			printf("  Invalid number...enter a valid number:");
			printf("\n------------------------------------------\n");
			goto aa;
		}
		printf("\nEnter the position:");
		tt:
		printf("\n  -> Row:");
		r=(getche()-48);
		if(r==33||r==65)
		exit(0);
		
		printf("\n  -> Column:");
		c=(getche()-48);
		if(c==33||c==65)
		exit(0);
		
		r=r-1;
		c=c-1;
		flag=0;
		if(c>=0&&c<n&&r>=0&&r<n)
		{
			for(i=0;i<l;i++)
			{	
				if(r==rw[i]&&c==col[i])
				{
					flag=1;
					break;
				}
			}
				if(flag==1)
				{
					printf("\n\n-----------------\n");
					printf(" Illegal move...");
					printf("\n-----------------\n\n\n");
					goto aa;
				}
				else
				{	
					a[r][c]= num;
					moves++;
				}
		}
		
		else
		{
			printf("\n\n-----------------------------------\n");
			printf("  Invalid position...Enter again");
			printf("\n-----------------------------------\n");
			goto tt;
		}
		display(a,rw,col,l,n,moves);
		check(a,n);
	}
}


int sud61(int a[9][9],int rw[40],int col[40])
{
	int l=16,i;
	int row[16]={0,0,0,0,1,1,2,2,3,3,4,4,5,5,5,5};
	int colum[16]={0,2,4,5,0,3,1,5,0,4,2,5,0,1,3,5};
	
	a[0][0]=1;a[0][2]=3;a[0][4]=6;a[0][5]=2;a[1][0]=2;a[1][3]=1;a[2][1]=2;a[2][5]=6;
	a[3][0]=3;a[3][4]=5;a[4][2]=2;a[4][5]=5;a[5][0]=6;a[5][1]=1;a[5][3]=3;a[5][5]=4;
	
	for(i=0;i<l;i++)
	{
		rw[i]=row[i];
	}
	for(i=0;i<l;i++)
	{
		col[i]=colum[i];
	}
	return l;
	
}

int sud62(int a[9][9],int rw[40],int col[40])
{
	int l=12,i;
	int row[12]={0,0,1,1,1,2,3,4,4,4,5,5};
	int colum[12]={1,4,0,3,5,1,4,0,2,5,1,4};
	
	a[0][1]=5;a[0][4]=2;a[1][0]=1;a[1][3]=4;a[1][5]=6;a[2][1]=2;a[3][4]=1;a[4][0]=2;a[4][2]=6;a[4][5]=5;a[5][1]=1;a[5][4]=6;
	
	for(i=0;i<l;i++)
	{
		rw[i]=row[i];
	}
	for(i=0;i<l;i++)
	{
		col[i]=colum[i];
	}
	return l;
	
}
int sud63(int a[9][9],int rw[40],int col[40])
{
	int l=12,i;
	int row[12]={0,0,0,1,2,2,3,3,4,5,5,5};
	int colum[12]={0,3,5,2,0,4,1,5,3,0,2,5};
	
	a[0][0]=1;a[0][3]=4;a[0][5]=5;a[1][2]=2;a[2][0]=5;a[2][4]=6;a[3][1]=4;a[3][5]=3;a[4][3]=5;a[5][0]=2;a[5][2]=5;a[5][5]=6;

	for(i=0;i<l;i++)
	{
		rw[i]=row[i];
	}
	for(i=0;i<l;i++)
	{
		col[i]=colum[i];
	}
	
	return l;
	
}

int sud64(int a[9][9],int rw[40],int col[40])
{
	int l=12,i;
	int row[12]={0,0,0,1,2,2,3,3,4,5,5,5};
	int colum[12]={2,3,4,0,0,5,0,5,5,1,2,3};
	
	a[0][2]=5;a[0][3]=6;a[0][4]=3;a[1][0]=4;a[2][0]=5;a[2][5]=2;a[3][0]=6;a[3][5]=3;a[4][5]=6;a[5][1]=2;a[5][2]=6;a[5][3]=5;
	
	for(i=0;i<l;i++)
	{
		rw[i]=row[i];
	}
	for(i=0;i<l;i++)
	{
		col[i]=colum[i];
	}
	return l;
	
}



int sud911(int a[9][9],int rw[40],int col[40])
{
	int l=31,i;
	int row[35]={0,0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,3,3,3,4,4,4,4,6,6,6,7,7,7,7,7};
	int colum[35]={2,3,4,5,7,8,2,4,5,7,0,2,3,4,5,7,0,3,5,2,4,5,7,3,4,5,0,2,4,5,7};
	
	a[0][2]=8;a[0][3]=3;a[0][4]=5;a[0][5]=6;a[0][7]=9;a[0][8]=1;a[1][2]=1;a[1][4]=4;a[1][5]=2;a[1][7]=5;a[2][0]=3;a[2][2]=6;
	a[2][3]=7;a[2][4]=9;a[2][5]=1;a[2][7]=8;a[3][0]=4;a[3][3]=5;a[3][5]=3;a[4][2]=3;a[4][4]=8;a[4][5]=9;a[4][7]=1;a[6][3]=9;
	a[6][4]=7;a[6][5]=5;a[7][0]=9;a[7][2]=7;a[7][4]=1;a[7][5]=4;a[7][7]=6;
	
	for(i=0;i<l;i++)
	{
		rw[i]=row[i];
	}
	for(i=0;i<l;i++)
	{
		col[i]=colum[i];
	}
	return l;
	
}

int sud912(int a[9][9],int rw[40],int col[40])
{
	int l=31,i;
	int row[35]={0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,4,4,5,5,6,6,6,6,6,7,7,8,8,8};
	int colum[35]={1,4,6,8,1,2,4,6,7,8,1,2,3,4,6,7,8,2,3,6,8,2,3,4,7,8,3,6,2,6,8};
	
	a[0][1]=3;a[0][4]=4;a[0][6]=6;a[0][8]=7;a[1][1]=8;a[1][2]=5;a[1][4]=6;a[1][6]=9;a[1][7]=1;a[1][8]=2;a[2][1]=6;a[2][2]=7;
	a[2][3]=9;a[2][4]=8;a[2][6]=3;a[2][7]=5;a[2][8]=4;a[4][2]=3;a[4][3]=1;a[5][6]=2;a[5][8]=6;a[6][2]=6;a[6][3]=5;a[6][4]=9;
	a[6][7]=7;a[6][8]=3;a[7][3]=7;a[7][6]=8;a[8][2]=8;a[8][6]=8;a[8][8]=9;
	
	for(i=0;i<l;i++)
	{
		rw[i]=row[i];
	}
	for(i=0;i<l;i++)
	{
		col[i]=colum[i];
	}
	return l;
	
}

int sud921(int a[9][9],int rw[40],int col[40])
{
	int l=25,i;
	int row[35]={1,1,1,2,2,2,3,3,3,3,3,4,4,4,4,5,5,6,6,7,7,8,8,8,8};
	int colum[35]={2,5,6,0,1,3,2,3,5,6,7,0,1,3,8,2,7,0,3,1,5,0,1,4,7};
	
	a[1][2]=1;a[1][5]=9;a[1][6]=8;a[2][0]=9;a[2][1]=2;a[2][3]=7;a[3][2]=7;a[3][3]=2;a[3][5]=8;a[3][6]=6;a[3][7]=5;a[4][0]=2;
	a[4][1]=8;a[4][3]=6;a[4][8]=4;a[5][2]=5;a[5][7]=3;a[6][0]=7;a[6][3]=4;a[7][1]=5;a[7][5]=6;a[8][0]=4;a[8][1]=9;a[8][4]=5;
	a[8][7]=1;
	
	for(i=0;i<l;i++)
	{
		rw[i]=row[i];
	}
	for(i=0;i<l;i++)
	{
		col[i]=colum[i];
	}
	return l;
	
}

int sud922(int a[9][9],int rw[40],int col[40])
{
	int l=26,i;
	int row[35]={0,0,0,0,1,1,1,1,1,2,3,3,4,4,4,5,5,5,5,5,7,7,7,8,8,8};
	int colum[35]={3,4,5,7,1,4,5,7,8,8,0,8,1,4,8,0,1,4,5,8,3,4,8,1,5,7};
	
	a[0][3]=8;a[0][4]=1;a[0][5]=4;a[0][7]=6;a[1][1]=4;a[1][4]=5;a[1][5]=7;a[1][7]=9;a[1][8]=2;a[2][8]=8;a[3][0]=5;a[3][8]=9;
	a[4][1]=2;a[4][4]=8;a[4][8]=5;a[5][0]=8;a[5][1]=7;a[5][4]=3;a[5][5]=1;a[5][8]=4;a[7][3]=4;a[7][4]=7;a[7][8]=3;a[8][1]=8;
	a[8][5]=2;a[8][7]=7;
	
	for(i=0;i<l;i++)
	{
		rw[i]=row[i];
	}
	for(i=0;i<l;i++)
	{
		col[i]=colum[i];
	}
	return l;
	
}



void gen_default(int n,int sudoku,int ch)
{
	int i,j,l=0,r,c,a[9][9],rw[40],col[40],num,moves=0,temp;

	for(i=0;i<n;i++)// initializing the array to 0
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	
	if(n==9)
	{
		srand(time(NULL));
		temp=(rand()%2+1);
		if(ch==1)
		{
			switch(temp)
			{
				case 1:
					l=sud911(a,rw,col);
					break;
				case 2:
					l=sud912(a,rw,col);
					break;
			}	
		}
		else if(ch==2)
		{
			switch(temp)
			{
				case 1:
					l=sud921(a,rw,col);
					break;
				case 2:
					l=sud922(a,rw,col);
					break;
			}	
		}
	}
	
	else 
	if(n==6)
	{
		srand(time(NULL));
		temp=(rand()%4+1);	
	
		switch(temp)
		{
			case 1:
				l=sud61(a,rw,col);
				break;
			case 2:
				l=sud62(a,rw,col);
				break;
			case 3:
				l=sud63(a,rw,col);
				break;
			case 4:
				l=sud64(a,rw,col);
				break;
		}
	}
	     display(a,rw,col,l,n,moves);	//display function call	
		 getdata(a,rw,col,l,n);	//getdata function call	
}



void main()
{
	int sudoku,choice,n=0,type;
	printf("================================================================================\n");
	printf("\t\t\t    \" WELCOME TO SUDOKU \"\n\n");
	printf(" Developed by ANIRUDH AGARWAL | AMIT NAUTIYAL | AKSHAY NEGI | JAGJEET GAMBHIR\n\n");
	printf("================================================================================\n");
	printf(" GAME INSTRUCTIONS:\n--------------------\n-> Press numbers between 1 to 9 to enter elemnts in sudoku \n-> Press 0 to delete a number at a desired position \n-> Press Q to quit the game\n");
		
	printf("\n\nEnter the choice: \n 1. 6x6 \n 2. 9x9   ");
	pp:
	type=(getch()-48);
	
	if(type==33||type==65)
	exit(0);
	
	if(type!=1&&type!=2)
	goto pp;
	//printf("%d",type);
	srand(time(NULL));
	
	switch(type)
	{
		case 1:
			n=6;
				printf("\n\n________________________________________________________________________________\n");
				printf("\t\t\tYou have opt for 6x6 sudoku...\n");
				printf("");
				printf("________________________________________________________________________________\n");
				sudoku=rand()%3+10;
			break;
		case 2:
			n=9;
				printf("\n\n________________________________________________________________________________\n");
		printf(" \t\t\tYou have opt for 9x9 sudoku...\n");
		printf("________________________________________________________________________________\n");
			printf("Enter the choice: \n 1. Beginner \n 2. Expert \n ");
			pp1:
			choice=(getch()-48);
			
			if(choice==33||choice==65)
			exit(0);
			
			if(choice!=1&&choice!=2)
			goto pp1;
			//printf("\n%d\n",choice);
			switch(choice)
			{
				case 1:
					p1:
					sudoku=rand();
					if(sudoku>40||sudoku<28)
					{
						goto p1;
					}
					//printf("\n%d\n",sudoku);
					break;
				case 2:
					p2:
					sudoku=rand();
					if(sudoku>27||sudoku<20)
					{
						goto p2;
					}
					//printf("\n%d\n",sudoku);
					break;
				default:
					printf("Invalid choice...");
			}

			break;
			
		default:
			printf("Invalid choice...");
	}
	gen_default(n,sudoku,choice);
}

	
	
	

	
