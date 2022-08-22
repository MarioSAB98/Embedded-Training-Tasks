#include <stdio.h>
#include <string.h>
#include <time.h>
#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(termData->transactionDate, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    return TERMINAL_OK;
}


EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData){
    
    uint8_t expMonth[3], expYear[3], currMonth[3], currYear[3];
    
    strncpy(expMonth, &cardData->cardExpirationDate[0], 2);       expMonth[2] = '\0';
    strncpy(expYear, &cardData->cardExpirationDate[3], 2);        expYear[2] = '\0';
    strncpy(currMonth, &termData->transactionDate[3], 2);         currMonth[2] = '\0';
    strncpy(currYear, &termData->transactionDate[8], 2);          currYear[2] = '\0';
    printf("%s %s %s %s\n", expMonth, expYear, currMonth, currYear);

    if(strcmp(expYear, currYear) > 0){
        return TERMINAL_OK;
    }
    else if( strcmp(expYear, currYear) == 0 && strcmp(expMonth, currMonth) >= 0){
        return TERMINAL_OK;
    }
    else{
        return EXPIRED_CARD;
    }
}


EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
    float transAmount = 0.0;
    printf("Enter the transaction amount (e.g: 452.25)\n");
    scanf("%f", &transAmount);
    if(transAmount <= 0){
        termData->transAmount = 0.0;
        return INVALID_AMOUNT;
    }
    else{
        termData->transAmount = transAmount;
        return TERMINAL_OK;
    }
}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){
    if(termData->transAmount > termData->maxTransAmount){
        return EXCEED_MAX_AMOUNT;
    }
    else{
        return TERMINAL_OK;
    }
}


EN_terminalError_t setMaxAmount(ST_terminalData_t *termData){
    float maxTransAmount = 0.0;
    printf("Enter the transaction maximum allowed amount (e.g: 600.0)\n");
    scanf("%f", &maxTransAmount);
    if(maxTransAmount <= 0){
        termData->maxTransAmount = 0.0;
        return INVALID_MAX_AMOUNT;
    }
    else{
        termData->maxTransAmount = maxTransAmount;
        return TERMINAL_OK;
    }
}


int main(){
    ST_terminalData_t termData = {12.0, 15.0, "22/08/2022"};
    ST_cardData_t cardData = {"Mostafa Nasrat Metwally", "1234567890123456", "07/22"};
    //getTransactionDate(&termData);
    //isCardExpired(&cardData, &termData);

}