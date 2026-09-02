/*
 * training_source.h
 *
 * Source of the training content.
 */

#ifndef _training_source_H_
#define _training_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct training_source_t training_source_t;


// Enum  for training_source

typedef enum { simplebilly_api_training_source__NULL = 0, simplebilly_api_training_source__builtin, simplebilly_api_training_source__plugin } simplebilly_api_training_source__e;

char* training_source_training_source_ToString(simplebilly_api_training_source__e training_source);

simplebilly_api_training_source__e training_source_training_source_FromString(char* training_source);

cJSON *training_source_convertToJSON(simplebilly_api_training_source__e training_source);

simplebilly_api_training_source__e training_source_parseFromJSON(cJSON *training_sourceJSON);

#endif /* _training_source_H_ */

