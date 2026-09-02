#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bank_lookup.h"



static bank_lookup_t *bank_lookup_create_internal(
    char *bank_name,
    char *bic,
    char *iban,
    char *nextgenpsd2_url,
    int *psd2_supported
    ) {
    bank_lookup_t *bank_lookup_local_var = malloc(sizeof(bank_lookup_t));
    if (!bank_lookup_local_var) {
        return NULL;
    }
    memset(bank_lookup_local_var, 0, sizeof(bank_lookup_t));
    bank_lookup_local_var->_library_owned = 1;
    bank_lookup_local_var->bank_name = bank_name;
    bank_lookup_local_var->bic = bic;
    bank_lookup_local_var->iban = iban;
    bank_lookup_local_var->nextgenpsd2_url = nextgenpsd2_url;
    bank_lookup_local_var->psd2_supported = psd2_supported;
    return bank_lookup_local_var;
}

__attribute__((deprecated)) bank_lookup_t *bank_lookup_create(
    char *bank_name,
    char *bic,
    char *iban,
    char *nextgenpsd2_url,
    int *psd2_supported
    ) {
    int *psd2_supported_copy = NULL;
    if (psd2_supported) {
        psd2_supported_copy = malloc(sizeof(int));
        if (psd2_supported_copy) *psd2_supported_copy = *psd2_supported;
    }
    bank_lookup_t *result = bank_lookup_create_internal (
        bank_name,
        bic,
        iban,
        nextgenpsd2_url,
        psd2_supported_copy
        );
    if (!result) {
        free(psd2_supported_copy);
    }
    return result;
}

void bank_lookup_free(bank_lookup_t *bank_lookup) {
    if(NULL == bank_lookup){
        return ;
    }
    if(bank_lookup->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bank_lookup_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bank_lookup->bank_name) {
        free(bank_lookup->bank_name);
        bank_lookup->bank_name = NULL;
    }
    if (bank_lookup->bic) {
        free(bank_lookup->bic);
        bank_lookup->bic = NULL;
    }
    if (bank_lookup->iban) {
        free(bank_lookup->iban);
        bank_lookup->iban = NULL;
    }
    if (bank_lookup->nextgenpsd2_url) {
        free(bank_lookup->nextgenpsd2_url);
        bank_lookup->nextgenpsd2_url = NULL;
    }
    if (bank_lookup->psd2_supported) {
        free(bank_lookup->psd2_supported);
        bank_lookup->psd2_supported = NULL;
    }
    free(bank_lookup);
}

