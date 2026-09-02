#ifndef shipping_rate_TEST
#define shipping_rate_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_rate_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_rate.h"
shipping_rate_t* instantiate_shipping_rate(int include_optional);



shipping_rate_t* instantiate_shipping_rate(int include_optional) {
  shipping_rate_t* shipping_rate = NULL;
  if (include_optional) {
    shipping_rate = shipping_rate_create(
      "0",
      "0",
      "0",
      "0",
      0,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1.337
    );
  } else {
    shipping_rate = shipping_rate_create(
      "0",
      "0",
      "0",
      "0",
      0,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1.337
    );
  }

  return shipping_rate;
}


#ifdef shipping_rate_MAIN

void test_shipping_rate(int include_optional) {
    shipping_rate_t* shipping_rate_1 = instantiate_shipping_rate(include_optional);

	cJSON* jsonshipping_rate_1 = shipping_rate_convertToJSON(shipping_rate_1);
	printf("shipping_rate :\n%s\n", cJSON_Print(jsonshipping_rate_1));
	shipping_rate_t* shipping_rate_2 = shipping_rate_parseFromJSON(jsonshipping_rate_1);
	cJSON* jsonshipping_rate_2 = shipping_rate_convertToJSON(shipping_rate_2);
	printf("repeating shipping_rate:\n%s\n", cJSON_Print(jsonshipping_rate_2));
}

int main() {
  test_shipping_rate(1);
  test_shipping_rate(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_rate_MAIN
#endif // shipping_rate_TEST
