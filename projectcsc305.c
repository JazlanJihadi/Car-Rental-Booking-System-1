#include<stdio.h>
#include<conio.h>
#include<string.h>
   int status;
   char password[15];
   int cont;
   char name[50],licenseNum[14],carName[20];
   char contactNum[15],dayStart[30],dayEnd[30];
   int  rent,i,j;
   int  choice,choose,carChoose;
   float prices,tot=0,price;
   int  park[14][5];

int myvi=15,exora=10,viva=20,kancil=15,kelisa=10;

void welcome()
{
   printf("WELCOME \n");
   printf("Enter 1 to continue or 0 to exit:");
   scanf("%d",&choice);
}

int statusType()
{
   printf("WELCOME \n");
   printf("Enter 1 for user and 0 for admin:");
   scanf("%d",&status);

   return status;
}

void carsLocationInParkingLot()
{
    for (i = 0; i < 14; ++i)
   {
   	if(i%2==0)
    {  	printf("\n");}
   	printf("\nRow %d \t",(i+1));
     { 	for (j = 0; j < 5; ++j)
		{		printf("*  ");}}
   }
   printf("/n");
   printf("\nRow  1 until  3 are myvi\n");
   printf("Row  4 until  5 are exora\n");
   printf("Row  6 until  9 are viva\n");
   printf("Row 10 until 12 are kancil\n");
   printf("Row 13 until 14 are kelisa\n");
   printf("\n\nPress any button to continue.");
}

void menu()
{
   printf("\nEnter your choice:\n");
   printf("1. Reserve vehicles \n");
   printf("2. Contact Us \n");
   printf("3. Location of Car in Parking lot with the current amount of car \n");
   printf("4. Exit \n");
   printf("Enter your choice:");
   scanf("%d",&choose);
}

//void parking()
//{
//}

//void reserveReceipt()
//{
//}
void printDataAdmin(float price)
{
   printf("\n\n");
   printf("\nName            :%s" ,name);
   printf("\nLicense number  :%s"   ,licenseNum);
   printf("\nEnter car name  :%s"   ,carName);
   printf("\nContact Number  :%s"   ,contactNum);
   printf("\nDays rent       :%d"   ,rent);
   printf("\nDays Start Rent :%s"   ,dayStart);
   printf("\nDays End Rent   :%s"   ,dayEnd);
   printf("\nPrice           :RM %.2f",price);
}

float reservations()
{
   printf("\nEnter name:");
   scanf("%s",&name);
   printf("\nLicense number:");
   scanf("%s",&licenseNum);
   printf("\nEnter car choice(1-Viva, 2-Myvi, 3-Exora, 4-kancil, 5-kelisa):");
   scanf("%d",&carChoose);
   printf("\nContact Number:");
   scanf("%s",&contactNum);
   printf("\nDays rent:");
   scanf("%d",&rent);
   printf("\nDays Start Rent (days/month/year):");
   scanf("%s",&dayStart);
   printf("\nDays End Rent(days/month/year):");
   scanf("%s",&dayEnd);
   //	parking();
   switch(carChoose)
   {
   	case 1:
      		viva=viva-1;
            prices=100.0;
         	strcpy(carName,"Viva");
   			break;
   	case 2:
   			myvi=myvi-1;
            prices=120.0;
         	strcpy(carName,"Myvi");
   			break;
   	case 3:
      		exora=exora-1;
            prices=200.0;
         	strcpy(carName,"Exora");
   			break;
   	case 4:
      		kancil=kancil-1;
            prices=50.0;
         	strcpy(carName,"Kancil");
   			break;
   	case 5:
      		kelisa=kelisa-1;
            prices=70.0;
         	strcpy(carName,"Kelisa");
   			break;
   }
   prices=rent*prices;
   printDataAdmin(prices);
   return prices;
}

void vehiclesName()
{
   printf("\nVehicle that we have:\n");
   printf("1. Viva    RM100/day		%d left\n",viva);
   printf("2. Myvi    RM120/day		%d left\n",myvi);
   printf("3. Exora   RM200/day		%d left\n",exora);
   printf("4. Kancil  RM50/day		%d left\n",kancil);
   printf("5. Kelisa  RM70/day		%d left\n",kelisa);
}

void contactUs()
{
  	printf("\nContact us :\n");
  	printf("013-6432648\n011-123456789\n");
	printf("\ncar_rent@gmail.com\ncarrent.com\n");
    printf("\n\nPress any button to continue.");
}


int main()
{
	do
  	{
   		int stat=statusType();
   		if(stat==1)
  		{
			welcome();
			while(choice==1)
			{
  	    		menu();
      			if(choose==1)
      			{
        			vehiclesName();
        			printf("\n");
      		    	tot=tot+reservations();
        			printf("\n");
      			}
      			else if(choose==2)
         		{
      				contactUs();
      		
      			}
      			else if(choose==3)
      			{
        			carsLocationInParkingLot();
        			printf("/n");
      			}
      			else
      				break;
   			}
   			printf("\n Thank you for using our service :)");
   		}
   		else if(stat==0)
   		{	
		    printf("\nEnter password to continue:");
   			scanf("%s",&password);
   			if(strcmp(password,"ADMIN")==0)
   			{
   				printf("\n\n\nThe total income of the day : RM %.2f",tot); 
   			}
   			else if(strcmp(password,"ADMIN")!=0)
   			{
   				printf("\n\n\n ERROR LOGGING IN ( INCORRECT PASSWORD )"); 
   			}
		}
		else
			break;	 
   		printf("\n\nDo you want to do another action(0=yes/1=no):");
   		scanf("%d",&cont);
  	}while(cont==0);
   	getch();
   	return 0;
}



