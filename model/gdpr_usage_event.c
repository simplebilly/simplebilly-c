#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_usage_event.h"



static gdpr_usage_event_t *gdpr_usage_event_create_internal(
    char *created_at,
    char *event_type,
    char *id,
    int *quantity,
    char *tenant_id
    ) {
    gdpr_usage_event_t *gdpr_usage_event_local_var = malloc(sizeof(gdpr_usage_event_t));
    if (!gdpr_usage_event_local_var) {
        return NULL;
    }
    memset(gdpr_usage_event_local_var, 0, sizeof(gdpr_usage_event_t));
    gdpr_usage_event_local_var->_library_owned = 1;
    gdpr_usage_event_local_var->created_at = created_at;
    gdpr_usage_event_local_var->event_type = event_type;
    gdpr_usage_event_local_var->id = id;
    gdpr_usage_event_local_var->quantity = quantity;
    gdpr_usage_event_local_var->tenant_id = tenant_id;
    return gdpr_usage_event_local_var;
}

__attribute__((deprecated)) gdpr_usage_event_t *gdpr_usage_event_create(
    char *created_at,
    char *event_type,
    char *id,
    int *quantity,
    char *tenant_id
    ) {
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    gdpr_usage_event_t *result = gdpr_usage_event_create_internal (
        created_at,
        event_type,
        id,
        quantity_copy,
        tenant_id
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void gdpr_usage_event_free(gdpr_usage_event_t *gdpr_usage_event) {
    if(NULL == gdpr_usage_event){
        return ;
    }
    if(gdpr_usage_event->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_usage_event_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_usage_event->created_at) {
        free(gdpr_usage_event->created_at);
        gdpr_usage_event->created_at = NULL;
    }
    if (gdpr_usage_event->event_type) {
        free(gdpr_usage_event->event_type);
        gdpr_usage_event->event_type = NULL;
    }
    if (gdpr_usage_event->id) {
        free(gdpr_usage_event->id);
        gdpr_usage_event->id = NULL;
    }
    if (gdpr_usage_event->quantity) {
        free(gdpr_usage_event->quantity);
        gdpr_usage_event->quantity = NULL;
    }
    if (gdpr_usage_event->tenant_id) {
        free(gdpr_usage_event->tenant_id);
        gdpr_usage_event->tenant_id = NULL;
    }
    free(gdpr_usage_event);
}

cJSON *gdpr_usage_event_convertToJSON(gdpr_usage_event_t *gdpr_usage_event) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_usage_event->created_at
    if (!gdpr_usage_event->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", gdpr_usage_event->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // gdpr_usage_event->event_type
    if (!gdpr_usage_event->event_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "eventType", gdpr_usage_event->event_type) == NULL) {
    goto fail; //String
    }


    // gdpr_usage_event->id
    if (!gdpr_usage_event->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", gdpr_usage_event->id) == NULL) {
    goto fail; //String
    }


    // gdpr_usage_event->quantity
    if (!gdpr_usage_event->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *gdpr_usage_event->quantity) == NULL) {
    goto fail; //Numeric
    }


    // gdpr_usage_event->tenant_id
    if (!gdpr_usage_event->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", gdpr_usage_event->tenant_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gdpr_usage_event_t *gdpr_usage_event_parseFromJSON(cJSON *gdpr_usage_eventJSON){

    gdpr_usage_event_t *gdpr_usage_event_local_var = NULL;

    char *created_at_local_str = NULL;

    char *event_type_local_str = NULL;

    char *id_local_str = NULL;

    // define the local variable for gdpr_usage_event->quantity
    int *quantity_local_var = NULL;

    char *tenant_id_local_str = NULL;

    // gdpr_usage_event->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(gdpr_usage_eventJSON, "createdAt");
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

    // gdpr_usage_event->event_type
    cJSON *event_type = cJSON_GetObjectItemCaseSensitive(gdpr_usage_eventJSON, "eventType");
    if (cJSON_IsNull(event_type)) {
        event_type = NULL;
    }
    if (!event_type) {
        goto end;
    }

    
    if(!cJSON_IsString(event_type))
    {
    goto end; //String
    }

    // gdpr_usage_event->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(gdpr_usage_eventJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // gdpr_usage_event->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(gdpr_usage_eventJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(int));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;

    // gdpr_usage_event->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(gdpr_usage_eventJSON, "tenantId");
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


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (event_type && !cJSON_IsNull(event_type)) event_type_local_str = strdup(event_type->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);

    gdpr_usage_event_local_var = gdpr_usage_event_create_internal (
        created_at_local_str,
        event_type_local_str,
        id_local_str,
        quantity_local_var,
        tenant_id_local_str
        );

    if (!gdpr_usage_event_local_var) {
        goto end;
    }

    return gdpr_usage_event_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (event_type_local_str) {
        free(event_type_local_str);
        event_type_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    return NULL;

}
