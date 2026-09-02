#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/delivery_date.h"
#include "../model/delivery_date_create.h"
#include "../model/delivery_date_status_update.h"
#include "../model/plugin_error.h"


delivery_date_t*
DeliveryDateAPI_createDeliveryDate(apiClient_t *apiClient, delivery_date_create_t *delivery_date_create);


void
DeliveryDateAPI_deleteDeliveryDate(apiClient_t *apiClient, char *delivery_date_id);


delivery_date_t*
DeliveryDateAPI_getDeliveryDate(apiClient_t *apiClient, char *delivery_date_id);


// On-time performance summary: how many promised delivery dates were met within a period.
//
any_type_t*
DeliveryDateAPI_getDeliveryPerformance(apiClient_t *apiClient, int *page, int *pageSize, char *orderNumber, char *status, char from, char to);


list_t*
DeliveryDateAPI_listDeliveryDates(apiClient_t *apiClient, int *page, int *pageSize, char *orderNumber, char *status, char from, char to);


delivery_date_t*
DeliveryDateAPI_updateDeliveryDate(apiClient_t *apiClient, char *delivery_date_id, body);


delivery_date_t*
DeliveryDateAPI_updateDeliveryDateStatus(apiClient_t *apiClient, char *delivery_date_id, delivery_date_status_update_t *delivery_date_status_update);


