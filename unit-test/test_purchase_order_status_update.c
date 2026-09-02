#ifndef purchase_order_status_update_TEST
#define purchase_order_status_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define purchase_order_status_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/purchase_order_status_update.h"
purchase_order_status_update_t* instantiate_purchase_order_status_update(int include_optional);



purchase_order_status_update_t* instantiate_purchase_order_status_update(int include_optional) {
  purchase_order_status_update_t* purchase_order_status_update = NULL;
  if (include_optional) {
    purchase_order_status_update = purchase_order_status_update_create(
      "0"
    );
  } else {
    purchase_order_status_update = purchase_order_status_update_create(
      "0"
    );
  }

  return purchase_order_status_update;
}


#ifdef purchase_order_status_update_MAIN

void test_purchase_order_status_update(int include_optional) {
    purchase_order_status_update_t* purchase_order_status_update_1 = instantiate_purchase_order_status_update(include_optional);

	cJSON* jsonpurchase_order_status_update_1 = purchase_order_status_update_convertToJSON(purchase_order_status_update_1);
	printf("purchase_order_status_update :\n%s\n", cJSON_Print(jsonpurchase_order_status_update_1));
	purchase_order_status_update_t* purchase_order_status_update_2 = purchase_order_status_update_parseFromJSON(jsonpurchase_order_status_update_1);
	cJSON* jsonpurchase_order_status_update_2 = purchase_order_status_update_convertToJSON(purchase_order_status_update_2);
	printf("repeating purchase_order_status_update:\n%s\n", cJSON_Print(jsonpurchase_order_status_update_2));
}

int main() {
  test_purchase_order_status_update(1);
  test_purchase_order_status_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // purchase_order_status_update_MAIN
#endif // purchase_order_status_update_TEST
