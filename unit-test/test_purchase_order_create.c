#ifndef purchase_order_create_TEST
#define purchase_order_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define purchase_order_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/purchase_order_create.h"
purchase_order_create_t* instantiate_purchase_order_create(int include_optional);



purchase_order_create_t* instantiate_purchase_order_create(int include_optional) {
  purchase_order_create_t* purchase_order_create = NULL;
  if (include_optional) {
    purchase_order_create = purchase_order_create_create(
      "0",
      null,
      "2013-10-20",
      null,
      "0",
      "2013-10-20",
      "0",
      draft,
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    purchase_order_create = purchase_order_create_create(
      "0",
      null,
      "2013-10-20",
      null,
      "0",
      "2013-10-20",
      "0",
      draft,
      "0",
      "0",
      "0",
      "0"
    );
  }

  return purchase_order_create;
}


#ifdef purchase_order_create_MAIN

void test_purchase_order_create(int include_optional) {
    purchase_order_create_t* purchase_order_create_1 = instantiate_purchase_order_create(include_optional);

	cJSON* jsonpurchase_order_create_1 = purchase_order_create_convertToJSON(purchase_order_create_1);
	printf("purchase_order_create :\n%s\n", cJSON_Print(jsonpurchase_order_create_1));
	purchase_order_create_t* purchase_order_create_2 = purchase_order_create_parseFromJSON(jsonpurchase_order_create_1);
	cJSON* jsonpurchase_order_create_2 = purchase_order_create_convertToJSON(purchase_order_create_2);
	printf("repeating purchase_order_create:\n%s\n", cJSON_Print(jsonpurchase_order_create_2));
}

int main() {
  test_purchase_order_create(1);
  test_purchase_order_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // purchase_order_create_MAIN
#endif // purchase_order_create_TEST
