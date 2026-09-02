/*
 * compliance_entry.h
 *
 * 
 */

#ifndef _compliance_entry_H_
#define _compliance_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct compliance_entry_t compliance_entry_t;




typedef struct compliance_entry_t {
    char *description; // string
    char *module; // string
    list_t *regulations; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} compliance_entry_t;

__attribute__((deprecated)) compliance_entry_t *compliance_entry_create(
    char *description,
    char *module,
    list_t *regulations
);

void compliance_entry_free(compliance_entry_t *compliance_entry);

compliance_entry_t *compliance_entry_parseFromJSON(cJSON *compliance_entryJSON);

cJSON *compliance_entry_convertToJSON(compliance_entry_t *compliance_entry);

#endif /* _compliance_entry_H_ */

