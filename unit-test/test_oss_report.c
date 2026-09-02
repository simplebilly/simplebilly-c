#ifndef oss_report_TEST
#define oss_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define oss_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/oss_report.h"
oss_report_t* instantiate_oss_report(int include_optional);



oss_report_t* instantiate_oss_report(int include_optional) {
  oss_report_t* oss_report = NULL;
  if (include_optional) {
    oss_report = oss_report_create(
      list_createList(),
      0
    );
  } else {
    oss_report = oss_report_create(
      list_createList(),
      0
    );
  }

  return oss_report;
}


#ifdef oss_report_MAIN

void test_oss_report(int include_optional) {
    oss_report_t* oss_report_1 = instantiate_oss_report(include_optional);

	cJSON* jsonoss_report_1 = oss_report_convertToJSON(oss_report_1);
	printf("oss_report :\n%s\n", cJSON_Print(jsonoss_report_1));
	oss_report_t* oss_report_2 = oss_report_parseFromJSON(jsonoss_report_1);
	cJSON* jsonoss_report_2 = oss_report_convertToJSON(oss_report_2);
	printf("repeating oss_report:\n%s\n", cJSON_Print(jsonoss_report_2));
}

int main() {
  test_oss_report(1);
  test_oss_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // oss_report_MAIN
#endif // oss_report_TEST
