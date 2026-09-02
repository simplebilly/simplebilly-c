/*
 * ghg_scope.h
 *
 * GHG scope: \&quot;1\&quot; | \&quot;2\&quot; | \&quot;3\&quot;.
 */

#ifndef _ghg_scope_H_
#define _ghg_scope_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ghg_scope_t ghg_scope_t;


// Enum  for ghg_scope

typedef enum { simplebilly_api_ghg_scope__NULL = 0, simplebilly_api_ghg_scope___1, simplebilly_api_ghg_scope___2, simplebilly_api_ghg_scope___3 } simplebilly_api_ghg_scope__e;

char* ghg_scope_ghg_scope_ToString(simplebilly_api_ghg_scope__e ghg_scope);

simplebilly_api_ghg_scope__e ghg_scope_ghg_scope_FromString(char* ghg_scope);

cJSON *ghg_scope_convertToJSON(simplebilly_api_ghg_scope__e ghg_scope);

simplebilly_api_ghg_scope__e ghg_scope_parseFromJSON(cJSON *ghg_scopeJSON);

#endif /* _ghg_scope_H_ */

