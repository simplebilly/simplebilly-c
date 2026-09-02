#ifndef shipping_threshold_update_TEST
#define shipping_threshold_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_threshold_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_threshold_update.h"
shipping_threshold_update_t* instantiate_shipping_threshold_update(int include_optional);



shipping_threshold_update_t* instantiate_shipping_threshold_update(int include_optional) {
  shipping_threshold_update_t* shipping_threshold_update = NULL;
  if (include_optional) {
    shipping_threshold_update = shipping_threshold_update_create(
      1,
      56,
      "0",
      "0",
      "0",
      56,
      "0"
    );
  } else {
    shipping_threshold_update = shipping_threshold_update_create(
      1,
      56,
      "0",
      "0",
      "0",
      56,
      "0"
    );
  }

  return shipping_threshold_update;
}


#ifdef shipping_threshold_update_MAIN

void test_shipping_threshold_update(int include_optional) {
    shipping_threshold_update_t* shipping_threshold_update_1 = instantiate_shipping_threshold_update(include_optional);

	cJSON* jsonshipping_threshold_update_1 = shipping_threshold_update_convertToJSON(shipping_threshold_update_1);
	printf("shipping_threshold_update :\n%s\n", cJSON_Print(jsonshipping_threshold_update_1));
	shipping_threshold_update_t* shipping_threshold_update_2 = shipping_threshold_update_parseFromJSON(jsonshipping_threshold_update_1);
	cJSON* jsonshipping_threshold_update_2 = shipping_threshold_update_convertToJSON(shipping_threshold_update_2);
	printf("repeating shipping_threshold_update:\n%s\n", cJSON_Print(jsonshipping_threshold_update_2));
}

int main() {
  test_shipping_threshold_update(1);
  test_shipping_threshold_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_threshold_update_MAIN
#endif // shipping_threshold_update_TEST
