/*
 * service_job_create.h
 *
 * 
 */

#ifndef _service_job_create_H_
#define _service_job_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_job_create_t service_job_create_t;

#include "service_job_status.h"



typedef struct service_job_create_t {
    char *address; // string
    char *customer_email; // string
    char *customer_id; // string
    char *customer_name; // string
    char *customer_phone; // string
    char *description; // string
    int *estimated_duration_minutes; //numeric
    double *lat; //numeric
    double *lng; //numeric
    char *notes; // string
    service_job_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} service_job_create_t;

__attribute__((deprecated)) service_job_create_t *service_job_create_create(
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
);

void service_job_create_free(service_job_create_t *service_job_create);

service_job_create_t *service_job_create_parseFromJSON(cJSON *service_job_createJSON);

cJSON *service_job_create_convertToJSON(service_job_create_t *service_job_create);

#endif /* _service_job_create_H_ */

