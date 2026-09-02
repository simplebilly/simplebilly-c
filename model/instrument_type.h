/*
 * instrument_type.h
 *
 * Silent-partnership instrument: \&quot;typisch\&quot; | \&quot;atypisch\&quot;.
 */

#ifndef _instrument_type_H_
#define _instrument_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instrument_type_t instrument_type_t;


// Enum  for instrument_type

typedef enum { simplebilly_api_instrument_type__NULL = 0, simplebilly_api_instrument_type__typisch, simplebilly_api_instrument_type__atypisch } simplebilly_api_instrument_type__e;

char* instrument_type_instrument_type_ToString(simplebilly_api_instrument_type__e instrument_type);

simplebilly_api_instrument_type__e instrument_type_instrument_type_FromString(char* instrument_type);

cJSON *instrument_type_convertToJSON(simplebilly_api_instrument_type__e instrument_type);

simplebilly_api_instrument_type__e instrument_type_parseFromJSON(cJSON *instrument_typeJSON);

#endif /* _instrument_type_H_ */

