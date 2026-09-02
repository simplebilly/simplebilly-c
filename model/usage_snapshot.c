#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "usage_snapshot.h"



static usage_snapshot_t *usage_snapshot_create_internal(
    long *connectors,
    long *invoices_this_month,
    long *overage_seats,
    long *users
    ) {
    usage_snapshot_t *usage_snapshot_local_var = malloc(sizeof(usage_snapshot_t));
    if (!usage_snapshot_local_var) {
        return NULL;
    }
    memset(usage_snapshot_local_var, 0, sizeof(usage_snapshot_t));
    usage_snapshot_local_var->_library_owned = 1;
    usage_snapshot_local_var->connectors = connectors;
    usage_snapshot_local_var->invoices_this_month = invoices_this_month;
    usage_snapshot_local_var->overage_seats = overage_seats;
    usage_snapshot_local_var->users = users;
    return usage_snapshot_local_var;
}

__attribute__((deprecated)) usage_snapshot_t *usage_snapshot_create(
    long *connectors,
    long *invoices_this_month,
    long *overage_seats,
    long *users
    ) {
    long *connectors_copy = NULL;
    if (connectors) {
        connectors_copy = malloc(sizeof(long));
        if (connectors_copy) *connectors_copy = *connectors;
    }
    long *invoices_this_month_copy = NULL;
    if (invoices_this_month) {
        invoices_this_month_copy = malloc(sizeof(long));
        if (invoices_this_month_copy) *invoices_this_month_copy = *invoices_this_month;
    }
    long *overage_seats_copy = NULL;
    if (overage_seats) {
        overage_seats_copy = malloc(sizeof(long));
        if (overage_seats_copy) *overage_seats_copy = *overage_seats;
    }
    long *users_copy = NULL;
    if (users) {
        users_copy = malloc(sizeof(long));
        if (users_copy) *users_copy = *users;
    }
    usage_snapshot_t *result = usage_snapshot_create_internal (
        connectors_copy,
        invoices_this_month_copy,
        overage_seats_copy,
        users_copy
        );
    if (!result) {
        free(connectors_copy);
        free(invoices_this_month_copy);
        free(overage_seats_copy);
        free(users_copy);
    }
    return result;
}

void usage_snapshot_free(usage_snapshot_t *usage_snapshot) {
    if(NULL == usage_snapshot){
        return ;
    }
    if(usage_snapshot->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "usage_snapshot_free");
        return ;
    }
    listEntry_t *listEntry;
    if (usage_snapshot->connectors) {
        free(usage_snapshot->connectors);
        usage_snapshot->connectors = NULL;
    }
    if (usage_snapshot->invoices_this_month) {
        free(usage_snapshot->invoices_this_month);
        usage_snapshot->invoices_this_month = NULL;
    }
    if (usage_snapshot->overage_seats) {
        free(usage_snapshot->overage_seats);
        usage_snapshot->overage_seats = NULL;
    }
    if (usage_snapshot->users) {
        free(usage_snapshot->users);
        usage_snapshot->users = NULL;
    }
    free(usage_snapshot);
}

cJSON *usage_snapshot_convertToJSON(usage_snapshot_t *usage_snapshot) {
    cJSON *item = cJSON_CreateObject();

    // usage_snapshot->connectors
    if (!usage_snapshot->connectors) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "connectors", *usage_snapshot->connectors) == NULL) {
    goto fail; //Numeric
    }


    // usage_snapshot->invoices_this_month
    if (!usage_snapshot->invoices_this_month) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "invoicesThisMonth", *usage_snapshot->invoices_this_month) == NULL) {
    goto fail; //Numeric
    }


    // usage_snapshot->overage_seats
    if (!usage_snapshot->overage_seats) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "overageSeats", *usage_snapshot->overage_seats) == NULL) {
    goto fail; //Numeric
    }


    // usage_snapshot->users
    if (!usage_snapshot->users) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "users", *usage_snapshot->users) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

usage_snapshot_t *usage_snapshot_parseFromJSON(cJSON *usage_snapshotJSON){

    usage_snapshot_t *usage_snapshot_local_var = NULL;

    // define the local variable for usage_snapshot->connectors
    long *connectors_local_var = NULL;

    // define the local variable for usage_snapshot->invoices_this_month
    long *invoices_this_month_local_var = NULL;

    // define the local variable for usage_snapshot->overage_seats
    long *overage_seats_local_var = NULL;

    // define the local variable for usage_snapshot->users
    long *users_local_var = NULL;

    // usage_snapshot->connectors
    cJSON *connectors = cJSON_GetObjectItemCaseSensitive(usage_snapshotJSON, "connectors");
    if (cJSON_IsNull(connectors)) {
        connectors = NULL;
    }
    if (!connectors) {
        goto end;
    }

    
    if(!cJSON_IsNumber(connectors))
    {
    goto end; //Numeric
    }
    connectors_local_var = malloc(sizeof(long));
    if(!connectors_local_var)
    {
        goto end;
    }
    *connectors_local_var = connectors->valuedouble;

    // usage_snapshot->invoices_this_month
    cJSON *invoices_this_month = cJSON_GetObjectItemCaseSensitive(usage_snapshotJSON, "invoicesThisMonth");
    if (cJSON_IsNull(invoices_this_month)) {
        invoices_this_month = NULL;
    }
    if (!invoices_this_month) {
        goto end;
    }

    
    if(!cJSON_IsNumber(invoices_this_month))
    {
    goto end; //Numeric
    }
    invoices_this_month_local_var = malloc(sizeof(long));
    if(!invoices_this_month_local_var)
    {
        goto end;
    }
    *invoices_this_month_local_var = invoices_this_month->valuedouble;

    // usage_snapshot->overage_seats
    cJSON *overage_seats = cJSON_GetObjectItemCaseSensitive(usage_snapshotJSON, "overageSeats");
    if (cJSON_IsNull(overage_seats)) {
        overage_seats = NULL;
    }
    if (!overage_seats) {
        goto end;
    }

    
    if(!cJSON_IsNumber(overage_seats))
    {
    goto end; //Numeric
    }
    overage_seats_local_var = malloc(sizeof(long));
    if(!overage_seats_local_var)
    {
        goto end;
    }
    *overage_seats_local_var = overage_seats->valuedouble;

    // usage_snapshot->users
    cJSON *users = cJSON_GetObjectItemCaseSensitive(usage_snapshotJSON, "users");
    if (cJSON_IsNull(users)) {
        users = NULL;
    }
    if (!users) {
        goto end;
    }

    
    if(!cJSON_IsNumber(users))
    {
    goto end; //Numeric
    }
    users_local_var = malloc(sizeof(long));
    if(!users_local_var)
    {
        goto end;
    }
    *users_local_var = users->valuedouble;



    usage_snapshot_local_var = usage_snapshot_create_internal (
        connectors_local_var,
        invoices_this_month_local_var,
        overage_seats_local_var,
        users_local_var
        );

    if (!usage_snapshot_local_var) {
        goto end;
    }

    return usage_snapshot_local_var;
end:
    if (connectors_local_var) {
        free(connectors_local_var);
        connectors_local_var = NULL;
    }
    if (invoices_this_month_local_var) {
        free(invoices_this_month_local_var);
        invoices_this_month_local_var = NULL;
    }
    if (overage_seats_local_var) {
        free(overage_seats_local_var);
        overage_seats_local_var = NULL;
    }
    if (users_local_var) {
        free(users_local_var);
        users_local_var = NULL;
    }
    return NULL;

}
