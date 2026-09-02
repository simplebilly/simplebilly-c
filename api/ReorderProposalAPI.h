#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/reorder_proposal_response.h"


// Convert a reorder proposal into a draft purchase order.
//
// Returns the created purchase order id. Suggested line items are generated with the current reorder quantity per product.
//
any_type_t*
ReorderProposalAPI_applyReorderProposal(apiClient_t *apiClient, int *configuredOnly, char *warehouseId);


reorder_proposal_response_t*
ReorderProposalAPI_getReorderProposal(apiClient_t *apiClient, int *configuredOnly, char *warehouseId);


