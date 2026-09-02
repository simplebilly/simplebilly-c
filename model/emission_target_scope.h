/*
 * emission_target_scope.h
 *
 * Emission target scope: \&quot;total\&quot; | \&quot;1\&quot; | \&quot;2\&quot; | \&quot;3\&quot;.
 */

#ifndef _emission_target_scope_H_
#define _emission_target_scope_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct emission_target_scope_t emission_target_scope_t;


// Enum  for emission_target_scope

typedef enum { simplebilly_api_emission_target_scope__NULL = 0, simplebilly_api_emission_target_scope__total, simplebilly_api_emission_target_scope___1, simplebilly_api_emission_target_scope___2, simplebilly_api_emission_target_scope___3 } simplebilly_api_emission_target_scope__e;

char* emission_target_scope_emission_target_scope_ToString(simplebilly_api_emission_target_scope__e emission_target_scope);

simplebilly_api_emission_target_scope__e emission_target_scope_emission_target_scope_FromString(char* emission_target_scope);

cJSON *emission_target_scope_convertToJSON(simplebilly_api_emission_target_scope__e emission_target_scope);

simplebilly_api_emission_target_scope__e emission_target_scope_parseFromJSON(cJSON *emission_target_scopeJSON);

#endif /* _emission_target_scope_H_ */

