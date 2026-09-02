#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "silent_partner.h"



static silent_partner_t *silent_partner_create_internal(
    char *contract_date,
    char *einlage,
    char *gewinnquote_pct,
    char *gewinnvortrag,
    instrument_type_t *instrument_type,
    int *kest_pflichtig,
    char *name,
    char *notes,
    char *verlust_verrechnungskonto,
    int *verlustbeteiligung
    ) {
    silent_partner_t *silent_partner_local_var = malloc(sizeof(silent_partner_t));
    if (!silent_partner_local_var) {
        return NULL;
    }
    memset(silent_partner_local_var, 0, sizeof(silent_partner_t));
    silent_partner_local_var->_library_owned = 1;
    silent_partner_local_var->contract_date = contract_date;
    silent_partner_local_var->einlage = einlage;
    silent_partner_local_var->gewinnquote_pct = gewinnquote_pct;
    silent_partner_local_var->gewinnvortrag = gewinnvortrag;
    silent_partner_local_var->instrument_type = instrument_type;
    silent_partner_local_var->kest_pflichtig = kest_pflichtig;
    silent_partner_local_var->name = name;
    silent_partner_local_var->notes = notes;
    silent_partner_local_var->verlust_verrechnungskonto = verlust_verrechnungskonto;
    silent_partner_local_var->verlustbeteiligung = verlustbeteiligung;
    return silent_partner_local_var;
}

__attribute__((deprecated)) silent_partner_t *silent_partner_create(
    char *contract_date,
    char *einlage,
    char *gewinnquote_pct,
    char *gewinnvortrag,
    instrument_type_t *instrument_type,
    int *kest_pflichtig,
    char *name,
    char *notes,
    char *verlust_verrechnungskonto,
    int *verlustbeteiligung
    ) {
    int *kest_pflichtig_copy = NULL;
    if (kest_pflichtig) {
        kest_pflichtig_copy = malloc(sizeof(int));
        if (kest_pflichtig_copy) *kest_pflichtig_copy = *kest_pflichtig;
    }
    int *verlustbeteiligung_copy = NULL;
    if (verlustbeteiligung) {
        verlustbeteiligung_copy = malloc(sizeof(int));
        if (verlustbeteiligung_copy) *verlustbeteiligung_copy = *verlustbeteiligung;
    }
    silent_partner_t *result = silent_partner_create_internal (
        contract_date,
        einlage,
        gewinnquote_pct,
        gewinnvortrag,
        instrument_type,
        kest_pflichtig_copy,
        name,
        notes,
        verlust_verrechnungskonto,
        verlustbeteiligung_copy
        );
    if (!result) {
        free(kest_pflichtig_copy);
        free(verlustbeteiligung_copy);
    }
    return result;
}

void silent_partner_free(silent_partner_t *silent_partner) {
    if(NULL == silent_partner){
        return ;
    }
    if(silent_partner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "silent_partner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (silent_partner->contract_date) {
        free(silent_partner->contract_date);
        silent_partner->contract_date = NULL;
    }
    if (silent_partner->einlage) {
        free(silent_partner->einlage);
        silent_partner->einlage = NULL;
    }
    if (silent_partner->gewinnquote_pct) {
        free(silent_partner->gewinnquote_pct);
        silent_partner->gewinnquote_pct = NULL;
    }
    if (silent_partner->gewinnvortrag) {
        free(silent_partner->gewinnvortrag);
        silent_partner->gewinnvortrag = NULL;
    }
    if (silent_partner->instrument_type) {
        instrument_type_free(silent_partner->instrument_type);
        silent_partner->instrument_type = NULL;
    }
    if (silent_partner->kest_pflichtig) {
        free(silent_partner->kest_pflichtig);
        silent_partner->kest_pflichtig = NULL;
    }
    if (silent_partner->name) {
        free(silent_partner->name);
        silent_partner->name = NULL;
    }
    if (silent_partner->notes) {
        free(silent_partner->notes);
        silent_partner->notes = NULL;
    }
    if (silent_partner->verlust_verrechnungskonto) {
        free(silent_partner->verlust_verrechnungskonto);
        silent_partner->verlust_verrechnungskonto = NULL;
    }
    if (silent_partner->verlustbeteiligung) {
        free(silent_partner->verlustbeteiligung);
        silent_partner->verlustbeteiligung = NULL;
    }
    free(silent_partner);
}

