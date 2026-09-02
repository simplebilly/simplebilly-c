#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shareholder_create.h"



static shareholder_create_t *shareholder_create_create_internal(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
    ) {
    shareholder_create_t *shareholder_create_local_var = malloc(sizeof(shareholder_create_t));
    if (!shareholder_create_local_var) {
        return NULL;
    }
    memset(shareholder_create_local_var, 0, sizeof(shareholder_create_t));
    shareholder_create_local_var->_library_owned = 1;
    shareholder_create_local_var->address = address;
    shareholder_create_local_var->birth_date = birth_date;
    shareholder_create_local_var->email = email;
    shareholder_create_local_var->first_name = first_name;
    shareholder_create_local_var->last_name = last_name;
    shareholder_create_local_var->share_number = share_number;
    shareholder_create_local_var->shares = shares;
    return shareholder_create_local_var;
}

__attribute__((deprecated)) shareholder_create_t *shareholder_create_create(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
    ) {
    shareholder_create_t *result = shareholder_create_create_internal (
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

void shareholder_create_free(shareholder_create_t *shareholder_create) {
    if(NULL == shareholder_create){
        return ;
    }
    if(shareholder_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shareholder_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shareholder_create->address) {
        free(shareholder_create->address);
        shareholder_create->address = NULL;
    }
    if (shareholder_create->birth_date) {
        free(shareholder_create->birth_date);
        shareholder_create->birth_date = NULL;
    }
    if (shareholder_create->email) {
        free(shareholder_create->email);
        shareholder_create->email = NULL;
    }
    if (shareholder_create->first_name) {
        free(shareholder_create->first_name);
        shareholder_create->first_name = NULL;
    }
    if (shareholder_create->last_name) {
        free(shareholder_create->last_name);
        shareholder_create->last_name = NULL;
    }
    if (shareholder_create->share_number) {
        free(shareholder_create->share_number);
        shareholder_create->share_number = NULL;
    }
    if (shareholder_create->shares) {
        free(shareholder_create->shares);
        shareholder_create->shares = NULL;
    }
    free(shareholder_create);
}

cJSON *shareholder_create_convertToJSON(shareholder_create_t *shareholder_create) {
    cJSON *item = cJSON_CreateObject();

    // shareholder_create->address
    if(shareholder_create->address) {
    if(cJSON_AddStringToObject(item, "address", shareholder_create->address) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_create->birth_date
    if(shareholder_create->birth_date) {
    if(cJSON_AddStringToObject(item, "birthDate", shareholder_create->birth_date) == NULL) {
    goto fail; //Date
    }
    }


    // shareholder_create->email
    if(shareholder_create->email) {
    if(cJSON_AddStringToObject(item, "email", shareholder_create->email) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_create->first_name
    if(shareholder_create->first_name) {
    if(cJSON_AddStringToObject(item, "firstName", shareholder_create->first_name) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_create->last_name
    if(shareholder_create->last_name) {
    if(cJSON_AddStringToObject(item, "lastName", shareholder_create->last_name) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_create->share_number
    if(shareholder_create->share_number) {
    if(cJSON_AddStringToObject(item, "shareNumber", shareholder_create->share_number) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_create->shares
    if(shareholder_create->shares) {
    if(cJSON_AddStringToObject(item, "shares", shareholder_create->shares) == NULL) {
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

shareholder_create_t *shareholder_create_parseFromJSON(cJSON *shareholder_createJSON){

    shareholder_create_t *shareholder_create_local_var = NULL;

    char *address_local_str = NULL;

    char *birth_date_local_str = NULL;

    char *email_local_str = NULL;

    char *first_name_local_str = NULL;

    char *last_name_local_str = NULL;

    char *share_number_local_str = NULL;

    char *shares_local_str = NULL;

    // shareholder_create->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(shareholder_createJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // shareholder_create->birth_date
    cJSON *birth_date = cJSON_GetObjectItemCaseSensitive(shareholder_createJSON, "birthDate");
    if (cJSON_IsNull(birth_date)) {
        birth_date = NULL;
    }
    if (birth_date) { 
    if(!cJSON_IsString(birth_date))
    {
    goto end; //Date
    }
    }

    // shareholder_create->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(shareholder_createJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // shareholder_create->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(shareholder_createJSON, "firstName");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // shareholder_create->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(shareholder_createJSON, "lastName");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // shareholder_create->share_number
    cJSON *share_number = cJSON_GetObjectItemCaseSensitive(shareholder_createJSON, "shareNumber");
    if (cJSON_IsNull(share_number)) {
        share_number = NULL;
    }
    if (share_number) { 
    if(!cJSON_IsString(share_number) && !cJSON_IsNull(share_number))
    {
    goto end; //String
    }
    }

    // shareholder_create->shares
    cJSON *shares = cJSON_GetObjectItemCaseSensitive(shareholder_createJSON, "shares");
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

    shareholder_create_local_var = shareholder_create_create_internal (
        address_local_str,
        birth_date_local_str,
        email_local_str,
        first_name_local_str,
        last_name_local_str,
        share_number_local_str,
        shares_local_str
        );

    if (!shareholder_create_local_var) {
        goto end;
    }

    return shareholder_create_local_var;
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
