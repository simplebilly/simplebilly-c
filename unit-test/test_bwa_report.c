#ifndef bwa_report_TEST
#define bwa_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bwa_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bwa_report.h"
bwa_report_t* instantiate_bwa_report(int include_optional);

#include "test_bwa_expenses.c"
#include "test_bwa_revenue.c"
#include "test_bwa_summary.c"


bwa_report_t* instantiate_bwa_report(int include_optional) {
  bwa_report_t* bwa_report = NULL;
  if (include_optional) {
    bwa_report = bwa_report_create(
       // false, not to have infinite recursion
      instantiate_bwa_expenses(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_bwa_revenue(0),
       // false, not to have infinite recursion
      instantiate_bwa_summary(0)
    );
  } else {
    bwa_report = bwa_report_create(
      NULL,
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return bwa_report;
}


#ifdef bwa_report_MAIN

void test_bwa_report(int include_optional) {
    bwa_report_t* bwa_report_1 = instantiate_bwa_report(include_optional);

	cJSON* jsonbwa_report_1 = bwa_report_convertToJSON(bwa_report_1);
	printf("bwa_report :\n%s\n", cJSON_Print(jsonbwa_report_1));
	bwa_report_t* bwa_report_2 = bwa_report_parseFromJSON(jsonbwa_report_1);
	cJSON* jsonbwa_report_2 = bwa_report_convertToJSON(bwa_report_2);
	printf("repeating bwa_report:\n%s\n", cJSON_Print(jsonbwa_report_2));
}

int main() {
  test_bwa_report(1);
  test_bwa_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // bwa_report_MAIN
#endif // bwa_report_TEST
