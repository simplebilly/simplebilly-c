#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "participation_create.h"



static participation_create_t *participation_create_create_internal(
    char *acquired_at,
    int *board_appointment,
    char *company_name,
    int *control_agreement,
    char *legal_form,
    char *ownership_pct,
    int *purpose_vehicle,
    int *voting_majority
    ) {
    participation_create_t *participation_create_local_var = malloc(sizeof(participation_create_t));
    if (!participation_create_local_var) {
        return NULL;
    }
    memset(participation_create_local_var, 0, sizeof(participation_create_t));
    participation_create_local_var->_library_owned = 1;
    participation_create_local_var->acquired_at = acquired_at;
    participation_create_local_var->board_appointment = board_appointment;
    participation_create_local_var->company_name = company_name;
    participation_create_local_var->control_agreement = control_agreement;
    participation_create_local_var->legal_form = legal_form;
    participation_create_local_var->ownership_pct = ownership_pct;
    participation_create_local_var->purpose_vehicle = purpose_vehicle;
    participation_create_local_var->voting_majority = voting_majority;
    return participation_create_local_var;
}

__attribute__((deprecated)) participation_create_t *participation_create_create(
    char *acquired_at,
    int *board_appointment,
    char *company_name,
    int *control_agreement,
    char *legal_form,
    char *ownership_pct,
    int *purpose_vehicle,
    int *voting_majority
    ) {
    int *board_appointment_copy = NULL;
    if (board_appointment) {
        board_appointment_copy = malloc(sizeof(int));
        if (board_appointment_copy) *board_appointment_copy = *board_appointment;
    }
    int *control_agreement_copy = NULL;
    if (control_agreement) {
        control_agreement_copy = malloc(sizeof(int));
        if (control_agreement_copy) *control_agreement_copy = *control_agreement;
    }
    int *purpose_vehicle_copy = NULL;
    if (purpose_vehicle) {
        purpose_vehicle_copy = malloc(sizeof(int));
        if (purpose_vehicle_copy) *purpose_vehicle_copy = *purpose_vehicle;
    }
    int *voting_majority_copy = NULL;
    if (voting_majority) {
        voting_majority_copy = malloc(sizeof(int));
        if (voting_majority_copy) *voting_majority_copy = *voting_majority;
    }
    participation_create_t *result = participation_create_create_internal (
        acquired_at,
        board_appointment_copy,
        company_name,
        control_agreement_copy,
        legal_form,
        ownership_pct,
        purpose_vehicle_copy,
        voting_majority_copy
        );
    if (!result) {
        free(board_appointment_copy);
        free(control_agreement_copy);
        free(purpose_vehicle_copy);
        free(voting_majority_copy);
    }
    return result;
}

void participation_create_free(participation_create_t *participation_create) {
    if(NULL == participation_create){
        return ;
    }
    if(participation_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "participation_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (participation_create->acquired_at) {
        free(participation_create->acquired_at);
        participation_create->acquired_at = NULL;
    }
    if (participation_create->board_appointment) {
        free(participation_create->board_appointment);
        participation_create->board_appointment = NULL;
    }
    if (participation_create->company_name) {
        free(participation_create->company_name);
        participation_create->company_name = NULL;
    }
    if (participation_create->control_agreement) {
        free(participation_create->control_agreement);
        participation_create->control_agreement = NULL;
    }
    if (participation_create->legal_form) {
        free(participation_create->legal_form);
        participation_create->legal_form = NULL;
    }
    if (participation_create->ownership_pct) {
        free(participation_create->ownership_pct);
        participation_create->ownership_pct = NULL;
    }
    if (participation_create->purpose_vehicle) {
        free(participation_create->purpose_vehicle);
        participation_create->purpose_vehicle = NULL;
    }
    if (participation_create->voting_majority) {
        free(participation_create->voting_majority);
        participation_create->voting_majority = NULL;
    }
    free(participation_create);
}

