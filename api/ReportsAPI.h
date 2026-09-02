#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/bilanz_report.h"
#include "../model/gu_v_report.h"
#include "../model/konto_report.h"
#include "../model/umsatzsteuer_report.h"


// Bilanz (Balance Sheet)
//
bilanz_report_t*
ReportsAPI_bilanzReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size);


// Gewinn- und Verlustrechnung (P&L statement)
//
gu_v_report_t*
ReportsAPI_guvReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size);


// Kontenansicht (Account Overview)
//
konto_report_t*
ReportsAPI_kontenansichtReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size);


// Umsatzsteuer-Voranmeldung (VAT report)
//
umsatzsteuer_report_t*
ReportsAPI_umsatzsteuerReportApi(apiClient_t *apiClient, int *year, int *month, char *date_from, char *date_to, int *page, int *page_size);


