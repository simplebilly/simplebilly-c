#ifndef participation_update_TEST
#define participation_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define participation_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/participation_update.h"
participation_update_t* instantiate_participation_update(int include_optional);



participation_update_t* instantiate_participation_update(int include_optional) {
  participation_update_t* participation_update = NULL;
  if (include_optional) {
    participation_update = participation_update_create(
      "2013-10-20",
      1,
      "0",
      1,
      "0",
      "0",
      1,
      1
    );
  } else {
    participation_update = participation_update_create(
      "2013-10-20",
      1,
      "0",
      1,
      "0",
      "0",
      1,
      1
    );
  }

  return participation_update;
}


#ifdef participation_update_MAIN

void test_participation_update(int include_optional) {
    participation_update_t* participation_update_1 = instantiate_participation_update(include_optional);

	cJSON* jsonparticipation_update_1 = participation_update_convertToJSON(participation_update_1);
	printf("participation_update :\n%s\n", cJSON_Print(jsonparticipation_update_1));
	participation_update_t* participation_update_2 = participation_update_parseFromJSON(jsonparticipation_update_1);
	cJSON* jsonparticipation_update_2 = participation_update_convertToJSON(participation_update_2);
	printf("repeating participation_update:\n%s\n", cJSON_Print(jsonparticipation_update_2));
}

int main() {
  test_participation_update(1);
  test_participation_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // participation_update_MAIN
#endif // participation_update_TEST
