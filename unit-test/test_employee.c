#ifndef employee_TEST
#define employee_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define employee_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/employee.h"
employee_t* instantiate_employee(int include_optional);



employee_t* instantiate_employee(int include_optional) {
  employee_t* employee = NULL;
  if (include_optional) {
    employee = employee_create(
      "0",
      "0",
      "0",
      "0",
      ABW,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      male,
      "2013-10-20",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "a",
      "0",
      simplebilly_api_employee__active,
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  } else {
    employee = employee_create(
      "0",
      "0",
      "0",
      "0",
      ABW,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      male,
      "2013-10-20",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "a",
      "0",
      simplebilly_api_employee__active,
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  }

  return employee;
}


#ifdef employee_MAIN

void test_employee(int include_optional) {
    employee_t* employee_1 = instantiate_employee(include_optional);

	cJSON* jsonemployee_1 = employee_convertToJSON(employee_1);
	printf("employee :\n%s\n", cJSON_Print(jsonemployee_1));
	employee_t* employee_2 = employee_parseFromJSON(jsonemployee_1);
	cJSON* jsonemployee_2 = employee_convertToJSON(employee_2);
	printf("repeating employee:\n%s\n", cJSON_Print(jsonemployee_2));
}

int main() {
  test_employee(1);
  test_employee(0);

  printf("Hello world \n");
  return 0;
}

#endif // employee_MAIN
#endif // employee_TEST
