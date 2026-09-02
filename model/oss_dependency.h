/*
 * oss_dependency.h
 *
 * 
 */

#ifndef _oss_dependency_H_
#define _oss_dependency_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct oss_dependency_t oss_dependency_t;




typedef struct oss_dependency_t {
    char *dependency_type; // string
    char *license; // string
    char *name; // string
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} oss_dependency_t;

__attribute__((deprecated)) oss_dependency_t *oss_dependency_create(
    char *dependency_type,
    char *license,
    char *name,
    char *version
);

void oss_dependency_free(oss_dependency_t *oss_dependency);

oss_dependency_t *oss_dependency_parseFromJSON(cJSON *oss_dependencyJSON);

cJSON *oss_dependency_convertToJSON(oss_dependency_t *oss_dependency);

#endif /* _oss_dependency_H_ */

