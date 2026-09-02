#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stille_report.h"



static stille_report_t *stille_report_create_internal(
    char *jahresueberschuss,
    list_t *partners,
    int *year
    ) {
    stille_report_t *stille_report_local_var = malloc(sizeof(stille_report_t));
    if (!stille_report_local_var) {
        return NULL;
    }
    memset(stille_report_local_var, 0, sizeof(stille_report_t));
    stille_report_local_var->_library_owned = 1;
    stille_report_local_var->jahresueberschuss = jahresueberschuss;
    stille_report_local_var->partners = partners;
    stille_report_local_var->year = year;
    return stille_report_local_var;
}

__attribute__((deprecated)) stille_report_t *stille_report_create(
    char *jahresueberschuss,
    list_t *partners,
    int *year
    ) {
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    stille_report_t *result = stille_report_create_internal (
        jahresueberschuss,
        partners,
        year_copy
        );
    if (!result) {
        free(year_copy);
    }
    return result;
}

void stille_report_free(stille_report_t *stille_report) {
    if(NULL == stille_report){
        return ;
    }
    if(stille_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stille_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stille_report->jahresueberschuss) {
        free(stille_report->jahresueberschuss);
        stille_report->jahresueberschuss = NULL;
    }
    if (stille_report->partners) {
        list_ForEach(listEntry, stille_report->partners) {
            stille_partner_zeile_free(listEntry->data);
        }
        list_freeList(stille_report->partners);
        stille_report->partners = NULL;
    }
    if (stille_report->year) {
        free(stille_report->year);
        stille_report->year = NULL;
    }
    free(stille_report);
}

cJSON *stille_report_convertToJSON(stille_report_t *stille_report) {
    cJSON *item = cJSON_CreateObject();

    // stille_report->jahresueberschuss
    if (!stille_report->jahresueberschuss) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "jahresueberschuss", stille_report->jahresueberschuss) == NULL) {
    goto fail; //String
    }


    // stille_report->partners
    if (!stille_report->partners) {
        goto fail;
    }
    cJSON *partners = cJSON_AddArrayToObject(item, "partners");
    if(partners == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *partnersListEntry;
    if (stille_report->partners) {
    list_ForEach(partnersListEntry, stille_report->partners) {
    cJSON *itemLocal = stille_partner_zeile_convertToJSON(partnersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(partners, itemLocal);
    }
    }


    // stille_report->year
    if (!stille_report->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *stille_report->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stille_report_t *stille_report_parseFromJSON(cJSON *stille_reportJSON){

    stille_report_t *stille_report_local_var = NULL;

    char *jahresueberschuss_local_str = NULL;

    // define the local list for stille_report->partners
    list_t *partnersList = NULL;

    // define the local variable for stille_report->year
    int *year_local_var = NULL;

    // stille_report->jahresueberschuss
    cJSON *jahresueberschuss = cJSON_GetObjectItemCaseSensitive(stille_reportJSON, "jahresueberschuss");
    if (cJSON_IsNull(jahresueberschuss)) {
        jahresueberschuss = NULL;
    }
    if (!jahresueberschuss) {
        goto end;
    }

    
    if(!cJSON_IsString(jahresueberschuss))
    {
    goto end; //String
    }

    // stille_report->partners
    cJSON *partners = cJSON_GetObjectItemCaseSensitive(stille_reportJSON, "partners");
    if (cJSON_IsNull(partners)) {
        partners = NULL;
    }
    if (!partners) {
        goto end;
    }

    
    cJSON *partners_local_nonprimitive = NULL;
    if(!cJSON_IsArray(partners)){
        goto end; //nonprimitive container
    }

    partnersList = list_createList();

    cJSON_ArrayForEach(partners_local_nonprimitive,partners )
    {
        if(!cJSON_IsObject(partners_local_nonprimitive)){
            goto end;
        }
        stille_partner_zeile_t *partnersItem = stille_partner_zeile_parseFromJSON(partners_local_nonprimitive);

        list_addElement(partnersList, partnersItem);
    }

    // stille_report->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(stille_reportJSON, "year");
    if (cJSON_IsNull(year)) {
        year = NULL;
    }
    if (!year) {
        goto end;
    }

    
    if(!cJSON_IsNumber(year))
    {
    goto end; //Numeric
    }
    year_local_var = malloc(sizeof(int));
    if(!year_local_var)
    {
        goto end;
    }
    *year_local_var = year->valuedouble;


    if (jahresueberschuss && !cJSON_IsNull(jahresueberschuss)) jahresueberschuss_local_str = strdup(jahresueberschuss->valuestring);

    stille_report_local_var = stille_report_create_internal (
        jahresueberschuss_local_str,
        partnersList,
        year_local_var
        );

    if (!stille_report_local_var) {
        goto end;
    }

    return stille_report_local_var;
end:
    if (jahresueberschuss_local_str) {
        free(jahresueberschuss_local_str);
        jahresueberschuss_local_str = NULL;
    }
    if (partnersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, partnersList) {
            stille_partner_zeile_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(partnersList);
        partnersList = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
