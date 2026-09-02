#ifndef activity_update_TEST
#define activity_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_update.h"
activity_update_t* instantiate_activity_update(int include_optional);



activity_update_t* instantiate_activity_update(int include_optional) {
  activity_update_t* activity_update = NULL;
  if (include_optional) {
    activity_update = activity_update_create(
      call,
      "0",
      "0",
      "0",
      "2013-10-20",
      "2013-10-20",
      open,
      "0"
    );
  } else {
    activity_update = activity_update_create(
      call,
      "0",
      "0",
      "0",
      "2013-10-20",
      "2013-10-20",
      open,
      "0"
    );
  }

  return activity_update;
}


#ifdef activity_update_MAIN

void test_activity_update(int include_optional) {
    activity_update_t* activity_update_1 = instantiate_activity_update(include_optional);

	cJSON* jsonactivity_update_1 = activity_update_convertToJSON(activity_update_1);
	printf("activity_update :\n%s\n", cJSON_Print(jsonactivity_update_1));
	activity_update_t* activity_update_2 = activity_update_parseFromJSON(jsonactivity_update_1);
	cJSON* jsonactivity_update_2 = activity_update_convertToJSON(activity_update_2);
	printf("repeating activity_update:\n%s\n", cJSON_Print(jsonactivity_update_2));
}

int main() {
  test_activity_update(1);
  test_activity_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_update_MAIN
#endif // activity_update_TEST
