/*
 * api_response_vec_team.h
 *
 * 
 */

#ifndef _api_response_vec_team_H_
#define _api_response_vec_team_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_vec_team_t api_response_vec_team_t;

#include "api_response_team_data.h"



typedef struct api_response_vec_team_t {
    list_t *data; //nonprimitive container
    char *error; // string
    char *message; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_vec_team_t;

__attribute__((deprecated)) api_response_vec_team_t *api_response_vec_team_create(
    list_t *data,
    char *error,
    char *message,
    int *success
);

void api_response_vec_team_free(api_response_vec_team_t *api_response_vec_team);

api_response_vec_team_t *api_response_vec_team_parseFromJSON(cJSON *api_response_vec_teamJSON);

cJSON *api_response_vec_team_convertToJSON(api_response_vec_team_t *api_response_vec_team);

#endif /* _api_response_vec_team_H_ */

