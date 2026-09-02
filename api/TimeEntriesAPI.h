#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/labor_cost_row.h"
#include "../model/plugin_error.h"
#include "../model/time_entry_clock_in.h"
#include "../model/time_entry_clock_out.h"
#include "../model/time_entry_dto.h"


// Clock in for the authenticated user (resolved via their employee profile).
//
time_entry_dto_t*
TimeEntriesAPI_clockInTimeEntry(apiClient_t *apiClient, time_entry_clock_in_t *time_entry_clock_in);


// Clock out an entry: the entry's owner, or anyone with `time_entries:write`.
//
time_entry_dto_t*
TimeEntriesAPI_clockOutTimeEntry(apiClient_t *apiClient, char *id, time_entry_clock_out_t *time_entry_clock_out);


// Labor-cost report: worked hours aggregated per employee / order / day, valued at the employee's hourly cost rate.
//
list_t*
TimeEntriesAPI_getLaborCosts(apiClient_t *apiClient, char from, char to, char *group_by);


// List time entries with optional date-range / active / employee filters.
//
list_t*
TimeEntriesAPI_listTimeEntries(apiClient_t *apiClient, char from, char to, int *active, char *employee_id);


