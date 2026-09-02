#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/service_assignment.h"
#include "../model/service_assignment_create.h"
#include "../model/service_assignment_update.h"


service_assignment_t*
ServiceAssignmentAPI_createServiceAssignment(apiClient_t *apiClient, service_assignment_create_t *service_assignment_create);


void
ServiceAssignmentAPI_deleteServiceAssignment(apiClient_t *apiClient, char *id);


service_assignment_t*
ServiceAssignmentAPI_getServiceAssignment(apiClient_t *apiClient, char *id);


list_t*
ServiceAssignmentAPI_getServiceAssignments(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


service_assignment_t*
ServiceAssignmentAPI_updateServiceAssignment(apiClient_t *apiClient, char *id, service_assignment_update_t *service_assignment_update);


