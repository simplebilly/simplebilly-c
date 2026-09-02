#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_job.h"



static service_job_t *service_job_create_internal(
    char *address,
    char *customer_email,
    char *customer_id,
    char *customer_name,
    char *customer_phone,
    char *description,
    int *estimated_duration_minutes,
    double *lat,
    double *lng,
    char *notes,
    service_job_status_t *status
    ) {
    service_job_t *service_job_local_var = malloc(sizeof(service_job_t));
    if (!service_job_local_var) {
        return NULL;
    }
    memset(service_job_local_var, 0, sizeof(service_job_t));
    service_job_local_var->_library_owned = 1;
    service_job_local_var->address = address;
    service_job_local_var->customer_email = customer_email;
    service_job_local_var->customer_id = customer_id;
    service_job_local_var->customer_name = customer_name;
    service_job_local_var->customer_phone = customer_phone;
    service_job_local_var->description = description;
    service_job_local_var->estimated_duration_minutes = estimated_duration_minutes;
    service_job_local_var->lat = lat;
    service_job_local_var->lng = lng;
    service_job_local_var->notes = notes;
    service_job_local_var->status = status;
    return service_job_local_var;
}

__attribute__((deprecated)) service_job_t *service_job_create(
    char *address,
    char *customer_email,
    char *customer_id,
    char *customer_name,
    char *customer_phone,
    char *description,
    int *estimated_duration_minutes,
    double *lat,
    double *lng,
    char *notes,
    service_job_status_t *status
    ) {
    int *estimated_duration_minutes_copy = NULL;
    if (estimated_duration_minutes) {
        estimated_duration_minutes_copy = malloc(sizeof(int));
        if (estimated_duration_minutes_copy) *estimated_duration_minutes_copy = *estimated_duration_minutes;
    }
    double *lat_copy = NULL;
    if (lat) {
        lat_copy = malloc(sizeof(double));
        if (lat_copy) *lat_copy = *lat;
    }
    double *lng_copy = NULL;
    if (lng) {
        lng_copy = malloc(sizeof(double));
        if (lng_copy) *lng_copy = *lng;
    }
    service_job_t *result = service_job_create_internal (
        address,
        customer_email,
        customer_id,
        customer_name,
        customer_phone,
        description,
        estimated_duration_minutes_copy,
        lat_copy,
        lng_copy,
        notes,
        status
        );
    if (!result) {
        free(estimated_duration_minutes_copy);
        free(lat_copy);
        free(lng_copy);
    }
    return result;
}

void service_job_free(service_job_t *service_job) {
    if(NULL == service_job){
        return ;
    }
    if(service_job->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "service_job_free");
        return ;
    }
    listEntry_t *listEntry;
    if (service_job->address) {
        free(service_job->address);
        service_job->address = NULL;
    }
    if (service_job->customer_email) {
        free(service_job->customer_email);
        service_job->customer_email = NULL;
    }
    if (service_job->customer_id) {
        free(service_job->customer_id);
        service_job->customer_id = NULL;
    }
    if (service_job->customer_name) {
        free(service_job->customer_name);
        service_job->customer_name = NULL;
    }
    if (service_job->customer_phone) {
        free(service_job->customer_phone);
        service_job->customer_phone = NULL;
    }
    if (service_job->description) {
        free(service_job->description);
        service_job->description = NULL;
    }
    if (service_job->estimated_duration_minutes) {
        free(service_job->estimated_duration_minutes);
        service_job->estimated_duration_minutes = NULL;
    }
    if (service_job->lat) {
        free(service_job->lat);
        service_job->lat = NULL;
    }
    if (service_job->lng) {
        free(service_job->lng);
        service_job->lng = NULL;
    }
    if (service_job->notes) {
        free(service_job->notes);
        service_job->notes = NULL;
    }
    if (service_job->status) {
        service_job_status_free(service_job->status);
        service_job->status = NULL;
    }
    free(service_job);
}

