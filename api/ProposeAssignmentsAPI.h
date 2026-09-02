#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/proposed_assignment.h"


list_t*
ProposeAssignmentsAPI_proposeAssignmentsApi(apiClient_t *apiClient, double min_confidence, char *customer_id);


