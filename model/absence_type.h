/*
 * absence_type.h
 *
 * Absence type.
 */

#ifndef _absence_type_H_
#define _absence_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct absence_type_t absence_type_t;


// Enum  for absence_type

typedef enum { simplebilly_api_absence_type__NULL = 0, simplebilly_api_absence_type__vacation, simplebilly_api_absence_type__sick, simplebilly_api_absence_type__sabbatical, simplebilly_api_absence_type__parental, simplebilly_api_absence_type__other } simplebilly_api_absence_type__e;

char* absence_type_absence_type_ToString(simplebilly_api_absence_type__e absence_type);

simplebilly_api_absence_type__e absence_type_absence_type_FromString(char* absence_type);

cJSON *absence_type_convertToJSON(simplebilly_api_absence_type__e absence_type);

simplebilly_api_absence_type__e absence_type_parseFromJSON(cJSON *absence_typeJSON);

#endif /* _absence_type_H_ */

