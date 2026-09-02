#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/rfq.h"
#include "../model/rfq_status_update.h"


// Convert an RFQ into a draft purchase order using the quoted unit prices (falling back to the requested prices, then leaving them blank). Marks the RFQ as `converted`.
//
any_type_t*
RfqAPI_convertRfq(apiClient_t *apiClient, char *rfq_id);


rfq_t*
RfqAPI_createRfq(apiClient_t *apiClient, rfq_t *rfq);


void
RfqAPI_deleteRfq(apiClient_t *apiClient, char *rfq_id);


rfq_t*
RfqAPI_getRfq(apiClient_t *apiClient, char *rfq_id);


list_t*
RfqAPI_listRfqs(apiClient_t *apiClient, int *page, int *page_size, char *status, char *supplier_name);


rfq_t*
RfqAPI_updateRfq(apiClient_t *apiClient, char *rfq_id, body);


rfq_t*
RfqAPI_updateRfqStatus(apiClient_t *apiClient, char *rfq_id, rfq_status_update_t *rfq_status_update);


