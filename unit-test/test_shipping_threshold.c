#ifndef shipping_threshold_TEST
#define shipping_threshold_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_threshold_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_threshold.h"
shipping_threshold_t* instantiate_shipping_threshold(int include_optional);



shipping_threshold_t* instantiate_shipping_threshold(int include_optional) {
  shipping_threshold_t* shipping_threshold = NULL;
  if (include_optional) {
    shipping_threshold = shipping_threshold_create(
      1,
      56,
      "0",
      "0",
      "0",
      56,
      "0"
    );
  } else {
    shipping_threshold = shipping_threshold_create(
      1,
      56,
      "0",
      "0",
      "0",
      56,
      "0"
    );
  }

  return shipping_threshold;
}


#ifdef shipping_threshold_MAIN

void test_shipping_threshold(int include_optional) {
    shipping_threshold_t* shipping_threshold_1 = instantiate_shipping_threshold(include_optional);

	cJSON* jsonshipping_threshold_1 = shipping_threshold_convertToJSON(shipping_threshold_1);
	printf("shipping_threshold :\n%s\n", cJSON_Print(jsonshipping_threshold_1));
	shipping_threshold_t* shipping_threshold_2 = shipping_threshold_parseFromJSON(jsonshipping_threshold_1);
	cJSON* jsonshipping_threshold_2 = shipping_threshold_convertToJSON(shipping_threshold_2);
	printf("repeating shipping_threshold:\n%s\n", cJSON_Print(jsonshipping_threshold_2));
}

int main() {
  test_shipping_threshold(1);
  test_shipping_threshold(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_threshold_MAIN
#endif // shipping_threshold_TEST
