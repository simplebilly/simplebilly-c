/*
 * support_ticket_status.h
 *
 * Support ticket status.
 */

#ifndef _support_ticket_status_H_
#define _support_ticket_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct support_ticket_status_t support_ticket_status_t;


// Enum  for support_ticket_status

typedef enum { simplebilly_api_support_ticket_status__NULL = 0, simplebilly_api_support_ticket_status__open, simplebilly_api_support_ticket_status__awaiting_reply, simplebilly_api_support_ticket_status__resolved, simplebilly_api_support_ticket_status__closed } simplebilly_api_support_ticket_status__e;

char* support_ticket_status_support_ticket_status_ToString(simplebilly_api_support_ticket_status__e support_ticket_status);

simplebilly_api_support_ticket_status__e support_ticket_status_support_ticket_status_FromString(char* support_ticket_status);

cJSON *support_ticket_status_convertToJSON(simplebilly_api_support_ticket_status__e support_ticket_status);

simplebilly_api_support_ticket_status__e support_ticket_status_parseFromJSON(cJSON *support_ticket_statusJSON);

#endif /* _support_ticket_status_H_ */

