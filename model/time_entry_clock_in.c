#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_entry_clock_in.h"



static time_entry_clock_in_t *time_entry_clock_in_create_internal(
    char *notes
    ) {
    time_entry_clock_in_t *time_entry_clock_in_local_var = malloc(sizeof(time_entry_clock_in_t));
    if (!time_entry_clock_in_local_var) {
        return NULL;
    }
    memset(time_entry_clock_in_local_var, 0, sizeof(time_entry_clock_in_t));
    time_entry_clock_in_local_var->_library_owned = 1;
    time_entry_clock_in_local_var->notes = notes;
    return time_entry_clock_in_local_var;
}

__attribute__((deprecated)) time_entry_clock_in_t *time_entry_clock_in_create(
    char *notes
    ) {
    time_entry_clock_in_t *result = time_entry_clock_in_create_internal (
        notes
        );
    if (!result) {
    }
    return result;
}

void time_entry_clock_in_free(time_entry_clock_in_t *time_entry_clock_in) {
    if(NULL == time_entry_clock_in){
        return ;
    }
    if(time_entry_clock_in->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "time_entry_clock_in_free");
        return ;
    }
    listEntry_t *listEntry;
    if (time_entry_clock_in->notes) {
        free(time_entry_clock_in->notes);
        time_entry_clock_in->notes = NULL;
    }
    free(time_entry_clock_in);
}

cJSON *time_entry_clock_in_convertToJSON(time_entry_clock_in_t *time_entry_clock_in) {
    cJSON *item = cJSON_CreateObject();

    // time_entry_clock_in->notes
    if(time_entry_clock_in->notes) {
    if(cJSON_AddStringToObject(item, "notes", time_entry_clock_in->notes) == NULL) {
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

time_entry_clock_in_t *time_entry_clock_in_parseFromJSON(cJSON *time_entry_clock_inJSON){

    time_entry_clock_in_t *time_entry_clock_in_local_var = NULL;

    char *notes_local_str = NULL;

    // time_entry_clock_in->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(time_entry_clock_inJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }


    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);

    time_entry_clock_in_local_var = time_entry_clock_in_create_internal (
        notes_local_str
        );

    if (!time_entry_clock_in_local_var) {
        goto end;
    }

    return time_entry_clock_in_local_var;
end:
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    return NULL;

}
