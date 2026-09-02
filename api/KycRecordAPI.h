#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/kyc_record.h"
#include "../model/kyc_record_create.h"
#include "../model/kyc_record_update.h"
#include "../model/plugin_error.h"


kyc_record_t*
KycRecordAPI_createKycRecord(apiClient_t *apiClient, kyc_record_create_t *kyc_record_create);


void
KycRecordAPI_deleteKycRecord(apiClient_t *apiClient, char *id);


kyc_record_t*
KycRecordAPI_getKycRecord(apiClient_t *apiClient, char *id);


list_t*
KycRecordAPI_getKycRecords(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


kyc_record_t*
KycRecordAPI_updateKycRecord(apiClient_t *apiClient, char *id, kyc_record_update_t *kyc_record_update);


