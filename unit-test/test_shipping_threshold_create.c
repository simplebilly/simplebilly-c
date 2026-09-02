#ifndef shipping_threshold_create_TEST
#define shipping_threshold_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_threshold_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_threshold_create.h"
shipping_threshold_create_t* instantiate_shipping_threshold_create(int include_optional);



shipping_threshold_create_t* instantiate_shipping_threshold_create(int include_optional) {
  shipping_threshold_create_t* shipping_threshold_create = NULL;
  if (include_optional) {
    shipping_threshold_create = shipping_threshold_create_create(
      1,
      56,
      "0",
      "0",
      "0",
      56,
      "0"
    );
  } else {
    shipping_threshold_create = shipping_threshold_create_create(
      1,
      56,
      "0",
      "0",
      "0",
      56,
      "0"
    );
  }

  return shipping_threshold_create;
}


#ifdef shipping_threshold_create_MAIN

void test_shipping_threshold_create(int include_optional) {
    shipping_threshold_create_t* shipping_threshold_create_1 = instantiate_shipping_threshold_create(include_optional);

	cJSON* jsonshipping_threshold_create_1 = shipping_threshold_create_convertToJSON(shipping_threshold_create_1);
	printf("shipping_threshold_create :\n%s\n", cJSON_Print(jsonshipping_threshold_create_1));
	shipping_threshold_create_t* shipping_threshold_create_2 = shipping_threshold_create_parseFromJSON(jsonshipping_threshold_create_1);
	cJSON* jsonshipping_threshold_create_2 = shipping_threshold_create_convertToJSON(shipping_threshold_create_2);
	printf("repeating shipping_threshold_create:\n%s\n", cJSON_Print(jsonshipping_threshold_create_2));
}

int main() {
  test_shipping_threshold_create(1);
  test_shipping_threshold_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_threshold_create_MAIN
#endif // shipping_threshold_create_TEST
