#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "anlage_g_kfz_hinweis.h"



static anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis_create_internal(
    char *bezeichnung,
    char *kennzeichen,
    char *privat_anteil_prozent
    ) {
    anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis_local_var = malloc(sizeof(anlage_g_kfz_hinweis_t));
    if (!anlage_g_kfz_hinweis_local_var) {
        return NULL;
    }
    memset(anlage_g_kfz_hinweis_local_var, 0, sizeof(anlage_g_kfz_hinweis_t));
    anlage_g_kfz_hinweis_local_var->_library_owned = 1;
    anlage_g_kfz_hinweis_local_var->bezeichnung = bezeichnung;
    anlage_g_kfz_hinweis_local_var->kennzeichen = kennzeichen;
    anlage_g_kfz_hinweis_local_var->privat_anteil_prozent = privat_anteil_prozent;
    return anlage_g_kfz_hinweis_local_var;
}

__attribute__((deprecated)) anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis_create(
    char *bezeichnung,
    char *kennzeichen,
    char *privat_anteil_prozent
    ) {
    anlage_g_kfz_hinweis_t *result = anlage_g_kfz_hinweis_create_internal (
        bezeichnung,
        kennzeichen,
        privat_anteil_prozent
        );
    if (!result) {
    }
    return result;
}

void anlage_g_kfz_hinweis_free(anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis) {
    if(NULL == anlage_g_kfz_hinweis){
        return ;
    }
    if(anlage_g_kfz_hinweis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "anlage_g_kfz_hinweis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (anlage_g_kfz_hinweis->bezeichnung) {
        free(anlage_g_kfz_hinweis->bezeichnung);
        anlage_g_kfz_hinweis->bezeichnung = NULL;
    }
    if (anlage_g_kfz_hinweis->kennzeichen) {
        free(anlage_g_kfz_hinweis->kennzeichen);
        anlage_g_kfz_hinweis->kennzeichen = NULL;
    }
    if (anlage_g_kfz_hinweis->privat_anteil_prozent) {
        free(anlage_g_kfz_hinweis->privat_anteil_prozent);
        anlage_g_kfz_hinweis->privat_anteil_prozent = NULL;
    }
    free(anlage_g_kfz_hinweis);
}

cJSON *anlage_g_kfz_hinweis_convertToJSON(anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis) {
    cJSON *item = cJSON_CreateObject();

    // anlage_g_kfz_hinweis->bezeichnung
    if (!anlage_g_kfz_hinweis->bezeichnung) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bezeichnung", anlage_g_kfz_hinweis->bezeichnung) == NULL) {
    goto fail; //String
    }


    // anlage_g_kfz_hinweis->kennzeichen
    if (!anlage_g_kfz_hinweis->kennzeichen) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kennzeichen", anlage_g_kfz_hinweis->kennzeichen) == NULL) {
    goto fail; //String
    }


    // anlage_g_kfz_hinweis->privat_anteil_prozent
    if (!anlage_g_kfz_hinweis->privat_anteil_prozent) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "privat_anteil_prozent", anlage_g_kfz_hinweis->privat_anteil_prozent) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis_parseFromJSON(cJSON *anlage_g_kfz_hinweisJSON){

    anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis_local_var = NULL;

    char *bezeichnung_local_str = NULL;

    char *kennzeichen_local_str = NULL;

    char *privat_anteil_prozent_local_str = NULL;

    // anlage_g_kfz_hinweis->bezeichnung
    cJSON *bezeichnung = cJSON_GetObjectItemCaseSensitive(anlage_g_kfz_hinweisJSON, "bezeichnung");
    if (cJSON_IsNull(bezeichnung)) {
        bezeichnung = NULL;
    }
    if (!bezeichnung) {
        goto end;
    }

    
    if(!cJSON_IsString(bezeichnung))
    {
    goto end; //String
    }

    // anlage_g_kfz_hinweis->kennzeichen
    cJSON *kennzeichen = cJSON_GetObjectItemCaseSensitive(anlage_g_kfz_hinweisJSON, "kennzeichen");
    if (cJSON_IsNull(kennzeichen)) {
        kennzeichen = NULL;
    }
    if (!kennzeichen) {
        goto end;
    }

    
    if(!cJSON_IsString(kennzeichen))
    {
    goto end; //String
    }

    // anlage_g_kfz_hinweis->privat_anteil_prozent
    cJSON *privat_anteil_prozent = cJSON_GetObjectItemCaseSensitive(anlage_g_kfz_hinweisJSON, "privat_anteil_prozent");
    if (cJSON_IsNull(privat_anteil_prozent)) {
        privat_anteil_prozent = NULL;
    }
    if (!privat_anteil_prozent) {
        goto end;
    }

    
    if(!cJSON_IsString(privat_anteil_prozent))
    {
    goto end; //String
    }


    if (bezeichnung && !cJSON_IsNull(bezeichnung)) bezeichnung_local_str = strdup(bezeichnung->valuestring);
    if (kennzeichen && !cJSON_IsNull(kennzeichen)) kennzeichen_local_str = strdup(kennzeichen->valuestring);
    if (privat_anteil_prozent && !cJSON_IsNull(privat_anteil_prozent)) privat_anteil_prozent_local_str = strdup(privat_anteil_prozent->valuestring);

    anlage_g_kfz_hinweis_local_var = anlage_g_kfz_hinweis_create_internal (
        bezeichnung_local_str,
        kennzeichen_local_str,
        privat_anteil_prozent_local_str
        );

    if (!anlage_g_kfz_hinweis_local_var) {
        goto end;
    }

    return anlage_g_kfz_hinweis_local_var;
end:
    if (bezeichnung_local_str) {
        free(bezeichnung_local_str);
        bezeichnung_local_str = NULL;
    }
    if (kennzeichen_local_str) {
        free(kennzeichen_local_str);
        kennzeichen_local_str = NULL;
    }
    if (privat_anteil_prozent_local_str) {
        free(privat_anteil_prozent_local_str);
        privat_anteil_prozent_local_str = NULL;
    }
    return NULL;

}
