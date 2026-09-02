#ifndef shipping_rule_TEST
#define shipping_rule_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_rule_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_rule.h"
shipping_rule_t* instantiate_shipping_rule(int include_optional);



shipping_rule_t* instantiate_shipping_rule(int include_optional) {
  shipping_rule_t* shipping_rule = NULL;
  if (include_optional) {
    shipping_rule = shipping_rule_create(
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
    shipping_rule = shipping_rule_create(
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

  return shipping_rule;
}


#ifdef shipping_rule_MAIN

void test_shipping_rule(int include_optional) {
    shipping_rule_t* shipping_rule_1 = instantiate_shipping_rule(include_optional);

	cJSON* jsonshipping_rule_1 = shipping_rule_convertToJSON(shipping_rule_1);
	printf("shipping_rule :\n%s\n", cJSON_Print(jsonshipping_rule_1));
	shipping_rule_t* shipping_rule_2 = shipping_rule_parseFromJSON(jsonshipping_rule_1);
	cJSON* jsonshipping_rule_2 = shipping_rule_convertToJSON(shipping_rule_2);
	printf("repeating shipping_rule:\n%s\n", cJSON_Print(jsonshipping_rule_2));
}

int main() {
  test_shipping_rule(1);
  test_shipping_rule(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_rule_MAIN
#endif // shipping_rule_TEST
