#ifndef update_automation_TEST
#define update_automation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_automation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_automation.h"
update_automation_t* instantiate_update_automation(int include_optional);



update_automation_t* instantiate_update_automation(int include_optional) {
  update_automation_t* update_automation = NULL;
  if (include_optional) {
    update_automation = update_automation_create(
      null,
      1
    );
  } else {
    update_automation = update_automation_create(
      null,
      1
    );
  }

  return update_automation;
}


#ifdef update_automation_MAIN

void test_update_automation(int include_optional) {
    update_automation_t* update_automation_1 = instantiate_update_automation(include_optional);

	cJSON* jsonupdate_automation_1 = update_automation_convertToJSON(update_automation_1);
	printf("update_automation :\n%s\n", cJSON_Print(jsonupdate_automation_1));
	update_automation_t* update_automation_2 = update_automation_parseFromJSON(jsonupdate_automation_1);
	cJSON* jsonupdate_automation_2 = update_automation_convertToJSON(update_automation_2);
	printf("repeating update_automation:\n%s\n", cJSON_Print(jsonupdate_automation_2));
}

int main() {
  test_update_automation(1);
  test_update_automation(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_automation_MAIN
#endif // update_automation_TEST
