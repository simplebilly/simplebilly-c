#ifndef shipping_rule_update_TEST
#define shipping_rule_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_rule_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_rule_update.h"
shipping_rule_update_t* instantiate_shipping_rule_update(int include_optional);



shipping_rule_update_t* instantiate_shipping_rule_update(int include_optional) {
  shipping_rule_update_t* shipping_rule_update = NULL;
  if (include_optional) {
    shipping_rule_update = shipping_rule_update_create(
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
    shipping_rule_update = shipping_rule_update_create(
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

  return shipping_rule_update;
}


#ifdef shipping_rule_update_MAIN

void test_shipping_rule_update(int include_optional) {
    shipping_rule_update_t* shipping_rule_update_1 = instantiate_shipping_rule_update(include_optional);

	cJSON* jsonshipping_rule_update_1 = shipping_rule_update_convertToJSON(shipping_rule_update_1);
	printf("shipping_rule_update :\n%s\n", cJSON_Print(jsonshipping_rule_update_1));
	shipping_rule_update_t* shipping_rule_update_2 = shipping_rule_update_parseFromJSON(jsonshipping_rule_update_1);
	cJSON* jsonshipping_rule_update_2 = shipping_rule_update_convertToJSON(shipping_rule_update_2);
	printf("repeating shipping_rule_update:\n%s\n", cJSON_Print(jsonshipping_rule_update_2));
}

int main() {
  test_shipping_rule_update(1);
  test_shipping_rule_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_rule_update_MAIN
#endif // shipping_rule_update_TEST
