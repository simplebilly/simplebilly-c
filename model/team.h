/*
 * team.h
 *
 * 
 */

#ifndef _team_H_
#define _team_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct team_t team_t;




typedef struct team_t {
    char *created_at; //date time
    char *description; // string
    char *id; // string
    char *name; // string
    char *parent_team_id; // string
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} team_t;

__attribute__((deprecated)) team_t *team_create(
    char *created_at,
    char *description,
    char *id,
    char *name,
    char *parent_team_id,
    char *tenant_id,
    char *updated_at
);

void team_free(team_t *team);

team_t *team_parseFromJSON(cJSON *teamJSON);

cJSON *team_convertToJSON(team_t *team);

#endif /* _team_H_ */

