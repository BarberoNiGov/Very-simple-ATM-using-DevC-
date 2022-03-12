// JONRICH B. BASCUG 
// BSCS 1-Y2-1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <conio.h>



//Functions
void login();
void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit();
void errorMessage();
void printMsg();




//Main Code
int main() {
	system("color 3E");
    //Local Declarations
    int option;
    float balance = 20000.00;
    int choose;
    int pin = 1111;
    int tmpPin;
 
    bool again = true;
    // insert code here...
    
    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t  %s\n", ctime(&now));
    printf("          ********** Welcome to Bascug's ATM Banking Machine ***********\n\n");
	printf("                           Please enter your PIN: ");
    
    
    scanf("%d", &tmpPin);
    if (pin != tmpPin)
    {
    	system("CLS");
    	printf(" \n                                  INVALID PIN!");
    	return 0;
	}
    while (again) {
    	system("CLS");
    	
    mainMenu();
 
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);

 
 
        switch (option) {
            case 1:
             system("CLS");
                checkBalance(balance);
                break;
            case 2:
             system("CLS");
                balance = moneyDeposit(balance);
                break;
            case 3:
             system("CLS");
                balance = moneyWithdraw(balance);
                break;
 
            case 4:
             system("CLS");
                menuExit();
                return 0;
 
            default:
                errorMessage();
                break;
        }
 
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Would you like to do another transaction:\n");
        printf("1 > Yes\n");
        printf("2 > No\n\n");
        scanf("%d", &choose);
 
        system("CLS");
 
        if (choose == 2) {
            again = false;
            menuExit();
 
        }
 
}
 
  
    return 0;
}//main code

 
 
 
//Functions

 
void mainMenu() {
	
    printf("                \n");
    printf("               **** Please choose one of the options below ****\n\n");
    printf("               [ 1 ]  Check Balance\n");
    printf("               [ 2 ]  Deposit\n");   
    printf("               [ 3 ]  Withdraw\n"); 
    printf("               [ 4 ]  Exit\n\n");
 
}//Main Menu
 
void checkBalance(float balance) {
    printf("You Choose to See your Balance\n");
    printf("\n\nYour Available Balance is: P%.2f\n\n", balance); 
 
}//Check Balance
 
float moneyDeposit(float balance) {
    float deposit;
    printf("You choose to Deposit a money\n");
    printf("\n\nYour Balance is: P%.2f\n\n", balance);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Enter your amount to DEPOSIT: ");
    scanf("%f", &deposit);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
   
 
 
    balance += deposit;
    system("CLS");
 
    printf("\nYour New Balance is: P%.2f\n\n", balance);
    return balance;
 
}//money deposit


 
float moneyWithdraw(float balance) {
    float withdraw;
    bool back = true;
 
    printf("You choose to Withdraw a money\n");
    printf("\n\nYour Balance is: P%.2f\n\n", balance);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
 
    while (back) {
    printf("Enter your amount to WITHDRAW: ");
    scanf("%f", &withdraw);
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
 
 
    if (withdraw <= balance) {
        back = false;
        balance -= withdraw;
        system("CLS");
        printf("\nYour withdrawing money is: P%.2f\n", withdraw);
        printf("Your New Balance is: P%.2f\n\n", balance);
 
    }
	  
		else {
			system("CLS");
        printf("\nYou have an INSUFFICIENT BALANCE\n");
         printf("Your Balance is: P%.2f\n\n", balance);
    }
}
    return balance;
 
 
}//money withdraw
 
void menuExit() {
    printf("------------------------------ TAKE YOUR RECEIPT -------------------------------\n");
    printf("--------------- THANK YOU FOR USING BASCUG'S ATM BANKING MACHINE ---------------\n");
 
}//exit menu
 
void errorMessage() {;
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n                     !!! YOU SELECTED INVALID NUMBER !!!\n\n");
}//error message
 
 


