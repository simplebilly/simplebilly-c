#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gez_report.h"



static gez_report_t *gez_report_create_internal(
    long *beitragsfreie_kfz,
    long *beitragspflichtige_kfz,
    list_t *betriebsstaetten,
    char *hinweis,
    char *hotelzimmer_beitrag,
    char *jaehrlicher_beitrag,
    int *jahr,
    char *kfz_beitrag,
    char *monatlicher_beitrag,
    char *vierteljaehrlicher_beitrag
    ) {
    gez_report_t *gez_report_local_var = malloc(sizeof(gez_report_t));
    if (!gez_report_local_var) {
        return NULL;
    }
    memset(gez_report_local_var, 0, sizeof(gez_report_t));
    gez_report_local_var->_library_owned = 1;
    gez_report_local_var->beitragsfreie_kfz = beitragsfreie_kfz;
    gez_report_local_var->beitragspflichtige_kfz = beitragspflichtige_kfz;
    gez_report_local_var->betriebsstaetten = betriebsstaetten;
    gez_report_local_var->hinweis = hinweis;
    gez_report_local_var->hotelzimmer_beitrag = hotelzimmer_beitrag;
    gez_report_local_var->jaehrlicher_beitrag = jaehrlicher_beitrag;
    gez_report_local_var->jahr = jahr;
    gez_report_local_var->kfz_beitrag = kfz_beitrag;
    gez_report_local_var->monatlicher_beitrag = monatlicher_beitrag;
    gez_report_local_var->vierteljaehrlicher_beitrag = vierteljaehrlicher_beitrag;
    return gez_report_local_var;
}

__attribute__((deprecated)) gez_report_t *gez_report_create(
    long *beitragsfreie_kfz,
    long *beitragspflichtige_kfz,
    list_t *betriebsstaetten,
    char *hinweis,
    char *hotelzimmer_beitrag,
    char *jaehrlicher_beitrag,
    int *jahr,
    char *kfz_beitrag,
    char *monatlicher_beitrag,
    char *vierteljaehrlicher_beitrag
    ) {
    long *beitragsfreie_kfz_copy = NULL;
    if (beitragsfreie_kfz) {
        beitragsfreie_kfz_copy = malloc(sizeof(long));
        if (beitragsfreie_kfz_copy) *beitragsfreie_kfz_copy = *beitragsfreie_kfz;
    }
    long *beitragspflichtige_kfz_copy = NULL;
    if (beitragspflichtige_kfz) {
        beitragspflichtige_kfz_copy = malloc(sizeof(long));
        if (beitragspflichtige_kfz_copy) *beitragspflichtige_kfz_copy = *beitragspflichtige_kfz;
    }
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    gez_report_t *result = gez_report_create_internal (
        beitragsfreie_kfz_copy,
        beitragspflichtige_kfz_copy,
        betriebsstaetten,
        hinweis,
        hotelzimmer_beitrag,
        jaehrlicher_beitrag,
        jahr_copy,
        kfz_beitrag,
        monatlicher_beitrag,
        vierteljaehrlicher_beitrag
        );
    if (!result) {
        free(beitragsfreie_kfz_copy);
        free(beitragspflichtige_kfz_copy);
        free(jahr_copy);
    }
    return result;
}

void gez_report_free(gez_report_t *gez_report) {
    if(NULL == gez_report){
        return ;
    }
    if(gez_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gez_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gez_report->beitragsfreie_kfz) {
        free(gez_report->beitragsfreie_kfz);
        gez_report->beitragsfreie_kfz = NULL;
    }
    if (gez_report->beitragspflichtige_kfz) {
        free(gez_report->beitragspflichtige_kfz);
        gez_report->beitragspflichtige_kfz = NULL;
    }
    if (gez_report->betriebsstaetten) {
        list_ForEach(listEntry, gez_report->betriebsstaetten) {
            betriebsstaetten_detail_free(listEntry->data);
        }
        list_freeList(gez_report->betriebsstaetten);
        gez_report->betriebsstaetten = NULL;
    }
    if (gez_report->hinweis) {
        free(gez_report->hinweis);
        gez_report->hinweis = NULL;
    }
    if (gez_report->hotelzimmer_beitrag) {
        free(gez_report->hotelzimmer_beitrag);
        gez_report->hotelzimmer_beitrag = NULL;
    }
    if (gez_report->jaehrlicher_beitrag) {
        free(gez_report->jaehrlicher_beitrag);
        gez_report->jaehrlicher_beitrag = NULL;
    }
    if (gez_report->jahr) {
        free(gez_report->jahr);
        gez_report->jahr = NULL;
    }
    if (gez_report->kfz_beitrag) {
        free(gez_report->kfz_beitrag);
        gez_report->kfz_beitrag = NULL;
    }
    if (gez_report->monatlicher_beitrag) {
        free(gez_report->monatlicher_beitrag);
        gez_report->monatlicher_beitrag = NULL;
    }
    if (gez_report->vierteljaehrlicher_beitrag) {
        free(gez_report->vierteljaehrlicher_beitrag);
        gez_report->vierteljaehrlicher_beitrag = NULL;
    }
    free(gez_report);
}

