#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ai_suggestion.h"



static ai_suggestion_t *ai_suggestion_create_internal(
    double *confidence,
    char *reasoning,
    char *suggested_priority,
    char *suggested_reply,
    char *suggested_status,
    list_t *tool_calls
    ) {
    ai_suggestion_t *ai_suggestion_local_var = malloc(sizeof(ai_suggestion_t));
    if (!ai_suggestion_local_var) {
        return NULL;
    }
    memset(ai_suggestion_local_var, 0, sizeof(ai_suggestion_t));
    ai_suggestion_local_var->_library_owned = 1;
    ai_suggestion_local_var->confidence = confidence;
    ai_suggestion_local_var->reasoning = reasoning;
    ai_suggestion_local_var->suggested_priority = suggested_priority;
    ai_suggestion_local_var->suggested_reply = suggested_reply;
    ai_suggestion_local_var->suggested_status = suggested_status;
    ai_suggestion_local_var->tool_calls = tool_calls;
    return ai_suggestion_local_var;
}

__attribute__((deprecated)) ai_suggestion_t *ai_suggestion_create(
    double *confidence,
    char *reasoning,
    char *suggested_priority,
    char *suggested_reply,
    char *suggested_status,
    list_t *tool_calls
    ) {
    double *confidence_copy = NULL;
    if (confidence) {
        confidence_copy = malloc(sizeof(double));
        if (confidence_copy) *confidence_copy = *confidence;
    }
    ai_suggestion_t *result = ai_suggestion_create_internal (
        confidence_copy,
        reasoning,
        suggested_priority,
        suggested_reply,
        suggested_status,
        tool_calls
        );
    if (!result) {
        free(confidence_copy);
    }
    return result;
}

void ai_suggestion_free(ai_suggestion_t *ai_suggestion) {
    if(NULL == ai_suggestion){
        return ;
    }
    if(ai_suggestion->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ai_suggestion_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ai_suggestion->confidence) {
        free(ai_suggestion->confidence);
        ai_suggestion->confidence = NULL;
    }
    if (ai_suggestion->reasoning) {
        free(ai_suggestion->reasoning);
        ai_suggestion->reasoning = NULL;
    }
    if (ai_suggestion->suggested_priority) {
        free(ai_suggestion->suggested_priority);
        ai_suggestion->suggested_priority = NULL;
    }
    if (ai_suggestion->suggested_reply) {
        free(ai_suggestion->suggested_reply);
        ai_suggestion->suggested_reply = NULL;
    }
    if (ai_suggestion->suggested_status) {
        free(ai_suggestion->suggested_status);
        ai_suggestion->suggested_status = NULL;
    }
    if (ai_suggestion->tool_calls) {
        list_ForEach(listEntry, ai_suggestion->tool_calls) {
            free(listEntry->data);
        }
        list_freeList(ai_suggestion->tool_calls);
        ai_suggestion->tool_calls = NULL;
    }
    free(ai_suggestion);
}

