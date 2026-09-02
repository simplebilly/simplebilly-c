#ifndef check_status_TEST
#define check_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define check_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/check_status.h"
check_status_t* instantiate_check_status(int include_optional);



check_status_t* instantiate_check_status(int include_optional) {
  check_status_t* check_status = NULL;
  if (include_optional) {
    check_status = check_status_create(
    );
  } else {
    check_status = check_status_create(
    );
  }

  return check_status;
}


#ifdef check_status_MAIN

void test_check_status(int include_optional) {
    check_status_t* check_status_1 = instantiate_check_status(include_optional);

	cJSON* jsoncheck_status_1 = check_status_convertToJSON(check_status_1);
	printf("check_status :\n%s\n", cJSON_Print(jsoncheck_status_1));
	check_status_t* check_status_2 = check_status_parseFromJSON(jsoncheck_status_1);
	cJSON* jsoncheck_status_2 = check_status_convertToJSON(check_status_2);
	printf("repeating check_status:\n%s\n", cJSON_Print(jsoncheck_status_2));
}

int main() {
  test_check_status(1);
  test_check_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // check_status_MAIN
#endif // check_status_TEST
