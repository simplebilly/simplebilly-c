#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "budget_ergebnis.h"



static budget_ergebnis_t *budget_ergebnis_create_internal(
    int *jahr,
    int *monat,
    list_t *monats_budget,
    list_t *prognose_restjahr
    ) {
    budget_ergebnis_t *budget_ergebnis_local_var = malloc(sizeof(budget_ergebnis_t));
    if (!budget_ergebnis_local_var) {
        return NULL;
    }
    memset(budget_ergebnis_local_var, 0, sizeof(budget_ergebnis_t));
    budget_ergebnis_local_var->_library_owned = 1;
    budget_ergebnis_local_var->jahr = jahr;
    budget_ergebnis_local_var->monat = monat;
    budget_ergebnis_local_var->monats_budget = monats_budget;
    budget_ergebnis_local_var->prognose_restjahr = prognose_restjahr;
    return budget_ergebnis_local_var;
}

__attribute__((deprecated)) budget_ergebnis_t *budget_ergebnis_create(
    int *jahr,
    int *monat,
    list_t *monats_budget,
    list_t *prognose_restjahr
    ) {
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    int *monat_copy = NULL;
    if (monat) {
        monat_copy = malloc(sizeof(int));
        if (monat_copy) *monat_copy = *monat;
    }
    budget_ergebnis_t *result = budget_ergebnis_create_internal (
        jahr_copy,
        monat_copy,
        monats_budget,
        prognose_restjahr
        );
    if (!result) {
        free(jahr_copy);
        free(monat_copy);
    }
    return result;
}

void budget_ergebnis_free(budget_ergebnis_t *budget_ergebnis) {
    if(NULL == budget_ergebnis){
        return ;
    }
    if(budget_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "budget_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (budget_ergebnis->jahr) {
        free(budget_ergebnis->jahr);
        budget_ergebnis->jahr = NULL;
    }
    if (budget_ergebnis->monat) {
        free(budget_ergebnis->monat);
        budget_ergebnis->monat = NULL;
    }
    if (budget_ergebnis->monats_budget) {
        list_ForEach(listEntry, budget_ergebnis->monats_budget) {
            budget_kategorie_free(listEntry->data);
        }
        list_freeList(budget_ergebnis->monats_budget);
        budget_ergebnis->monats_budget = NULL;
    }
    if (budget_ergebnis->prognose_restjahr) {
        list_ForEach(listEntry, budget_ergebnis->prognose_restjahr) {
            budget_kategorie_free(listEntry->data);
        }
        list_freeList(budget_ergebnis->prognose_restjahr);
        budget_ergebnis->prognose_restjahr = NULL;
    }
    free(budget_ergebnis);
}

