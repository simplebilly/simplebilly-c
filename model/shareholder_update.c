#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shareholder_update.h"



static shareholder_update_t *shareholder_update_create_internal(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
    ) {
    shareholder_update_t *shareholder_update_local_var = malloc(sizeof(shareholder_update_t));
    if (!shareholder_update_local_var) {
        return NULL;
    }
    memset(shareholder_update_local_var, 0, sizeof(shareholder_update_t));
    shareholder_update_local_var->_library_owned = 1;
    shareholder_update_local_var->address = address;
    shareholder_update_local_var->birth_date = birth_date;
    shareholder_update_local_var->email = email;
    shareholder_update_local_var->first_name = first_name;
    shareholder_update_local_var->last_name = last_name;
    shareholder_update_local_var->share_number = share_number;
    shareholder_update_local_var->shares = shares;
    return shareholder_update_local_var;
}

__attribute__((deprecated)) shareholder_update_t *shareholder_update_create(
    char *address,
    char *birth_date,
    char *email,
    char *first_name,
    char *last_name,
    char *share_number,
    char *shares
    ) {
    shareholder_update_t *result = shareholder_update_create_internal (
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

void shareholder_update_free(shareholder_update_t *shareholder_update) {
    if(NULL == shareholder_update){
        return ;
    }
    if(shareholder_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shareholder_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shareholder_update->address) {
        free(shareholder_update->address);
        shareholder_update->address = NULL;
    }
    if (shareholder_update->birth_date) {
        free(shareholder_update->birth_date);
        shareholder_update->birth_date = NULL;
    }
    if (shareholder_update->email) {
        free(shareholder_update->email);
        shareholder_update->email = NULL;
    }
    if (shareholder_update->first_name) {
        free(shareholder_update->first_name);
        shareholder_update->first_name = NULL;
    }
    if (shareholder_update->last_name) {
        free(shareholder_update->last_name);
        shareholder_update->last_name = NULL;
    }
    if (shareholder_update->share_number) {
        free(shareholder_update->share_number);
        shareholder_update->share_number = NULL;
    }
    if (shareholder_update->shares) {
        free(shareholder_update->shares);
        shareholder_update->shares = NULL;
    }
    free(shareholder_update);
}

cJSON *shareholder_update_convertToJSON(shareholder_update_t *shareholder_update) {
    cJSON *item = cJSON_CreateObject();

    // shareholder_update->address
    if(shareholder_update->address) {
    if(cJSON_AddStringToObject(item, "address", shareholder_update->address) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_update->birth_date
    if(shareholder_update->birth_date) {
    if(cJSON_AddStringToObject(item, "birthDate", shareholder_update->birth_date) == NULL) {
    goto fail; //Date
    }
    }


    // shareholder_update->email
    if(shareholder_update->email) {
    if(cJSON_AddStringToObject(item, "email", shareholder_update->email) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_update->first_name
    if(shareholder_update->first_name) {
    if(cJSON_AddStringToObject(item, "firstName", shareholder_update->first_name) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_update->last_name
    if(shareholder_update->last_name) {
    if(cJSON_AddStringToObject(item, "lastName", shareholder_update->last_name) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_update->share_number
    if(shareholder_update->share_number) {
    if(cJSON_AddStringToObject(item, "shareNumber", shareholder_update->share_number) == NULL) {
    goto fail; //String
    }
    }


    // shareholder_update->shares
    if(shareholder_update->shares) {
    if(cJSON_AddStringToObject(item, "shares", shareholder_update->shares) == NULL) {
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

shareholder_update_t *shareholder_update_parseFromJSON(cJSON *shareholder_updateJSON){

    shareholder_update_t *shareholder_update_local_var = NULL;

    char *address_local_str = NULL;

    char *birth_date_local_str = NULL;

    char *email_local_str = NULL;

    char *first_name_local_str = NULL;

    char *last_name_local_str = NULL;

    char *share_number_local_str = NULL;

    char *shares_local_str = NULL;

    // shareholder_update->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(shareholder_updateJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // shareholder_update->birth_date
    cJSON *birth_date = cJSON_GetObjectItemCaseSensitive(shareholder_updateJSON, "birthDate");
    if (cJSON_IsNull(birth_date)) {
        birth_date = NULL;
    }
    if (birth_date) { 
    if(!cJSON_IsString(birth_date))
    {
    goto end; //Date
    }
    }

    // shareholder_update->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(shareholder_updateJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // shareholder_update->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(shareholder_updateJSON, "firstName");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (first_name) { 
    if(!cJSON_IsString(first_name) && !cJSON_IsNull(first_name))
    {
    goto end; //String
    }
    }

    // shareholder_update->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(shareholder_updateJSON, "lastName");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // shareholder_update->share_number
    cJSON *share_number = cJSON_GetObjectItemCaseSensitive(shareholder_updateJSON, "shareNumber");
    if (cJSON_IsNull(share_number)) {
        share_number = NULL;
    }
    if (share_number) { 
    if(!cJSON_IsString(share_number) && !cJSON_IsNull(share_number))
    {
    goto end; //String
    }
    }

    // shareholder_update->shares
    cJSON *shares = cJSON_GetObjectItemCaseSensitive(shareholder_updateJSON, "shares");
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

    shareholder_update_local_var = shareholder_update_create_internal (
        address_local_str,
        birth_date_local_str,
        email_local_str,
        first_name_local_str,
        last_name_local_str,
        share_number_local_str,
        shares_local_str
        );

    if (!shareholder_update_local_var) {
        goto end;
    }

    return shareholder_update_local_var;
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
