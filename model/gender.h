/*
 * gender.h
 *
 * Gender for pay-transparency reporting.
 */

#ifndef _gender_H_
#define _gender_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gender_t gender_t;


// Enum  for gender

typedef enum { simplebilly_api_gender__NULL = 0, simplebilly_api_gender__male, simplebilly_api_gender__female, simplebilly_api_gender__diverse } simplebilly_api_gender__e;

char* gender_gender_ToString(simplebilly_api_gender__e gender);

simplebilly_api_gender__e gender_gender_FromString(char* gender);

cJSON *gender_convertToJSON(simplebilly_api_gender__e gender);

simplebilly_api_gender__e gender_parseFromJSON(cJSON *genderJSON);

#endif /* _gender_H_ */