cJSON *budget_ergebnis_convertToJSON(budget_ergebnis_t *budget_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // budget_ergebnis->jahr
    if (!budget_ergebnis->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *budget_ergebnis->jahr) == NULL) {
    goto fail; //Numeric
    }


    // budget_ergebnis->monat
    if (!budget_ergebnis->monat) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "monat", *budget_ergebnis->monat) == NULL) {
    goto fail; //Numeric
    }


    // budget_ergebnis->monats_budget
    if (!budget_ergebnis->monats_budget) {
        goto fail;
    }
    cJSON *monats_budget = cJSON_AddArrayToObject(item, "monats_budget");
    if(monats_budget == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *monats_budgetListEntry;
    if (budget_ergebnis->monats_budget) {
    list_ForEach(monats_budgetListEntry, budget_ergebnis->monats_budget) {
    cJSON *itemLocal = budget_kategorie_convertToJSON(monats_budgetListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(monats_budget, itemLocal);
    }
    }


    // budget_ergebnis->prognose_restjahr
    if (!budget_ergebnis->prognose_restjahr) {
        goto fail;
    }
    cJSON *prognose_restjahr = cJSON_AddArrayToObject(item, "prognose_restjahr");
    if(prognose_restjahr == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *prognose_restjahrListEntry;
    if (budget_ergebnis->prognose_restjahr) {
    list_ForEach(prognose_restjahrListEntry, budget_ergebnis->prognose_restjahr) {
    cJSON *itemLocal = budget_kategorie_convertToJSON(prognose_restjahrListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prognose_restjahr, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

budget_ergebnis_t *budget_ergebnis_parseFromJSON(cJSON *budget_ergebnisJSON){

    budget_ergebnis_t *budget_ergebnis_local_var = NULL;

    // define the local variable for budget_ergebnis->jahr
    int *jahr_local_var = NULL;

    // define the local variable for budget_ergebnis->monat
    int *monat_local_var = NULL;

    // define the local list for budget_ergebnis->monats_budget
    list_t *monats_budgetList = NULL;

    // define the local list for budget_ergebnis->prognose_restjahr
    list_t *prognose_restjahrList = NULL;

    // budget_ergebnis->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(budget_ergebnisJSON, "jahr");
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

    // budget_ergebnis->monat
    cJSON *monat = cJSON_GetObjectItemCaseSensitive(budget_ergebnisJSON, "monat");
    if (cJSON_IsNull(monat)) {
        monat = NULL;
    }
    if (!monat) {
        goto end;
    }

    
    if(!cJSON_IsNumber(monat))
    {
    goto end; //Numeric
    }
    monat_local_var = malloc(sizeof(int));
    if(!monat_local_var)
    {
        goto end;
    }
    *monat_local_var = monat->valuedouble;

    // budget_ergebnis->monats_budget
    cJSON *monats_budget = cJSON_GetObjectItemCaseSensitive(budget_ergebnisJSON, "monats_budget");
    if (cJSON_IsNull(monats_budget)) {
        monats_budget = NULL;
    }
    if (!monats_budget) {
        goto end;
    }

    
    cJSON *monats_budget_local_nonprimitive = NULL;
    if(!cJSON_IsArray(monats_budget)){
        goto end; //nonprimitive container
    }

    monats_budgetList = list_createList();

    cJSON_ArrayForEach(monats_budget_local_nonprimitive,monats_budget )
    {
        if(!cJSON_IsObject(monats_budget_local_nonprimitive)){
            goto end;
        }
        budget_kategorie_t *monats_budgetItem = budget_kategorie_parseFromJSON(monats_budget_local_nonprimitive);

        list_addElement(monats_budgetList, monats_budgetItem);
    }

    // budget_ergebnis->prognose_restjahr
    cJSON *prognose_restjahr = cJSON_GetObjectItemCaseSensitive(budget_ergebnisJSON, "prognose_restjahr");
    if (cJSON_IsNull(prognose_restjahr)) {
        prognose_restjahr = NULL;
    }
    if (!prognose_restjahr) {
        goto end;
    }

    
    cJSON *prognose_restjahr_local_nonprimitive = NULL;
    if(!cJSON_IsArray(prognose_restjahr)){
        goto end; //nonprimitive container
    }

    prognose_restjahrList = list_createList();

    cJSON_ArrayForEach(prognose_restjahr_local_nonprimitive,prognose_restjahr )
    {
        if(!cJSON_IsObject(prognose_restjahr_local_nonprimitive)){
            goto end;
        }
        budget_kategorie_t *prognose_restjahrItem = budget_kategorie_parseFromJSON(prognose_restjahr_local_nonprimitive);

        list_addElement(prognose_restjahrList, prognose_restjahrItem);
    }



    budget_ergebnis_local_var = budget_ergebnis_create_internal (
        jahr_local_var,
        monat_local_var,
        monats_budgetList,
        prognose_restjahrList
        );

    if (!budget_ergebnis_local_var) {
        goto end;
    }

    return budget_ergebnis_local_var;
end:
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (monat_local_var) {
        free(monat_local_var);
        monat_local_var = NULL;
    }
    if (monats_budgetList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, monats_budgetList) {
            budget_kategorie_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(monats_budgetList);
        monats_budgetList = NULL;
    }
    if (prognose_restjahrList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, prognose_restjahrList) {
            budget_kategorie_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(prognose_restjahrList);
        prognose_restjahrList = NULL;
    }
    return NULL;

}
