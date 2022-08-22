#include "card.h"
#include <string.h>


EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    char name[100];
    printf("enter card holder name \n");
    fgets(name, sizeof(name), stdin);
    int length = strlen(name) - 1;
    if (length >= 20 && length <= 24)
    {
        strcpy(cardData->cardHolderName, name);
        return CARD_OK;
    }
    else
        return WRONG_NAME;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    char date[10];
    printf("enter card expiry date in the form (MM/YY), e.g: 12/12 \n");
    fgets(date, sizeof(date), stdin);
    int length = strlen(date) - 1;
    if (length != 5)
    {
        return WRONG_EXP_DATE;
    }
    else if(date[2] != "/")
        return WRONG_EXP_DATE;
    else if(date[0] == "/" || date[1] == "/" || date[3] == "/" || date[4] == "/")
        return WRONG_EXP_DATE;
    else
    {
        strcpy(cardData->cardExpirationDate, date);
        return CARD_OK;
    }
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    char PAN[50];
    printf("enter card primary account number\n");
    fgets(PAN, sizeof(PAN), stdin);
    int length = strlen(PAN) - 1;
    if (length >= 16 && length <= 19)
    {
        strcpy(cardData->primaryAccountNumber, PAN);
        return CARD_OK;
    }
    else
        return WRONG_PAN;
}