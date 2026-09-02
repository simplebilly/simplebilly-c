#ifndef customer_TEST
#define customer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer.h"
customer_t* instantiate_customer(int include_optional);



customer_t* instantiate_customer(int include_optional) {
  customer_t* customer = NULL;
  if (include_optional) {
    customer = customer_create(
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
    customer = customer_create(
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

  return customer;
}


#ifdef customer_MAIN

void test_customer(int include_optional) {
    customer_t* customer_1 = instantiate_customer(include_optional);

	cJSON* jsoncustomer_1 = customer_convertToJSON(customer_1);
	printf("customer :\n%s\n", cJSON_Print(jsoncustomer_1));
	customer_t* customer_2 = customer_parseFromJSON(jsoncustomer_1);
	cJSON* jsoncustomer_2 = customer_convertToJSON(customer_2);
	printf("repeating customer:\n%s\n", cJSON_Print(jsoncustomer_2));
}

int main() {
  test_customer(1);
  test_customer(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_MAIN
#endif // customer_TEST
