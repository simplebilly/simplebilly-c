/*
 * emission_method.h
 *
 * Emission calculation method: \&quot;activity\&quot; | \&quot;spend\&quot; | \&quot;supplier\&quot;.
 */

#ifndef _emission_method_H_
#define _emission_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct emission_method_t emission_method_t;


// Enum  for emission_method

typedef enum { simplebilly_api_emission_method__NULL = 0, simplebilly_api_emission_method__activity, simplebilly_api_emission_method__spend, simplebilly_api_emission_method__supplier } simplebilly_api_emission_method__e;

char* emission_method_emission_method_ToString(simplebilly_api_emission_method__e emission_method);

simplebilly_api_emission_method__e emission_method_emission_method_FromString(char* emission_method);

cJSON *emission_method_convertToJSON(simplebilly_api_emission_method__e emission_method);

simplebilly_api_emission_method__e emission_method_parseFromJSON(cJSON *emission_methodJSON);

#endif /* _emission_method_H_ */