cJSON *gez_report_convertToJSON(gez_report_t *gez_report) {
    cJSON *item = cJSON_CreateObject();

    // gez_report->beitragsfreie_kfz
    if (!gez_report->beitragsfreie_kfz) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "beitragsfreie_kfz", *gez_report->beitragsfreie_kfz) == NULL) {
    goto fail; //Numeric
    }


    // gez_report->beitragspflichtige_kfz
    if (!gez_report->beitragspflichtige_kfz) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "beitragspflichtige_kfz", *gez_report->beitragspflichtige_kfz) == NULL) {
    goto fail; //Numeric
    }


    // gez_report->betriebsstaetten
    if (!gez_report->betriebsstaetten) {
        goto fail;
    }
    cJSON *betriebsstaetten = cJSON_AddArrayToObject(item, "betriebsstaetten");
    if(betriebsstaetten == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *betriebsstaettenListEntry;
    if (gez_report->betriebsstaetten) {
    list_ForEach(betriebsstaettenListEntry, gez_report->betriebsstaetten) {
    cJSON *itemLocal = betriebsstaetten_detail_convertToJSON(betriebsstaettenListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(betriebsstaetten, itemLocal);
    }
    }


    // gez_report->hinweis
    if (!gez_report->hinweis) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hinweis", gez_report->hinweis) == NULL) {
    goto fail; //String
    }


    // gez_report->hotelzimmer_beitrag
    if (!gez_report->hotelzimmer_beitrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hotelzimmer_beitrag", gez_report->hotelzimmer_beitrag) == NULL) {
    goto fail; //String
    }


    // gez_report->jaehrlicher_beitrag
    if (!gez_report->jaehrlicher_beitrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "jaehrlicher_beitrag", gez_report->jaehrlicher_beitrag) == NULL) {
    goto fail; //String
    }


    // gez_report->jahr
    if (!gez_report->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *gez_report->jahr) == NULL) {
    goto fail; //Numeric
    }


    // gez_report->kfz_beitrag
    if (!gez_report->kfz_beitrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kfz_beitrag", gez_report->kfz_beitrag) == NULL) {
    goto fail; //String
    }


    // gez_report->monatlicher_beitrag
    if (!gez_report->monatlicher_beitrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "monatlicher_beitrag", gez_report->monatlicher_beitrag) == NULL) {
    goto fail; //String
    }


    // gez_report->vierteljaehrlicher_beitrag
    if (!gez_report->vierteljaehrlicher_beitrag) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "vierteljaehrlicher_beitrag", gez_report->vierteljaehrlicher_beitrag) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gez_report_t *gez_report_parseFromJSON(cJSON *gez_reportJSON){

    gez_report_t *gez_report_local_var = NULL;

    // define the local variable for gez_report->beitragsfreie_kfz
    long *beitragsfreie_kfz_local_var = NULL;

    // define the local variable for gez_report->beitragspflichtige_kfz
    long *beitragspflichtige_kfz_local_var = NULL;

    // define the local list for gez_report->betriebsstaetten
    list_t *betriebsstaettenList = NULL;

    char *hinweis_local_str = NULL;

    char *hotelzimmer_beitrag_local_str = NULL;

    char *jaehrlicher_beitrag_local_str = NULL;

    // define the local variable for gez_report->jahr
    int *jahr_local_var = NULL;

    char *kfz_beitrag_local_str = NULL;

    char *monatlicher_beitrag_local_str = NULL;

    char *vierteljaehrlicher_beitrag_local_str = NULL;

    // gez_report->beitragsfreie_kfz
    cJSON *beitragsfreie_kfz = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "beitragsfreie_kfz");
    if (cJSON_IsNull(beitragsfreie_kfz)) {
        beitragsfreie_kfz = NULL;
    }
    if (!beitragsfreie_kfz) {
        goto end;
    }

    
    if(!cJSON_IsNumber(beitragsfreie_kfz))
    {
    goto end; //Numeric
    }
    beitragsfreie_kfz_local_var = malloc(sizeof(long));
    if(!beitragsfreie_kfz_local_var)
    {
        goto end;
    }
    *beitragsfreie_kfz_local_var = beitragsfreie_kfz->valuedouble;

    // gez_report->beitragspflichtige_kfz
    cJSON *beitragspflichtige_kfz = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "beitragspflichtige_kfz");
    if (cJSON_IsNull(beitragspflichtige_kfz)) {
        beitragspflichtige_kfz = NULL;
    }
    if (!beitragspflichtige_kfz) {
        goto end;
    }

    
    if(!cJSON_IsNumber(beitragspflichtige_kfz))
    {
    goto end; //Numeric
    }
    beitragspflichtige_kfz_local_var = malloc(sizeof(long));
    if(!beitragspflichtige_kfz_local_var)
    {
        goto end;
    }
    *beitragspflichtige_kfz_local_var = beitragspflichtige_kfz->valuedouble;

    // gez_report->betriebsstaetten
    cJSON *betriebsstaetten = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "betriebsstaetten");
    if (cJSON_IsNull(betriebsstaetten)) {
        betriebsstaetten = NULL;
    }
    if (!betriebsstaetten) {
        goto end;
    }

    
    cJSON *betriebsstaetten_local_nonprimitive = NULL;
    if(!cJSON_IsArray(betriebsstaetten)){
        goto end; //nonprimitive container
    }

    betriebsstaettenList = list_createList();

    cJSON_ArrayForEach(betriebsstaetten_local_nonprimitive,betriebsstaetten )
    {
        if(!cJSON_IsObject(betriebsstaetten_local_nonprimitive)){
            goto end;
        }
        betriebsstaetten_detail_t *betriebsstaettenItem = betriebsstaetten_detail_parseFromJSON(betriebsstaetten_local_nonprimitive);

        list_addElement(betriebsstaettenList, betriebsstaettenItem);
    }

    // gez_report->hinweis
    cJSON *hinweis = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "hinweis");
    if (cJSON_IsNull(hinweis)) {
        hinweis = NULL;
    }
    if (!hinweis) {
        goto end;
    }

    
    if(!cJSON_IsString(hinweis))
    {
    goto end; //String
    }

    // gez_report->hotelzimmer_beitrag
    cJSON *hotelzimmer_beitrag = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "hotelzimmer_beitrag");
    if (cJSON_IsNull(hotelzimmer_beitrag)) {
        hotelzimmer_beitrag = NULL;
    }
    if (!hotelzimmer_beitrag) {
        goto end;
    }

    
    if(!cJSON_IsString(hotelzimmer_beitrag))
    {
    goto end; //String
    }

    // gez_report->jaehrlicher_beitrag
    cJSON *jaehrlicher_beitrag = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "jaehrlicher_beitrag");
    if (cJSON_IsNull(jaehrlicher_beitrag)) {
        jaehrlicher_beitrag = NULL;
    }
    if (!jaehrlicher_beitrag) {
        goto end;
    }

    
    if(!cJSON_IsString(jaehrlicher_beitrag))
    {
    goto end; //String
    }

    // gez_report->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "jahr");
    if (cJSON_IsNull(jahr)) {
        jahr = NULL;
    }
    if (!jahr) {
        goto end;
    }

    
    if(!cJSON_IsNumber(jahr))
    {
    goto end; //Numeric
    }
    jahr_local_var = malloc(sizeof(int));
    if(!jahr_local_var)
    {
        goto end;
    }
    *jahr_local_var = jahr->valuedouble;

    // gez_report->kfz_beitrag
    cJSON *kfz_beitrag = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "kfz_beitrag");
    if (cJSON_IsNull(kfz_beitrag)) {
        kfz_beitrag = NULL;
    }
    if (!kfz_beitrag) {
        goto end;
    }

    
    if(!cJSON_IsString(kfz_beitrag))
    {
    goto end; //String
    }

    // gez_report->monatlicher_beitrag
    cJSON *monatlicher_beitrag = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "monatlicher_beitrag");
    if (cJSON_IsNull(monatlicher_beitrag)) {
        monatlicher_beitrag = NULL;
    }
    if (!monatlicher_beitrag) {
        goto end;
    }

    
    if(!cJSON_IsString(monatlicher_beitrag))
    {
    goto end; //String
    }

    // gez_report->vierteljaehrlicher_beitrag
    cJSON *vierteljaehrlicher_beitrag = cJSON_GetObjectItemCaseSensitive(gez_reportJSON, "vierteljaehrlicher_beitrag");
    if (cJSON_IsNull(vierteljaehrlicher_beitrag)) {
        vierteljaehrlicher_beitrag = NULL;
    }
    if (!vierteljaehrlicher_beitrag) {
        goto end;
    }

    
    if(!cJSON_IsString(vierteljaehrlicher_beitrag))
    {
    goto end; //String
    }


    if (hinweis && !cJSON_IsNull(hinweis)) hinweis_local_str = strdup(hinweis->valuestring);
    if (hotelzimmer_beitrag && !cJSON_IsNull(hotelzimmer_beitrag)) hotelzimmer_beitrag_local_str = strdup(hotelzimmer_beitrag->valuestring);
    if (jaehrlicher_beitrag && !cJSON_IsNull(jaehrlicher_beitrag)) jaehrlicher_beitrag_local_str = strdup(jaehrlicher_beitrag->valuestring);
    if (kfz_beitrag && !cJSON_IsNull(kfz_beitrag)) kfz_beitrag_local_str = strdup(kfz_beitrag->valuestring);
    if (monatlicher_beitrag && !cJSON_IsNull(monatlicher_beitrag)) monatlicher_beitrag_local_str = strdup(monatlicher_beitrag->valuestring);
    if (vierteljaehrlicher_beitrag && !cJSON_IsNull(vierteljaehrlicher_beitrag)) vierteljaehrlicher_beitrag_local_str = strdup(vierteljaehrlicher_beitrag->valuestring);

    gez_report_local_var = gez_report_create_internal (
        beitragsfreie_kfz_local_var,
        beitragspflichtige_kfz_local_var,
        betriebsstaettenList,
        hinweis_local_str,
        hotelzimmer_beitrag_local_str,
        jaehrlicher_beitrag_local_str,
        jahr_local_var,
        kfz_beitrag_local_str,
        monatlicher_beitrag_local_str,
        vierteljaehrlicher_beitrag_local_str
        );

    if (!gez_report_local_var) {
        goto end;
    }

    return gez_report_local_var;
