#ifndef customer_update_TEST
#define customer_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer_update.h"
customer_update_t* instantiate_customer_update(int include_optional);



customer_update_t* instantiate_customer_update(int include_optional) {
  customer_update_t* customer_update = NULL;
  if (include_optional) {
    customer_update = customer_update_create(
      null,
      "0",
      "0",
      "0",
      "0",
      0,
      "a",
      "a"
    );
  } else {
    customer_update = customer_update_create(
      null,
      "0",
      "0",
      "0",
      "0",
      0,
      "a",
      "a"
    );
  }

  return customer_update;
}


#ifdef customer_update_MAIN

void test_customer_update(int include_optional) {
    customer_update_t* customer_update_1 = instantiate_customer_update(include_optional);

	cJSON* jsoncustomer_update_1 = customer_update_convertToJSON(customer_update_1);
	printf("customer_update :\n%s\n", cJSON_Print(jsoncustomer_update_1));
	customer_update_t* customer_update_2 = customer_update_parseFromJSON(jsoncustomer_update_1);
	cJSON* jsoncustomer_update_2 = customer_update_convertToJSON(customer_update_2);
	printf("repeating customer_update:\n%s\n", cJSON_Print(jsoncustomer_update_2));
}

int main() {
  test_customer_update(1);
  test_customer_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_update_MAIN
#endif // customer_update_TEST
