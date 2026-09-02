#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/tax_rate_create.h"


// Create a tax rate (`admin:settings`).
//
void
TaxAPI_createTaxRate(apiClient_t *apiClient, tax_rate_create_t *tax_rate_create);


// Delete a tax rate by id (`admin:settings`).
//
void
TaxAPI_deleteTaxRate(apiClient_t *apiClient, char *id);


// List the calling tenant's tax rates.
//
void
TaxAPI_listTaxRates(apiClient_t *apiClient);


// Update a tax rate by id (`admin:settings`). Replaces all body fields.
//
void
TaxAPI_updateTaxRate(apiClient_t *apiClient, char *id, tax_rate_create_t *tax_rate_create);


