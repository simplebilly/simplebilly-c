#ifndef plausibility_report_TEST
#define plausibility_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plausibility_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plausibility_report.h"
plausibility_report_t* instantiate_plausibility_report(int include_optional);

#include "test_plausibility_summary.c"


plausibility_report_t* instantiate_plausibility_report(int include_optional) {
  plausibility_report_t* plausibility_report = NULL;
  if (include_optional) {
    plausibility_report = plausibility_report_create(
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_plausibility_summary(0)
    );
  } else {
    plausibility_report = plausibility_report_create(
      list_createList(),
      "0",
      NULL
    );
  }

  return plausibility_report;
}


#ifdef plausibility_report_MAIN

void test_plausibility_report(int include_optional) {
    plausibility_report_t* plausibility_report_1 = instantiate_plausibility_report(include_optional);

	cJSON* jsonplausibility_report_1 = plausibility_report_convertToJSON(plausibility_report_1);
	printf("plausibility_report :\n%s\n", cJSON_Print(jsonplausibility_report_1));
	plausibility_report_t* plausibility_report_2 = plausibility_report_parseFromJSON(jsonplausibility_report_1);
	cJSON* jsonplausibility_report_2 = plausibility_report_convertToJSON(plausibility_report_2);
	printf("repeating plausibility_report:\n%s\n", cJSON_Print(jsonplausibility_report_2));
}

int main() {
  test_plausibility_report(1);
  test_plausibility_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // plausibility_report_MAIN
#endif // plausibility_report_TEST
