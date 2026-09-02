#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_shipment_request.h"



static create_shipment_request_t *create_shipment_request_create_internal(
    char *carrier,
    char *service,
    double *weight_kg
    ) {
    create_shipment_request_t *create_shipment_request_local_var = malloc(sizeof(create_shipment_request_t));
    if (!create_shipment_request_local_var) {
        return NULL;
    }
    memset(create_shipment_request_local_var, 0, sizeof(create_shipment_request_t));
    create_shipment_request_local_var->_library_owned = 1;
    create_shipment_request_local_var->carrier = carrier;
    create_shipment_request_local_var->service = service;
    create_shipment_request_local_var->weight_kg = weight_kg;
    return create_shipment_request_local_var;
}

__attribute__((deprecated)) create_shipment_request_t *create_shipment_request_create(
    char *carrier,
    char *service,
    double *weight_kg
    ) {
    double *weight_kg_copy = NULL;
    if (weight_kg) {
        weight_kg_copy = malloc(sizeof(double));
        if (weight_kg_copy) *weight_kg_copy = *weight_kg;
    }
    create_shipment_request_t *result = create_shipment_request_create_internal (
        carrier,
        service,
        weight_kg_copy
        );
    if (!result) {
        free(weight_kg_copy);
    }
    return result;
}

void create_shipment_request_free(create_shipment_request_t *create_shipment_request) {
    if(NULL == create_shipment_request){
        return ;
    }
    if(create_shipment_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_shipment_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_shipment_request->carrier) {
        free(create_shipment_request->carrier);
        create_shipment_request->carrier = NULL;
    }
    if (create_shipment_request->service) {
        free(create_shipment_request->service);
        create_shipment_request->service = NULL;
    }
    if (create_shipment_request->weight_kg) {
        free(create_shipment_request->weight_kg);
        create_shipment_request->weight_kg = NULL;
    }
    free(create_shipment_request);
}

cJSON *create_shipment_request_convertToJSON(create_shipment_request_t *create_shipment_request) {
    cJSON *item = cJSON_CreateObject();

    // create_shipment_request->carrier
    if (!create_shipment_request->carrier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "carrier", create_shipment_request->carrier) == NULL) {
    goto fail; //String
    }


    // create_shipment_request->service
    if(create_shipment_request->service) {
    if(cJSON_AddStringToObject(item, "service", create_shipment_request->service) == NULL) {
    goto fail; //String
    }
    }


    // create_shipment_request->weight_kg
    if(create_shipment_request->weight_kg) {
    if(cJSON_AddNumberToObject(item, "weight_kg", *create_shipment_request->weight_kg) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_shipment_request_t *create_shipment_request_parseFromJSON(cJSON *create_shipment_requestJSON){

    create_shipment_request_t *create_shipment_request_local_var = NULL;

    char *carrier_local_str = NULL;

    char *service_local_str = NULL;

    // define the local variable for create_shipment_request->weight_kg
    double *weight_kg_local_var = NULL;

    // create_shipment_request->carrier
    cJSON *carrier = cJSON_GetObjectItemCaseSensitive(create_shipment_requestJSON, "carrier");
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

    // create_shipment_request->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(create_shipment_requestJSON, "service");
    if (cJSON_IsNull(service)) {
        service = NULL;
    }
    if (service) { 
    if(!cJSON_IsString(service) && !cJSON_IsNull(service))
    {
    goto end; //String
    }
    }

    // create_shipment_request->weight_kg
    cJSON *weight_kg = cJSON_GetObjectItemCaseSensitive(create_shipment_requestJSON, "weight_kg");
    if (cJSON_IsNull(weight_kg)) {
        weight_kg = NULL;
    }
    if (weight_kg) { 
    if(!cJSON_IsNumber(weight_kg))
    {
    goto end; //Numeric
    }
    weight_kg_local_var = malloc(sizeof(double));
    if(!weight_kg_local_var)
    {
        goto end;
    }
    *weight_kg_local_var = weight_kg->valuedouble;
    }


    if (carrier && !cJSON_IsNull(carrier)) carrier_local_str = strdup(carrier->valuestring);
    if (service && !cJSON_IsNull(service)) service_local_str = strdup(service->valuestring);

    create_shipment_request_local_var = create_shipment_request_create_internal (
        carrier_local_str,
        service_local_str,
        weight_kg_local_var
        );

    if (!create_shipment_request_local_var) {
        goto end;
    }

    return create_shipment_request_local_var;
end:
    if (carrier_local_str) {
        free(carrier_local_str);
        carrier_local_str = NULL;
    }
    if (service_local_str) {
        free(service_local_str);
        service_local_str = NULL;
    }
    if (weight_kg_local_var) {
        free(weight_kg_local_var);
        weight_kg_local_var = NULL;
    }
    return NULL;

}
