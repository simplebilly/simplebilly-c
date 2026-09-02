#ifndef employee_status_TEST
#define employee_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define employee_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/employee_status.h"
employee_status_t* instantiate_employee_status(int include_optional);



employee_status_t* instantiate_employee_status(int include_optional) {
  employee_status_t* employee_status = NULL;
  if (include_optional) {
    employee_status = employee_status_create(
    );
  } else {
    employee_status = employee_status_create(
    );
  }

  return employee_status;
}


#ifdef employee_status_MAIN

void test_employee_status(int include_optional) {
    employee_status_t* employee_status_1 = instantiate_employee_status(include_optional);

	cJSON* jsonemployee_status_1 = employee_status_convertToJSON(employee_status_1);
	printf("employee_status :\n%s\n", cJSON_Print(jsonemployee_status_1));
	employee_status_t* employee_status_2 = employee_status_parseFromJSON(jsonemployee_status_1);
	cJSON* jsonemployee_status_2 = employee_status_convertToJSON(employee_status_2);
	printf("repeating employee_status:\n%s\n", cJSON_Print(jsonemployee_status_2));
}

int main() {
  test_employee_status(1);
  test_employee_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // employee_status_MAIN
#endif // employee_status_TEST
