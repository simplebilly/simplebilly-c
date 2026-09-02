#ifndef service_job_status_TEST
#define service_job_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_job_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_job_status.h"
service_job_status_t* instantiate_service_job_status(int include_optional);



service_job_status_t* instantiate_service_job_status(int include_optional) {
  service_job_status_t* service_job_status = NULL;
  if (include_optional) {
    service_job_status = service_job_status_create(
    );
  } else {
    service_job_status = service_job_status_create(
    );
  }

  return service_job_status;
}


#ifdef service_job_status_MAIN

void test_service_job_status(int include_optional) {
    service_job_status_t* service_job_status_1 = instantiate_service_job_status(include_optional);

	cJSON* jsonservice_job_status_1 = service_job_status_convertToJSON(service_job_status_1);
	printf("service_job_status :\n%s\n", cJSON_Print(jsonservice_job_status_1));
	service_job_status_t* service_job_status_2 = service_job_status_parseFromJSON(jsonservice_job_status_1);
	cJSON* jsonservice_job_status_2 = service_job_status_convertToJSON(service_job_status_2);
	printf("repeating service_job_status:\n%s\n", cJSON_Print(jsonservice_job_status_2));
}

int main() {
  test_service_job_status(1);
  test_service_job_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_job_status_MAIN
#endif // service_job_status_TEST
