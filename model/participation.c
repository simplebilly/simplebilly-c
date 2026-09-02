#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "participation.h"



static participation_t *participation_create_internal(
    char *acquired_at,
    int *board_appointment,
    char *company_name,
    int *control_agreement,
    char *legal_form,
    char *ownership_pct,
    int *purpose_vehicle,
    int *voting_majority
    ) {
    participation_t *participation_local_var = malloc(sizeof(participation_t));
    if (!participation_local_var) {
        return NULL;
    }
    memset(participation_local_var, 0, sizeof(participation_t));
    participation_local_var->_library_owned = 1;
    participation_local_var->acquired_at = acquired_at;
    participation_local_var->board_appointment = board_appointment;
    participation_local_var->company_name = company_name;
    participation_local_var->control_agreement = control_agreement;
    participation_local_var->legal_form = legal_form;
    participation_local_var->ownership_pct = ownership_pct;
    participation_local_var->purpose_vehicle = purpose_vehicle;
    participation_local_var->voting_majority = voting_majority;
    return participation_local_var;
}

__attribute__((deprecated)) participation_t *participation_create(
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
    participation_t *result = participation_create_internal (
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

void participation_free(participation_t *participation) {
    if(NULL == participation){
        return ;
    }
    if(participation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "participation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (participation->acquired_at) {
        free(participation->acquired_at);
        participation->acquired_at = NULL;
    }
    if (participation->board_appointment) {
        free(participation->board_appointment);
        participation->board_appointment = NULL;
    }
    if (participation->company_name) {
        free(participation->company_name);
        participation->company_name = NULL;
    }
    if (participation->control_agreement) {
        free(participation->control_agreement);
        participation->control_agreement = NULL;
    }
    if (participation->legal_form) {
        free(participation->legal_form);
        participation->legal_form = NULL;
    }
    if (participation->ownership_pct) {
        free(participation->ownership_pct);
        participation->ownership_pct = NULL;
    }
    if (participation->purpose_vehicle) {
        free(participation->purpose_vehicle);
        participation->purpose_vehicle = NULL;
    }
    if (participation->voting_majority) {
        free(participation->voting_majority);
        participation->voting_majority = NULL;
    }
    free(participation);
}

cJSON *participation_convertToJSON(participation_t *participation) {
    cJSON *item = cJSON_CreateObject();

    // participation->acquired_at
    if(participation->acquired_at) {
    if(cJSON_AddStringToObject(item, "acquiredAt", participation->acquired_at) == NULL) {
    goto fail; //Date
    }
    }


    // participation->board_appointment
    if(participation->board_appointment) {
    if(cJSON_AddBoolToObject(item, "boardAppointment", *participation->board_appointment) == NULL) {
    goto fail; //Bool
    }
    }


    // participation->company_name
    if(participation->company_name) {
    if(cJSON_AddStringToObject(item, "companyName", participation->company_name) == NULL) {
    goto fail; //String
    }
    }


    // participation->control_agreement
    if(participation->control_agreement) {
    if(cJSON_AddBoolToObject(item, "controlAgreement", *participation->control_agreement) == NULL) {
    goto fail; //Bool
    }
    }


    // participation->legal_form
    if(participation->legal_form) {
    if(cJSON_AddStringToObject(item, "legalForm", participation->legal_form) == NULL) {
    goto fail; //String
    }
    }


    // participation->ownership_pct
    if(participation->ownership_pct) {
    if(cJSON_AddStringToObject(item, "ownershipPct", participation->ownership_pct) == NULL) {
    goto fail; //String
    }
    }


    // participation->purpose_vehicle
    if(participation->purpose_vehicle) {
    if(cJSON_AddBoolToObject(item, "purposeVehicle", *participation->purpose_vehicle) == NULL) {
    goto fail; //Bool
    }
    }


    // participation->voting_majority
    if(participation->voting_majority) {
    if(cJSON_AddBoolToObject(item, "votingMajority", *participation->voting_majority) == NULL) {
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

participation_t *participation_parseFromJSON(cJSON *participationJSON){

    participation_t *participation_local_var = NULL;

    char *acquired_at_local_str = NULL;

    // define the local variable for participation->board_appointment
    int *board_appointment_local_var = NULL;

    char *company_name_local_str = NULL;

    // define the local variable for participation->control_agreement
    int *control_agreement_local_var = NULL;

    char *legal_form_local_str = NULL;

    char *ownership_pct_local_str = NULL;

    // define the local variable for participation->purpose_vehicle
    int *purpose_vehicle_local_var = NULL;

    // define the local variable for participation->voting_majority
    int *voting_majority_local_var = NULL;

    // participation->acquired_at
    cJSON *acquired_at = cJSON_GetObjectItemCaseSensitive(participationJSON, "acquiredAt");
    if (cJSON_IsNull(acquired_at)) {
        acquired_at = NULL;
    }
    if (acquired_at) { 
    if(!cJSON_IsString(acquired_at))
    {
    goto end; //Date
    }
    }

    // participation->board_appointment
    cJSON *board_appointment = cJSON_GetObjectItemCaseSensitive(participationJSON, "boardAppointment");
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

    // participation->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(participationJSON, "companyName");
    if (cJSON_IsNull(company_name)) {
        company_name = NULL;
    }
    if (company_name) { 
    if(!cJSON_IsString(company_name) && !cJSON_IsNull(company_name))
    {
    goto end; //String
    }
    }

    // participation->control_agreement
    cJSON *control_agreement = cJSON_GetObjectItemCaseSensitive(participationJSON, "controlAgreement");
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

    // participation->legal_form
    cJSON *legal_form = cJSON_GetObjectItemCaseSensitive(participationJSON, "legalForm");
    if (cJSON_IsNull(legal_form)) {
        legal_form = NULL;
    }
    if (legal_form) { 
    if(!cJSON_IsString(legal_form) && !cJSON_IsNull(legal_form))
    {
    goto end; //String
    }
    }

    // participation->ownership_pct
    cJSON *ownership_pct = cJSON_GetObjectItemCaseSensitive(participationJSON, "ownershipPct");
    if (cJSON_IsNull(ownership_pct)) {
        ownership_pct = NULL;
    }
    if (ownership_pct) { 
    if(!cJSON_IsString(ownership_pct) && !cJSON_IsNull(ownership_pct))
    {
    goto end; //String
    }
    }

    // participation->purpose_vehicle
    cJSON *purpose_vehicle = cJSON_GetObjectItemCaseSensitive(participationJSON, "purposeVehicle");
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

    // participation->voting_majority
    cJSON *voting_majority = cJSON_GetObjectItemCaseSensitive(participationJSON, "votingMajority");
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

    participation_local_var = participation_create_internal (
        acquired_at_local_str,
        board_appointment_local_var,
        company_name_local_str,
        control_agreement_local_var,
        legal_form_local_str,
        ownership_pct_local_str,
        purpose_vehicle_local_var,
        voting_majority_local_var
        );

    if (!participation_local_var) {
        goto end;
    }

    return participation_local_var;
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
