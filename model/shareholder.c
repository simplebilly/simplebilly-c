#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shareholder.h"



static shareholder_t *shareholder_create_internal(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
    ) {
    shareholder_t *shareholder_local_var = malloc(sizeof(shareholder_t));
    if (!shareholder_local_var) {
        return NULL;
    }
    memset(shareholder_local_var, 0, sizeof(shareholder_t));
    shareholder_local_var->_library_owned = 1;
    shareholder_local_var->address = address;
    shareholder_local_var->birth_date = birth_date;
    shareholder_local_var->email = email;
    shareholder_local_var->first_name = first_name;
    shareholder_local_var->last_name = last_name;
    shareholder_local_var->share_number = share_number;
    shareholder_local_var->shares = shares;
    return shareholder_local_var;
}

__attribute__((deprecated)) shareholder_t *shareholder_create(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
    ) {
    shareholder_t *result = shareholder_create_internal (
        address,
        birth_date,
        email,
        first_name,
        last_name,
        share_number,
        shares
        );
    if (!result) {
    }
    return result;
}

void shareholder_free(shareholder_t *shareholder) {
    if(NULL == shareholder){
        return ;
    }
    if(shareholder->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shareholder_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shareholder->address) {
        free(shareholder->address);
        shareholder->address = NULL;
    }
    if (shareholder->birth_date) {
        free(shareholder->birth_date);
        shareholder->birth_date = NULL;
    }
    if (shareholder->email) {
        free(shareholder->email);
        shareholder->email = NULL;
    }
    if (shareholder->first_name) {
        free(shareholder->first_name);
        shareholder->first_name = NULL;
    }
    if (shareholder->last_name) {
        free(shareholder->last_name);
        shareholder->last_name = NULL;
    }
    if (shareholder->share_number) {
        free(shareholder->share_number);
        shareholder->share_number = NULL;
    }
    if (shareholder->shares) {
        free(shareholder->shares);
        shareholder->shares = NULL;
    }
    free(shareholder);
}

cJSON *shareholder_convertToJSON(shareholder_t *shareholder) {
    cJSON *item = cJSON_CreateObject();

    // shareholder->address
    if(shareholder->address) {
    if(cJSON_AddStringToObject(item, "address", shareholder->address) == NULL) {
    goto fail; //String
    }
    }


    // shareholder->birth_date
    if(shareholder->birth_date) {
    if(cJSON_AddStringToObject(item, "birthDate", shareholder->birth_date) == NULL) {
    goto fail; //Date
    }
    }


    // shareholder->email
    if(shareholder->email) {
    if(cJSON_AddStringToObject(item, "email", shareholder->email) == NULL) {
    goto fail; //String
    }
    }


    // shareholder->first_name
    if(shareholder->first_name) {
    if(cJSON_AddStringToObject(item, "firstName", shareholder->first_name) == NULL) {
    goto fail; //String
    }
    }


    // shareholder->last_name
    if(shareholder->last_name) {
    if(cJSON_AddStringToObject(item, "lastName", shareholder->last_name) == NULL) {
    goto fail; //String
    }
    }


    // shareholder->share_number
    if(shareholder->share_number) {
    if(cJSON_AddStringToObject(item, "shareNumber", shareholder->share_number) == NULL) {
    goto fail; //String
    }
    }


    // shareholder->shares
    if(shareholder->shares) {
    if(cJSON_AddStringToObject(item, "shares", shareholder->shares) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

shareholder_t *shareholder_parseFromJSON(cJSON *shareholderJSON){

    shareholder_t *shareholder_local_var = NULL;

    char *address_local_str = NULL;

    char *birth_date_local_str = NULL;

    char *email_local_str = NULL;

    char *first_name_local_str = NULL;

    char *last_name_local_str = NULL;

    char *share_number_local_str = NULL;

    char *shares_local_str = NULL;

    // shareholder->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(shareholderJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // shareholder->birth_date
    cJSON *birth_date = cJSON_GetObjectItemCaseSensitive(shareholderJSON, "birthDate");
    if (cJSON_IsNull(birth_date)) {
        birth_date = NULL;
    }
    if (birth_date) { 
    if(!cJSON_IsString(birth_date))
    {
    goto end; //Date
    }
    }

    // shareholder->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(shareholderJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // shareholder->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(shareholderJSON, "firstName");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // shareholder->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(shareholderJSON, "lastName");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // shareholder->share_number
    cJSON *share_number = cJSON_GetObjectItemCaseSensitive(shareholderJSON, "shareNumber");
    if (cJSON_IsNull(share_number)) {
        share_number = NULL;
    }
    if (share_number) { 
    if(!cJSON_IsString(share_number) && !cJSON_IsNull(share_number))
    {
    goto end; //String
    }
    }

    // shareholder->shares
    cJSON *shares = cJSON_GetObjectItemCaseSensitive(shareholderJSON, "shares");
    if (cJSON_IsNull(shares)) {
        shares = NULL;
    }
    if (shares) { 
    if(!cJSON_IsString(shares) && !cJSON_IsNull(shares))
    {
    goto end; //String
    }
    }


    if (address && !cJSON_IsNull(address)) address_local_str = strdup(address->valuestring);
    if (birth_date) birth_date_local_str = strdup(birth_date->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);
    if (share_number && !cJSON_IsNull(share_number)) share_number_local_str = strdup(share_number->valuestring);
    if (shares && !cJSON_IsNull(shares)) shares_local_str = strdup(shares->valuestring);

    shareholder_local_var = shareholder_create_internal (
        address_local_str,
        birth_date_local_str,
        email_local_str,
        first_name_local_str,
        last_name_local_str,
        share_number_local_str,
        shares_local_str
        );

    if (!shareholder_local_var) {
        goto end;
    }

    return shareholder_local_var;
end:
    if (address_local_str) {
        free(address_local_str);
        address_local_str = NULL;
    }
    if (birth_date_local_str) {
        free(birth_date_local_str);
        birth_date_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (first_name_local_str) {
        free(first_name_local_str);
        first_name_local_str = NULL;
    }
    if (last_name_local_str) {
        free(last_name_local_str);
        last_name_local_str = NULL;
    }
    if (share_number_local_str) {
        free(share_number_local_str);
        share_number_local_str = NULL;
    }
    if (shares_local_str) {
        free(shares_local_str);
        shares_local_str = NULL;
    }
    return NULL;

}
