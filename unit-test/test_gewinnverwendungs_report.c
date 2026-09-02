#ifndef gewinnverwendungs_report_TEST
#define gewinnverwendungs_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gewinnverwendungs_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gewinnverwendungs_report.h"
gewinnverwendungs_report_t* instantiate_gewinnverwendungs_report(int include_optional);



gewinnverwendungs_report_t* instantiate_gewinnverwendungs_report(int include_optional) {
  gewinnverwendungs_report_t* gewinnverwendungs_report = NULL;
  if (include_optional) {
    gewinnverwendungs_report = gewinnverwendungs_report_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      list_createList()
    );
  } else {
    gewinnverwendungs_report = gewinnverwendungs_report_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      list_createList()
    );
  }

  return gewinnverwendungs_report;
}


#ifdef gewinnverwendungs_report_MAIN

void test_gewinnverwendungs_report(int include_optional) {
    gewinnverwendungs_report_t* gewinnverwendungs_report_1 = instantiate_gewinnverwendungs_report(include_optional);

	cJSON* jsongewinnverwendungs_report_1 = gewinnverwendungs_report_convertToJSON(gewinnverwendungs_report_1);
	printf("gewinnverwendungs_report :\n%s\n", cJSON_Print(jsongewinnverwendungs_report_1));
	gewinnverwendungs_report_t* gewinnverwendungs_report_2 = gewinnverwendungs_report_parseFromJSON(jsongewinnverwendungs_report_1);
	cJSON* jsongewinnverwendungs_report_2 = gewinnverwendungs_report_convertToJSON(gewinnverwendungs_report_2);
	printf("repeating gewinnverwendungs_report:\n%s\n", cJSON_Print(jsongewinnverwendungs_report_2));
}

int main() {
  test_gewinnverwendungs_report(1);
  test_gewinnverwendungs_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // gewinnverwendungs_report_MAIN
#endif // gewinnverwendungs_report_TEST
