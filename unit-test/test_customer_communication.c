#ifndef customer_communication_TEST
#define customer_communication_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_communication_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer_communication.h"
customer_communication_t* instantiate_customer_communication(int include_optional);



customer_communication_t* instantiate_customer_communication(int include_optional) {
  customer_communication_t* customer_communication = NULL;
  if (include_optional) {
    customer_communication = customer_communication_create(
      "0",
      simplebilly_api_customer_communication__email,
      "0",
      "0",
      simplebilly_api_customer_communication__inbound,
      "2013-10-20T19:20:30+01:00",
      "0",
      null
    );
  } else {
    customer_communication = customer_communication_create(
      "0",
      simplebilly_api_customer_communication__email,
      "0",
      "0",
      simplebilly_api_customer_communication__inbound,
      "2013-10-20T19:20:30+01:00",
      "0",
      null
    );
  }

  return customer_communication;
}


#ifdef customer_communication_MAIN

void test_customer_communication(int include_optional) {
    customer_communication_t* customer_communication_1 = instantiate_customer_communication(include_optional);

	cJSON* jsoncustomer_communication_1 = customer_communication_convertToJSON(customer_communication_1);
	printf("customer_communication :\n%s\n", cJSON_Print(jsoncustomer_communication_1));
	customer_communication_t* customer_communication_2 = customer_communication_parseFromJSON(jsoncustomer_communication_1);
	cJSON* jsoncustomer_communication_2 = customer_communication_convertToJSON(customer_communication_2);
	printf("repeating customer_communication:\n%s\n", cJSON_Print(jsoncustomer_communication_2));
}

int main() {
  test_customer_communication(1);
  test_customer_communication(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_communication_MAIN
#endif // customer_communication_TEST
