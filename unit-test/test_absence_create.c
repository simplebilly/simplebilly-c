#ifndef absence_create_TEST
#define absence_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define absence_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/absence_create.h"
absence_create_t* instantiate_absence_create(int include_optional);



absence_create_t* instantiate_absence_create(int include_optional) {
  absence_create_t* absence_create = NULL;
  if (include_optional) {
    absence_create = absence_create_create(
      vacation,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "2013-10-20",
      "0",
      "2013-10-20",
      pending
    );
  } else {
    absence_create = absence_create_create(
      vacation,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "2013-10-20",
      "0",
      "2013-10-20",
      pending
    );
  }

  return absence_create;
}


#ifdef absence_create_MAIN

void test_absence_create(int include_optional) {
    absence_create_t* absence_create_1 = instantiate_absence_create(include_optional);

	cJSON* jsonabsence_create_1 = absence_create_convertToJSON(absence_create_1);
	printf("absence_create :\n%s\n", cJSON_Print(jsonabsence_create_1));
	absence_create_t* absence_create_2 = absence_create_parseFromJSON(jsonabsence_create_1);
	cJSON* jsonabsence_create_2 = absence_create_convertToJSON(absence_create_2);
	printf("repeating absence_create:\n%s\n", cJSON_Print(jsonabsence_create_2));
}

int main() {
  test_absence_create(1);
  test_absence_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // absence_create_MAIN
#endif // absence_create_TEST
