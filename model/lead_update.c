#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lead_update.h"



static lead_update_t *lead_update_create_internal(
    char *company,
    char *converted_at,
    char *created_at,
    char *email,
    char *first_contact_at,
    char *name,
    char *notes,
    char *phone,
    int *score,
    char *source,
    lead_status_t *status,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
    ) {
    lead_update_t *lead_update_local_var = malloc(sizeof(lead_update_t));
    if (!lead_update_local_var) {
        return NULL;
    }
    memset(lead_update_local_var, 0, sizeof(lead_update_t));
    lead_update_local_var->_library_owned = 1;
    lead_update_local_var->company = company;
    lead_update_local_var->converted_at = converted_at;
    lead_update_local_var->created_at = created_at;
    lead_update_local_var->email = email;
    lead_update_local_var->first_contact_at = first_contact_at;
    lead_update_local_var->name = name;
    lead_update_local_var->notes = notes;
    lead_update_local_var->phone = phone;
    lead_update_local_var->score = score;
    lead_update_local_var->source = source;
    lead_update_local_var->status = status;
    lead_update_local_var->tags = tags;
    lead_update_local_var->tenant_id = tenant_id;
    lead_update_local_var->updated_at = updated_at;
    return lead_update_local_var;
}

__attribute__((deprecated)) lead_update_t *lead_update_create(
    char *company,
    char *converted_at,
    char *created_at,
    char *email,
    char *first_contact_at,
    char *name,
    char *notes,
    char *phone,
    int *score,
    char *source,
    lead_status_t *status,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
    ) {
    int *score_copy = NULL;
    if (score) {
        score_copy = malloc(sizeof(int));
        if (score_copy) *score_copy = *score;
    }
    lead_update_t *result = lead_update_create_internal (
        company,
        converted_at,
        created_at,
        email,
        first_contact_at,
        name,
        notes,
        phone,
        score_copy,
        source,
        status,
        tags,
        tenant_id,
        updated_at
        );
    if (!result) {
        free(score_copy);
    }
    return result;
}

