#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/plugin_error.h"
#include "../model/workflow.h"
#include "../model/workflow_enabled_update.h"


list_t*
WorkflowsAPI_listWorkflowsApi(apiClient_t *apiClient);


workflow_t*
WorkflowsAPI_setWorkflowEnabledApi(apiClient_t *apiClient, char *workflow_id, workflow_enabled_update_t *workflow_enabled_update);


