#ifndef customer_info_TEST
#define customer_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer_info.h"
customer_info_t* instantiate_customer_info(int include_optional);



customer_info_t* instantiate_customer_info(int include_optional) {
  customer_info_t* customer_info = NULL;
  if (include_optional) {
    customer_info = customer_info_create(
      0,
      1
    );
  } else {
    customer_info = customer_info_create(
      0,
      1
    );
  }

  return customer_info;
}


#ifdef customer_info_MAIN

void test_customer_info(int include_optional) {
    customer_info_t* customer_info_1 = instantiate_customer_info(include_optional);

	cJSON* jsoncustomer_info_1 = customer_info_convertToJSON(customer_info_1);
	printf("customer_info :\n%s\n", cJSON_Print(jsoncustomer_info_1));
	customer_info_t* customer_info_2 = customer_info_parseFromJSON(jsoncustomer_info_1);
	cJSON* jsoncustomer_info_2 = customer_info_convertToJSON(customer_info_2);
	printf("repeating customer_info:\n%s\n", cJSON_Print(jsoncustomer_info_2));
}

int main() {
  test_customer_info(1);
  test_customer_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_info_MAIN
#endif // customer_info_TEST