void lead_update_free(lead_update_t *lead_update) {
    if(NULL == lead_update){
        return ;
    }
    if(lead_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lead_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (lead_update->company) {
        free(lead_update->company);
        lead_update->company = NULL;
    }
    if (lead_update->converted_at) {
        free(lead_update->converted_at);
        lead_update->converted_at = NULL;
    }
    if (lead_update->created_at) {
        free(lead_update->created_at);
        lead_update->created_at = NULL;
    }
    if (lead_update->email) {
        free(lead_update->email);
        lead_update->email = NULL;
    }
    if (lead_update->first_contact_at) {
        free(lead_update->first_contact_at);
        lead_update->first_contact_at = NULL;
    }
    if (lead_update->name) {
        free(lead_update->name);
        lead_update->name = NULL;
    }
    if (lead_update->notes) {
        free(lead_update->notes);
        lead_update->notes = NULL;
    }
    if (lead_update->phone) {
        free(lead_update->phone);
        lead_update->phone = NULL;
    }
    if (lead_update->score) {
        free(lead_update->score);
        lead_update->score = NULL;
    }
    if (lead_update->source) {
        free(lead_update->source);
        lead_update->source = NULL;
    }
    if (lead_update->status) {
        lead_status_free(lead_update->status);
        lead_update->status = NULL;
    }
    if (lead_update->tags) {
        _free(lead_update->tags);
        lead_update->tags = NULL;
    }
    if (lead_update->tenant_id) {
        free(lead_update->tenant_id);
        lead_update->tenant_id = NULL;
    }
    if (lead_update->updated_at) {
        free(lead_update->updated_at);
        lead_update->updated_at = NULL;
    }
    free(lead_update);
}

cJSON *lead_update_convertToJSON(lead_update_t *lead_update) {
    cJSON *item = cJSON_CreateObject();

    // lead_update->company
    if(lead_update->company) {
    if(cJSON_AddStringToObject(item, "company", lead_update->company) == NULL) {
    goto fail; //String
    }
    }


    // lead_update->converted_at
    if(lead_update->converted_at) {
    if(cJSON_AddStringToObject(item, "convertedAt", lead_update->converted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // lead_update->created_at
    if(lead_update->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", lead_update->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // lead_update->email
    if(lead_update->email) {
    if(cJSON_AddStringToObject(item, "email", lead_update->email) == NULL) {
    goto fail; //String
    }
    }


    // lead_update->first_contact_at
    if(lead_update->first_contact_at) {
    if(cJSON_AddStringToObject(item, "firstContactAt", lead_update->first_contact_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // lead_update->name
    if(lead_update->name) {
    if(cJSON_AddStringToObject(item, "name", lead_update->name) == NULL) {
    goto fail; //String
    }
    }


    // lead_update->notes
    if(lead_update->notes) {
    if(cJSON_AddStringToObject(item, "notes", lead_update->notes) == NULL) {
    goto fail; //String
    }
    }


    // lead_update->phone
    if(lead_update->phone) {
    if(cJSON_AddStringToObject(item, "phone", lead_update->phone) == NULL) {
    goto fail; //String
    }
    }


    // lead_update->score
    if(lead_update->score) {
    if(cJSON_AddNumberToObject(item, "score", *lead_update->score) == NULL) {
    goto fail; //Numeric
    }
    }


    // lead_update->source
    if(lead_update->source) {
    if(cJSON_AddStringToObject(item, "source", lead_update->source) == NULL) {
    goto fail; //String
    }
    }


    // lead_update->status
    if(lead_update->status) {
    cJSON *status_local_JSON = lead_status_convertToJSON(lead_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // lead_update->tags
    if(lead_update->tags) {
    cJSON *tags_local_JSON = _convertToJSON(lead_update->tags);
    if(tags_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "tags", tags_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // lead_update->tenant_id
    if(lead_update->tenant_id) {
    if(cJSON_AddStringToObject(item, "tenantId", lead_update->tenant_id) == NULL) {
    goto fail; //String
    }
    }


    // lead_update->updated_at
    if(lead_update->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", lead_update->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lead_update_t *lead_update_parseFromJSON(cJSON *lead_updateJSON){

    lead_update_t *lead_update_local_var = NULL;

    char *company_local_str = NULL;

    char *converted_at_local_str = NULL;

    char *created_at_local_str = NULL;

    char *email_local_str = NULL;

    char *first_contact_at_local_str = NULL;

    char *name_local_str = NULL;

    char *notes_local_str = NULL;

    char *phone_local_str = NULL;

    // define the local variable for lead_update->score
    int *score_local_var = NULL;

    char *source_local_str = NULL;

    // define the local variable for lead_update->status
    lead_status_t *status_local_nonprim = NULL;

    // define the local variable for lead_update->tags
    _t *tags_local_nonprim = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // lead_update->company
    cJSON *company = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "company");
    if (cJSON_IsNull(company)) {
        company = NULL;
    }
    if (company) { 
    if(!cJSON_IsString(company) && !cJSON_IsNull(company))
    {
    goto end; //String
    }
    }

    // lead_update->converted_at
    cJSON *converted_at = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "convertedAt");
    if (cJSON_IsNull(converted_at)) {
        converted_at = NULL;
    }
    if (converted_at) { 
    if(!cJSON_IsString(converted_at) && !cJSON_IsNull(converted_at))
    {
    goto end; //DateTime
    }
    }

    // lead_update->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // lead_update->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // lead_update->first_contact_at
    cJSON *first_contact_at = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "firstContactAt");
    if (cJSON_IsNull(first_contact_at)) {
        first_contact_at = NULL;
    }
    if (first_contact_at) { 
    if(!cJSON_IsString(first_contact_at) && !cJSON_IsNull(first_contact_at))
    {
    goto end; //DateTime
    }
    }

    // lead_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // lead_update->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // lead_update->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // lead_update->score
    cJSON *score = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "score");
    if (cJSON_IsNull(score)) {
        score = NULL;
    }
    if (score) { 
    if(!cJSON_IsNumber(score))
    {
    goto end; //Numeric
    }
    score_local_var = malloc(sizeof(int));
    if(!score_local_var)
    {
        goto end;
    }
    *score_local_var = score->valuedouble;
    }

    // lead_update->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (source) { 
    if(!cJSON_IsString(source) && !cJSON_IsNull(source))
    {
    goto end; //String
    }
    }

    // lead_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = lead_status_parseFromJSON(status); //custom
    }

    // lead_update->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (tags) { 
    tags_local_nonprim = _parseFromJSON(tags); //custom
    }

    // lead_update->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (tenant_id) { 
    if(!cJSON_IsString(tenant_id) && !cJSON_IsNull(tenant_id))
    {
    goto end; //String
    }
    }

    // lead_update->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(lead_updateJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (company && !cJSON_IsNull(company)) company_local_str = strdup(company->valuestring);
    if (converted_at && !cJSON_IsNull(converted_at)) converted_at_local_str = strdup(converted_at->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (first_contact_at && !cJSON_IsNull(first_contact_at)) first_contact_at_local_str = strdup(first_contact_at->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (source && !cJSON_IsNull(source)) source_local_str = strdup(source->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    lead_update_local_var = lead_update_create_internal (
        company_local_str,
        converted_at_local_str,
        created_at_local_str,
        email_local_str,
        first_contact_at_local_str,
        name_local_str,
        notes_local_str,
        phone_local_str,
        score_local_var,
        source_local_str,
        status ? status_local_nonprim : NULL,
        tags ? tags_local_nonprim : NULL,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!lead_update_local_var) {
        goto end;
    }

    return lead_update_local_var;
end:
    if (company_local_str) {
        free(company_local_str);
        company_local_str = NULL;
    }
    if (converted_at_local_str) {
        free(converted_at_local_str);
        converted_at_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (first_contact_at_local_str) {
        free(first_contact_at_local_str);
        first_contact_at_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (phone_local_str) {
        free(phone_local_str);
        phone_local_str = NULL;
    }
    if (score_local_var) {
        free(score_local_var);
        score_local_var = NULL;
    }
    if (source_local_str) {
        free(source_local_str);
        source_local_str = NULL;
    }
    if (status_local_nonprim) {
        lead_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (tags_local_nonprim) {
        _free(tags_local_nonprim);
        tags_local_nonprim = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
