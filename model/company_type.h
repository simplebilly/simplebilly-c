/*
 * company_type.h
 *
 * Legal form / company type of the tenant.
 */

#ifndef _company_type_H_
#define _company_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct company_type_t company_type_t;


// Enum  for company_type

typedef enum { simplebilly_api_company_type__NULL = 0, simplebilly_api_company_type__gmbh, simplebilly_api_company_type__ug, simplebilly_api_company_type__einzelhaendler, simplebilly_api_company_type__freiberufler, simplebilly_api_company_type__ag, simplebilly_api_company_type__gbr } simplebilly_api_company_type__e;

char* company_type_company_type_ToString(simplebilly_api_company_type__e company_type);

simplebilly_api_company_type__e company_type_company_type_FromString(char* company_type);

cJSON *company_type_convertToJSON(simplebilly_api_company_type__e company_type);

simplebilly_api_company_type__e company_type_parseFromJSON(cJSON *company_typeJSON);

#endif /* _company_type_H_ */

