#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/qr_code_response.h"


qr_code_response_t*
GenerateQrcodeAPI_generateQrcodeApi(apiClient_t *apiClient, char *iban, char *id, char *holder_name, char *bic, char *amount, char *reference, char *purpose);