cJSON *service_job_convertToJSON(service_job_t *service_job) {
    cJSON *item = cJSON_CreateObject();

    // service_job->address
    if(service_job->address) {
    if(cJSON_AddStringToObject(item, "address", service_job->address) == NULL) {
    goto fail; //String
    }
    }


    // service_job->customer_email
    if(service_job->customer_email) {
    if(cJSON_AddStringToObject(item, "customerEmail", service_job->customer_email) == NULL) {
    goto fail; //String
    }
    }


    // service_job->customer_id
    if(service_job->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", service_job->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // service_job->customer_name
    if(service_job->customer_name) {
    if(cJSON_AddStringToObject(item, "customerName", service_job->customer_name) == NULL) {
    goto fail; //String
    }
    }


    // service_job->customer_phone
    if(service_job->customer_phone) {
    if(cJSON_AddStringToObject(item, "customerPhone", service_job->customer_phone) == NULL) {
    goto fail; //String
    }
    }


    // service_job->description
    if(service_job->description) {
    if(cJSON_AddStringToObject(item, "description", service_job->description) == NULL) {
    goto fail; //String
    }
    }


    // service_job->estimated_duration_minutes
    if(service_job->estimated_duration_minutes) {
    if(cJSON_AddNumberToObject(item, "estimatedDurationMinutes", *service_job->estimated_duration_minutes) == NULL) {
    goto fail; //Numeric
    }
    }


    // service_job->lat
    if(service_job->lat) {
    if(cJSON_AddNumberToObject(item, "lat", *service_job->lat) == NULL) {
    goto fail; //Numeric
    }
    }


    // service_job->lng
    if(service_job->lng) {
    if(cJSON_AddNumberToObject(item, "lng", *service_job->lng) == NULL) {
    goto fail; //Numeric
    }
    }


    // service_job->notes
    if(service_job->notes) {
    if(cJSON_AddStringToObject(item, "notes", service_job->notes) == NULL) {
    goto fail; //String
    }
    }


    // service_job->status
    if(service_job->status) {
    cJSON *status_local_JSON = service_job_status_convertToJSON(service_job->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

service_job_t *service_job_parseFromJSON(cJSON *service_jobJSON){

    service_job_t *service_job_local_var = NULL;

    char *address_local_str = NULL;

    char *customer_email_local_str = NULL;

    char *customer_id_local_str = NULL;

    char *customer_name_local_str = NULL;

    char *customer_phone_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for service_job->estimated_duration_minutes
    int *estimated_duration_minutes_local_var = NULL;

    // define the local variable for service_job->lat
    double *lat_local_var = NULL;

    // define the local variable for service_job->lng
    double *lng_local_var = NULL;

    char *notes_local_str = NULL;

    // define the local variable for service_job->status
    service_job_status_t *status_local_nonprim = NULL;

    // service_job->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // service_job->customer_email
    cJSON *customer_email = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "customerEmail");
    if (cJSON_IsNull(customer_email)) {
        customer_email = NULL;
    }
    if (customer_email) { 
    if(!cJSON_IsString(customer_email) && !cJSON_IsNull(customer_email))
    {
    goto end; //String
    }
    }

    // service_job->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // service_job->customer_name
    cJSON *customer_name = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "customerName");
    if (cJSON_IsNull(customer_name)) {
        customer_name = NULL;
    }
    if (customer_name) { 
    if(!cJSON_IsString(customer_name) && !cJSON_IsNull(customer_name))
    {
    goto end; //String
    }
    }

    // service_job->customer_phone
    cJSON *customer_phone = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "customerPhone");
    if (cJSON_IsNull(customer_phone)) {
        customer_phone = NULL;
    }
    if (customer_phone) { 
    if(!cJSON_IsString(customer_phone) && !cJSON_IsNull(customer_phone))
    {
    goto end; //String
    }
    }

    // service_job->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // service_job->estimated_duration_minutes
    cJSON *estimated_duration_minutes = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "estimatedDurationMinutes");
    if (cJSON_IsNull(estimated_duration_minutes)) {
        estimated_duration_minutes = NULL;
    }
    if (estimated_duration_minutes) { 
    if(!cJSON_IsNumber(estimated_duration_minutes))
    {
    goto end; //Numeric
    }
    estimated_duration_minutes_local_var = malloc(sizeof(int));
    if(!estimated_duration_minutes_local_var)
    {
        goto end;
    }
    *estimated_duration_minutes_local_var = estimated_duration_minutes->valuedouble;
    }

    // service_job->lat
    cJSON *lat = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "lat");
    if (cJSON_IsNull(lat)) {
        lat = NULL;
    }
    if (lat) { 
    if(!cJSON_IsNumber(lat))
    {
    goto end; //Numeric
    }
    lat_local_var = malloc(sizeof(double));
    if(!lat_local_var)
    {
        goto end;
    }
    *lat_local_var = lat->valuedouble;
    }

    // service_job->lng
    cJSON *lng = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "lng");
    if (cJSON_IsNull(lng)) {
        lng = NULL;
    }
    if (lng) { 
    if(!cJSON_IsNumber(lng))
    {
    goto end; //Numeric
    }
    lng_local_var = malloc(sizeof(double));
    if(!lng_local_var)
    {
        goto end;
    }
    *lng_local_var = lng->valuedouble;
    }

    // service_job->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // service_job->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(service_jobJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = service_job_status_parseFromJSON(status); //custom
    }


    if (address && !cJSON_IsNull(address)) address_local_str = strdup(address->valuestring);
    if (customer_email && !cJSON_IsNull(customer_email)) customer_email_local_str = strdup(customer_email->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (customer_name && !cJSON_IsNull(customer_name)) customer_name_local_str = strdup(customer_name->valuestring);
    if (customer_phone && !cJSON_IsNull(customer_phone)) customer_phone_local_str = strdup(customer_phone->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);

    service_job_local_var = service_job_create_internal (
        address_local_str,
        customer_email_local_str,
        customer_id_local_str,
        customer_name_local_str,
        customer_phone_local_str,
        description_local_str,
        estimated_duration_minutes_local_var,
        lat_local_var,
        lng_local_var,
        notes_local_str,
        status ? status_local_nonprim : NULL
        );

    if (!service_job_local_var) {
        goto end;
    }

    return service_job_local_var;
end:
    if (address_local_str) {
        free(address_local_str);
        address_local_str = NULL;
    }
    if (customer_email_local_str) {
        free(customer_email_local_str);
        customer_email_local_str = NULL;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (customer_name_local_str) {
        free(customer_name_local_str);
        customer_name_local_str = NULL;
    }
    if (customer_phone_local_str) {
        free(customer_phone_local_str);
        customer_phone_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (estimated_duration_minutes_local_var) {
        free(estimated_duration_minutes_local_var);
        estimated_duration_minutes_local_var = NULL;
    }
    if (lat_local_var) {
        free(lat_local_var);
        lat_local_var = NULL;
    }
    if (lng_local_var) {
        free(lng_local_var);
        lng_local_var = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (status_local_nonprim) {
        service_job_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
