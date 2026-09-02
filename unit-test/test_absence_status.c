#ifndef absence_status_TEST
#define absence_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define absence_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/absence_status.h"
absence_status_t* instantiate_absence_status(int include_optional);



absence_status_t* instantiate_absence_status(int include_optional) {
  absence_status_t* absence_status = NULL;
  if (include_optional) {
    absence_status = absence_status_create(
    );
  } else {
    absence_status = absence_status_create(
    );
  }

  return absence_status;
}


#ifdef absence_status_MAIN

void test_absence_status(int include_optional) {
    absence_status_t* absence_status_1 = instantiate_absence_status(include_optional);

	cJSON* jsonabsence_status_1 = absence_status_convertToJSON(absence_status_1);
	printf("absence_status :\n%s\n", cJSON_Print(jsonabsence_status_1));
	absence_status_t* absence_status_2 = absence_status_parseFromJSON(jsonabsence_status_1);
	cJSON* jsonabsence_status_2 = absence_status_convertToJSON(absence_status_2);
	printf("repeating absence_status:\n%s\n", cJSON_Print(jsonabsence_status_2));
}

int main() {
  test_absence_status(1);
  test_absence_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // absence_status_MAIN
#endif // absence_status_TEST
