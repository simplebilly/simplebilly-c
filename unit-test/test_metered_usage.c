#ifndef metered_usage_TEST
#define metered_usage_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define metered_usage_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/metered_usage.h"
metered_usage_t* instantiate_metered_usage(int include_optional);



metered_usage_t* instantiate_metered_usage(int include_optional) {
  metered_usage_t* metered_usage = NULL;
  if (include_optional) {
    metered_usage = metered_usage_create(
      56,
      "0",
      56
    );
  } else {
    metered_usage = metered_usage_create(
      56,
      "0",
      56
    );
  }

  return metered_usage;
}


#ifdef metered_usage_MAIN

void test_metered_usage(int include_optional) {
    metered_usage_t* metered_usage_1 = instantiate_metered_usage(include_optional);

	cJSON* jsonmetered_usage_1 = metered_usage_convertToJSON(metered_usage_1);
	printf("metered_usage :\n%s\n", cJSON_Print(jsonmetered_usage_1));
	metered_usage_t* metered_usage_2 = metered_usage_parseFromJSON(jsonmetered_usage_1);
	cJSON* jsonmetered_usage_2 = metered_usage_convertToJSON(metered_usage_2);
	printf("repeating metered_usage:\n%s\n", cJSON_Print(jsonmetered_usage_2));
}

int main() {
  test_metered_usage(1);
  test_metered_usage(0);

  printf("Hello world \n");
  return 0;
}

#endif // metered_usage_MAIN
#endif // metered_usage_TEST
