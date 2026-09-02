#ifndef customer_communication_create_TEST
#define customer_communication_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_communication_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer_communication_create.h"
customer_communication_create_t* instantiate_customer_communication_create(int include_optional);



customer_communication_create_t* instantiate_customer_communication_create(int include_optional) {
  customer_communication_create_t* customer_communication_create = NULL;
  if (include_optional) {
    customer_communication_create = customer_communication_create_create(
      "0",
      simplebilly_api_customer_communication_create__email,
      "0",
      "0",
      simplebilly_api_customer_communication_create__inbound,
      "2013-10-20T19:20:30+01:00",
      "0",
      null
    );
  } else {
    customer_communication_create = customer_communication_create_create(
      "0",
      simplebilly_api_customer_communication_create__email,
      "0",
      "0",
      simplebilly_api_customer_communication_create__inbound,
      "2013-10-20T19:20:30+01:00",
      "0",
      null
    );
  }

  return customer_communication_create;
}


#ifdef customer_communication_create_MAIN

void test_customer_communication_create(int include_optional) {
    customer_communication_create_t* customer_communication_create_1 = instantiate_customer_communication_create(include_optional);

	cJSON* jsoncustomer_communication_create_1 = customer_communication_create_convertToJSON(customer_communication_create_1);
	printf("customer_communication_create :\n%s\n", cJSON_Print(jsoncustomer_communication_create_1));
	customer_communication_create_t* customer_communication_create_2 = customer_communication_create_parseFromJSON(jsoncustomer_communication_create_1);
	cJSON* jsoncustomer_communication_create_2 = customer_communication_create_convertToJSON(customer_communication_create_2);
	printf("repeating customer_communication_create:\n%s\n", cJSON_Print(jsoncustomer_communication_create_2));
}

int main() {
  test_customer_communication_create(1);
  test_customer_communication_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_communication_create_MAIN
#endif // customer_communication_create_TEST
