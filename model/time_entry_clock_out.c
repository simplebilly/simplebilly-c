#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_entry_clock_out.h"



static time_entry_clock_out_t *time_entry_clock_out_create_internal(
    char *clock_out,
    char *hours
    ) {
    time_entry_clock_out_t *time_entry_clock_out_local_var = malloc(sizeof(time_entry_clock_out_t));
    if (!time_entry_clock_out_local_var) {
        return NULL;
    }
    memset(time_entry_clock_out_local_var, 0, sizeof(time_entry_clock_out_t));
    time_entry_clock_out_local_var->_library_owned = 1;
    time_entry_clock_out_local_var->clock_out = clock_out;
    time_entry_clock_out_local_var->hours = hours;
    return time_entry_clock_out_local_var;
}

__attribute__((deprecated)) time_entry_clock_out_t *time_entry_clock_out_create(
    char *clock_out,
    char *hours
    ) {
    time_entry_clock_out_t *result = time_entry_clock_out_create_internal (
        clock_out,
        hours
        );
    if (!result) {
    }
    return result;
}

void time_entry_clock_out_free(time_entry_clock_out_t *time_entry_clock_out) {
    if(NULL == time_entry_clock_out){
        return ;
    }
    if(time_entry_clock_out->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "time_entry_clock_out_free");
        return ;
    }
    listEntry_t *listEntry;
    if (time_entry_clock_out->clock_out) {
        free(time_entry_clock_out->clock_out);
        time_entry_clock_out->clock_out = NULL;
    }
    if (time_entry_clock_out->hours) {
        free(time_entry_clock_out->hours);
        time_entry_clock_out->hours = NULL;
    }
    free(time_entry_clock_out);
}

cJSON *time_entry_clock_out_convertToJSON(time_entry_clock_out_t *time_entry_clock_out) {
    cJSON *item = cJSON_CreateObject();

    // time_entry_clock_out->clock_out
    if (!time_entry_clock_out->clock_out) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clock_out", time_entry_clock_out->clock_out) == NULL) {
    goto fail; //Date-Time
    }


    // time_entry_clock_out->hours
    if(time_entry_clock_out->hours) {
    if(cJSON_AddStringToObject(item, "hours", time_entry_clock_out->hours) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

time_entry_clock_out_t *time_entry_clock_out_parseFromJSON(cJSON *time_entry_clock_outJSON){

    time_entry_clock_out_t *time_entry_clock_out_local_var = NULL;

    char *clock_out_local_str = NULL;

    char *hours_local_str = NULL;

    // time_entry_clock_out->clock_out
    cJSON *clock_out = cJSON_GetObjectItemCaseSensitive(time_entry_clock_outJSON, "clock_out");
    if (cJSON_IsNull(clock_out)) {
        clock_out = NULL;
    }
    if (!clock_out) {
        goto end;
    }

    
    if(!cJSON_IsString(clock_out) && !cJSON_IsNull(clock_out))
    {
    goto end; //DateTime
    }

    // time_entry_clock_out->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(time_entry_clock_outJSON, "hours");
    if (cJSON_IsNull(hours)) {
        hours = NULL;
    }
    if (hours) { 
    if(!cJSON_IsString(hours) && !cJSON_IsNull(hours))
    {
    goto end; //String
    }
    }


    if (clock_out && !cJSON_IsNull(clock_out)) clock_out_local_str = strdup(clock_out->valuestring);
    if (hours && !cJSON_IsNull(hours)) hours_local_str = strdup(hours->valuestring);

    time_entry_clock_out_local_var = time_entry_clock_out_create_internal (
        clock_out_local_str,
        hours_local_str
        );

    if (!time_entry_clock_out_local_var) {
        goto end;
    }

    return time_entry_clock_out_local_var;
end:
    if (clock_out_local_str) {
        free(clock_out_local_str);
        clock_out_local_str = NULL;
    }
    if (hours_local_str) {
        free(hours_local_str);
        hours_local_str = NULL;
    }
    return NULL;

}
