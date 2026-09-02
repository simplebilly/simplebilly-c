#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/recurring_template.h"


recurring_template_t*
RecurringTemplateAPI_createRecurringTemplate(apiClient_t *apiClient, body);


void
RecurringTemplateAPI_deleteRecurringTemplate(apiClient_t *apiClient, char *template_id);


recurring_template_t*
RecurringTemplateAPI_getRecurringTemplate(apiClient_t *apiClient, char *template_id);


list_t*
RecurringTemplateAPI_listRecurringTemplates(apiClient_t *apiClient);