cJSON *bank_lookup_convertToJSON(bank_lookup_t *bank_lookup) {
    cJSON *item = cJSON_CreateObject();

    // bank_lookup->bank_name
    if(bank_lookup->bank_name) {
    if(cJSON_AddStringToObject(item, "bank_name", bank_lookup->bank_name) == NULL) {
    goto fail; //String
    }
    }


    // bank_lookup->bic
    if(bank_lookup->bic) {
    if(cJSON_AddStringToObject(item, "bic", bank_lookup->bic) == NULL) {
    goto fail; //String
    }
    }


    // bank_lookup->iban
    if (!bank_lookup->iban) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "iban", bank_lookup->iban) == NULL) {
    goto fail; //String
    }


    // bank_lookup->nextgenpsd2_url
    if(bank_lookup->nextgenpsd2_url) {
    if(cJSON_AddStringToObject(item, "nextgenpsd2_url", bank_lookup->nextgenpsd2_url) == NULL) {
    goto fail; //String
    }
    }


    // bank_lookup->psd2_supported
    if (!bank_lookup->psd2_supported) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "psd2_supported", *bank_lookup->psd2_supported) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bank_lookup_t *bank_lookup_parseFromJSON(cJSON *bank_lookupJSON){

    bank_lookup_t *bank_lookup_local_var = NULL;

    char *bank_name_local_str = NULL;

    char *bic_local_str = NULL;

    char *iban_local_str = NULL;

    char *nextgenpsd2_url_local_str = NULL;

    // define the local variable for bank_lookup->psd2_supported
    int *psd2_supported_local_var = NULL;

    // bank_lookup->bank_name
    cJSON *bank_name = cJSON_GetObjectItemCaseSensitive(bank_lookupJSON, "bank_name");
    if (cJSON_IsNull(bank_name)) {
        bank_name = NULL;
    }
    if (bank_name) { 
    if(!cJSON_IsString(bank_name) && !cJSON_IsNull(bank_name))
    {
    goto end; //String
    }
    }

    // bank_lookup->bic
    cJSON *bic = cJSON_GetObjectItemCaseSensitive(bank_lookupJSON, "bic");
    if (cJSON_IsNull(bic)) {
        bic = NULL;
    }
    if (bic) { 
    if(!cJSON_IsString(bic) && !cJSON_IsNull(bic))
    {
    goto end; //String
    }
    }

    // bank_lookup->iban
    cJSON *iban = cJSON_GetObjectItemCaseSensitive(bank_lookupJSON, "iban");
    if (cJSON_IsNull(iban)) {
        iban = NULL;
    }
    if (!iban) {
        goto end;
    }

    
    if(!cJSON_IsString(iban))
    {
    goto end; //String
    }

    // bank_lookup->nextgenpsd2_url
    cJSON *nextgenpsd2_url = cJSON_GetObjectItemCaseSensitive(bank_lookupJSON, "nextgenpsd2_url");
    if (cJSON_IsNull(nextgenpsd2_url)) {
        nextgenpsd2_url = NULL;
    }
    if (nextgenpsd2_url) { 
    if(!cJSON_IsString(nextgenpsd2_url) && !cJSON_IsNull(nextgenpsd2_url))
    {
    goto end; //String
    }
    }

    // bank_lookup->psd2_supported
    cJSON *psd2_supported = cJSON_GetObjectItemCaseSensitive(bank_lookupJSON, "psd2_supported");
    if (cJSON_IsNull(psd2_supported)) {
        psd2_supported = NULL;
    }
    if (!psd2_supported) {
        goto end;
    }

    
    if(!cJSON_IsBool(psd2_supported))
    {
    goto end; //Bool
    }
    psd2_supported_local_var = malloc(sizeof(int));
    if(!psd2_supported_local_var)
    {
        goto end;
    }
    *psd2_supported_local_var = psd2_supported->valueint;


    if (bank_name && !cJSON_IsNull(bank_name)) bank_name_local_str = strdup(bank_name->valuestring);
    if (bic && !cJSON_IsNull(bic)) bic_local_str = strdup(bic->valuestring);
    if (iban && !cJSON_IsNull(iban)) iban_local_str = strdup(iban->valuestring);
    if (nextgenpsd2_url && !cJSON_IsNull(nextgenpsd2_url)) nextgenpsd2_url_local_str = strdup(nextgenpsd2_url->valuestring);

    bank_lookup_local_var = bank_lookup_create_internal (
        bank_name_local_str,
        bic_local_str,
        iban_local_str,
        nextgenpsd2_url_local_str,
        psd2_supported_local_var
        );

    if (!bank_lookup_local_var) {
        goto end;
    }

    return bank_lookup_local_var;
end:
    if (bank_name_local_str) {
        free(bank_name_local_str);
        bank_name_local_str = NULL;
    }
    if (bic_local_str) {
        free(bic_local_str);
        bic_local_str = NULL;
    }
    if (iban_local_str) {
        free(iban_local_str);
        iban_local_str = NULL;
    }
    if (nextgenpsd2_url_local_str) {
        free(nextgenpsd2_url_local_str);
        nextgenpsd2_url_local_str = NULL;
    }
    if (psd2_supported_local_var) {
        free(psd2_supported_local_var);
        psd2_supported_local_var = NULL;
    }
    return NULL;

}
