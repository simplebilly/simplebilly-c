#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "konzern_beteiligung.h"



static konzern_beteiligung_t *konzern_beteiligung_create_internal(
    char *company_name,
    list_t *control_basis,
    int *controlled,
    char *ownership_pct
    ) {
    konzern_beteiligung_t *konzern_beteiligung_local_var = malloc(sizeof(konzern_beteiligung_t));
    if (!konzern_beteiligung_local_var) {
        return NULL;
    }
    memset(konzern_beteiligung_local_var, 0, sizeof(konzern_beteiligung_t));
    konzern_beteiligung_local_var->_library_owned = 1;
    konzern_beteiligung_local_var->company_name = company_name;
    konzern_beteiligung_local_var->control_basis = control_basis;
    konzern_beteiligung_local_var->controlled = controlled;
    konzern_beteiligung_local_var->ownership_pct = ownership_pct;
    return konzern_beteiligung_local_var;
}

__attribute__((deprecated)) konzern_beteiligung_t *konzern_beteiligung_create(
    char *company_name,
    list_t *control_basis,
    int *controlled,
    char *ownership_pct
    ) {
    int *controlled_copy = NULL;
    if (controlled) {
        controlled_copy = malloc(sizeof(int));
        if (controlled_copy) *controlled_copy = *controlled;
    }
    konzern_beteiligung_t *result = konzern_beteiligung_create_internal (
        company_name,
        control_basis,
        controlled_copy,
        ownership_pct
        );
    if (!result) {
        free(controlled_copy);
    }
    return result;
}

void konzern_beteiligung_free(konzern_beteiligung_t *konzern_beteiligung) {
    if(NULL == konzern_beteiligung){
        return ;
    }
    if(konzern_beteiligung->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "konzern_beteiligung_free");
        return ;
    }
    listEntry_t *listEntry;
    if (konzern_beteiligung->company_name) {
        free(konzern_beteiligung->company_name);
        konzern_beteiligung->company_name = NULL;
    }
    if (konzern_beteiligung->control_basis) {
        list_ForEach(listEntry, konzern_beteiligung->control_basis) {
            free(listEntry->data);
        }
        list_freeList(konzern_beteiligung->control_basis);
        konzern_beteiligung->control_basis = NULL;
    }
    if (konzern_beteiligung->controlled) {
        free(konzern_beteiligung->controlled);
        konzern_beteiligung->controlled = NULL;
    }
    if (konzern_beteiligung->ownership_pct) {
        free(konzern_beteiligung->ownership_pct);
        konzern_beteiligung->ownership_pct = NULL;
    }
    free(konzern_beteiligung);
}

cJSON *konzern_beteiligung_convertToJSON(konzern_beteiligung_t *konzern_beteiligung) {
    cJSON *item = cJSON_CreateObject();

    // konzern_beteiligung->company_name
    if (!konzern_beteiligung->company_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "company_name", konzern_beteiligung->company_name) == NULL) {
    goto fail; //String
    }


    // konzern_beteiligung->control_basis
    if (!konzern_beteiligung->control_basis) {
        goto fail;
    }
    cJSON *control_basis = cJSON_AddArrayToObject(item, "control_basis");
    if(control_basis == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *control_basisListEntry;
    list_ForEach(control_basisListEntry, konzern_beteiligung->control_basis) {
    if(cJSON_AddStringToObject(control_basis, "", control_basisListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // konzern_beteiligung->controlled
    if (!konzern_beteiligung->controlled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "controlled", *konzern_beteiligung->controlled) == NULL) {
    goto fail; //Bool
    }


    // konzern_beteiligung->ownership_pct
    if (!konzern_beteiligung->ownership_pct) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ownership_pct", konzern_beteiligung->ownership_pct) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

konzern_beteiligung_t *konzern_beteiligung_parseFromJSON(cJSON *konzern_beteiligungJSON){

    konzern_beteiligung_t *konzern_beteiligung_local_var = NULL;

    char *company_name_local_str = NULL;

    // define the local list for konzern_beteiligung->control_basis
    list_t *control_basisList = NULL;

    // define the local variable for konzern_beteiligung->controlled
    int *controlled_local_var = NULL;

    char *ownership_pct_local_str = NULL;

    // konzern_beteiligung->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(konzern_beteiligungJSON, "company_name");
    if (cJSON_IsNull(company_name)) {
        company_name = NULL;
    }
    if (!company_name) {
        goto end;
    }

    
    if(!cJSON_IsString(company_name))
    {
    goto end; //String
    }

    // konzern_beteiligung->control_basis
    cJSON *control_basis = cJSON_GetObjectItemCaseSensitive(konzern_beteiligungJSON, "control_basis");
    if (cJSON_IsNull(control_basis)) {
        control_basis = NULL;
    }
    if (!control_basis) {
        goto end;
    }

    
    cJSON *control_basis_local = NULL;
    if(!cJSON_IsArray(control_basis)) {
        goto end;//primitive container
    }
    control_basisList = list_createList();

    cJSON_ArrayForEach(control_basis_local, control_basis)
    {
        if(!cJSON_IsString(control_basis_local))
        {
            goto end;
        }
        list_addElement(control_basisList , strdup(control_basis_local->valuestring));
    }

    // konzern_beteiligung->controlled
    cJSON *controlled = cJSON_GetObjectItemCaseSensitive(konzern_beteiligungJSON, "controlled");
    if (cJSON_IsNull(controlled)) {
        controlled = NULL;
    }
    if (!controlled) {
        goto end;
    }

    
    if(!cJSON_IsBool(controlled))
    {
    goto end; //Bool
    }
    controlled_local_var = malloc(sizeof(int));
    if(!controlled_local_var)
    {
        goto end;
    }
    *controlled_local_var = controlled->valueint;

    // konzern_beteiligung->ownership_pct
    cJSON *ownership_pct = cJSON_GetObjectItemCaseSensitive(konzern_beteiligungJSON, "ownership_pct");
    if (cJSON_IsNull(ownership_pct)) {
        ownership_pct = NULL;
    }
    if (!ownership_pct) {
        goto end;
    }

    
    if(!cJSON_IsString(ownership_pct))
    {
    goto end; //String
    }


    if (company_name && !cJSON_IsNull(company_name)) company_name_local_str = strdup(company_name->valuestring);
    if (ownership_pct && !cJSON_IsNull(ownership_pct)) ownership_pct_local_str = strdup(ownership_pct->valuestring);

    konzern_beteiligung_local_var = konzern_beteiligung_create_internal (
        company_name_local_str,
        control_basisList,
        controlled_local_var,
        ownership_pct_local_str
        );

    if (!konzern_beteiligung_local_var) {
        goto end;
    }

    return konzern_beteiligung_local_var;
end:
    if (company_name_local_str) {
        free(company_name_local_str);
        company_name_local_str = NULL;
    }
    if (control_basisList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, control_basisList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(control_basisList);
        control_basisList = NULL;
    }
    if (controlled_local_var) {
        free(controlled_local_var);
        controlled_local_var = NULL;
    }
    if (ownership_pct_local_str) {
        free(ownership_pct_local_str);
        ownership_pct_local_str = NULL;
    }
    return NULL;

}
