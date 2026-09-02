#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/open_item.h"


list_t*
ListOpenItemsAPI_listOpenItemsApi(apiClient_t *apiClient, long reminder_level1_days, long reminder_level2_days, long reminder_level3_days, char *customer_id);


