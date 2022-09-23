#include <stdio.h>
#include <stdlib.h>

/*
 * Name: Preet Bhoiwala
 * Date: 9/11/22
 * Class: CIS 2107
 * Assignment: LAB 3 ATM
 * Statement: Write a C Program for an ATM by implementing functions.
 */

//use switch cases


void printTitle();
int pinVerify();
int checkBalance(int balance);
//void menuOptions(int balance);
int cashWithdrawal(int balance);
int cashDeposition(int balance);
void quit();

//int pinNumber = 3014;
//int transactions = 0;
//int balance = 5000;

int main() {
    int pinNumber = 3014;
    int transactions = 0;
    int balance = 5000;


    printTitle();
    pinVerify();
    printf("\n********Welcome to ATM Service**************\n");

    int choice = 0;
    while (choice != 4) {
        printf("\n1.Check Balance\n");
        printf("2.Withdraw Cash\n");
        printf("3.Deposit Cash\n");
        printf("4.Quit\n");
        printf("**********************************************\n\n");
        printf("Enter your choice: ");

//    cashWithdrawal(balance);
//    cashDeposition(balance);
//    quit();

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                checkBalance(balance);
                ++transactions;
                break;

            case 2:
                balance = cashWithdrawal(balance);
                checkBalance(balance);
                ++transactions;
                break;

            case 3:
                balance = cashDeposition(balance);
                checkBalance(balance);
                ++transactions;
                break;

            case 4:
                printf("The number of transactions you made was: %d\n\n", transactions);
                quit();
                break;

        }
    }

}


int pinVerify() {
    int verifyPin = 0;
    int counter = 0;


    for (int i = 0; i < 3; i++) {

        printf("Please enter your pin number: \n");
        scanf("%d", &verifyPin);

        if (verifyPin == 3014) {
            return 0;
        }

        if (verifyPin != 3014) {
            printf("Wrong pin number. Please try again.\n");
            counter += 1;

        }
        if (counter == 3 && verifyPin != 3014) {
            printf("ERROR!");
            exit(0);

        }
    }
}
void printReceipt() {
    int receipt = 0;
    printf("%s", "\nWould you like a receipt?\n\n\t1. Yes\n\t2. No\n\nSelection: ");
    scanf("%d", &receipt);
    if (receipt == 1) {
        printf("Receipt printing...\n");
    } else if (receipt == 2) {
        printf("Okay, no receipt will be printed.");
    }

}



//printing out the checkBalance that nana currently has --> 5000
int checkBalance(int balance) {
    printf("Your current balance is:$%d\n\n", balance);
    printf("\nThanks for using ATM");
    // printReceipt();
}

int cashWithdrawal(int balance) {

  int withdrawAmount = 0;
  int checkWithdrawAttempts = 0;

  for(int i = 0; i < 3; i++) {
      printf("\n\tEnter your withdraw amount: ");
      scanf("%d", &withdrawAmount);
      if(withdrawAmount > 0 && (withdrawAmount % 20 == 0) && withdrawAmount <= 1000) {
          break;
      } else {
          printf("\tInvalid amount entered. Try again.");
          checkWithdrawAttempts += 1;
      } if(checkWithdrawAttempts == 3) {
          printf("You've reached your limit of 3 attempts\n.");
          printf("Thank you for using our ATM");
          exit(0);

      }

  }

  printReceipt();
  balance = balance - withdrawAmount;
  return balance;


}

int cashDeposition(int balance) {
    int depositAmount = 0;
    int checkDepositAttempts = 0;
    for(int i = 0; i < 3; i++) {
        printf("\nEnter the deposit amount: ");
        scanf("%d", &depositAmount);
        if(depositAmount > 0 && (depositAmount < 10000)) {
            break;
        } else {
            printf("Entered invalid amount. Please try again.\n");
            checkDepositAttempts += 1;
        } if (checkDepositAttempts == 3) {
            printf("You've reached your limit of 3 attempts\n.");
            printf("Thank you for using our ATM");

            exit(0);
        }
    }

    printReceipt();
    balance = balance + depositAmount;
    return balance;
}

void quit() {
    printf("\nThank you for banking with us\n");
    exit(0);
}


void printTitle() {
    printf("Welcome!");
    printf("\n");
}