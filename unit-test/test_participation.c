#ifndef participation_TEST
#define participation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define participation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/participation.h"
participation_t* instantiate_participation(int include_optional);



participation_t* instantiate_participation(int include_optional) {
  participation_t* participation = NULL;
  if (include_optional) {
    participation = participation_create(
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
    participation = participation_create(
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

  return participation;
}


#ifdef participation_MAIN

void test_participation(int include_optional) {
    participation_t* participation_1 = instantiate_participation(include_optional);

	cJSON* jsonparticipation_1 = participation_convertToJSON(participation_1);
	printf("participation :\n%s\n", cJSON_Print(jsonparticipation_1));
	participation_t* participation_2 = participation_parseFromJSON(jsonparticipation_1);
	cJSON* jsonparticipation_2 = participation_convertToJSON(participation_2);
	printf("repeating participation:\n%s\n", cJSON_Print(jsonparticipation_2));
}

int main() {
  test_participation(1);
  test_participation(0);

  printf("Hello world \n");
  return 0;
}

#endif // participation_MAIN
#endif // participation_TEST
