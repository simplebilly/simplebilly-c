/*
 * ticket_priority.h
 *
 * Support ticket priority.
 */

#ifndef _ticket_priority_H_
#define _ticket_priority_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ticket_priority_t ticket_priority_t;


// Enum  for ticket_priority

typedef enum { simplebilly_api_ticket_priority__NULL = 0, simplebilly_api_ticket_priority__normal, simplebilly_api_ticket_priority__high } simplebilly_api_ticket_priority__e;

char* ticket_priority_ticket_priority_ToString(simplebilly_api_ticket_priority__e ticket_priority);

simplebilly_api_ticket_priority__e ticket_priority_ticket_priority_FromString(char* ticket_priority);

cJSON *ticket_priority_convertToJSON(simplebilly_api_ticket_priority__e ticket_priority);

simplebilly_api_ticket_priority__e ticket_priority_parseFromJSON(cJSON *ticket_priorityJSON);

#endif /* _ticket_priority_H_ */

