

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

int n_acc(struct info form)
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

void view_list()
{
   
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

   
           printf("\n%6d\t %10s\t\t\t%10s\t\t%d",form.a_no,form.name,form.address,form.phone);
        printf("\n\n\n\npress any key to continue  ");
        getch();
}

