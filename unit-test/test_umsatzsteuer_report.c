#ifndef umsatzsteuer_report_TEST
#define umsatzsteuer_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define umsatzsteuer_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/umsatzsteuer_report.h"
umsatzsteuer_report_t* instantiate_umsatzsteuer_report(int include_optional);



umsatzsteuer_report_t* instantiate_umsatzsteuer_report(int include_optional) {
  umsatzsteuer_report_t* umsatzsteuer_report = NULL;
  if (include_optional) {
    umsatzsteuer_report = umsatzsteuer_report_create(
      "0",
      list_createList(),
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    umsatzsteuer_report = umsatzsteuer_report_create(
      "0",
      list_createList(),
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return umsatzsteuer_report;
}


#ifdef umsatzsteuer_report_MAIN

void test_umsatzsteuer_report(int include_optional) {
    umsatzsteuer_report_t* umsatzsteuer_report_1 = instantiate_umsatzsteuer_report(include_optional);

	cJSON* jsonumsatzsteuer_report_1 = umsatzsteuer_report_convertToJSON(umsatzsteuer_report_1);
	printf("umsatzsteuer_report :\n%s\n", cJSON_Print(jsonumsatzsteuer_report_1));
	umsatzsteuer_report_t* umsatzsteuer_report_2 = umsatzsteuer_report_parseFromJSON(jsonumsatzsteuer_report_1);
	cJSON* jsonumsatzsteuer_report_2 = umsatzsteuer_report_convertToJSON(umsatzsteuer_report_2);
	printf("repeating umsatzsteuer_report:\n%s\n", cJSON_Print(jsonumsatzsteuer_report_2));
}

int main() {
  test_umsatzsteuer_report(1);
  test_umsatzsteuer_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // umsatzsteuer_report_MAIN
#endif // umsatzsteuer_report_TEST
