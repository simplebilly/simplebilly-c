#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/lead.h"
#include "../model/lead_update.h"


list_t*
LeadAPI_listLeadsApi(apiClient_t *apiClient, char *status, char *source, char *search, int *page, int *page_size);


lead_t*
LeadAPI_updateLeadApi(apiClient_t *apiClient, char *lead_id, lead_update_t *lead_update);


