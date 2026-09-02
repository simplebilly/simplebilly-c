#ifndef participation_create_TEST
#define participation_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define participation_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/participation_create.h"
participation_create_t* instantiate_participation_create(int include_optional);



participation_create_t* instantiate_participation_create(int include_optional) {
  participation_create_t* participation_create = NULL;
  if (include_optional) {
    participation_create = participation_create_create(
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
    participation_create = participation_create_create(
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

  return participation_create;
}


#ifdef participation_create_MAIN

void test_participation_create(int include_optional) {
    participation_create_t* participation_create_1 = instantiate_participation_create(include_optional);

	cJSON* jsonparticipation_create_1 = participation_create_convertToJSON(participation_create_1);
	printf("participation_create :\n%s\n", cJSON_Print(jsonparticipation_create_1));
	participation_create_t* participation_create_2 = participation_create_parseFromJSON(jsonparticipation_create_1);
	cJSON* jsonparticipation_create_2 = participation_create_convertToJSON(participation_create_2);
	printf("repeating participation_create:\n%s\n", cJSON_Print(jsonparticipation_create_2));
}

int main() {
  test_participation_create(1);
  test_participation_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // participation_create_MAIN
#endif // participation_create_TEST
