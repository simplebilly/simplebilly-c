#ifndef emissions_report_TEST
#define emissions_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define emissions_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/emissions_report.h"
emissions_report_t* instantiate_emissions_report(int include_optional);

#include "test_data_quality.c"


emissions_report_t* instantiate_emissions_report(int include_optional) {
  emissions_report_t* emissions_report = NULL;
  if (include_optional) {
    emissions_report = emissions_report_create(
      list_createList(),
      list_createList(),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_data_quality(0),
      1.337,
      1.337,
      1.337,
      1.337,
      list_createList(),
      "0"
    );
  } else {
    emissions_report = emissions_report_create(
      list_createList(),
      list_createList(),
      list_createList(),
      NULL,
      1.337,
      1.337,
      1.337,
      1.337,
      list_createList(),
      "0"
    );
  }

  return emissions_report;
}


#ifdef emissions_report_MAIN

void test_emissions_report(int include_optional) {
    emissions_report_t* emissions_report_1 = instantiate_emissions_report(include_optional);

	cJSON* jsonemissions_report_1 = emissions_report_convertToJSON(emissions_report_1);
	printf("emissions_report :\n%s\n", cJSON_Print(jsonemissions_report_1));
	emissions_report_t* emissions_report_2 = emissions_report_parseFromJSON(jsonemissions_report_1);
	cJSON* jsonemissions_report_2 = emissions_report_convertToJSON(emissions_report_2);
	printf("repeating emissions_report:\n%s\n", cJSON_Print(jsonemissions_report_2));
}

int main() {
  test_emissions_report(1);
  test_emissions_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // emissions_report_MAIN
#endif // emissions_report_TEST
