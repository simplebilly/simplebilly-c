/*
 * connector_type.h
 *
 * How a marketplace connector authenticates: static API key or OAuth2.
 */

#ifndef _connector_type_H_
#define _connector_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct connector_type_t connector_type_t;


// Enum  for connector_type

typedef enum { simplebilly_api_connector_type__NULL = 0, simplebilly_api_connector_type__apikey, simplebilly_api_connector_type__oauth } simplebilly_api_connector_type__e;

char* connector_type_connector_type_ToString(simplebilly_api_connector_type__e connector_type);

simplebilly_api_connector_type__e connector_type_connector_type_FromString(char* connector_type);

cJSON *connector_type_convertToJSON(simplebilly_api_connector_type__e connector_type);

simplebilly_api_connector_type__e connector_type_parseFromJSON(cJSON *connector_typeJSON);

#endif /* _connector_type_H_ */

