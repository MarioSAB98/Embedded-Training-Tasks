#include "app.h"
#include <stdio.h>
#include "../Card/card.c"
#include "../Server/server.c"

#define SPACER "___________________________________________________\n"

void appStart(void){
    initalizeAccountsDatabase();
    printf(SPACER);
    printf("\n              Welcome to ABC Bank         \n");
    printf(SPACER);


    // Initiating card module
    ST_cardData_t creditCard;

    while (getCardHolderName(&creditCard) == WRONG_NAME)
    {
        printf("!!!     Invalid name! It should be 20 letters min. and 24 letters max.\n");
    }
    printf(SPACER);

    while (getCardExpiryDate(&creditCard) == WRONG_EXP_DATE)
    {
        printf("!!!     Invalid date! The date should contain:\n");
        printf("- Month with 2 digits (e.g: 01 for Jan)\n");
        printf("- Forward slash (/)!\n");
        printf("- Year with 2 digits (e.g: 22 for 2022)\n");
    }
    printf(SPACER);
    
    while (getCardPAN(&creditCard) == WRONG_PAN)
    {
        printf("!!!     Invalid PAN! It should be from 16-19 digits\n");
    }
    printf(SPACER);


    //Initiating terminal module
    ST_terminalData_t terminal;
    
    getTransactionDate(&terminal);
    
    if(isCardExpired(&creditCard, &terminal) == EXPIRED_CARD)
    {
        printf("!!!     Declined transaction!\nExpired Card\n");
        printf(SPACER);
        return;
    }
    
    while(setMaxAmount(&terminal) == INVALID_MAX_AMOUNT)
    {
        printf("!!!     Invalid max amount! It should be greater than 0\n");
    }

    while(getTransactionAmount(&terminal) == INVALID_AMOUNT)
    {
        printf("!!!     Invalid amount! It should be greater than 0\n");
    }

    if(isBelowMaxAmount(&terminal) == EXCEED_MAX_AMOUNT)
    {
        printf("!!!     Declined transaction! Exceeded max amount\n");
        printf(SPACER);
        return;
    }else{
        ST_transaction_t *transData;
        transData ->cardHolderData = creditCard;
        transData ->terminalData = terminal;
        transData ->transState = DECLINED;
        transData ->transactionSequenceNumber = transactionSeq;
        recieveTransactionData(&transData);
    }



    //Initiating server module
    

    


}

int main(){

    appStart();
}