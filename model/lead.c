#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lead.h"



static lead_t *lead_create_internal(
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
    simplebilly_api_lead_status__e status,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
    ) {
    lead_t *lead_local_var = malloc(sizeof(lead_t));
    if (!lead_local_var) {
        return NULL;
    }
    memset(lead_local_var, 0, sizeof(lead_t));
    lead_local_var->_library_owned = 1;
    lead_local_var->company = company;
    lead_local_var->converted_at = converted_at;
    lead_local_var->created_at = created_at;
    lead_local_var->email = email;
    lead_local_var->first_contact_at = first_contact_at;
    lead_local_var->name = name;
    lead_local_var->notes = notes;
    lead_local_var->phone = phone;
    lead_local_var->score = score;
    lead_local_var->source = source;
    lead_local_var->status = status;
    lead_local_var->tags = tags;
    lead_local_var->tenant_id = tenant_id;
    lead_local_var->updated_at = updated_at;
    return lead_local_var;
}

__attribute__((deprecated)) lead_t *lead_create(
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
    simplebilly_api_lead_status__e status,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
    ) {
    int *score_copy = NULL;
    if (score) {
        score_copy = malloc(sizeof(int));
        if (score_copy) *score_copy = *score;
    }
    lead_t *result = lead_create_internal (
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

void lead_free(lead_t *lead) {
    if(NULL == lead){
        return ;
    }
    if(lead->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lead_free");
        return ;
    }
    listEntry_t *listEntry;
    if (lead->company) {
        free(lead->company);
        lead->company = NULL;
    }
    if (lead->converted_at) {
        free(lead->converted_at);
        lead->converted_at = NULL;
    }
    if (lead->created_at) {
        free(lead->created_at);
        lead->created_at = NULL;
    }
    if (lead->email) {
        free(lead->email);
        lead->email = NULL;
    }
    if (lead->first_contact_at) {
        free(lead->first_contact_at);
        lead->first_contact_at = NULL;
    }
    if (lead->name) {
        free(lead->name);
        lead->name = NULL;
    }
    if (lead->notes) {
        free(lead->notes);
        lead->notes = NULL;
    }
    if (lead->phone) {
        free(lead->phone);
        lead->phone = NULL;
    }
    if (lead->score) {
        free(lead->score);
        lead->score = NULL;
    }
    if (lead->source) {
        free(lead->source);
        lead->source = NULL;
    }
    if (lead->tags) {
        _free(lead->tags);
        lead->tags = NULL;
    }
    if (lead->tenant_id) {
        free(lead->tenant_id);
        lead->tenant_id = NULL;
    }
    if (lead->updated_at) {
        free(lead->updated_at);
        lead->updated_at = NULL;
    }
    free(lead);
}

cJSON *lead_convertToJSON(lead_t *lead) {
    cJSON *item = cJSON_CreateObject();

    // lead->company
    if(lead->company) {
    if(cJSON_AddStringToObject(item, "company", lead->company) == NULL) {
    goto fail; //String
    }
    }


    // lead->converted_at
    if(lead->converted_at) {
    if(cJSON_AddStringToObject(item, "convertedAt", lead->converted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // lead->created_at
    if (!lead->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", lead->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // lead->email
    if(lead->email) {
    if(cJSON_AddStringToObject(item, "email", lead->email) == NULL) {
    goto fail; //String
    }
    }


    // lead->first_contact_at
    if (!lead->first_contact_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "firstContactAt", lead->first_contact_at) == NULL) {
    goto fail; //Date-Time
    }


    // lead->name
    if (!lead->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", lead->name) == NULL) {
    goto fail; //String
    }


    // lead->notes
    if(lead->notes) {
    if(cJSON_AddStringToObject(item, "notes", lead->notes) == NULL) {
    goto fail; //String
    }
    }


    // lead->phone
    if(lead->phone) {
    if(cJSON_AddStringToObject(item, "phone", lead->phone) == NULL) {
    goto fail; //String
    }
    }


    // lead->score
    if (!lead->score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "score", *lead->score) == NULL) {
    goto fail; //Numeric
    }


    // lead->source
    if (!lead->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", lead->source) == NULL) {
    goto fail; //String
    }


    // lead->status
    if (simplebilly_api_lead_status__NULL == lead->status) {
        goto fail;
    }
    cJSON *status_local_JSON = lead_status_convertToJSON(lead->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // lead->tags
    if (!lead->tags) {
        goto fail;
    }
    cJSON *tags_local_JSON = _convertToJSON(lead->tags);
    if(tags_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "tags", tags_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // lead->tenant_id
    if (!lead->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", lead->tenant_id) == NULL) {
    goto fail; //String
    }


    // lead->updated_at
    if(lead->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", lead->updated_at) == NULL) {
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

lead_t *lead_parseFromJSON(cJSON *leadJSON){

    lead_t *lead_local_var = NULL;

    char *company_local_str = NULL;

    char *converted_at_local_str = NULL;

    char *created_at_local_str = NULL;

    char *email_local_str = NULL;

    char *first_contact_at_local_str = NULL;

    char *name_local_str = NULL;

    char *notes_local_str = NULL;

    char *phone_local_str = NULL;

    // define the local variable for lead->score
    int *score_local_var = NULL;

    char *source_local_str = NULL;

    // define the local variable for lead->status
    simplebilly_api_lead_status__e status_local_nonprim = 0;

    // define the local variable for lead->tags
    _t *tags_local_nonprim = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // lead->company
    cJSON *company = cJSON_GetObjectItemCaseSensitive(leadJSON, "company");
    if (cJSON_IsNull(company)) {
        company = NULL;
    }
    if (company) { 
    if(!cJSON_IsString(company) && !cJSON_IsNull(company))
    {
    goto end; //String
    }
    }

    // lead->converted_at
    cJSON *converted_at = cJSON_GetObjectItemCaseSensitive(leadJSON, "convertedAt");
    if (cJSON_IsNull(converted_at)) {
        converted_at = NULL;
    }
    if (converted_at) { 
    if(!cJSON_IsString(converted_at) && !cJSON_IsNull(converted_at))
    {
    goto end; //DateTime
    }
    }

    // lead->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(leadJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // lead->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(leadJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // lead->first_contact_at
    cJSON *first_contact_at = cJSON_GetObjectItemCaseSensitive(leadJSON, "firstContactAt");
    if (cJSON_IsNull(first_contact_at)) {
        first_contact_at = NULL;
    }
    if (!first_contact_at) {
        goto end;
    }

    
    if(!cJSON_IsString(first_contact_at) && !cJSON_IsNull(first_contact_at))
    {
    goto end; //DateTime
    }

    // lead->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(leadJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // lead->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(leadJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // lead->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(leadJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // lead->score
    cJSON *score = cJSON_GetObjectItemCaseSensitive(leadJSON, "score");
    if (cJSON_IsNull(score)) {
        score = NULL;
    }
    if (!score) {
        goto end;
    }

    
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

    // lead->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(leadJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }

    // lead->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(leadJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = lead_status_parseFromJSON(status); //custom

    // lead->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(leadJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (!tags) {
        goto end;
    }

    
    tags_local_nonprim = _parseFromJSON(tags); //custom

    // lead->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(leadJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (!tenant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_id))
    {
    goto end; //String
    }

    // lead->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(leadJSON, "updatedAt");
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

    lead_local_var = lead_create_internal (
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
        status_local_nonprim,
        tags_local_nonprim,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!lead_local_var) {
        goto end;
    }

    return lead_local_var;
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
        status_local_nonprim = 0;
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
