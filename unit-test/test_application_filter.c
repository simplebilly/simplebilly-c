#ifndef application_filter_TEST
#define application_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define application_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/application_filter.h"
application_filter_t* instantiate_application_filter(int include_optional);



application_filter_t* instantiate_application_filter(int include_optional) {
  application_filter_t* application_filter = NULL;
  if (include_optional) {
    application_filter = application_filter_create(
      0,
      0,
      "0",
      "0"
    );
  } else {
    application_filter = application_filter_create(
      0,
      0,
      "0",
      "0"
    );
  }

  return application_filter;
}


#ifdef application_filter_MAIN

void test_application_filter(int include_optional) {
    application_filter_t* application_filter_1 = instantiate_application_filter(include_optional);

	cJSON* jsonapplication_filter_1 = application_filter_convertToJSON(application_filter_1);
	printf("application_filter :\n%s\n", cJSON_Print(jsonapplication_filter_1));
	application_filter_t* application_filter_2 = application_filter_parseFromJSON(jsonapplication_filter_1);
	cJSON* jsonapplication_filter_2 = application_filter_convertToJSON(application_filter_2);
	printf("repeating application_filter:\n%s\n", cJSON_Print(jsonapplication_filter_2));
}

int main() {
  test_application_filter(1);
  test_application_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // application_filter_MAIN
#endif // application_filter_TEST
