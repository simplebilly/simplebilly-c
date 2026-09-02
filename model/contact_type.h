/*
 * contact_type.h
 *
 * Contact category: customer or supplier.
 */

#ifndef _contact_type_H_
#define _contact_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct contact_type_t contact_type_t;


// Enum  for contact_type

typedef enum { simplebilly_api_contact_type__NULL = 0, simplebilly_api_contact_type__customer, simplebilly_api_contact_type__supplier } simplebilly_api_contact_type__e;

char* contact_type_contact_type_ToString(simplebilly_api_contact_type__e contact_type);

simplebilly_api_contact_type__e contact_type_contact_type_FromString(char* contact_type);

cJSON *contact_type_convertToJSON(simplebilly_api_contact_type__e contact_type);

simplebilly_api_contact_type__e contact_type_parseFromJSON(cJSON *contact_typeJSON);

#endif /* _contact_type_H_ */

