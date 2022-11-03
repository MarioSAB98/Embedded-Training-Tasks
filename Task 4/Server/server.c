#include "server.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

ST_accountsDB_t dbAccounts[255];
ST_transaction_t dbTransactions[255]={{0},{0},{0},0};
int AccountRecords=0;
int TransactionsRecords=0;
int accountIndex=-1;
int transactionSeq=100000000;

EN_serverError_t isBlockedAccount (ST_accountsDB_t *accountRefrence){

        if(accountRefrence[accountIndex].state==BLOCKED){
            return BLOCKED_ACCOUNT;
        }else{
            return SERVER_OK;
        }

}

void getIndex(ST_transaction_t *transData){
    int flag =0;
    for(int i=0;i<AccountRecords;i++){
        if(!strcmp(transData->cardHolderData.primaryAccountNumber,dbAccounts[i].primaryAccountNumber)){
            accountIndex=i;
            break;
        }
    }

}


EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence){
    int flag =0;
    for(int i=0;i<AccountRecords;i++){
        if(!strcmp(cardData->primaryAccountNumber,accountRefrence->primaryAccountNumber)){
            flag=1;
            break;
        }
    }
    if (flag){
        return SERVER_OK;
    }else{
        return ACCOUNT_NOT_FOUND;
    }
    
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData){
    
    if(termData->transAmount > dbAccounts[accountIndex].balance){
        return LOW_BALANCE;
    }else{
        return SERVER_OK;
    }
    
}

EN_transState_t recieveTransactionData(ST_transaction_t *transData){
    getIndex(transData);
    ST_terminalData_t *termData=&(transData->terminalData);
    if(isValidAccount(&transData->cardHolderData, &dbAccounts[accountIndex])!=SERVER_OK){
        printf("!!!    It's a Fraud Card");
        return FRAUD_CARD;
    }else if (isAmountAvailable(termData)!=SERVER_OK){
        printf("!!!    It's a Insufficient fund");
        return INSUFFICIENT_FUND;
    }else if (isBlockedAccount(dbAccounts)){
        printf("!!!    It's a stolen card");
        return DECLINED_STOLEN_CARD;
    }else if(saveTransaction(transData)==SAVING_FAILED){
        printf("!!!    Save Failed");
        return INTERNAL_SERVER_ERROR;
    }else{
        printf("!!!    Transaction Approved");
        return APPROVED;
    
    }
    
        
}

EN_serverError_t saveTransaction (ST_transaction_t *transData){
    transData->transactionSequenceNumber=transactionSeq;
    dbTransactions[TransactionsRecords] = *transData;
    transactionSeq++;
    TransactionsRecords++;
    
    if(getTransaction(transactionSeq-1,transData)==SERVER_OK){
        return SERVER_OK;
    }else{
        return SAVING_FAILED;
    }
    
}

EN_serverError_t getTransaction (uint32_t transactionSequenceNumber, ST_transaction_t *transData){
    if(transactionSequenceNumber==transData->transactionSequenceNumber){
        return SERVER_OK;
    }else{
        return TRANSACTION_NOT_FOUND;
    }
}



void initalizeAccountsDatabase(){
    dbAccounts[0] = (ST_accountsDB_t) {2000.0, RUNNING,"1234567890123456"};
    AccountRecords++;
    dbAccounts[1] = (ST_accountsDB_t){100000.0, BLOCKED,"2234567890123456"};
    AccountRecords++;
    dbAccounts[2] = (ST_accountsDB_t){4352.0, RUNNING,"3234567890123456"};
    AccountRecords++;
    dbAccounts[3] = (ST_accountsDB_t){1241.0, BLOCKED,"4234567890123456"};
    AccountRecords++;
    dbAccounts[4] = (ST_accountsDB_t){12.0, RUNNING,"5234567890123456"};
    AccountRecords++;
    dbAccounts[5] = (ST_accountsDB_t){2352642.0, RUNNING,"6234567890123456"};
    AccountRecords++;
    dbAccounts[6] = (ST_accountsDB_t){233.0, BLOCKED,"7234567890123456"};
    AccountRecords++;
    dbAccounts[7] = (ST_accountsDB_t){235325.0, RUNNING,"8234567890123456"};
    AccountRecords++;
    dbAccounts[8] = (ST_accountsDB_t){2354.0, RUNNING,"9234567890123456"};
    AccountRecords++;
    dbAccounts[9] = (ST_accountsDB_t){1412412.0, RUNNING,"0234567890123456"};   
    AccountRecords++;
}