cJSON *silent_partner_convertToJSON(silent_partner_t *silent_partner) {
    cJSON *item = cJSON_CreateObject();

    // silent_partner->contract_date
    if(silent_partner->contract_date) {
    if(cJSON_AddStringToObject(item, "contractDate", silent_partner->contract_date) == NULL) {
    goto fail; //Date
    }
    }


    // silent_partner->einlage
    if(silent_partner->einlage) {
    if(cJSON_AddStringToObject(item, "einlage", silent_partner->einlage) == NULL) {
    goto fail; //String
    }
    }


    // silent_partner->gewinnquote_pct
    if(silent_partner->gewinnquote_pct) {
    if(cJSON_AddStringToObject(item, "gewinnquotePct", silent_partner->gewinnquote_pct) == NULL) {
    goto fail; //String
    }
    }


    // silent_partner->gewinnvortrag
    if(silent_partner->gewinnvortrag) {
    if(cJSON_AddStringToObject(item, "gewinnvortrag", silent_partner->gewinnvortrag) == NULL) {
    goto fail; //String
    }
    }


    // silent_partner->instrument_type
    if (!silent_partner->instrument_type) {
        goto fail;
    }
    cJSON *instrument_type_local_JSON = instrument_type_convertToJSON(silent_partner->instrument_type);
    if(instrument_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "instrumentType", instrument_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // silent_partner->kest_pflichtig
    if(silent_partner->kest_pflichtig) {
    if(cJSON_AddBoolToObject(item, "kestPflichtig", *silent_partner->kest_pflichtig) == NULL) {
    goto fail; //Bool
    }
    }


    // silent_partner->name
    if(silent_partner->name) {
    if(cJSON_AddStringToObject(item, "name", silent_partner->name) == NULL) {
    goto fail; //String
    }
    }


    // silent_partner->notes
    if(silent_partner->notes) {
    if(cJSON_AddStringToObject(item, "notes", silent_partner->notes) == NULL) {
    goto fail; //String
    }
    }


    // silent_partner->verlust_verrechnungskonto
    if(silent_partner->verlust_verrechnungskonto) {
    if(cJSON_AddStringToObject(item, "verlustVerrechnungskonto", silent_partner->verlust_verrechnungskonto) == NULL) {
    goto fail; //String
    }
    }


    // silent_partner->verlustbeteiligung
    if(silent_partner->verlustbeteiligung) {
    if(cJSON_AddBoolToObject(item, "verlustbeteiligung", *silent_partner->verlustbeteiligung) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

silent_partner_t *silent_partner_parseFromJSON(cJSON *silent_partnerJSON){

    silent_partner_t *silent_partner_local_var = NULL;

    char *contract_date_local_str = NULL;

    char *einlage_local_str = NULL;

    char *gewinnquote_pct_local_str = NULL;

    char *gewinnvortrag_local_str = NULL;

    // define the local variable for silent_partner->instrument_type
    instrument_type_t *instrument_type_local_nonprim = NULL;

    // define the local variable for silent_partner->kest_pflichtig
    int *kest_pflichtig_local_var = NULL;

    char *name_local_str = NULL;

    char *notes_local_str = NULL;

    char *verlust_verrechnungskonto_local_str = NULL;

    // define the local variable for silent_partner->verlustbeteiligung
    int *verlustbeteiligung_local_var = NULL;

    // silent_partner->contract_date
    cJSON *contract_date = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "contractDate");
    if (cJSON_IsNull(contract_date)) {
        contract_date = NULL;
    }
    if (contract_date) { 
    if(!cJSON_IsString(contract_date))
    {
    goto end; //Date
    }
    }

    // silent_partner->einlage
    cJSON *einlage = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "einlage");
    if (cJSON_IsNull(einlage)) {
        einlage = NULL;
    }
    if (einlage) { 
    if(!cJSON_IsString(einlage) && !cJSON_IsNull(einlage))
    {
    goto end; //String
    }
    }

    // silent_partner->gewinnquote_pct
    cJSON *gewinnquote_pct = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "gewinnquotePct");
    if (cJSON_IsNull(gewinnquote_pct)) {
        gewinnquote_pct = NULL;
    }
    if (gewinnquote_pct) { 
    if(!cJSON_IsString(gewinnquote_pct) && !cJSON_IsNull(gewinnquote_pct))
    {
    goto end; //String
    }
    }

    // silent_partner->gewinnvortrag
    cJSON *gewinnvortrag = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "gewinnvortrag");
    if (cJSON_IsNull(gewinnvortrag)) {
        gewinnvortrag = NULL;
    }
    if (gewinnvortrag) { 
    if(!cJSON_IsString(gewinnvortrag) && !cJSON_IsNull(gewinnvortrag))
    {
    goto end; //String
    }
    }

    // silent_partner->instrument_type
    cJSON *instrument_type = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "instrumentType");
    if (cJSON_IsNull(instrument_type)) {
        instrument_type = NULL;
    }
    if (!instrument_type) {
        goto end;
    }

    
    instrument_type_local_nonprim = instrument_type_parseFromJSON(instrument_type); //custom

    // silent_partner->kest_pflichtig
    cJSON *kest_pflichtig = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "kestPflichtig");
    if (cJSON_IsNull(kest_pflichtig)) {
        kest_pflichtig = NULL;
    }
    if (kest_pflichtig) { 
    if(!cJSON_IsBool(kest_pflichtig))
    {
    goto end; //Bool
    }
    kest_pflichtig_local_var = malloc(sizeof(int));
    if(!kest_pflichtig_local_var)
    {
        goto end;
    }
    *kest_pflichtig_local_var = kest_pflichtig->valueint;
    }

    // silent_partner->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // silent_partner->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // silent_partner->verlust_verrechnungskonto
    cJSON *verlust_verrechnungskonto = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "verlustVerrechnungskonto");
    if (cJSON_IsNull(verlust_verrechnungskonto)) {
        verlust_verrechnungskonto = NULL;
    }
    if (verlust_verrechnungskonto) { 
    if(!cJSON_IsString(verlust_verrechnungskonto) && !cJSON_IsNull(verlust_verrechnungskonto))
    {
    goto end; //String
    }
    }

    // silent_partner->verlustbeteiligung
    cJSON *verlustbeteiligung = cJSON_GetObjectItemCaseSensitive(silent_partnerJSON, "verlustbeteiligung");
    if (cJSON_IsNull(verlustbeteiligung)) {
        verlustbeteiligung = NULL;
    }
    if (verlustbeteiligung) { 
    if(!cJSON_IsBool(verlustbeteiligung))
    {
    goto end; //Bool
    }
    verlustbeteiligung_local_var = malloc(sizeof(int));
    if(!verlustbeteiligung_local_var)
    {
        goto end;
    }
    *verlustbeteiligung_local_var = verlustbeteiligung->valueint;
    }


    if (contract_date) contract_date_local_str = strdup(contract_date->valuestring);
    if (einlage && !cJSON_IsNull(einlage)) einlage_local_str = strdup(einlage->valuestring);
    if (gewinnquote_pct && !cJSON_IsNull(gewinnquote_pct)) gewinnquote_pct_local_str = strdup(gewinnquote_pct->valuestring);
    if (gewinnvortrag && !cJSON_IsNull(gewinnvortrag)) gewinnvortrag_local_str = strdup(gewinnvortrag->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (verlust_verrechnungskonto && !cJSON_IsNull(verlust_verrechnungskonto)) verlust_verrechnungskonto_local_str = strdup(verlust_verrechnungskonto->valuestring);

    silent_partner_local_var = silent_partner_create_internal (
        contract_date_local_str,
        einlage_local_str,
        gewinnquote_pct_local_str,
        gewinnvortrag_local_str,
        instrument_type_local_nonprim,
        kest_pflichtig_local_var,
        name_local_str,
        notes_local_str,
        verlust_verrechnungskonto_local_str,
        verlustbeteiligung_local_var
        );

    if (!silent_partner_local_var) {
        goto end;
    }

    return silent_partner_local_var;
end:
    if (contract_date_local_str) {
        free(contract_date_local_str);
        contract_date_local_str = NULL;
    }
    if (einlage_local_str) {
        free(einlage_local_str);
        einlage_local_str = NULL;
    }
    if (gewinnquote_pct_local_str) {
        free(gewinnquote_pct_local_str);
        gewinnquote_pct_local_str = NULL;
    }
    if (gewinnvortrag_local_str) {
        free(gewinnvortrag_local_str);
        gewinnvortrag_local_str = NULL;
    }
    if (instrument_type_local_nonprim) {
        instrument_type_free(instrument_type_local_nonprim);
        instrument_type_local_nonprim = NULL;
    }
    if (kest_pflichtig_local_var) {
        free(kest_pflichtig_local_var);
        kest_pflichtig_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (verlust_verrechnungskonto_local_str) {
        free(verlust_verrechnungskonto_local_str);
        verlust_verrechnungskonto_local_str = NULL;
    }
    if (verlustbeteiligung_local_var) {
        free(verlustbeteiligung_local_var);
        verlustbeteiligung_local_var = NULL;
    }
    return NULL;

}
