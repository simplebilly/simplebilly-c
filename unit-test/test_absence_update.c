#ifndef absence_update_TEST
#define absence_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define absence_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/absence_update.h"
absence_update_t* instantiate_absence_update(int include_optional);



absence_update_t* instantiate_absence_update(int include_optional) {
  absence_update_t* absence_update = NULL;
  if (include_optional) {
    absence_update = absence_update_create(
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
    absence_update = absence_update_create(
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

  return absence_update;
}


#ifdef absence_update_MAIN

void test_absence_update(int include_optional) {
    absence_update_t* absence_update_1 = instantiate_absence_update(include_optional);

	cJSON* jsonabsence_update_1 = absence_update_convertToJSON(absence_update_1);
	printf("absence_update :\n%s\n", cJSON_Print(jsonabsence_update_1));
	absence_update_t* absence_update_2 = absence_update_parseFromJSON(jsonabsence_update_1);
	cJSON* jsonabsence_update_2 = absence_update_convertToJSON(absence_update_2);
	printf("repeating absence_update:\n%s\n", cJSON_Print(jsonabsence_update_2));
}

int main() {
  test_absence_update(1);
  test_absence_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // absence_update_MAIN
#endif // absence_update_TEST
