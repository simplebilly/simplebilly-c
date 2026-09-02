#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kosten_vorschau.h"



static kosten_vorschau_t *kosten_vorschau_create_internal(
    list_t *eintraege,
    char *gesamt
    ) {
    kosten_vorschau_t *kosten_vorschau_local_var = malloc(sizeof(kosten_vorschau_t));
    if (!kosten_vorschau_local_var) {
        return NULL;
    }
    memset(kosten_vorschau_local_var, 0, sizeof(kosten_vorschau_t));
    kosten_vorschau_local_var->_library_owned = 1;
    kosten_vorschau_local_var->eintraege = eintraege;
    kosten_vorschau_local_var->gesamt = gesamt;
    return kosten_vorschau_local_var;
}

__attribute__((deprecated)) kosten_vorschau_t *kosten_vorschau_create(
    list_t *eintraege,
    char *gesamt
    ) {
    kosten_vorschau_t *result = kosten_vorschau_create_internal (
        eintraege,
        gesamt
        );
    if (!result) {
    }
    return result;
}

void kosten_vorschau_free(kosten_vorschau_t *kosten_vorschau) {
    if(NULL == kosten_vorschau){
        return ;
    }
    if(kosten_vorschau->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kosten_vorschau_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kosten_vorschau->eintraege) {
        list_ForEach(listEntry, kosten_vorschau->eintraege) {
            kosten_eintrag_free(listEntry->data);
        }
        list_freeList(kosten_vorschau->eintraege);
        kosten_vorschau->eintraege = NULL;
    }
    if (kosten_vorschau->gesamt) {
        free(kosten_vorschau->gesamt);
        kosten_vorschau->gesamt = NULL;
    }
    free(kosten_vorschau);
}

cJSON *kosten_vorschau_convertToJSON(kosten_vorschau_t *kosten_vorschau) {
    cJSON *item = cJSON_CreateObject();

    // kosten_vorschau->eintraege
    if (!kosten_vorschau->eintraege) {
        goto fail;
    }
    cJSON *eintraege = cJSON_AddArrayToObject(item, "eintraege");
    if(eintraege == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *eintraegeListEntry;
    if (kosten_vorschau->eintraege) {
    list_ForEach(eintraegeListEntry, kosten_vorschau->eintraege) {
    cJSON *itemLocal = kosten_eintrag_convertToJSON(eintraegeListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(eintraege, itemLocal);
    }
    }


    // kosten_vorschau->gesamt
    if (!kosten_vorschau->gesamt) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesamt", kosten_vorschau->gesamt) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kosten_vorschau_t *kosten_vorschau_parseFromJSON(cJSON *kosten_vorschauJSON){

    kosten_vorschau_t *kosten_vorschau_local_var = NULL;

    // define the local list for kosten_vorschau->eintraege
    list_t *eintraegeList = NULL;

    char *gesamt_local_str = NULL;

    // kosten_vorschau->eintraege
    cJSON *eintraege = cJSON_GetObjectItemCaseSensitive(kosten_vorschauJSON, "eintraege");
    if (cJSON_IsNull(eintraege)) {
        eintraege = NULL;
    }
    if (!eintraege) {
        goto end;
    }

    
    cJSON *eintraege_local_nonprimitive = NULL;
    if(!cJSON_IsArray(eintraege)){
        goto end; //nonprimitive container
    }

    eintraegeList = list_createList();

    cJSON_ArrayForEach(eintraege_local_nonprimitive,eintraege )
    {
        if(!cJSON_IsObject(eintraege_local_nonprimitive)){
            goto end;
        }
        kosten_eintrag_t *eintraegeItem = kosten_eintrag_parseFromJSON(eintraege_local_nonprimitive);

        list_addElement(eintraegeList, eintraegeItem);
    }

    // kosten_vorschau->gesamt
    cJSON *gesamt = cJSON_GetObjectItemCaseSensitive(kosten_vorschauJSON, "gesamt");
    if (cJSON_IsNull(gesamt)) {
        gesamt = NULL;
    }
    if (!gesamt) {
        goto end;
    }

    
    if(!cJSON_IsString(gesamt))
    {
    goto end; //String
    }


    if (gesamt && !cJSON_IsNull(gesamt)) gesamt_local_str = strdup(gesamt->valuestring);

    kosten_vorschau_local_var = kosten_vorschau_create_internal (
        eintraegeList,
        gesamt_local_str
        );

    if (!kosten_vorschau_local_var) {
        goto end;
    }

    return kosten_vorschau_local_var;
end:
    if (eintraegeList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, eintraegeList) {
            kosten_eintrag_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(eintraegeList);
        eintraegeList = NULL;
    }
    if (gesamt_local_str) {
        free(gesamt_local_str);
        gesamt_local_str = NULL;
    }
    return NULL;

}
