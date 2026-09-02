/*
 * declaration_type.h
 *
 * Art der Erklärung: \&quot;dcgk\&quot; (Entsprechenserklärung § 161 AktG) oder \&quot;unternehmensfuehrung\&quot; (Erklärung zur Unternehmensführung § 289f HGB).
 */

#ifndef _declaration_type_H_
#define _declaration_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct declaration_type_t declaration_type_t;


// Enum  for declaration_type

typedef enum { simplebilly_api_declaration_type__NULL = 0, simplebilly_api_declaration_type__dcgk, simplebilly_api_declaration_type__unternehmensfuehrung } simplebilly_api_declaration_type__e;

char* declaration_type_declaration_type_ToString(simplebilly_api_declaration_type__e declaration_type);

simplebilly_api_declaration_type__e declaration_type_declaration_type_FromString(char* declaration_type);

cJSON *declaration_type_convertToJSON(simplebilly_api_declaration_type__e declaration_type);

simplebilly_api_declaration_type__e declaration_type_parseFromJSON(cJSON *declaration_typeJSON);

#endif /* _declaration_type_H_ */

