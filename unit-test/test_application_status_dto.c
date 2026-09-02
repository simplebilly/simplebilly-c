#ifndef application_status_dto_TEST
#define application_status_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define application_status_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/application_status_dto.h"
application_status_dto_t* instantiate_application_status_dto(int include_optional);



application_status_dto_t* instantiate_application_status_dto(int include_optional) {
  application_status_dto_t* application_status_dto = NULL;
  if (include_optional) {
    application_status_dto = application_status_dto_create(
      "0",
      "0"
    );
  } else {
    application_status_dto = application_status_dto_create(
      "0",
      "0"
    );
  }

  return application_status_dto;
}


#ifdef application_status_dto_MAIN

void test_application_status_dto(int include_optional) {
    application_status_dto_t* application_status_dto_1 = instantiate_application_status_dto(include_optional);

	cJSON* jsonapplication_status_dto_1 = application_status_dto_convertToJSON(application_status_dto_1);
	printf("application_status_dto :\n%s\n", cJSON_Print(jsonapplication_status_dto_1));
	application_status_dto_t* application_status_dto_2 = application_status_dto_parseFromJSON(jsonapplication_status_dto_1);
	cJSON* jsonapplication_status_dto_2 = application_status_dto_convertToJSON(application_status_dto_2);
	printf("repeating application_status_dto:\n%s\n", cJSON_Print(jsonapplication_status_dto_2));
}

int main() {
  test_application_status_dto(1);
  test_application_status_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // application_status_dto_MAIN
#endif // application_status_dto_TEST
