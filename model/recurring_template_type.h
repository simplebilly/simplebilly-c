/*
 * recurring_template_type.h
 *
 * Recurring template type.
 */

#ifndef _recurring_template_type_H_
#define _recurring_template_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct recurring_template_type_t recurring_template_type_t;


// Enum  for recurring_template_type

typedef enum { simplebilly_api_recurring_template_type__NULL = 0, simplebilly_api_recurring_template_type__invoice, simplebilly_api_recurring_template_type__report } simplebilly_api_recurring_template_type__e;

char* recurring_template_type_recurring_template_type_ToString(simplebilly_api_recurring_template_type__e recurring_template_type);

simplebilly_api_recurring_template_type__e recurring_template_type_recurring_template_type_FromString(char* recurring_template_type);

cJSON *recurring_template_type_convertToJSON(simplebilly_api_recurring_template_type__e recurring_template_type);

simplebilly_api_recurring_template_type__e recurring_template_type_parseFromJSON(cJSON *recurring_template_typeJSON);

#endif /* _recurring_template_type_H_ */

