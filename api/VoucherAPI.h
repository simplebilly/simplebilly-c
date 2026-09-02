#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/plugin_error.h"
#include "../model/voucher.h"
#include "../model/voucher_create.h"


voucher_t*
VoucherAPI_createVoucher(apiClient_t *apiClient, voucher_create_t *voucher_create);


void
VoucherAPI_deleteVoucher(apiClient_t *apiClient, char *voucher_id);


voucher_t*
VoucherAPI_getVoucher(apiClient_t *apiClient, char *voucher_id);


list_t*
VoucherAPI_listVouchers(apiClient_t *apiClient, int *page, int *page_size, char *voucher_type, char *voucher_status, char *contact_name, char date_from, char date_to);


voucher_t*
VoucherAPI_updateVoucher(apiClient_t *apiClient, char *voucher_id, body);


voucher_t*
VoucherAPI_voucherRestore(apiClient_t *apiClient, char *voucher_id);


