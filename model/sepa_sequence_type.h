/*
 * sepa_sequence_type.h
 *
 * SEPA mandate sequence type (ISO 20022 mandate codes).
 */

#ifndef _sepa_sequence_type_H_
#define _sepa_sequence_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sepa_sequence_type_t sepa_sequence_type_t;


// Enum  for sepa_sequence_type

typedef enum { simplebilly_api_sepa_sequence_type__NULL = 0, simplebilly_api_sepa_sequence_type__FRST, simplebilly_api_sepa_sequence_type__RCUR, simplebilly_api_sepa_sequence_type__FNAL, simplebilly_api_sepa_sequence_type__OOFF } simplebilly_api_sepa_sequence_type__e;

char* sepa_sequence_type_sepa_sequence_type_ToString(simplebilly_api_sepa_sequence_type__e sepa_sequence_type);

simplebilly_api_sepa_sequence_type__e sepa_sequence_type_sepa_sequence_type_FromString(char* sepa_sequence_type);

cJSON *sepa_sequence_type_convertToJSON(simplebilly_api_sepa_sequence_type__e sepa_sequence_type);

simplebilly_api_sepa_sequence_type__e sepa_sequence_type_parseFromJSON(cJSON *sepa_sequence_typeJSON);

#endif /* _sepa_sequence_type_H_ */

