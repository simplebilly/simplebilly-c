#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/sepa_direct_debit_response.h"


sepa_direct_debit_response_t*
CreateSepaDirectDebitAPI_createSepaDirectDebitApi(apiClient_t *apiClient, char *creditor_name, char *creditor_iban, char *creditor_id, char *mandate_id, char *mandate_date, char *debtor_name, char *debtor_iban, char *amount, char *collection_date, char *creditor_bic, char *debtor_bic, char *description);


