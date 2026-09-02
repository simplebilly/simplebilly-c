#ifndef purchase_order_status_TEST
#define purchase_order_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define purchase_order_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/purchase_order_status.h"
purchase_order_status_t* instantiate_purchase_order_status(int include_optional);



purchase_order_status_t* instantiate_purchase_order_status(int include_optional) {
  purchase_order_status_t* purchase_order_status = NULL;
  if (include_optional) {
    purchase_order_status = purchase_order_status_create(
    );
  } else {
    purchase_order_status = purchase_order_status_create(
    );
  }

  return purchase_order_status;
}


#ifdef purchase_order_status_MAIN

void test_purchase_order_status(int include_optional) {
    purchase_order_status_t* purchase_order_status_1 = instantiate_purchase_order_status(include_optional);

	cJSON* jsonpurchase_order_status_1 = purchase_order_status_convertToJSON(purchase_order_status_1);
	printf("purchase_order_status :\n%s\n", cJSON_Print(jsonpurchase_order_status_1));
	purchase_order_status_t* purchase_order_status_2 = purchase_order_status_parseFromJSON(jsonpurchase_order_status_1);
	cJSON* jsonpurchase_order_status_2 = purchase_order_status_convertToJSON(purchase_order_status_2);
	printf("repeating purchase_order_status:\n%s\n", cJSON_Print(jsonpurchase_order_status_2));
}

int main() {
  test_purchase_order_status(1);
  test_purchase_order_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // purchase_order_status_MAIN
#endif // purchase_order_status_TEST
