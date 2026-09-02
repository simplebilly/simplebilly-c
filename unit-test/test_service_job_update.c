#ifndef service_job_update_TEST
#define service_job_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_job_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_job_update.h"
service_job_update_t* instantiate_service_job_update(int include_optional);



service_job_update_t* instantiate_service_job_update(int include_optional) {
  service_job_update_t* service_job_update = NULL;
  if (include_optional) {
    service_job_update = service_job_update_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1.337,
      1.337,
      "0",
      pending
    );
  } else {
    service_job_update = service_job_update_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1.337,
      1.337,
      "0",
      pending
    );
  }

  return service_job_update;
}


#ifdef service_job_update_MAIN

void test_service_job_update(int include_optional) {
    service_job_update_t* service_job_update_1 = instantiate_service_job_update(include_optional);

	cJSON* jsonservice_job_update_1 = service_job_update_convertToJSON(service_job_update_1);
	printf("service_job_update :\n%s\n", cJSON_Print(jsonservice_job_update_1));
	service_job_update_t* service_job_update_2 = service_job_update_parseFromJSON(jsonservice_job_update_1);
	cJSON* jsonservice_job_update_2 = service_job_update_convertToJSON(service_job_update_2);
	printf("repeating service_job_update:\n%s\n", cJSON_Print(jsonservice_job_update_2));
}

int main() {
  test_service_job_update(1);
  test_service_job_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_job_update_MAIN
#endif // service_job_update_TEST