cJSON *participation_create_convertToJSON(participation_create_t *participation_create) {
    cJSON *item = cJSON_CreateObject();

    // participation_create->acquired_at
    if(participation_create->acquired_at) {
    if(cJSON_AddStringToObject(item, "acquiredAt", participation_create->acquired_at) == NULL) {
    goto fail; //Date
    }
    }


    // participation_create->board_appointment
    if(participation_create->board_appointment) {
    if(cJSON_AddBoolToObject(item, "boardAppointment", *participation_create->board_appointment) == NULL) {
    goto fail; //Bool
    }
    }


    // participation_create->company_name
    if(participation_create->company_name) {
    if(cJSON_AddStringToObject(item, "companyName", participation_create->company_name) == NULL) {
    goto fail; //String
    }
    }


    // participation_create->control_agreement
    if(participation_create->control_agreement) {
    if(cJSON_AddBoolToObject(item, "controlAgreement", *participation_create->control_agreement) == NULL) {
    goto fail; //Bool
    }
    }


    // participation_create->legal_form
    if(participation_create->legal_form) {
    if(cJSON_AddStringToObject(item, "legalForm", participation_create->legal_form) == NULL) {
    goto fail; //String
    }
    }


    // participation_create->ownership_pct
    if(participation_create->ownership_pct) {
    if(cJSON_AddStringToObject(item, "ownershipPct", participation_create->ownership_pct) == NULL) {
    goto fail; //String
    }
    }


    // participation_create->purpose_vehicle
    if(participation_create->purpose_vehicle) {
    if(cJSON_AddBoolToObject(item, "purposeVehicle", *participation_create->purpose_vehicle) == NULL) {
    goto fail; //Bool
    }
    }


    // participation_create->voting_majority
    if(participation_create->voting_majority) {
    if(cJSON_AddBoolToObject(item, "votingMajority", *participation_create->voting_majority) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

participation_create_t *participation_create_parseFromJSON(cJSON *participation_createJSON){

    participation_create_t *participation_create_local_var = NULL;

    char *acquired_at_local_str = NULL;

    // define the local variable for participation_create->board_appointment
    int *board_appointment_local_var = NULL;

    char *company_name_local_str = NULL;

    // define the local variable for participation_create->control_agreement
    int *control_agreement_local_var = NULL;

    char *legal_form_local_str = NULL;

    char *ownership_pct_local_str = NULL;

    // define the local variable for participation_create->purpose_vehicle
    int *purpose_vehicle_local_var = NULL;

    // define the local variable for participation_create->voting_majority
    int *voting_majority_local_var = NULL;

    // participation_create->acquired_at
    cJSON *acquired_at = cJSON_GetObjectItemCaseSensitive(participation_createJSON, "acquiredAt");
    if (cJSON_IsNull(acquired_at)) {
        acquired_at = NULL;
    }
    if (acquired_at) { 
    if(!cJSON_IsString(acquired_at))
    {
    goto end; //Date
    }
    }

    // participation_create->board_appointment
    cJSON *board_appointment = cJSON_GetObjectItemCaseSensitive(participation_createJSON, "boardAppointment");
    if (cJSON_IsNull(board_appointment)) {
        board_appointment = NULL;
    }
    if (board_appointment) { 
    if(!cJSON_IsBool(board_appointment))
    {
    goto end; //Bool
    }
    board_appointment_local_var = malloc(sizeof(int));
    if(!board_appointment_local_var)
    {
        goto end;
    }
    *board_appointment_local_var = board_appointment->valueint;
    }

    // participation_create->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(participation_createJSON, "companyName");
    if (cJSON_IsNull(company_name)) {
        company_name = NULL;
    }
    if (company_name) { 
    if(!cJSON_IsString(company_name) && !cJSON_IsNull(company_name))
    {
    goto end; //String
    }
    }

    // participation_create->control_agreement
    cJSON *control_agreement = cJSON_GetObjectItemCaseSensitive(participation_createJSON, "controlAgreement");
    if (cJSON_IsNull(control_agreement)) {
        control_agreement = NULL;
    }
    if (control_agreement) { 
    if(!cJSON_IsBool(control_agreement))
    {
    goto end; //Bool
    }
    control_agreement_local_var = malloc(sizeof(int));
    if(!control_agreement_local_var)
    {
        goto end;
    }
    *control_agreement_local_var = control_agreement->valueint;
    }

    // participation_create->legal_form
    cJSON *legal_form = cJSON_GetObjectItemCaseSensitive(participation_createJSON, "legalForm");
    if (cJSON_IsNull(legal_form)) {
        legal_form = NULL;
    }
    if (legal_form) { 
    if(!cJSON_IsString(legal_form) && !cJSON_IsNull(legal_form))
    {
    goto end; //String
    }
    }

    // participation_create->ownership_pct
    cJSON *ownership_pct = cJSON_GetObjectItemCaseSensitive(participation_createJSON, "ownershipPct");
    if (cJSON_IsNull(ownership_pct)) {
        ownership_pct = NULL;
    }
    if (ownership_pct) { 
    if(!cJSON_IsString(ownership_pct) && !cJSON_IsNull(ownership_pct))
    {
    goto end; //String
    }
    }

    // participation_create->purpose_vehicle
    cJSON *purpose_vehicle = cJSON_GetObjectItemCaseSensitive(participation_createJSON, "purposeVehicle");
    if (cJSON_IsNull(purpose_vehicle)) {
        purpose_vehicle = NULL;
    }
    if (purpose_vehicle) { 
    if(!cJSON_IsBool(purpose_vehicle))
    {
    goto end; //Bool
    }
    purpose_vehicle_local_var = malloc(sizeof(int));
    if(!purpose_vehicle_local_var)
    {
        goto end;
    }
    *purpose_vehicle_local_var = purpose_vehicle->valueint;
    }

    // participation_create->voting_majority
    cJSON *voting_majority = cJSON_GetObjectItemCaseSensitive(participation_createJSON, "votingMajority");
    if (cJSON_IsNull(voting_majority)) {
        voting_majority = NULL;
    }
    if (voting_majority) { 
    if(!cJSON_IsBool(voting_majority))
    {
    goto end; //Bool
    }
    voting_majority_local_var = malloc(sizeof(int));
    if(!voting_majority_local_var)
    {
        goto end;
    }
    *voting_majority_local_var = voting_majority->valueint;
    }


    if (acquired_at) acquired_at_local_str = strdup(acquired_at->valuestring);
    if (company_name && !cJSON_IsNull(company_name)) company_name_local_str = strdup(company_name->valuestring);
    if (legal_form && !cJSON_IsNull(legal_form)) legal_form_local_str = strdup(legal_form->valuestring);
    if (ownership_pct && !cJSON_IsNull(ownership_pct)) ownership_pct_local_str = strdup(ownership_pct->valuestring);

    participation_create_local_var = participation_create_create_internal (
        acquired_at_local_str,
        board_appointment_local_var,
        company_name_local_str,
        control_agreement_local_var,
        legal_form_local_str,
        ownership_pct_local_str,
        purpose_vehicle_local_var,
        voting_majority_local_var
        );

    if (!participation_create_local_var) {
        goto end;
    }

    return participation_create_local_var;
end:
    if (acquired_at_local_str) {
        free(acquired_at_local_str);
        acquired_at_local_str = NULL;
    }
    if (board_appointment_local_var) {
        free(board_appointment_local_var);
        board_appointment_local_var = NULL;
    }
    if (company_name_local_str) {
        free(company_name_local_str);
        company_name_local_str = NULL;
    }
    if (control_agreement_local_var) {
        free(control_agreement_local_var);
        control_agreement_local_var = NULL;
    }
    if (legal_form_local_str) {
        free(legal_form_local_str);
        legal_form_local_str = NULL;
    }
    if (ownership_pct_local_str) {
        free(ownership_pct_local_str);
        ownership_pct_local_str = NULL;
    }
    if (purpose_vehicle_local_var) {
        free(purpose_vehicle_local_var);
        purpose_vehicle_local_var = NULL;
    }
    if (voting_majority_local_var) {
        free(voting_majority_local_var);
        voting_majority_local_var = NULL;
    }
    return NULL;

}
