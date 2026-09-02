#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "customer_group_update.h"



static customer_group_update_t *customer_group_update_create_internal(
    char *description,
    list_t *member_ids,
    char *membership_filter,
    char *name
    ) {
    customer_group_update_t *customer_group_update_local_var = malloc(sizeof(customer_group_update_t));
    if (!customer_group_update_local_var) {
        return NULL;
    }
    memset(customer_group_update_local_var, 0, sizeof(customer_group_update_t));
    customer_group_update_local_var->_library_owned = 1;
    customer_group_update_local_var->description = description;
    customer_group_update_local_var->member_ids = member_ids;
    customer_group_update_local_var->membership_filter = membership_filter;
    customer_group_update_local_var->name = name;
    return customer_group_update_local_var;
}

__attribute__((deprecated)) customer_group_update_t *customer_group_update_create(
    char *description,
    list_t *member_ids,
    char *membership_filter,
    char *name
    ) {
    customer_group_update_t *result = customer_group_update_create_internal (
        description,
        member_ids,
        membership_filter,
        name
        );
    if (!result) {
    }
    return result;
}

void customer_group_update_free(customer_group_update_t *customer_group_update) {
    if(NULL == customer_group_update){
        return ;
    }
    if(customer_group_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "customer_group_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (customer_group_update->description) {
        free(customer_group_update->description);
        customer_group_update->description = NULL;
    }
    if (customer_group_update->member_ids) {
        list_ForEach(listEntry, customer_group_update->member_ids) {
            free(listEntry->data);
        }
        list_freeList(customer_group_update->member_ids);
        customer_group_update->member_ids = NULL;
    }
    if (customer_group_update->membership_filter) {
        free(customer_group_update->membership_filter);
        customer_group_update->membership_filter = NULL;
    }
    if (customer_group_update->name) {
        free(customer_group_update->name);
        customer_group_update->name = NULL;
    }
    free(customer_group_update);
}

cJSON *customer_group_update_convertToJSON(customer_group_update_t *customer_group_update) {
    cJSON *item = cJSON_CreateObject();

    // customer_group_update->description
    if(customer_group_update->description) {
    if(cJSON_AddStringToObject(item, "description", customer_group_update->description) == NULL) {
    goto fail; //String
    }
    }


    // customer_group_update->member_ids
    if(customer_group_update->member_ids) {
    cJSON *member_ids = cJSON_AddArrayToObject(item, "memberIds");
    if(member_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *member_idsListEntry;
    list_ForEach(member_idsListEntry, customer_group_update->member_ids) {
    if(cJSON_AddStringToObject(member_ids, "", member_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // customer_group_update->membership_filter
    if(customer_group_update->membership_filter) {
    if(cJSON_AddStringToObject(item, "membershipFilter", customer_group_update->membership_filter) == NULL) {
    goto fail; //String
    }
    }


    // customer_group_update->name
    if(customer_group_update->name) {
    if(cJSON_AddStringToObject(item, "name", customer_group_update->name) == NULL) {
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

customer_group_update_t *customer_group_update_parseFromJSON(cJSON *customer_group_updateJSON){

    customer_group_update_t *customer_group_update_local_var = NULL;

    char *description_local_str = NULL;

    // define the local list for customer_group_update->member_ids
    list_t *member_idsList = NULL;

    char *membership_filter_local_str = NULL;

    char *name_local_str = NULL;

    // customer_group_update->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(customer_group_updateJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // customer_group_update->member_ids
    cJSON *member_ids = cJSON_GetObjectItemCaseSensitive(customer_group_updateJSON, "memberIds");
    if (cJSON_IsNull(member_ids)) {
        member_ids = NULL;
    }
    if (member_ids) { 
    cJSON *member_ids_local = NULL;
    if(!cJSON_IsArray(member_ids)) {
        goto end;//primitive container
    }
    member_idsList = list_createList();

    cJSON_ArrayForEach(member_ids_local, member_ids)
    {
        if(!cJSON_IsString(member_ids_local))
        {
            goto end;
        }
        list_addElement(member_idsList , strdup(member_ids_local->valuestring));
    }
    }

    // customer_group_update->membership_filter
    cJSON *membership_filter = cJSON_GetObjectItemCaseSensitive(customer_group_updateJSON, "membershipFilter");
    if (cJSON_IsNull(membership_filter)) {
        membership_filter = NULL;
    }
    if (membership_filter) { 
    if(!cJSON_IsString(membership_filter) && !cJSON_IsNull(membership_filter))
    {
    goto end; //String
    }
    }

    // customer_group_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(customer_group_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (membership_filter && !cJSON_IsNull(membership_filter)) membership_filter_local_str = strdup(membership_filter->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    customer_group_update_local_var = customer_group_update_create_internal (
        description_local_str,
        member_ids ? member_idsList : NULL,
        membership_filter_local_str,
        name_local_str
        );

    if (!customer_group_update_local_var) {
        goto end;
    }

    return customer_group_update_local_var;
end:
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (member_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, member_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(member_idsList);
        member_idsList = NULL;
    }
    if (membership_filter_local_str) {
        free(membership_filter_local_str);
        membership_filter_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
