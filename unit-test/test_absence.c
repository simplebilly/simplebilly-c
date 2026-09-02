#ifndef absence_TEST
#define absence_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define absence_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/absence.h"
absence_t* instantiate_absence(int include_optional);



absence_t* instantiate_absence(int include_optional) {
  absence_t* absence = NULL;
  if (include_optional) {
    absence = absence_create(
      vacation,
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      pending,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    absence = absence_create(
      vacation,
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      pending,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return absence;
}


#ifdef absence_MAIN

void test_absence(int include_optional) {
    absence_t* absence_1 = instantiate_absence(include_optional);

	cJSON* jsonabsence_1 = absence_convertToJSON(absence_1);
	printf("absence :\n%s\n", cJSON_Print(jsonabsence_1));
	absence_t* absence_2 = absence_parseFromJSON(jsonabsence_1);
	cJSON* jsonabsence_2 = absence_convertToJSON(absence_2);
	printf("repeating absence:\n%s\n", cJSON_Print(jsonabsence_2));
}

int main() {
  test_absence(1);
  test_absence(0);

  printf("Hello world \n");
  return 0;
}

#endif // absence_MAIN
#endif // absence_TEST
