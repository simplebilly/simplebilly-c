#ifndef customer_group_create_TEST
#define customer_group_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_group_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer_group_create.h"
customer_group_create_t* instantiate_customer_group_create(int include_optional);



customer_group_create_t* instantiate_customer_group_create(int include_optional) {
  customer_group_create_t* customer_group_create = NULL;
  if (include_optional) {
    customer_group_create = customer_group_create_create(
      "0",
      list_createList(),
      "0",
      "0"
    );
  } else {
    customer_group_create = customer_group_create_create(
      "0",
      list_createList(),
      "0",
      "0"
    );
  }

  return customer_group_create;
}


#ifdef customer_group_create_MAIN

void test_customer_group_create(int include_optional) {
    customer_group_create_t* customer_group_create_1 = instantiate_customer_group_create(include_optional);

	cJSON* jsoncustomer_group_create_1 = customer_group_create_convertToJSON(customer_group_create_1);
	printf("customer_group_create :\n%s\n", cJSON_Print(jsoncustomer_group_create_1));
	customer_group_create_t* customer_group_create_2 = customer_group_create_parseFromJSON(jsoncustomer_group_create_1);
	cJSON* jsoncustomer_group_create_2 = customer_group_create_convertToJSON(customer_group_create_2);
	printf("repeating customer_group_create:\n%s\n", cJSON_Print(jsoncustomer_group_create_2));
}

int main() {
  test_customer_group_create(1);
  test_customer_group_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_group_create_MAIN
#endif // customer_group_create_TEST
