#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payroll_run_status.h"


char* payroll_run_status_payroll_run_status_ToString(simplebilly_api_payroll_run_status__e payroll_run_status) {
    char *payroll_run_statusArray[] =  { "NULL", "draft", "calculated", "approved", "paid" };
    return payroll_run_statusArray[payroll_run_status];
}

simplebilly_api_payroll_run_status__e payroll_run_status_payroll_run_status_FromString(char* payroll_run_status) {
    int stringToReturn = 0;
    char *payroll_run_statusArray[] =  { "NULL", "draft", "calculated", "approved", "paid" };
    size_t sizeofArray = sizeof(payroll_run_statusArray) / sizeof(payroll_run_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(payroll_run_status, payroll_run_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *payroll_run_status_convertToJSON(simplebilly_api_payroll_run_status__e payroll_run_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "payroll_run_status", payroll_run_status_payroll_run_status_ToString(payroll_run_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_payroll_run_status__e payroll_run_status_parseFromJSON(cJSON *payroll_run_statusJSON) {
    if(!cJSON_IsString(payroll_run_statusJSON) || (payroll_run_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return payroll_run_status_payroll_run_status_FromString(payroll_run_statusJSON->valuestring);
}
