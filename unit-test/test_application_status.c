#ifndef application_status_TEST
#define application_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define application_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/application_status.h"
application_status_t* instantiate_application_status(int include_optional);



application_status_t* instantiate_application_status(int include_optional) {
  application_status_t* application_status = NULL;
  if (include_optional) {
    application_status = application_status_create(
    );
  } else {
    application_status = application_status_create(
    );
  }

  return application_status;
}


#ifdef application_status_MAIN

void test_application_status(int include_optional) {
    application_status_t* application_status_1 = instantiate_application_status(include_optional);

	cJSON* jsonapplication_status_1 = application_status_convertToJSON(application_status_1);
	printf("application_status :\n%s\n", cJSON_Print(jsonapplication_status_1));
	application_status_t* application_status_2 = application_status_parseFromJSON(jsonapplication_status_1);
	cJSON* jsonapplication_status_2 = application_status_convertToJSON(application_status_2);
	printf("repeating application_status:\n%s\n", cJSON_Print(jsonapplication_status_2));
}

int main() {
  test_application_status(1);
  test_application_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // application_status_MAIN
#endif // application_status_TEST
