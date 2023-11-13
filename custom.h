void password(char pwd[], int n){
	int x;
	for(x=0; x<n;x++){				// n= size of password
	pwd[x] = getch();
	
	if(pwd[x] != 8 && pwd[x] != 13){				// 8 means backspace
	printf("*");	
	}
	else if(pwd[x] == 13){			// 13 meas enter key
		x--;
	}
	else{
	printf("\b \b");
	x -=2;
	}
}
}
