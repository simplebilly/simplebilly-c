/*
 * metered_usage.h
 *
 * 
 */

#ifndef _metered_usage_H_
#define _metered_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct metered_usage_t metered_usage_t;




typedef struct metered_usage_t {
    long *limit; //numeric
    char *meter; // string
    long *used; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} metered_usage_t;

__attribute__((deprecated)) metered_usage_t *metered_usage_create(
    long *limit,
    char *meter,
    long *used
);

void metered_usage_free(metered_usage_t *metered_usage);

metered_usage_t *metered_usage_parseFromJSON(cJSON *metered_usageJSON);

cJSON *metered_usage_convertToJSON(metered_usage_t *metered_usage);

#endif /* _metered_usage_H_ */

