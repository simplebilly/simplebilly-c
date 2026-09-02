#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "smtp_encryption.h"


char* smtp_encryption_smtp_encryption_ToString(simplebilly_api_smtp_encryption__e smtp_encryption) {
    char *smtp_encryptionArray[] =  { "NULL", "StartTls", "Tls" };
    return smtp_encryptionArray[smtp_encryption];
}

simplebilly_api_smtp_encryption__e smtp_encryption_smtp_encryption_FromString(char* smtp_encryption) {
    int stringToReturn = 0;
    char *smtp_encryptionArray[] =  { "NULL", "StartTls", "Tls" };
    size_t sizeofArray = sizeof(smtp_encryptionArray) / sizeof(smtp_encryptionArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(smtp_encryption, smtp_encryptionArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *smtp_encryption_convertToJSON(simplebilly_api_smtp_encryption__e smtp_encryption) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "smtp_encryption", smtp_encryption_smtp_encryption_ToString(smtp_encryption)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_smtp_encryption__e smtp_encryption_parseFromJSON(cJSON *smtp_encryptionJSON) {
    if(!cJSON_IsString(smtp_encryptionJSON) || (smtp_encryptionJSON->valuestring == NULL)) {
        return 0;
    }
    return smtp_encryption_smtp_encryption_FromString(smtp_encryptionJSON->valuestring);
}
