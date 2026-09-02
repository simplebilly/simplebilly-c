#ifndef customer_communication_update_TEST
#define customer_communication_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_communication_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer_communication_update.h"
customer_communication_update_t* instantiate_customer_communication_update(int include_optional);



customer_communication_update_t* instantiate_customer_communication_update(int include_optional) {
  customer_communication_update_t* customer_communication_update = NULL;
  if (include_optional) {
    customer_communication_update = customer_communication_update_create(
      "0",
      email,
      "0",
      "0",
      inbound,
      "2013-10-20T19:20:30+01:00",
      "0",
      null
    );
  } else {
    customer_communication_update = customer_communication_update_create(
      "0",
      email,
      "0",
      "0",
      inbound,
      "2013-10-20T19:20:30+01:00",
      "0",
      null
    );
  }

  return customer_communication_update;
}


#ifdef customer_communication_update_MAIN

void test_customer_communication_update(int include_optional) {
    customer_communication_update_t* customer_communication_update_1 = instantiate_customer_communication_update(include_optional);

	cJSON* jsoncustomer_communication_update_1 = customer_communication_update_convertToJSON(customer_communication_update_1);
	printf("customer_communication_update :\n%s\n", cJSON_Print(jsoncustomer_communication_update_1));
	customer_communication_update_t* customer_communication_update_2 = customer_communication_update_parseFromJSON(jsoncustomer_communication_update_1);
	cJSON* jsoncustomer_communication_update_2 = customer_communication_update_convertToJSON(customer_communication_update_2);
	printf("repeating customer_communication_update:\n%s\n", cJSON_Print(jsoncustomer_communication_update_2));
}

int main() {
  test_customer_communication_update(1);
  test_customer_communication_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_communication_update_MAIN
#endif // customer_communication_update_TEST
