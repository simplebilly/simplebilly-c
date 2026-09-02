/*
 * package.h
 *
 * 
 */

#ifndef _package_H_
#define _package_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct package_t package_t;




typedef struct package_t {
    char *description; // string
    double *height_cm; //numeric
    double *length_cm; //numeric
    char *reference; // string
    double *weight_kg; //numeric
    double *width_cm; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} package_t;

__attribute__((deprecated)) package_t *package_create(
    char *description,
    double *height_cm,
    double *length_cm,
    char *reference,
    double *weight_kg,
    double *width_cm
);

void package_free(package_t *package);

package_t *package_parseFromJSON(cJSON *packageJSON);

cJSON *package_convertToJSON(package_t *package);

#endif /* _package_H_ */

