#ifndef automation_TEST
#define automation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define automation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/automation.h"
automation_t* instantiate_automation(int include_optional);



automation_t* instantiate_automation(int include_optional) {
  automation_t* automation = NULL;
  if (include_optional) {
    automation = automation_create(
      "0",
      null,
      "2013-10-20T19:20:30+01:00",
      1,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    automation = automation_create(
      "0",
      null,
      "2013-10-20T19:20:30+01:00",
      1,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return automation;
}


#ifdef automation_MAIN

void test_automation(int include_optional) {
    automation_t* automation_1 = instantiate_automation(include_optional);

	cJSON* jsonautomation_1 = automation_convertToJSON(automation_1);
	printf("automation :\n%s\n", cJSON_Print(jsonautomation_1));
	automation_t* automation_2 = automation_parseFromJSON(jsonautomation_1);
	cJSON* jsonautomation_2 = automation_convertToJSON(automation_2);
	printf("repeating automation:\n%s\n", cJSON_Print(jsonautomation_2));
}

int main() {
  test_automation(1);
  test_automation(0);

  printf("Hello world \n");
  return 0;
}

#endif // automation_MAIN
#endif // automation_TEST
