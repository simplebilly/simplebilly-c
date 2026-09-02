#ifndef reminder_level_TEST
#define reminder_level_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reminder_level_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reminder_level.h"
reminder_level_t* instantiate_reminder_level(int include_optional);



reminder_level_t* instantiate_reminder_level(int include_optional) {
  reminder_level_t* reminder_level = NULL;
  if (include_optional) {
    reminder_level = reminder_level_create(
    );
  } else {
    reminder_level = reminder_level_create(
    );
  }

  return reminder_level;
}


#ifdef reminder_level_MAIN

void test_reminder_level(int include_optional) {
    reminder_level_t* reminder_level_1 = instantiate_reminder_level(include_optional);

	cJSON* jsonreminder_level_1 = reminder_level_convertToJSON(reminder_level_1);
	printf("reminder_level :\n%s\n", cJSON_Print(jsonreminder_level_1));
	reminder_level_t* reminder_level_2 = reminder_level_parseFromJSON(jsonreminder_level_1);
	cJSON* jsonreminder_level_2 = reminder_level_convertToJSON(reminder_level_2);
	printf("repeating reminder_level:\n%s\n", cJSON_Print(jsonreminder_level_2));
}

int main() {
  test_reminder_level(1);
  test_reminder_level(0);

  printf("Hello world \n");
  return 0;
}

#endif // reminder_level_MAIN
#endif // reminder_level_TEST