cJSON *ai_suggestion_convertToJSON(ai_suggestion_t *ai_suggestion) {
    cJSON *item = cJSON_CreateObject();

    // ai_suggestion->confidence
    if (!ai_suggestion->confidence) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "confidence", *ai_suggestion->confidence) == NULL) {
    goto fail; //Numeric
    }


    // ai_suggestion->reasoning
    if (!ai_suggestion->reasoning) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "reasoning", ai_suggestion->reasoning) == NULL) {
    goto fail; //String
    }


    // ai_suggestion->suggested_priority
    if(ai_suggestion->suggested_priority) {
    if(cJSON_AddStringToObject(item, "suggested_priority", ai_suggestion->suggested_priority) == NULL) {
    goto fail; //String
    }
    }


    // ai_suggestion->suggested_reply
    if (!ai_suggestion->suggested_reply) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "suggested_reply", ai_suggestion->suggested_reply) == NULL) {
    goto fail; //String
    }


    // ai_suggestion->suggested_status
    if(ai_suggestion->suggested_status) {
    if(cJSON_AddStringToObject(item, "suggested_status", ai_suggestion->suggested_status) == NULL) {
    goto fail; //String
    }
    }


    // ai_suggestion->tool_calls
    if (!ai_suggestion->tool_calls) {
        goto fail;
    }
    cJSON *tool_calls = cJSON_AddArrayToObject(item, "tool_calls");
    if(tool_calls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *tool_callsListEntry;
    list_ForEach(tool_callsListEntry, ai_suggestion->tool_calls) {
    if(cJSON_AddStringToObject(tool_calls, "", tool_callsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ai_suggestion_t *ai_suggestion_parseFromJSON(cJSON *ai_suggestionJSON){

    ai_suggestion_t *ai_suggestion_local_var = NULL;

    // define the local variable for ai_suggestion->confidence
    double *confidence_local_var = NULL;

    char *reasoning_local_str = NULL;

    char *suggested_priority_local_str = NULL;

    char *suggested_reply_local_str = NULL;

    char *suggested_status_local_str = NULL;

    // define the local list for ai_suggestion->tool_calls
    list_t *tool_callsList = NULL;

    // ai_suggestion->confidence
    cJSON *confidence = cJSON_GetObjectItemCaseSensitive(ai_suggestionJSON, "confidence");
    if (cJSON_IsNull(confidence)) {
        confidence = NULL;
    }
    if (!confidence) {
        goto end;
    }

    
    if(!cJSON_IsNumber(confidence))
    {
    goto end; //Numeric
    }
    confidence_local_var = malloc(sizeof(double));
    if(!confidence_local_var)
    {
        goto end;
    }
    *confidence_local_var = confidence->valuedouble;

    // ai_suggestion->reasoning
    cJSON *reasoning = cJSON_GetObjectItemCaseSensitive(ai_suggestionJSON, "reasoning");
    if (cJSON_IsNull(reasoning)) {
        reasoning = NULL;
    }
    if (!reasoning) {
        goto end;
    }

    
    if(!cJSON_IsString(reasoning))
    {
    goto end; //String
    }

    // ai_suggestion->suggested_priority
    cJSON *suggested_priority = cJSON_GetObjectItemCaseSensitive(ai_suggestionJSON, "suggested_priority");
    if (cJSON_IsNull(suggested_priority)) {
        suggested_priority = NULL;
    }
    if (suggested_priority) { 
    if(!cJSON_IsString(suggested_priority) && !cJSON_IsNull(suggested_priority))
    {
    goto end; //String
    }
    }

    // ai_suggestion->suggested_reply
    cJSON *suggested_reply = cJSON_GetObjectItemCaseSensitive(ai_suggestionJSON, "suggested_reply");
    if (cJSON_IsNull(suggested_reply)) {
        suggested_reply = NULL;
    }
    if (!suggested_reply) {
        goto end;
    }

    
    if(!cJSON_IsString(suggested_reply))
    {
    goto end; //String
    }

    // ai_suggestion->suggested_status
    cJSON *suggested_status = cJSON_GetObjectItemCaseSensitive(ai_suggestionJSON, "suggested_status");
    if (cJSON_IsNull(suggested_status)) {
        suggested_status = NULL;
    }
    if (suggested_status) { 
    if(!cJSON_IsString(suggested_status) && !cJSON_IsNull(suggested_status))
    {
    goto end; //String
    }
    }

    // ai_suggestion->tool_calls
    cJSON *tool_calls = cJSON_GetObjectItemCaseSensitive(ai_suggestionJSON, "tool_calls");
    if (cJSON_IsNull(tool_calls)) {
        tool_calls = NULL;
    }
    if (!tool_calls) {
        goto end;
    }

    
    cJSON *tool_calls_local = NULL;
    if(!cJSON_IsArray(tool_calls)) {
        goto end;//primitive container
    }
    tool_callsList = list_createList();

    cJSON_ArrayForEach(tool_calls_local, tool_calls)
    {
        if(!cJSON_IsString(tool_calls_local))
        {
            goto end;
        }
        list_addElement(tool_callsList , strdup(tool_calls_local->valuestring));
    }


    if (reasoning && !cJSON_IsNull(reasoning)) reasoning_local_str = strdup(reasoning->valuestring);
    if (suggested_priority && !cJSON_IsNull(suggested_priority)) suggested_priority_local_str = strdup(suggested_priority->valuestring);
    if (suggested_reply && !cJSON_IsNull(suggested_reply)) suggested_reply_local_str = strdup(suggested_reply->valuestring);
    if (suggested_status && !cJSON_IsNull(suggested_status)) suggested_status_local_str = strdup(suggested_status->valuestring);

    ai_suggestion_local_var = ai_suggestion_create_internal (
        confidence_local_var,
        reasoning_local_str,
        suggested_priority_local_str,
        suggested_reply_local_str,
        suggested_status_local_str,
        tool_callsList
        );

    if (!ai_suggestion_local_var) {
        goto end;
    }

    return ai_suggestion_local_var;
end:
    if (confidence_local_var) {
        free(confidence_local_var);
        confidence_local_var = NULL;
    }
    if (reasoning_local_str) {
        free(reasoning_local_str);
        reasoning_local_str = NULL;
    }
    if (suggested_priority_local_str) {
        free(suggested_priority_local_str);
        suggested_priority_local_str = NULL;
    }
    if (suggested_reply_local_str) {
        free(suggested_reply_local_str);
        suggested_reply_local_str = NULL;
    }
    if (suggested_status_local_str) {
        free(suggested_status_local_str);
        suggested_status_local_str = NULL;
    }
    if (tool_callsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tool_callsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tool_callsList);
        tool_callsList = NULL;
    }
    return NULL;

}
