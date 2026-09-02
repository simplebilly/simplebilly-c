#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/payroll_create_payload.h"
#include "../model/payroll_pay_payload.h"
#include "../model/payroll_run_api.h"
#include "../model/yearly_payroll_summary.h"


payroll_run_api_t*
PayrollAPI_payrollApprove(apiClient_t *apiClient, char *id);


any_type_t*
PayrollAPI_payrollAutopay(apiClient_t *apiClient, char *id, body);


payroll_run_api_t*
PayrollAPI_payrollCalculate(apiClient_t *apiClient, char *id);


payroll_run_api_t*
PayrollAPI_payrollCreate(apiClient_t *apiClient, payroll_create_payload_t *payroll_create_payload);


void
PayrollAPI_payrollDelete(apiClient_t *apiClient, char *id);


void
PayrollAPI_payrollElsterExport(apiClient_t *apiClient, char *id);


any_type_t*
PayrollAPI_payrollEmail(apiClient_t *apiClient, char *id);


void
PayrollAPI_payrollEntryPdf(apiClient_t *apiClient, char *id, char *entry_id);


payroll_run_api_t*
PayrollAPI_payrollGet(apiClient_t *apiClient, char *id);


list_t*
PayrollAPI_payrollList(apiClient_t *apiClient, int *year, char *status);


payroll_run_api_t*
PayrollAPI_payrollPay(apiClient_t *apiClient, char *id, payroll_pay_payload_t *payroll_pay_payload);


void
PayrollAPI_payrollPdf(apiClient_t *apiClient, char *id);


yearly_payroll_summary_t*
PayrollAPI_payrollSummary(apiClient_t *apiClient, int *year);


any_type_t*
PayrollAPI_payrollSvMeldungen(apiClient_t *apiClient, char *id);


