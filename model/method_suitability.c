#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "method_suitability.h"



static method_suitability_t *method_suitability_create_internal(
    char *carrier,
    shipping_rate_t *rate,
    list_t *reasons,
    char *service,
    int *suitable
    ) {
    method_suitability_t *method_suitability_local_var = malloc(sizeof(method_suitability_t));
    if (!method_suitability_local_var) {
        return NULL;
    }
    memset(method_suitability_local_var, 0, sizeof(method_suitability_t));
    method_suitability_local_var->_library_owned = 1;
    method_suitability_local_var->carrier = carrier;
    method_suitability_local_var->rate = rate;
    method_suitability_local_var->reasons = reasons;
    method_suitability_local_var->service = service;
    method_suitability_local_var->suitable = suitable;
    return method_suitability_local_var;
}

__attribute__((deprecated)) method_suitability_t *method_suitability_create(
    char *carrier,
    shipping_rate_t *rate,
    list_t *reasons,
    char *service,
    int *suitable
    ) {
    int *suitable_copy = NULL;
    if (suitable) {
        suitable_copy = malloc(sizeof(int));
        if (suitable_copy) *suitable_copy = *suitable;
    }
    method_suitability_t *result = method_suitability_create_internal (
        carrier,
        rate,
        reasons,
        service,
        suitable_copy
        );
    if (!result) {
        free(suitable_copy);
    }
    return result;
}

void method_suitability_free(method_suitability_t *method_suitability) {
    if(NULL == method_suitability){
        return ;
    }
    if(method_suitability->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "method_suitability_free");
        return ;
    }
    listEntry_t *listEntry;
    if (method_suitability->carrier) {
        free(method_suitability->carrier);
        method_suitability->carrier = NULL;
    }
    if (method_suitability->rate) {
        shipping_rate_free(method_suitability->rate);
        method_suitability->rate = NULL;
    }
    if (method_suitability->reasons) {
        list_ForEach(listEntry, method_suitability->reasons) {
            free(listEntry->data);
        }
        list_freeList(method_suitability->reasons);
        method_suitability->reasons = NULL;
    }
    if (method_suitability->service) {
        free(method_suitability->service);
        method_suitability->service = NULL;
    }
    if (method_suitability->suitable) {
        free(method_suitability->suitable);
        method_suitability->suitable = NULL;
    }
    free(method_suitability);
}

cJSON *method_suitability_convertToJSON(method_suitability_t *method_suitability) {
    cJSON *item = cJSON_CreateObject();

    // method_suitability->carrier
    if (!method_suitability->carrier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "carrier", method_suitability->carrier) == NULL) {
    goto fail; //String
    }


    // method_suitability->rate
    if(method_suitability->rate) {
    cJSON *rate_local_JSON = shipping_rate_convertToJSON(method_suitability->rate);
    if(rate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rate", rate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // method_suitability->reasons
    if (!method_suitability->reasons) {
        goto fail;
    }
    cJSON *reasons = cJSON_AddArrayToObject(item, "reasons");
    if(reasons == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *reasonsListEntry;
    list_ForEach(reasonsListEntry, method_suitability->reasons) {
    if(cJSON_AddStringToObject(reasons, "", reasonsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // method_suitability->service
    if (!method_suitability->service) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "service", method_suitability->service) == NULL) {
    goto fail; //String
    }


    // method_suitability->suitable
    if (!method_suitability->suitable) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "suitable", *method_suitability->suitable) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

method_suitability_t *method_suitability_parseFromJSON(cJSON *method_suitabilityJSON){

    method_suitability_t *method_suitability_local_var = NULL;

    char *carrier_local_str = NULL;

    // define the local variable for method_suitability->rate
    shipping_rate_t *rate_local_nonprim = NULL;

    // define the local list for method_suitability->reasons
    list_t *reasonsList = NULL;

    char *service_local_str = NULL;

    // define the local variable for method_suitability->suitable
    int *suitable_local_var = NULL;

    // method_suitability->carrier
    cJSON *carrier = cJSON_GetObjectItemCaseSensitive(method_suitabilityJSON, "carrier");
    if (cJSON_IsNull(carrier)) {
        carrier = NULL;
    }
    if (!carrier) {
        goto end;
    }

    
    if(!cJSON_IsString(carrier))
    {
    goto end; //String
    }

    // method_suitability->rate
    cJSON *rate = cJSON_GetObjectItemCaseSensitive(method_suitabilityJSON, "rate");
    if (cJSON_IsNull(rate)) {
        rate = NULL;
    }
    if (rate) { 
    rate_local_nonprim = shipping_rate_parseFromJSON(rate); //nonprimitive
    }

    // method_suitability->reasons
    cJSON *reasons = cJSON_GetObjectItemCaseSensitive(method_suitabilityJSON, "reasons");
    if (cJSON_IsNull(reasons)) {
        reasons = NULL;
    }
    if (!reasons) {
        goto end;
    }

    
    cJSON *reasons_local = NULL;
    if(!cJSON_IsArray(reasons)) {
        goto end;//primitive container
    }
    reasonsList = list_createList();

    cJSON_ArrayForEach(reasons_local, reasons)
    {
        if(!cJSON_IsString(reasons_local))
        {
            goto end;
        }
        list_addElement(reasonsList , strdup(reasons_local->valuestring));
    }

    // method_suitability->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(method_suitabilityJSON, "service");
    if (cJSON_IsNull(service)) {
        service = NULL;
    }
    if (!service) {
        goto end;
    }

    
    if(!cJSON_IsString(service))
    {
    goto end; //String
    }

    // method_suitability->suitable
    cJSON *suitable = cJSON_GetObjectItemCaseSensitive(method_suitabilityJSON, "suitable");
    if (cJSON_IsNull(suitable)) {
        suitable = NULL;
    }
    if (!suitable) {
        goto end;
    }

    
    if(!cJSON_IsBool(suitable))
    {
    goto end; //Bool
    }
    suitable_local_var = malloc(sizeof(int));
    if(!suitable_local_var)
    {
        goto end;
    }
    *suitable_local_var = suitable->valueint;


    if (carrier && !cJSON_IsNull(carrier)) carrier_local_str = strdup(carrier->valuestring);
    if (service && !cJSON_IsNull(service)) service_local_str = strdup(service->valuestring);

    method_suitability_local_var = method_suitability_create_internal (
        carrier_local_str,
        rate ? rate_local_nonprim : NULL,
        reasonsList,
        service_local_str,
        suitable_local_var
        );

    if (!method_suitability_local_var) {
        goto end;
    }

    return method_suitability_local_var;
end:
    if (carrier_local_str) {
        free(carrier_local_str);
        carrier_local_str = NULL;
    }
    if (rate_local_nonprim) {
        shipping_rate_free(rate_local_nonprim);
        rate_local_nonprim = NULL;
    }
    if (reasonsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, reasonsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(reasonsList);
        reasonsList = NULL;
    }
    if (service_local_str) {
        free(service_local_str);
        service_local_str = NULL;
    }
    if (suitable_local_var) {
        free(suitable_local_var);
        suitable_local_var = NULL;
    }
    return NULL;

}
