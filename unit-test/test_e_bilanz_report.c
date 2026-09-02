#ifndef e_bilanz_report_TEST
#define e_bilanz_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define e_bilanz_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/e_bilanz_report.h"
e_bilanz_report_t* instantiate_e_bilanz_report(int include_optional);

#include "test_balance_sheet.c"
#include "test_income_statement.c"
#include "test_vat_summary.c"


e_bilanz_report_t* instantiate_e_bilanz_report(int include_optional) {
  e_bilanz_report_t* e_bilanz_report = NULL;
  if (include_optional) {
    e_bilanz_report = e_bilanz_report_create(
      list_createList(),
       // false, not to have infinite recursion
      instantiate_balance_sheet(0),
      "0",
       // false, not to have infinite recursion
      instantiate_income_statement(0),
      "0",
       // false, not to have infinite recursion
      instantiate_vat_summary(0)
    );
  } else {
    e_bilanz_report = e_bilanz_report_create(
      list_createList(),
      NULL,
      "0",
      NULL,
      "0",
      NULL
    );
  }

  return e_bilanz_report;
}


#ifdef e_bilanz_report_MAIN

void test_e_bilanz_report(int include_optional) {
    e_bilanz_report_t* e_bilanz_report_1 = instantiate_e_bilanz_report(include_optional);

	cJSON* jsone_bilanz_report_1 = e_bilanz_report_convertToJSON(e_bilanz_report_1);
	printf("e_bilanz_report :\n%s\n", cJSON_Print(jsone_bilanz_report_1));
	e_bilanz_report_t* e_bilanz_report_2 = e_bilanz_report_parseFromJSON(jsone_bilanz_report_1);
	cJSON* jsone_bilanz_report_2 = e_bilanz_report_convertToJSON(e_bilanz_report_2);
	printf("repeating e_bilanz_report:\n%s\n", cJSON_Print(jsone_bilanz_report_2));
}

int main() {
  test_e_bilanz_report(1);
  test_e_bilanz_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // e_bilanz_report_MAIN
#endif // e_bilanz_report_TEST
