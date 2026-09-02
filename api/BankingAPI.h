#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/bank_lookup.h"
#include "../model/hebesatz_lookup.h"


bank_lookup_t*
BankingAPI_bankLookupApi(apiClient_t *apiClient, char *iban);


void
BankingAPI_bankTransactionsApi(apiClient_t *apiClient);


list_t*
BankingAPI_hebesatzLookupApi(apiClient_t *apiClient, char *gemeindeschluessel, char *plz, char *name, char *stichtag, char *country_code);


