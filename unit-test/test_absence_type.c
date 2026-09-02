#ifndef absence_type_TEST
#define absence_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define absence_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/absence_type.h"
absence_type_t* instantiate_absence_type(int include_optional);



absence_type_t* instantiate_absence_type(int include_optional) {
  absence_type_t* absence_type = NULL;
  if (include_optional) {
    absence_type = absence_type_create(
    );
  } else {
    absence_type = absence_type_create(
    );
  }

  return absence_type;
}


#ifdef absence_type_MAIN

void test_absence_type(int include_optional) {
    absence_type_t* absence_type_1 = instantiate_absence_type(include_optional);

	cJSON* jsonabsence_type_1 = absence_type_convertToJSON(absence_type_1);
	printf("absence_type :\n%s\n", cJSON_Print(jsonabsence_type_1));
	absence_type_t* absence_type_2 = absence_type_parseFromJSON(jsonabsence_type_1);
	cJSON* jsonabsence_type_2 = absence_type_convertToJSON(absence_type_2);
	printf("repeating absence_type:\n%s\n", cJSON_Print(jsonabsence_type_2));
}

int main() {
  test_absence_type(1);
  test_absence_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // absence_type_MAIN
#endif // absence_type_TEST
