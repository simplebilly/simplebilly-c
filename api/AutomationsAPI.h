#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/automation_dto.h"
#include "../model/object.h"
#include "../model/update_automation.h"


list_t*
AutomationsAPI_listAutomations(apiClient_t *apiClient);


object_t*
AutomationsAPI_triggerAutomation(apiClient_t *apiClient, char *key);


automation_dto_t*
AutomationsAPI_updateAutomation(apiClient_t *apiClient, char *key, update_automation_t *update_automation);


