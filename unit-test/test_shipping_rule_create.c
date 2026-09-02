#ifndef shipping_rule_create_TEST
#define shipping_rule_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_rule_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_rule_create.h"
shipping_rule_create_t* instantiate_shipping_rule_create(int include_optional);



shipping_rule_create_t* instantiate_shipping_rule_create(int include_optional) {
  shipping_rule_create_t* shipping_rule_create = NULL;
  if (include_optional) {
    shipping_rule_create = shipping_rule_create_create(
      "0",
      ABW,
      "0",
      1,
      1.337,
      1.337,
      "0",
      "0",
      "0",
      56
    );
  } else {
    shipping_rule_create = shipping_rule_create_create(
      "0",
      ABW,
      "0",
      1,
      1.337,
      1.337,
      "0",
      "0",
      "0",
      56
    );
  }

  return shipping_rule_create;
}


#ifdef shipping_rule_create_MAIN

void test_shipping_rule_create(int include_optional) {
    shipping_rule_create_t* shipping_rule_create_1 = instantiate_shipping_rule_create(include_optional);

	cJSON* jsonshipping_rule_create_1 = shipping_rule_create_convertToJSON(shipping_rule_create_1);
	printf("shipping_rule_create :\n%s\n", cJSON_Print(jsonshipping_rule_create_1));
	shipping_rule_create_t* shipping_rule_create_2 = shipping_rule_create_parseFromJSON(jsonshipping_rule_create_1);
	cJSON* jsonshipping_rule_create_2 = shipping_rule_create_convertToJSON(shipping_rule_create_2);
	printf("repeating shipping_rule_create:\n%s\n", cJSON_Print(jsonshipping_rule_create_2));
}

int main() {
  test_shipping_rule_create(1);
  test_shipping_rule_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_rule_create_MAIN
#endif // shipping_rule_create_TEST
