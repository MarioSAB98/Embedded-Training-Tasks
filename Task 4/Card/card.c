#include "card.h"
#include <string.h>
#include <ctype.h>

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    char name[100];
    printf("Enter card holder name \n");
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
    printf("Enter card expiry date in the form (MM/YY), e.g: 12/12 \n");
    fgets(date, sizeof(date), stdin);
    int length = strlen(date) - 1;
    if (length != 5)
    {
        return WRONG_EXP_DATE;
    }
    else if(date[2] != '/')
    {
        return WRONG_EXP_DATE;
    }
    else if(!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[3]) || !isdigit(date[4]))
    {
        return WRONG_EXP_DATE;
    }
    else if( (date[0] == '0' && date[1] == '0') || (date[0] == '1' && date[1] > '2') || date[0] > '1')
    {
        return WRONG_EXP_DATE;
    }
    else
    {
        strcpy(cardData->cardExpirationDate, date);
        return CARD_OK;
    }
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    char PAN[50];
    printf("Enter card primary account number\n");
    fgets(PAN, sizeof(PAN), stdin);
    int length = strlen(PAN) - 1;
    if (length < 16 || length > 19)
    {
        return WRONG_PAN;
    }
    for(int i=0; i<length; i++){
        if(!isdigit(PAN[i]))
        {
            return WRONG_PAN;
        }
    }
    return CARD_OK;
}