#ifndef provider_info_TEST
#define provider_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define provider_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/provider_info.h"
provider_info_t* instantiate_provider_info(int include_optional);



provider_info_t* instantiate_provider_info(int include_optional) {
  provider_info_t* provider_info = NULL;
  if (include_optional) {
    provider_info = provider_info_create(
      "0",
      "0",
      1,
      list_createList(),
      1,
      1,
      1
    );
  } else {
    provider_info = provider_info_create(
      "0",
      "0",
      1,
      list_createList(),
      1,
      1,
      1
    );
  }

  return provider_info;
}


#ifdef provider_info_MAIN

void test_provider_info(int include_optional) {
    provider_info_t* provider_info_1 = instantiate_provider_info(include_optional);

	cJSON* jsonprovider_info_1 = provider_info_convertToJSON(provider_info_1);
	printf("provider_info :\n%s\n", cJSON_Print(jsonprovider_info_1));
	provider_info_t* provider_info_2 = provider_info_parseFromJSON(jsonprovider_info_1);
	cJSON* jsonprovider_info_2 = provider_info_convertToJSON(provider_info_2);
	printf("repeating provider_info:\n%s\n", cJSON_Print(jsonprovider_info_2));
}

int main() {
  test_provider_info(1);
  test_provider_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // provider_info_MAIN
#endif // provider_info_TEST
