#include <stdio.h>
#include <string.h>
#include "custom.h"
#include <windows.h>


int n_acc();
int zakat();
int Bill_payment();
void Transaction();
void view_list();
void update_info();


struct date
{
	int day,year,month;
};

struct info{
	char name[50],address[100],type[20];
	int age,a_no;
	long int phone,nic;
	float T_amount;
	struct date d1,d2;
}form;

int main()
{
	int choice;
	
	int a, breaker =0, c, d, e, x ;
	char usn[20], pwd[8];
	
	char dummy_usn[] = "blue babe";
	char dummy_pwd[] = "rockstar";

	login:
	printf("\n");
	printf("\t\t\t\t***********************\n"); 	
	printf("\t\t\t\tBank management system\n");
	printf("\t\t\t\t***********************\n");
	printf("\n\n");
	printf("\t\t\t\tLogin to Account\n");
	
	printf("\n\t\t\t\tuser name: ");
	gets(usn);
	
	printf("\t\t\t\tPassword : ");
	password(pwd, 8);
	

	printf("\n\n\n\n");
	printf("checking your account info loading/");	
	
	for(x = 0; x<8; x++)
	{
		if(pwd[x] == dummy_pwd[x] && usn[x] == dummy_usn[x])
		{
			printf(".");
			sleep(1);
		}
		else
		{
			printf("\n\nIncorrect User name or password");
			sleep(5);
			breaker = 1;
			break;
		}
	}
	
	if(breaker == 1)
	{
		system("cls");
		goto login;
	 }
	else{
		printf("\n\nSuccess !");
		

		do{
			system("cls");
			printf("\t\t\t\t\t\t\t\t\t Welcome To Daily Utility Bank\n");
			printf("\n\t\t\t\t\t\t\t\t\t ## Main Menu ##\n\n");
			printf("\n\t\t\t\t\t\t\t\t\t(1) Create New Account");
			printf("\n\t\t\t\t\t\t\t\t\t(2) Transactions");
			printf("\n\t\t\t\t\t\t\t\t\t(3) Update Existing Account");
			printf("\n\t\t\t\t\t\t\t\t\t(4) View Customer List");
			printf("\n\t\t\t\t\t\t\t\t\t(5) Zakat and Donations");
			printf("\n\t\t\t\t\t\t\t\t\t(6) Bill Payment");
			printf("\n\t\t\t\t\t\t\t\t\t(7) Exit"); 
			printf("\n Please Enter Your Choice");
			scanf("%d",&choice);
			system("cls");
			
			switch (choice)
			{
    			case 1:

        			printf("\t\t\t\t\t\t\t\t\t =========== Create new account ===========") ;
        			n_acc();
					break;
		
				case 2:
					
					printf("\t\t\t\t\t\t\t\t\t =========== TRANSACTIONS ===========");
					Transaction();
					break;
					
				case 3:
					update_info();
					break;
					
				case 4:
					printf("\t\t\t\t\t\t\t\t\t =========== CUSTOMERS LIST ===========\n");
					view_list();
					break;
		
				case 5:
					
					printf("\t\t\t\t\t\t\t\t\t =========== ZAKAT PORTAL ===========");
					zakat();
	    			break;	
	    
				case 6:
					
					Bill_payment();
					break;
			}
			
		}while(choice!=7);
	}
	
}

//============================================== functions are starting from there ====================================================

//---------------------------------------------------- create new account --------------------------------------------------------------
int n_acc()
{
	int chose;
	
	printf("\nEnter your name: ");
	scanf(" %s",&form.name);
	
	printf("\nEnter your date of birth (mm/dd/yy):");
	scanf("%d/%d%/%d",&form.d1.month,&form.d1.day,&form.d1.year);
	
	printf("\nEnter your Age:");
	scanf("%d",&form.age);
	
	printf("\nPlease Enter Your Current Address: ");
	scanf(" %s",&form.address);
	
	printf("\nEnter phone number: ");
	scanf("%ld",&form.phone);
	
	printf("\nEnter NIC number: ");
	scanf("%ld",&form.nic);
	
	printf("\nEnter Todays Date (mm/dd/yy): ");
	scanf("%d/%d%/%d",&form.d2.month,&form.d2.day,&form.d2.year);
	
	printf("\nEnter account number: ");
	scanf("%d",&form.a_no);
	
	printf("\nEnter amount you want to deposit: ");
	scanf("%f",&form.T_amount);
	
	printf("\nEnter type of account\n(1) for saving\n(2) for current\n(3) fixed1(for 1 year)\n(4) fixed2(for 2 year)\n(5) fixed3(for 3 year): ");
	scanf("%d",&chose);
	printf("\n\n\n");
	    printf("\n%6ld\t %10s\t\t\t%10s\t\t%ld",form.a_no,form.name,form.address,form.phone);

	
	switch (chose)
	{
		case 1:
			strcpy(form.type,"saving");
			break;
			
		case 2:
			strcpy(form.type,"current");
			break;
			
		case 3:
			strcpy(form.type,"fixed1(for 1 year)");
			break;
			
		case 4:
			strcpy(form.type,"fixed2(for 2 year)");
			break;
			
		case 5:
			strcpy(form.type,"fixed3(for 3 year)");
			break;
		
	}

}


//---------------------------------------------------------- zakat portal ---------------------------------------------------

