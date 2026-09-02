#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gewinnverwendungs_zeile.h"



static gewinnverwendungs_zeile_t *gewinnverwendungs_zeile_create_internal(
    char *betrag,
    char *label
    ) {
    gewinnverwendungs_zeile_t *gewinnverwendungs_zeile_local_var = malloc(sizeof(gewinnverwendungs_zeile_t));
    if (!gewinnverwendungs_zeile_local_var) {
        return NULL;
    }
    memset(gewinnverwendungs_zeile_local_var, 0, sizeof(gewinnverwendungs_zeile_t));
    gewinnverwendungs_zeile_local_var->_library_owned = 1;
    gewinnverwendungs_zeile_local_var->betrag = betrag;
    gewinnverwendungs_zeile_local_var->label = label;
    return gewinnverwendungs_zeile_local_var;
}

__attribute__((deprecated)) gewinnverwendungs_zeile_t *gewinnverwendungs_zeile_create(
    char *betrag,
    char *label
    ) {
    gewinnverwendungs_zeile_t *result = gewinnverwendungs_zeile_create_internal (
        betrag,
        label
        );
    if (!result) {
    }
    return result;
}

void gewinnverwendungs_zeile_free(gewinnverwendungs_zeile_t *gewinnverwendungs_zeile) {
    if(NULL == gewinnverwendungs_zeile){
        return ;
    }
    if(gewinnverwendungs_zeile->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gewinnverwendungs_zeile_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gewinnverwendungs_zeile->betrag) {
        free(gewinnverwendungs_zeile->betrag);
        gewinnverwendungs_zeile->betrag = NULL;
    }
    if (gewinnverwendungs_zeile->label) {
        free(gewinnverwendungs_zeile->label);
        gewinnverwendungs_zeile->label = NULL;
    }
    free(gewinnverwendungs_zeile);
}

cJSON *gewinnverwendungs_zeile_convertToJSON(gewinnverwendungs_zeile_t *gewinnverwendungs_zeile) {
    cJSON *item = cJSON_CreateObject();

    // gewinnverwendungs_zeile->betrag
    if (!gewinnverwendungs_zeile->betrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "betrag", gewinnverwendungs_zeile->betrag) == NULL) {
    goto fail; //String
    }


    // gewinnverwendungs_zeile->label
    if (!gewinnverwendungs_zeile->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", gewinnverwendungs_zeile->label) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gewinnverwendungs_zeile_t *gewinnverwendungs_zeile_parseFromJSON(cJSON *gewinnverwendungs_zeileJSON){

    gewinnverwendungs_zeile_t *gewinnverwendungs_zeile_local_var = NULL;

    char *betrag_local_str = NULL;

    char *label_local_str = NULL;

    // gewinnverwendungs_zeile->betrag
    cJSON *betrag = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_zeileJSON, "betrag");
    if (cJSON_IsNull(betrag)) {
        betrag = NULL;
    }
    if (!betrag) {
        goto end;
    }

    
    if(!cJSON_IsString(betrag))
    {
    goto end; //String
    }

    // gewinnverwendungs_zeile->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(gewinnverwendungs_zeileJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }


    if (betrag && !cJSON_IsNull(betrag)) betrag_local_str = strdup(betrag->valuestring);
    if (label && !cJSON_IsNull(label)) label_local_str = strdup(label->valuestring);

    gewinnverwendungs_zeile_local_var = gewinnverwendungs_zeile_create_internal (
        betrag_local_str,
        label_local_str
        );

    if (!gewinnverwendungs_zeile_local_var) {
        goto end;
    }

    return gewinnverwendungs_zeile_local_var;
end:
    if (betrag_local_str) {
        free(betrag_local_str);
        betrag_local_str = NULL;
    }
    if (label_local_str) {
        free(label_local_str);
        label_local_str = NULL;
    }
    return NULL;

}
