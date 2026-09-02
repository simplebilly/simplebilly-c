#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/x_rechnung_response.h"


x_rechnung_response_t*
GenerateXrechnungAPI_generateXrechnungApi(apiClient_t *apiClient, char *id, char *supplier_name, char *supplier_street, char *supplier_city, char *supplier_zip, char *supplier_country, char *supplier_vat_id);


