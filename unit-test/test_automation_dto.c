#ifndef automation_dto_TEST
#define automation_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define automation_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/automation_dto.h"
automation_dto_t* instantiate_automation_dto(int include_optional);



automation_dto_t* instantiate_automation_dto(int include_optional) {
  automation_dto_t* automation_dto = NULL;
  if (include_optional) {
    automation_dto = automation_dto_create(
      "0",
      null,
      0,
      "0",
      1,
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  } else {
    automation_dto = automation_dto_create(
      "0",
      null,
      0,
      "0",
      1,
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  }

  return automation_dto;
}


#ifdef automation_dto_MAIN

void test_automation_dto(int include_optional) {
    automation_dto_t* automation_dto_1 = instantiate_automation_dto(include_optional);

	cJSON* jsonautomation_dto_1 = automation_dto_convertToJSON(automation_dto_1);
	printf("automation_dto :\n%s\n", cJSON_Print(jsonautomation_dto_1));
	automation_dto_t* automation_dto_2 = automation_dto_parseFromJSON(jsonautomation_dto_1);
	cJSON* jsonautomation_dto_2 = automation_dto_convertToJSON(automation_dto_2);
	printf("repeating automation_dto:\n%s\n", cJSON_Print(jsonautomation_dto_2));
}

int main() {
  test_automation_dto(1);
  test_automation_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // automation_dto_MAIN
#endif // automation_dto_TEST
