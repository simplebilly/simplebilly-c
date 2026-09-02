#ifndef service_assignment_update_TEST
#define service_assignment_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_assignment_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_assignment_update.h"
service_assignment_update_t* instantiate_service_assignment_update(int include_optional);



service_assignment_update_t* instantiate_service_assignment_update(int include_optional) {
  service_assignment_update_t* service_assignment_update = NULL;
  if (include_optional) {
    service_assignment_update = service_assignment_update_create(
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      planned
    );
  } else {
    service_assignment_update = service_assignment_update_create(
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      planned
    );
  }

  return service_assignment_update;
}


#ifdef service_assignment_update_MAIN

void test_service_assignment_update(int include_optional) {
    service_assignment_update_t* service_assignment_update_1 = instantiate_service_assignment_update(include_optional);

	cJSON* jsonservice_assignment_update_1 = service_assignment_update_convertToJSON(service_assignment_update_1);
	printf("service_assignment_update :\n%s\n", cJSON_Print(jsonservice_assignment_update_1));
	service_assignment_update_t* service_assignment_update_2 = service_assignment_update_parseFromJSON(jsonservice_assignment_update_1);
	cJSON* jsonservice_assignment_update_2 = service_assignment_update_convertToJSON(service_assignment_update_2);
	printf("repeating service_assignment_update:\n%s\n", cJSON_Print(jsonservice_assignment_update_2));
}

int main() {
  test_service_assignment_update(1);
  test_service_assignment_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_assignment_update_MAIN
#endif // service_assignment_update_TEST
