/*
 * employment_type.h
 *
 * Employment type.
 */

#ifndef _employment_type_H_
#define _employment_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct employment_type_t employment_type_t;


// Enum  for employment_type

typedef enum { simplebilly_api_employment_type__NULL = 0, simplebilly_api_employment_type__fulltime, simplebilly_api_employment_type__parttime, simplebilly_api_employment_type__contract, simplebilly_api_employment_type__internship, simplebilly_api_employment_type__temporary } simplebilly_api_employment_type__e;

char* employment_type_employment_type_ToString(simplebilly_api_employment_type__e employment_type);

simplebilly_api_employment_type__e employment_type_employment_type_FromString(char* employment_type);

cJSON *employment_type_convertToJSON(simplebilly_api_employment_type__e employment_type);

simplebilly_api_employment_type__e employment_type_parseFromJSON(cJSON *employment_typeJSON);

#endif /* _employment_type_H_ */

