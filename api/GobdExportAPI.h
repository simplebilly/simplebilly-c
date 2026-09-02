#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/go_bd_export_response.h"
#include "../model/plugin_error.h"


go_bd_export_response_t*
GobdExportAPI_buchhalterCsvApi(apiClient_t *apiClient, char *date_from, char *date_to);


// GoBD/GDPdU export. Default: ZIP archive (`index.xml` + CSV tables, IDEA format). `?format=csv` returns the legacy single-journal CSV as JSON.
//
void
GobdExportAPI_gobdExportApi(apiClient_t *apiClient, int *year, char *format);


