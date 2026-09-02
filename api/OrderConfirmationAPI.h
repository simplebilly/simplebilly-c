#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/delivery_note.h"
#include "../model/order_confirmation.h"
#include "../model/order_confirmation_create.h"
#include "../model/plugin_error.h"


order_confirmation_t*
OrderConfirmationAPI_createConfirmation(apiClient_t *apiClient, order_confirmation_create_t *order_confirmation_create);


void
OrderConfirmationAPI_deleteConfirmation(apiClient_t *apiClient, char *confirmation_id);


void
OrderConfirmationAPI_downloadConfirmationPdf(apiClient_t *apiClient, char *confirmation_id);


order_confirmation_t*
OrderConfirmationAPI_getConfirmation(apiClient_t *apiClient, char *confirmation_id);


list_t*
OrderConfirmationAPI_listConfirmations(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


order_confirmation_t*
OrderConfirmationAPI_orderconfirmationRestore(apiClient_t *apiClient, char *confirmation_id);


delivery_note_t*
OrderConfirmationAPI_pursueConfirmation(apiClient_t *apiClient, char *confirmation_id);


