#ifndef platform_info_TEST
#define platform_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define platform_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/platform_info.h"
platform_info_t* instantiate_platform_info(int include_optional);

#include "test_plugin_pricing.c"


platform_info_t* instantiate_platform_info(int include_optional) {
  platform_info_t* platform_info = NULL;
  if (include_optional) {
    platform_info = platform_info_create(
      "0",
      list_createList(),
      list_createList(),
      list_createList(),
      "0",
      "0",
      null,
      list_createList(),
      1,
      1,
      1,
      "0"
    );
  } else {
    platform_info = platform_info_create(
      "0",
      list_createList(),
      list_createList(),
      list_createList(),
      "0",
      "0",
      null,
      list_createList(),
      1,
      1,
      1,
      "0"
    );
  }

  return platform_info;
}


#ifdef platform_info_MAIN

void test_platform_info(int include_optional) {
    platform_info_t* platform_info_1 = instantiate_platform_info(include_optional);

	cJSON* jsonplatform_info_1 = platform_info_convertToJSON(platform_info_1);
	printf("platform_info :\n%s\n", cJSON_Print(jsonplatform_info_1));
	platform_info_t* platform_info_2 = platform_info_parseFromJSON(jsonplatform_info_1);
	cJSON* jsonplatform_info_2 = platform_info_convertToJSON(platform_info_2);
	printf("repeating platform_info:\n%s\n", cJSON_Print(jsonplatform_info_2));
}

int main() {
  test_platform_info(1);
  test_platform_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // platform_info_MAIN
#endif // platform_info_TEST
