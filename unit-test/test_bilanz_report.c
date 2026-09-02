#ifndef bilanz_report_TEST
#define bilanz_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bilanz_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bilanz_report.h"
bilanz_report_t* instantiate_bilanz_report(int include_optional);



bilanz_report_t* instantiate_bilanz_report(int include_optional) {
  bilanz_report_t* bilanz_report = NULL;
  if (include_optional) {
    bilanz_report = bilanz_report_create(
      list_createList(),
      1,
      "0",
      list_createList(),
      "0",
      "0",
      "0"
    );
  } else {
    bilanz_report = bilanz_report_create(
      list_createList(),
      1,
      "0",
      list_createList(),
      "0",
      "0",
      "0"
    );
  }

  return bilanz_report;
}


#ifdef bilanz_report_MAIN

void test_bilanz_report(int include_optional) {
    bilanz_report_t* bilanz_report_1 = instantiate_bilanz_report(include_optional);

	cJSON* jsonbilanz_report_1 = bilanz_report_convertToJSON(bilanz_report_1);
	printf("bilanz_report :\n%s\n", cJSON_Print(jsonbilanz_report_1));
	bilanz_report_t* bilanz_report_2 = bilanz_report_parseFromJSON(jsonbilanz_report_1);
	cJSON* jsonbilanz_report_2 = bilanz_report_convertToJSON(bilanz_report_2);
	printf("repeating bilanz_report:\n%s\n", cJSON_Print(jsonbilanz_report_2));
}

int main() {
  test_bilanz_report(1);
  test_bilanz_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // bilanz_report_MAIN
#endif // bilanz_report_TEST
