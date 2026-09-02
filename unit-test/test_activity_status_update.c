#ifndef activity_status_update_TEST
#define activity_status_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_status_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_status_update.h"
activity_status_update_t* instantiate_activity_status_update(int include_optional);



activity_status_update_t* instantiate_activity_status_update(int include_optional) {
  activity_status_update_t* activity_status_update = NULL;
  if (include_optional) {
    activity_status_update = activity_status_update_create(
      "0"
    );
  } else {
    activity_status_update = activity_status_update_create(
      "0"
    );
  }

  return activity_status_update;
}


#ifdef activity_status_update_MAIN

void test_activity_status_update(int include_optional) {
    activity_status_update_t* activity_status_update_1 = instantiate_activity_status_update(include_optional);

	cJSON* jsonactivity_status_update_1 = activity_status_update_convertToJSON(activity_status_update_1);
	printf("activity_status_update :\n%s\n", cJSON_Print(jsonactivity_status_update_1));
	activity_status_update_t* activity_status_update_2 = activity_status_update_parseFromJSON(jsonactivity_status_update_1);
	cJSON* jsonactivity_status_update_2 = activity_status_update_convertToJSON(activity_status_update_2);
	printf("repeating activity_status_update:\n%s\n", cJSON_Print(jsonactivity_status_update_2));
}

int main() {
  test_activity_status_update(1);
  test_activity_status_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_status_update_MAIN
#endif // activity_status_update_TEST
