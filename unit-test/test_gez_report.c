#ifndef gez_report_TEST
#define gez_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gez_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gez_report.h"
gez_report_t* instantiate_gez_report(int include_optional);



gez_report_t* instantiate_gez_report(int include_optional) {
  gez_report_t* gez_report = NULL;
  if (include_optional) {
    gez_report = gez_report_create(
      0,
      0,
      list_createList(),
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0"
    );
  } else {
    gez_report = gez_report_create(
      0,
      0,
      list_createList(),
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0"
    );
  }

  return gez_report;
}


#ifdef gez_report_MAIN

void test_gez_report(int include_optional) {
    gez_report_t* gez_report_1 = instantiate_gez_report(include_optional);

	cJSON* jsongez_report_1 = gez_report_convertToJSON(gez_report_1);
	printf("gez_report :\n%s\n", cJSON_Print(jsongez_report_1));
	gez_report_t* gez_report_2 = gez_report_parseFromJSON(jsongez_report_1);
	cJSON* jsongez_report_2 = gez_report_convertToJSON(gez_report_2);
	printf("repeating gez_report:\n%s\n", cJSON_Print(jsongez_report_2));
}

int main() {
  test_gez_report(1);
  test_gez_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // gez_report_MAIN
#endif // gez_report_TEST
