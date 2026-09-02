#ifndef employee_create_TEST
#define employee_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define employee_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/employee_create.h"
employee_create_t* instantiate_employee_create(int include_optional);



employee_create_t* instantiate_employee_create(int include_optional) {
  employee_create_t* employee_create = NULL;
  if (include_optional) {
    employee_create = employee_create_create(
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
      simplebilly_api_employee_create__active,
      "0",
      "0",
      "0"
    );
  } else {
    employee_create = employee_create_create(
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
      simplebilly_api_employee_create__active,
      "0",
      "0",
      "0"
    );
  }

  return employee_create;
}


#ifdef employee_create_MAIN

void test_employee_create(int include_optional) {
    employee_create_t* employee_create_1 = instantiate_employee_create(include_optional);

	cJSON* jsonemployee_create_1 = employee_create_convertToJSON(employee_create_1);
	printf("employee_create :\n%s\n", cJSON_Print(jsonemployee_create_1));
	employee_create_t* employee_create_2 = employee_create_parseFromJSON(jsonemployee_create_1);
	cJSON* jsonemployee_create_2 = employee_create_convertToJSON(employee_create_2);
	printf("repeating employee_create:\n%s\n", cJSON_Print(jsonemployee_create_2));
}

int main() {
  test_employee_create(1);
  test_employee_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // employee_create_MAIN
#endif // employee_create_TEST