int zakat(){
	int i,choice,choice1,donate,Ano;
    float zak;
    char org[50];
    long int acc;
	
	printf("\n(1) For Zakat \n(2)For Donations or Any Type of Charity");
	scanf("%d",&choice);
	
	switch(choice){
		
	    case 1:	
	    
	    	printf("\n Please! Enter account number: ");
			scanf("%ld",&acc);
	    	
			
	        if(form.T_amount>=65000){
	    		
			printf("\nYou are Eligible for Zakat\n");
			printf("\nPress(1) Pay Zakat Through Bank\nPress(2) Pay Zakat By Yourself");
			scanf("%d",&choice1);
			
			switch(choice1)
			{
				case 1:
					
					zak=((form.T_amount*2.5)/100);
					form.T_amount-=zak;
					printf("\nYour Zakat Amount is: %.3f",zak);	
                	printf("\nYour Remaining Amount is: %.3f",form.T_amount);	
					break;
					
				default:
					break;
			}
		}
			
			else {
				printf("\nYou are Not Eligible For Zakat");
			}
			break;
			
		case 2:
		
			printf("\nPlease Enter The Amount You Want To Donate: ");
			scanf("%d",&donate);
			
			if (form.T_amount < donate)
			{
				printf("\nYou have insufficient amount.....");
			}
			
			else
			{
				printf("Please Enter The NGO/Organization You Want To Donate:");
				scanf(" %s",&org);
				printf("\nPlease Enter The Account No. Of NGO: ");
				scanf("%d",&Ano);
		
				printf("\nsending");
			for(i=0;i<4;i++){
				sleep(1);
				printf(".");		
			}
			form.T_amount-=donate;
		printf("\n Rs %d has been sent to %s ,Account No. %d succesfully!",donate,org,Ano);
		}
		
}
}

//--------------------------------------------------------- BILLS --------------------------------------------------------------

int Bill_payment()
{
	int choice;
	long int acc,bill,kesc,ssgc,i;
	float amount;
	
	printf("\n1. Electricity bill\n2. Gas bill\n\nEnter choice: ");
	scanf("%d",&choice);
	
	printf("\nPlease! Enter account number: ");
	scanf("%ld",&acc);
	
	printf("\nPlease! Enter Bill number: ");
	scanf("%ld",&bill);
	
	switch(choice)
	{
		case 1:
			
			
			printf("\nPlease! Enter account number of  Electricity Supply Company: ");
			scanf("%ld",&kesc);
			
			printf("\nEnter amount: ");
			scanf("%f",&amount);
			
			form.T_amount-=amount;
			
			printf("\n\nProcessing");
			for(i=0;i<4;i++){
				sleep(1);
				printf(".");		
			}
			printf("\n'BILL is paid Successfully' ");
			printf("\n\nBill Amount is: %.3f",amount);	
			printf("\nYour Remaining Amount is: %.3f",form.T_amount);
			break;
			
		case 2:
			
			
			printf("\nPlease! Enter account number of Gas Supply Company: ");
			scanf("%ld",&ssgc);
			
			printf("\nEnter amount: ");
			scanf("%f",&amount);
			
			form.T_amount-=amount;
			
			printf("\n\nProcessing");
			for(i=0;i<4;i++){
				sleep(1);
				printf(".");		
			}
			printf("\n'BILL is paid Successfully' ");
			printf("\n\nBill Amount is: %.3f",amount);	
			printf("\nYour Remaining Amount is: %.3f",form.T_amount);
			break;
	}
}

//------------------------------------------------------------ TRANSACTIONS -------------------------------------------------------

void Transaction()
{
	int a_num,chose;
	float d_amount,w_amount;
	
	printf("\nEnter the account number of the customer:");
	scanf("%d",&a_num);
	choice:
	system("cls");

	printf("\n (1)Deposit");
	printf("\n (2)Withdraw");
		
	printf("\nEnter your choice ");
	scanf("%d",&chose);
	switch (chose){
		case 1:
			printf("\nEnter the amount you want to deposit: Rs");
			scanf("%f",&d_amount);
			form.T_amount+=d_amount;
			break;
		case 2:
		    printf("\nEnter the amount you want to withdraw: Rs");
			scanf("%f",&w_amount);
			form.T_amount-=w_amount;
			break;
		default:
		printf("\nEnter a valid choice");
		sleep(3);
		goto choice;	
	}
}

//------------------------------------------------------------- CUSTOMER LIST ----------------------------------------------------------

void view_list()
{
   
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

   
    printf("\n%6ld\t %10s\t\t\t%10s\t\t%ld",form.a_no,form.name,form.address,form.phone);
        printf("\n\n\n\npress any key to continue  ");
        getch();
}


void update_info()
{
	int x, y, k = 0, breaker;
		// I'm making update existing account information
		
	char usr[] = {"78b3ebo&"};
	char testpwd[8] = {"        "};
	char pwd[8] = {"87654321"};
	char NewPwd[8] = {"        "};
	char c;

recap:
	//printf("\nthe value of ACSII code of %c is %d \n", a, a);

	printf("\n");
	printf("\t\t\t\t\t***********************\n"); 	
	printf("\t\t\t\t\tBank management system\n");
	printf("\t\t\t\t\t***********************\n");
	//printf("\n\n");
	printf("\n\t\t\t\t\tEnter new information\n");
//	printf("\t\t\t\t----------------------------------");
	fflush(stdin);
	printf("\n\n\t\t\t\t\t user name:   ");
	gets(usr);
	
	printf("\t\t\t\t\t old password: ");
	password(testpwd, 8);
	
	printf("\n\t\t\t\t\t New password:  ");
	password(NewPwd, 8);
	
	
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tchecking information /");	
	for(x=0; x<8;x++){
	k = (testpwd[x] == pwd[x]) ? k : 1;
	printf(".");
	sleep(1);
	}
	
	if(k==1){
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\tIncorrect password");
		sleep(3);
		system("cls");
		goto recap;
	}
	// if you are here, that means you have enter correct password
}