end:
    if (beitragsfreie_kfz_local_var) {
        free(beitragsfreie_kfz_local_var);
        beitragsfreie_kfz_local_var = NULL;
    }
    if (beitragspflichtige_kfz_local_var) {
        free(beitragspflichtige_kfz_local_var);
        beitragspflichtige_kfz_local_var = NULL;
    }
    if (betriebsstaettenList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, betriebsstaettenList) {
            betriebsstaetten_detail_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(betriebsstaettenList);
        betriebsstaettenList = NULL;
    }
    if (hinweis_local_str) {
        free(hinweis_local_str);
        hinweis_local_str = NULL;
    }
    if (hotelzimmer_beitrag_local_str) {
        free(hotelzimmer_beitrag_local_str);
        hotelzimmer_beitrag_local_str = NULL;
    }
    if (jaehrlicher_beitrag_local_str) {
        free(jaehrlicher_beitrag_local_str);
        jaehrlicher_beitrag_local_str = NULL;
    }
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (kfz_beitrag_local_str) {
        free(kfz_beitrag_local_str);
        kfz_beitrag_local_str = NULL;
    }
    if (monatlicher_beitrag_local_str) {
        free(monatlicher_beitrag_local_str);
        monatlicher_beitrag_local_str = NULL;
    }
    if (vierteljaehrlicher_beitrag_local_str) {
        free(vierteljaehrlicher_beitrag_local_str);
        vierteljaehrlicher_beitrag_local_str = NULL;
    }
    return NULL;

}
