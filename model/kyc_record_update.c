#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kyc_record_update.h"



static kyc_record_update_t *kyc_record_update_create_internal(
    char *customer_id,
    char *customer_name,
    char *kyc_date,
    char *notes,
    char *retention_until,
    char *risk_assessment
    ) {
    kyc_record_update_t *kyc_record_update_local_var = malloc(sizeof(kyc_record_update_t));
    if (!kyc_record_update_local_var) {
        return NULL;
    }
    memset(kyc_record_update_local_var, 0, sizeof(kyc_record_update_t));
    kyc_record_update_local_var->_library_owned = 1;
    kyc_record_update_local_var->customer_id = customer_id;
    kyc_record_update_local_var->customer_name = customer_name;
    kyc_record_update_local_var->kyc_date = kyc_date;
    kyc_record_update_local_var->notes = notes;
    kyc_record_update_local_var->retention_until = retention_until;
    kyc_record_update_local_var->risk_assessment = risk_assessment;
    return kyc_record_update_local_var;
}

__attribute__((deprecated)) kyc_record_update_t *kyc_record_update_create(
    char *customer_id,
    char *customer_name,
    char *kyc_date,
    char *notes,
    char *retention_until,
    char *risk_assessment
    ) {
    kyc_record_update_t *result = kyc_record_update_create_internal (
        customer_id,
        customer_name,
        kyc_date,
        notes,
        retention_until,
        risk_assessment
        );
    if (!result) {
    }
    return result;
}

void kyc_record_update_free(kyc_record_update_t *kyc_record_update) {
    if(NULL == kyc_record_update){
        return ;
    }
    if(kyc_record_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kyc_record_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kyc_record_update->customer_id) {
        free(kyc_record_update->customer_id);
        kyc_record_update->customer_id = NULL;
    }
    if (kyc_record_update->customer_name) {
        free(kyc_record_update->customer_name);
        kyc_record_update->customer_name = NULL;
    }
    if (kyc_record_update->kyc_date) {
        free(kyc_record_update->kyc_date);
        kyc_record_update->kyc_date = NULL;
    }
    if (kyc_record_update->notes) {
        free(kyc_record_update->notes);
        kyc_record_update->notes = NULL;
    }
    if (kyc_record_update->retention_until) {
        free(kyc_record_update->retention_until);
        kyc_record_update->retention_until = NULL;
    }
    if (kyc_record_update->risk_assessment) {
        free(kyc_record_update->risk_assessment);
        kyc_record_update->risk_assessment = NULL;
    }
    free(kyc_record_update);
}

cJSON *kyc_record_update_convertToJSON(kyc_record_update_t *kyc_record_update) {
    cJSON *item = cJSON_CreateObject();

    // kyc_record_update->customer_id
    if(kyc_record_update->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", kyc_record_update->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // kyc_record_update->customer_name
    if(kyc_record_update->customer_name) {
    if(cJSON_AddStringToObject(item, "customerName", kyc_record_update->customer_name) == NULL) {
    goto fail; //String
    }
    }


    // kyc_record_update->kyc_date
    if(kyc_record_update->kyc_date) {
    if(cJSON_AddStringToObject(item, "kycDate", kyc_record_update->kyc_date) == NULL) {
    goto fail; //Date
    }
    }


    // kyc_record_update->notes
    if(kyc_record_update->notes) {
    if(cJSON_AddStringToObject(item, "notes", kyc_record_update->notes) == NULL) {
    goto fail; //String
    }
    }


    // kyc_record_update->retention_until
    if(kyc_record_update->retention_until) {
    if(cJSON_AddStringToObject(item, "retentionUntil", kyc_record_update->retention_until) == NULL) {
    goto fail; //Date
    }
    }


    // kyc_record_update->risk_assessment
    if(kyc_record_update->risk_assessment) {
    if(cJSON_AddStringToObject(item, "riskAssessment", kyc_record_update->risk_assessment) == NULL) {
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

kyc_record_update_t *kyc_record_update_parseFromJSON(cJSON *kyc_record_updateJSON){

    kyc_record_update_t *kyc_record_update_local_var = NULL;

    char *customer_id_local_str = NULL;

    char *customer_name_local_str = NULL;

    char *kyc_date_local_str = NULL;

    char *notes_local_str = NULL;

    char *retention_until_local_str = NULL;

    char *risk_assessment_local_str = NULL;

    // kyc_record_update->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(kyc_record_updateJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // kyc_record_update->customer_name
    cJSON *customer_name = cJSON_GetObjectItemCaseSensitive(kyc_record_updateJSON, "customerName");
    if (cJSON_IsNull(customer_name)) {
        customer_name = NULL;
    }
    if (customer_name) { 
    if(!cJSON_IsString(customer_name) && !cJSON_IsNull(customer_name))
    {
    goto end; //String
    }
    }

    // kyc_record_update->kyc_date
    cJSON *kyc_date = cJSON_GetObjectItemCaseSensitive(kyc_record_updateJSON, "kycDate");
    if (cJSON_IsNull(kyc_date)) {
        kyc_date = NULL;
    }
    if (kyc_date) { 
    if(!cJSON_IsString(kyc_date))
    {
    goto end; //Date
    }
    }

    // kyc_record_update->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(kyc_record_updateJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // kyc_record_update->retention_until
    cJSON *retention_until = cJSON_GetObjectItemCaseSensitive(kyc_record_updateJSON, "retentionUntil");
    if (cJSON_IsNull(retention_until)) {
        retention_until = NULL;
    }
    if (retention_until) { 
    if(!cJSON_IsString(retention_until))
    {
    goto end; //Date
    }
    }

    // kyc_record_update->risk_assessment
    cJSON *risk_assessment = cJSON_GetObjectItemCaseSensitive(kyc_record_updateJSON, "riskAssessment");
    if (cJSON_IsNull(risk_assessment)) {
        risk_assessment = NULL;
    }
    if (risk_assessment) { 
    if(!cJSON_IsString(risk_assessment) && !cJSON_IsNull(risk_assessment))
    {
    goto end; //String
    }
    }


    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (customer_name && !cJSON_IsNull(customer_name)) customer_name_local_str = strdup(customer_name->valuestring);
    if (kyc_date) kyc_date_local_str = strdup(kyc_date->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (retention_until) retention_until_local_str = strdup(retention_until->valuestring);
    if (risk_assessment && !cJSON_IsNull(risk_assessment)) risk_assessment_local_str = strdup(risk_assessment->valuestring);

    kyc_record_update_local_var = kyc_record_update_create_internal (
        customer_id_local_str,
        customer_name_local_str,
        kyc_date_local_str,
        notes_local_str,
        retention_until_local_str,
        risk_assessment_local_str
        );

    if (!kyc_record_update_local_var) {
        goto end;
    }

    return kyc_record_update_local_var;
end:
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (customer_name_local_str) {
        free(customer_name_local_str);
        customer_name_local_str = NULL;
    }
    if (kyc_date_local_str) {
        free(kyc_date_local_str);
        kyc_date_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (retention_until_local_str) {
        free(retention_until_local_str);
        retention_until_local_str = NULL;
    }
    if (risk_assessment_local_str) {
        free(risk_assessment_local_str);
        risk_assessment_local_str = NULL;
    }
    return NULL;

}
