#ifndef stille_report_TEST
#define stille_report_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stille_report_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stille_report.h"
stille_report_t* instantiate_stille_report(int include_optional);



stille_report_t* instantiate_stille_report(int include_optional) {
  stille_report_t* stille_report = NULL;
  if (include_optional) {
    stille_report = stille_report_create(
      "0",
      list_createList(),
      56
    );
  } else {
    stille_report = stille_report_create(
      "0",
      list_createList(),
      56
    );
  }

  return stille_report;
}


#ifdef stille_report_MAIN

void test_stille_report(int include_optional) {
    stille_report_t* stille_report_1 = instantiate_stille_report(include_optional);

	cJSON* jsonstille_report_1 = stille_report_convertToJSON(stille_report_1);
	printf("stille_report :\n%s\n", cJSON_Print(jsonstille_report_1));
	stille_report_t* stille_report_2 = stille_report_parseFromJSON(jsonstille_report_1);
	cJSON* jsonstille_report_2 = stille_report_convertToJSON(stille_report_2);
	printf("repeating stille_report:\n%s\n", cJSON_Print(jsonstille_report_2));
}

int main() {
  test_stille_report(1);
  test_stille_report(0);

  printf("Hello world \n");
  return 0;
}

#endif // stille_report_MAIN
#endif // stille_report_TEST
