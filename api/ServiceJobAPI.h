#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/service_job.h"
#include "../model/service_job_create.h"
#include "../model/service_job_update.h"


service_job_t*
ServiceJobAPI_createServiceJob(apiClient_t *apiClient, service_job_create_t *service_job_create);


void
ServiceJobAPI_deleteServiceJob(apiClient_t *apiClient, char *id);


service_job_t*
ServiceJobAPI_getServiceJob(apiClient_t *apiClient, char *id);


list_t*
ServiceJobAPI_getServiceJobs(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


service_job_t*
ServiceJobAPI_updateServiceJob(apiClient_t *apiClient, char *id, service_job_update_t *service_job_update);


