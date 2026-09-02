/*
 * rfq_status.h
 *
 * RFQ status.
 */

#ifndef _rfq_status_H_
#define _rfq_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rfq_status_t rfq_status_t;


// Enum  for rfq_status

typedef enum { simplebilly_api_rfq_status__NULL = 0, simplebilly_api_rfq_status__draft, simplebilly_api_rfq_status__sent, simplebilly_api_rfq_status__offer_received, simplebilly_api_rfq_status__rejected, simplebilly_api_rfq_status__converted } simplebilly_api_rfq_status__e;

char* rfq_status_rfq_status_ToString(simplebilly_api_rfq_status__e rfq_status);

simplebilly_api_rfq_status__e rfq_status_rfq_status_FromString(char* rfq_status);

cJSON *rfq_status_convertToJSON(simplebilly_api_rfq_status__e rfq_status);

simplebilly_api_rfq_status__e rfq_status_parseFromJSON(cJSON *rfq_statusJSON);

#endif /* _rfq_status_H_ */

