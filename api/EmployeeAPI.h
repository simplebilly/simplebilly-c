#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/employee.h"
#include "../model/employee_create.h"
#include "../model/employee_update.h"
#include "../model/payroll_summary.h"
#include "../model/plugin_error.h"


employee_t*
EmployeeAPI_createEmployee(apiClient_t *apiClient, employee_create_t *employee_create);


void
EmployeeAPI_deleteEmployee(apiClient_t *apiClient, char *id);


employee_t*
EmployeeAPI_employeeRestore(apiClient_t *apiClient, char *id);


employee_t*
EmployeeAPI_getEmployee(apiClient_t *apiClient, char *id);


payroll_summary_t*
EmployeeAPI_getEmployeePayrollSummary(apiClient_t *apiClient, char *id, int *year);


list_t*
EmployeeAPI_getEmployees(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


employee_t*
EmployeeAPI_updateEmployee(apiClient_t *apiClient, char *id, employee_update_t *employee_update);


