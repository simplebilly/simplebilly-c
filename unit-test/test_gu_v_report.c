#ifndef gu_v_report_TEST
#define gu_v_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gu_v_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gu_v_report.h"
gu_v_report_t* instantiate_gu_v_report(int include_optional);



gu_v_report_t* instantiate_gu_v_report(int include_optional) {
  gu_v_report_t* gu_v_report = NULL;
  if (include_optional) {
    gu_v_report = gu_v_report_create(
      list_createList(),
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0"
    );
  } else {
    gu_v_report = gu_v_report_create(
      list_createList(),
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0"
    );
  }

  return gu_v_report;
}


#ifdef gu_v_report_MAIN

void test_gu_v_report(int include_optional) {
    gu_v_report_t* gu_v_report_1 = instantiate_gu_v_report(include_optional);

	cJSON* jsongu_v_report_1 = gu_v_report_convertToJSON(gu_v_report_1);
	printf("gu_v_report :\n%s\n", cJSON_Print(jsongu_v_report_1));
	gu_v_report_t* gu_v_report_2 = gu_v_report_parseFromJSON(jsongu_v_report_1);
	cJSON* jsongu_v_report_2 = gu_v_report_convertToJSON(gu_v_report_2);
	printf("repeating gu_v_report:\n%s\n", cJSON_Print(jsongu_v_report_2));
}

int main() {
  test_gu_v_report(1);
  test_gu_v_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // gu_v_report_MAIN
#endif // gu_v_report_TEST
