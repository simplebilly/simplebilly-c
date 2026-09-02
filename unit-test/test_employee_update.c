#ifndef employee_update_TEST
#define employee_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define employee_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/employee_update.h"
employee_update_t* instantiate_employee_update(int include_optional);



employee_update_t* instantiate_employee_update(int include_optional) {
  employee_update_t* employee_update = NULL;
  if (include_optional) {
    employee_update = employee_update_create(
      "0",
      "0",
      "0",
      "0",
      ABW,
      "2013-10-20",
      "0",
      "0",
      "0",
      male,
      "2013-10-20",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "a",
      "0",
      active,
      "0",
      "0",
      "0"
    );
  } else {
    employee_update = employee_update_create(
      "0",
      "0",
      "0",
      "0",
      ABW,
      "2013-10-20",
      "0",
      "0",
      "0",
      male,
      "2013-10-20",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "a",
      "0",
      active,
      "0",
      "0",
      "0"
    );
  }

  return employee_update;
}


#ifdef employee_update_MAIN

void test_employee_update(int include_optional) {
    employee_update_t* employee_update_1 = instantiate_employee_update(include_optional);

	cJSON* jsonemployee_update_1 = employee_update_convertToJSON(employee_update_1);
	printf("employee_update :\n%s\n", cJSON_Print(jsonemployee_update_1));
	employee_update_t* employee_update_2 = employee_update_parseFromJSON(jsonemployee_update_1);
	cJSON* jsonemployee_update_2 = employee_update_convertToJSON(employee_update_2);
	printf("repeating employee_update:\n%s\n", cJSON_Print(jsonemployee_update_2));
}

int main() {
  test_employee_update(1);
  test_employee_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // employee_update_MAIN
#endif // employee_update_TEST
