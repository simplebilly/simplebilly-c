#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ticket_priority.h"


char* ticket_priority_ticket_priority_ToString(simplebilly_api_ticket_priority__e ticket_priority) {
    char *ticket_priorityArray[] =  { "NULL", "normal", "high" };
    return ticket_priorityArray[ticket_priority];
}

simplebilly_api_ticket_priority__e ticket_priority_ticket_priority_FromString(char* ticket_priority) {
    int stringToReturn = 0;
    char *ticket_priorityArray[] =  { "NULL", "normal", "high" };
    size_t sizeofArray = sizeof(ticket_priorityArray) / sizeof(ticket_priorityArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(ticket_priority, ticket_priorityArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *ticket_priority_convertToJSON(simplebilly_api_ticket_priority__e ticket_priority) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "ticket_priority", ticket_priority_ticket_priority_ToString(ticket_priority)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_ticket_priority__e ticket_priority_parseFromJSON(cJSON *ticket_priorityJSON) {
    if(!cJSON_IsString(ticket_priorityJSON) || (ticket_priorityJSON->valuestring == NULL)) {
        return 0;
    }
    return ticket_priority_ticket_priority_FromString(ticket_priorityJSON->valuestring);
}
