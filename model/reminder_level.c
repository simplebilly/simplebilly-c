#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reminder_level.h"


char* reminder_level_reminder_level_ToString(simplebilly_api_reminder_level__e reminder_level) {
    char *reminder_levelArray[] =  { "NULL", "none", "due", "level1", "level2", "level3" };
    return reminder_levelArray[reminder_level];
}

simplebilly_api_reminder_level__e reminder_level_reminder_level_FromString(char* reminder_level) {
    int stringToReturn = 0;
    char *reminder_levelArray[] =  { "NULL", "none", "due", "level1", "level2", "level3" };
    size_t sizeofArray = sizeof(reminder_levelArray) / sizeof(reminder_levelArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(reminder_level, reminder_levelArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *reminder_level_convertToJSON(simplebilly_api_reminder_level__e reminder_level) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "reminder_level", reminder_level_reminder_level_ToString(reminder_level)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_reminder_level__e reminder_level_parseFromJSON(cJSON *reminder_levelJSON) {
    if(!cJSON_IsString(reminder_levelJSON) || (reminder_levelJSON->valuestring == NULL)) {
        return 0;
    }
    return reminder_level_reminder_level_FromString(reminder_levelJSON->valuestring);
}
