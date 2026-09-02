#ifndef customer_create_TEST
#define customer_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer_create.h"
customer_create_t* instantiate_customer_create(int include_optional);



customer_create_t* instantiate_customer_create(int include_optional) {
  customer_create_t* customer_create = NULL;
  if (include_optional) {
    customer_create = customer_create_create(
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
    customer_create = customer_create_create(
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

  return customer_create;
}


#ifdef customer_create_MAIN

void test_customer_create(int include_optional) {
    customer_create_t* customer_create_1 = instantiate_customer_create(include_optional);

	cJSON* jsoncustomer_create_1 = customer_create_convertToJSON(customer_create_1);
	printf("customer_create :\n%s\n", cJSON_Print(jsoncustomer_create_1));
	customer_create_t* customer_create_2 = customer_create_parseFromJSON(jsoncustomer_create_1);
	cJSON* jsoncustomer_create_2 = customer_create_convertToJSON(customer_create_2);
	printf("repeating customer_create:\n%s\n", cJSON_Print(jsoncustomer_create_2));
}

int main() {
  test_customer_create(1);
  test_customer_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_create_MAIN
#endif // customer_create_TEST
