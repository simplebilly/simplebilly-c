#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/payment_condition.h"
#include "../model/plugin_error.h"


list_t*
PaymentConditionAPI_listPaymentConditionsApi(apiClient_t *apiClient);


