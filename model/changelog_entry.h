/*
 * changelog_entry.h
 *
 * One changelog entry for a plugin release.
 */

#ifndef _changelog_entry_H_
#define _changelog_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct changelog_entry_t changelog_entry_t;




typedef struct changelog_entry_t {
    char *date; // string
    char *notes; // string
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} changelog_entry_t;

__attribute__((deprecated)) changelog_entry_t *changelog_entry_create(
    char *date,
    char *notes,
    char *version
);

void changelog_entry_free(changelog_entry_t *changelog_entry);

changelog_entry_t *changelog_entry_parseFromJSON(cJSON *changelog_entryJSON);

cJSON *changelog_entry_convertToJSON(changelog_entry_t *changelog_entry);

#endif /* _changelog_entry_H_ */

