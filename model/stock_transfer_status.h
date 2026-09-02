/*
 * stock_transfer_status.h
 *
 * Stock transfer status.
 */

#ifndef _stock_transfer_status_H_
#define _stock_transfer_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stock_transfer_status_t stock_transfer_status_t;


// Enum  for stock_transfer_status

typedef enum { simplebilly_api_stock_transfer_status__NULL = 0, simplebilly_api_stock_transfer_status__draft, simplebilly_api_stock_transfer_status__completed, simplebilly_api_stock_transfer_status__cancelled } simplebilly_api_stock_transfer_status__e;

char* stock_transfer_status_stock_transfer_status_ToString(simplebilly_api_stock_transfer_status__e stock_transfer_status);

simplebilly_api_stock_transfer_status__e stock_transfer_status_stock_transfer_status_FromString(char* stock_transfer_status);

cJSON *stock_transfer_status_convertToJSON(simplebilly_api_stock_transfer_status__e stock_transfer_status);

simplebilly_api_stock_transfer_status__e stock_transfer_status_parseFromJSON(cJSON *stock_transfer_statusJSON);

#endif /* _stock_transfer_status_H_ */

