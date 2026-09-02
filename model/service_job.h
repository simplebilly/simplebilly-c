/*
 * service_job.h
 *
 * 
 */

#ifndef _service_job_H_
#define _service_job_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_job_t service_job_t;

#include "service_job_status.h"



typedef struct service_job_t {
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
} service_job_t;

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
);

void service_job_free(service_job_t *service_job);

service_job_t *service_job_parseFromJSON(cJSON *service_jobJSON);

cJSON *service_job_convertToJSON(service_job_t *service_job);

#endif /* _service_job_H_ */

