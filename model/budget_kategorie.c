#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "budget_kategorie.h"



static budget_kategorie_t *budget_kategorie_create_internal(
    char *budget,
    char *differenz,
    char *goal,
    char *ist,
    char *kategorie
    ) {
    budget_kategorie_t *budget_kategorie_local_var = malloc(sizeof(budget_kategorie_t));
    if (!budget_kategorie_local_var) {
        return NULL;
    }
    memset(budget_kategorie_local_var, 0, sizeof(budget_kategorie_t));
    budget_kategorie_local_var->_library_owned = 1;
    budget_kategorie_local_var->budget = budget;
    budget_kategorie_local_var->differenz = differenz;
    budget_kategorie_local_var->goal = goal;
    budget_kategorie_local_var->ist = ist;
    budget_kategorie_local_var->kategorie = kategorie;
    return budget_kategorie_local_var;
}

__attribute__((deprecated)) budget_kategorie_t *budget_kategorie_create(
    char *budget,
    char *differenz,
    char *goal,
    char *ist,
    char *kategorie
    ) {
    budget_kategorie_t *result = budget_kategorie_create_internal (
        budget,
        differenz,
        goal,
        ist,
        kategorie
        );
    if (!result) {
    }
    return result;
}

void budget_kategorie_free(budget_kategorie_t *budget_kategorie) {
    if(NULL == budget_kategorie){
        return ;
    }
    if(budget_kategorie->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "budget_kategorie_free");
        return ;
    }
    listEntry_t *listEntry;
    if (budget_kategorie->budget) {
        free(budget_kategorie->budget);
        budget_kategorie->budget = NULL;
    }
    if (budget_kategorie->differenz) {
        free(budget_kategorie->differenz);
        budget_kategorie->differenz = NULL;
    }
    if (budget_kategorie->goal) {
        free(budget_kategorie->goal);
        budget_kategorie->goal = NULL;
    }
    if (budget_kategorie->ist) {
        free(budget_kategorie->ist);
        budget_kategorie->ist = NULL;
    }
    if (budget_kategorie->kategorie) {
        free(budget_kategorie->kategorie);
        budget_kategorie->kategorie = NULL;
    }
    free(budget_kategorie);
}

cJSON *budget_kategorie_convertToJSON(budget_kategorie_t *budget_kategorie) {
    cJSON *item = cJSON_CreateObject();

    // budget_kategorie->budget
    if (!budget_kategorie->budget) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "budget", budget_kategorie->budget) == NULL) {
    goto fail; //String
    }


    // budget_kategorie->differenz
    if (!budget_kategorie->differenz) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "differenz", budget_kategorie->differenz) == NULL) {
    goto fail; //String
    }


    // budget_kategorie->goal
    if(budget_kategorie->goal) {
    if(cJSON_AddStringToObject(item, "goal", budget_kategorie->goal) == NULL) {
    goto fail; //String
    }
    }


    // budget_kategorie->ist
    if (!budget_kategorie->ist) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ist", budget_kategorie->ist) == NULL) {
    goto fail; //String
    }


    // budget_kategorie->kategorie
    if (!budget_kategorie->kategorie) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kategorie", budget_kategorie->kategorie) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

budget_kategorie_t *budget_kategorie_parseFromJSON(cJSON *budget_kategorieJSON){

    budget_kategorie_t *budget_kategorie_local_var = NULL;

    char *budget_local_str = NULL;

    char *differenz_local_str = NULL;

    char *goal_local_str = NULL;

    char *ist_local_str = NULL;

    char *kategorie_local_str = NULL;

    // budget_kategorie->budget
    cJSON *budget = cJSON_GetObjectItemCaseSensitive(budget_kategorieJSON, "budget");
    if (cJSON_IsNull(budget)) {
        budget = NULL;
    }
    if (!budget) {
        goto end;
    }

    
    if(!cJSON_IsString(budget))
    {
    goto end; //String
    }

    // budget_kategorie->differenz
    cJSON *differenz = cJSON_GetObjectItemCaseSensitive(budget_kategorieJSON, "differenz");
    if (cJSON_IsNull(differenz)) {
        differenz = NULL;
    }
    if (!differenz) {
        goto end;
    }

    
    if(!cJSON_IsString(differenz))
    {
    goto end; //String
    }

    // budget_kategorie->goal
    cJSON *goal = cJSON_GetObjectItemCaseSensitive(budget_kategorieJSON, "goal");
    if (cJSON_IsNull(goal)) {
        goal = NULL;
    }
    if (goal) { 
    if(!cJSON_IsString(goal) && !cJSON_IsNull(goal))
    {
    goto end; //String
    }
    }

    // budget_kategorie->ist
    cJSON *ist = cJSON_GetObjectItemCaseSensitive(budget_kategorieJSON, "ist");
    if (cJSON_IsNull(ist)) {
        ist = NULL;
    }
    if (!ist) {
        goto end;
    }

    
    if(!cJSON_IsString(ist))
    {
    goto end; //String
    }

    // budget_kategorie->kategorie
    cJSON *kategorie = cJSON_GetObjectItemCaseSensitive(budget_kategorieJSON, "kategorie");
    if (cJSON_IsNull(kategorie)) {
        kategorie = NULL;
    }
    if (!kategorie) {
        goto end;
    }

    
    if(!cJSON_IsString(kategorie))
    {
    goto end; //String
    }


    if (budget && !cJSON_IsNull(budget)) budget_local_str = strdup(budget->valuestring);
    if (differenz && !cJSON_IsNull(differenz)) differenz_local_str = strdup(differenz->valuestring);
    if (goal && !cJSON_IsNull(goal)) goal_local_str = strdup(goal->valuestring);
    if (ist && !cJSON_IsNull(ist)) ist_local_str = strdup(ist->valuestring);
    if (kategorie && !cJSON_IsNull(kategorie)) kategorie_local_str = strdup(kategorie->valuestring);

    budget_kategorie_local_var = budget_kategorie_create_internal (
        budget_local_str,
        differenz_local_str,
        goal_local_str,
        ist_local_str,
        kategorie_local_str
        );

    if (!budget_kategorie_local_var) {
        goto end;
    }

    return budget_kategorie_local_var;
end:
    if (budget_local_str) {
        free(budget_local_str);
        budget_local_str = NULL;
    }
    if (differenz_local_str) {
        free(differenz_local_str);
        differenz_local_str = NULL;
    }
    if (goal_local_str) {
        free(goal_local_str);
        goal_local_str = NULL;
    }
    if (ist_local_str) {
        free(ist_local_str);
        ist_local_str = NULL;
    }
    if (kategorie_local_str) {
        free(kategorie_local_str);
        kategorie_local_str = NULL;
    }
    return NULL;

}
