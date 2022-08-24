#include "terminal.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

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


EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData){

    uint8_t *PAN;
    PAN = cardData->primaryAccountNumber;
    int length = strlen(cardData->primaryAccountNumber);
    
    int sum=0, checkSumControl;
    int luhnHelperValues[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    uint8_t multBy2 = 1;
    
    for(int i=length-2; i>=0; i--){
        int numi = PAN[i] - '0';
        if(multBy2){
            sum += luhnHelperValues[numi];
        }
        else{
            sum += numi;
        }
        multBy2 = (multBy2) ? 0 : 1;
    }
    checkSumControl = (10 - (sum % 10)) % 10;
    if(checkSumControl == (PAN[length-1]-'0')){
        printf("%d %d Valid", sum, checkSumControl);
        return TERMINAL_OK;
    }
    else{
        printf("%d %d Not Valid", sum, checkSumControl);
        return INVALID_CARD;
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