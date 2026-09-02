#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/activity.h"
#include "../model/activity_status_update.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"


activity_t*
ActivityAPI_createActivity(apiClient_t *apiClient, activity_t *activity);


void
ActivityAPI_deleteActivity(apiClient_t *apiClient, char *activity_id);


activity_t*
ActivityAPI_getActivity(apiClient_t *apiClient, char *activity_id);


list_t*
ActivityAPI_listActivities(apiClient_t *apiClient, int *page, int *pageSize, char *contactId, char *activityType, char *status, char *assignedTo, int *overdueOnly);


activity_t*
ActivityAPI_updateActivity(apiClient_t *apiClient, char *activity_id, body);


activity_t*
ActivityAPI_updateActivityStatus(apiClient_t *apiClient, char *activity_id, activity_status_update_t *activity_status_update);


