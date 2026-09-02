/*
 * api_response_team_data.h
 *
 * 
 */

#ifndef _api_response_team_data_H_
#define _api_response_team_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_team_data_t api_response_team_data_t;




typedef struct api_response_team_data_t {
    char *created_at; //date time
    char *description; // string
    char *id; // string
    char *name; // string
    char *parent_team_id; // string
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_team_data_t;

__attribute__((deprecated)) api_response_team_data_t *api_response_team_data_create(
    char *created_at,
    char *description,
    char *id,
    char *name,
    char *parent_team_id,
    char *tenant_id,
    char *updated_at
);

void api_response_team_data_free(api_response_team_data_t *api_response_team_data);

api_response_team_data_t *api_response_team_data_parseFromJSON(cJSON *api_response_team_dataJSON);

cJSON *api_response_team_data_convertToJSON(api_response_team_data_t *api_response_team_data);

#endif /* _api_response_team_data_H_ */

