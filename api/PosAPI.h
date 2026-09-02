#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/pos_register.h"
#include "../model/pos_register_create.h"
#include "../model/pos_table.h"
#include "../model/pos_table_create.h"


any_type_t*
PosAPI_posBilling(apiClient_t *apiClient);


any_type_t*
PosAPI_posCreateOrder(apiClient_t *apiClient, body);


pos_register_t*
PosAPI_posCreateRegister(apiClient_t *apiClient, pos_register_create_t *pos_register_create);


pos_table_t*
PosAPI_posCreateTable(apiClient_t *apiClient, pos_table_create_t *pos_table_create);


pos_register_t*
PosAPI_posDisableRegister(apiClient_t *apiClient, char *id);


pos_table_t*
PosAPI_posFreeTable(apiClient_t *apiClient, char *id);


any_type_t*
PosAPI_posKasseClosing(apiClient_t *apiClient, body);


any_type_t*
PosAPI_posKasseEntries(apiClient_t *apiClient);


any_type_t*
PosAPI_posKasseExport(apiClient_t *apiClient);


any_type_t*
PosAPI_posKassePayInOut(apiClient_t *apiClient, body);


any_type_t*
PosAPI_posListOrders(apiClient_t *apiClient, char *status);


any_type_t*
PosAPI_posListProducts(apiClient_t *apiClient, char *q);


list_t*
PosAPI_posListRegisters(apiClient_t *apiClient);


list_t*
PosAPI_posListTables(apiClient_t *apiClient);


any_type_t*
PosAPI_posOrderPrint(apiClient_t *apiClient, char *order_number);


any_type_t*
PosAPI_posOrderReceipt(apiClient_t *apiClient, char *order_number);


any_type_t*
PosAPI_posPayOrder(apiClient_t *apiClient, char *order_number, body);


any_type_t*
PosAPI_posSumupCheckout(apiClient_t *apiClient, body);


