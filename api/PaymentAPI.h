#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/payment.h"
#include "../model/payment_create.h"
#include "../model/plugin_error.h"


payment_t*
PaymentAPI_createPayment(apiClient_t *apiClient, payment_create_t *payment_create);


void
PaymentAPI_deletePayment(apiClient_t *apiClient, char *id);


payment_t*
PaymentAPI_getPayment(apiClient_t *apiClient, char *id);


list_t*
PaymentAPI_getPayments(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


payment_t*
PaymentAPI_paymentRestore(apiClient_t *apiClient, char *id);


payment_t*
PaymentAPI_updatePayment(apiClient_t *apiClient, char *id, body);


