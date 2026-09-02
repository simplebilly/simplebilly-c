/*
 * data_quality.h
 *
 * 
 */

#ifndef _data_quality_H_
#define _data_quality_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct data_quality_t data_quality_t;




typedef struct data_quality_t {
    int *activity_lines; //numeric
    double *activity_share_pct; //numeric
    int *spend_lines; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} data_quality_t;

__attribute__((deprecated)) data_quality_t *data_quality_create(
    int *activity_lines,
    double *activity_share_pct,
    int *spend_lines
);

void data_quality_free(data_quality_t *data_quality);

data_quality_t *data_quality_parseFromJSON(cJSON *data_qualityJSON);

cJSON *data_quality_convertToJSON(data_quality_t *data_quality);

#endif /* _data_quality_H_ */

