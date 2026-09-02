/*
 * institute_type.h
 *
 * Institutsart (KWG § 1).
 */

#ifndef _institute_type_H_
#define _institute_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct institute_type_t institute_type_t;


// Enum  for institute_type

typedef enum { simplebilly_api_institute_type__NULL = 0, simplebilly_api_institute_type__kein, simplebilly_api_institute_type__kreditinstitut, simplebilly_api_institute_type__finanzdienstleistungsinstitut, simplebilly_api_institute_type__finanzunternehmen, simplebilly_api_institute_type__versicherung } simplebilly_api_institute_type__e;

char* institute_type_institute_type_ToString(simplebilly_api_institute_type__e institute_type);

simplebilly_api_institute_type__e institute_type_institute_type_FromString(char* institute_type);

cJSON *institute_type_convertToJSON(simplebilly_api_institute_type__e institute_type);

simplebilly_api_institute_type__e institute_type_parseFromJSON(cJSON *institute_typeJSON);

#endif /* _institute_type_H_ */

