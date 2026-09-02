/*
 * user_profile.h
 *
 * 
 */

#ifndef _user_profile_H_
#define _user_profile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_profile_t user_profile_t;




typedef struct user_profile_t {
    char *created_at; //date time
    char *email; // string
    int *email_verified; //boolean
    char *first_name; // string
    char *full_name; // string
    char *id; // string
    char *last_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} user_profile_t;

__attribute__((deprecated)) user_profile_t *user_profile_create(
    char *created_at,
    char *email,
    int *email_verified,
    char *first_name,
    char *full_name,
    char *id,
    char *last_name
);

void user_profile_free(user_profile_t *user_profile);

user_profile_t *user_profile_parseFromJSON(cJSON *user_profileJSON);

cJSON *user_profile_convertToJSON(user_profile_t *user_profile);

#endif /* _user_profile_H_ */

