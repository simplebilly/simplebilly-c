#ifndef customer_group_update_TEST
#define customer_group_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define customer_group_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/customer_group_update.h"
customer_group_update_t* instantiate_customer_group_update(int include_optional);



customer_group_update_t* instantiate_customer_group_update(int include_optional) {
  customer_group_update_t* customer_group_update = NULL;
  if (include_optional) {
    customer_group_update = customer_group_update_create(
      "0",
      list_createList(),
      "0",
      "0"
    );
  } else {
    customer_group_update = customer_group_update_create(
      "0",
      list_createList(),
      "0",
      "0"
    );
  }

  return customer_group_update;
}


#ifdef customer_group_update_MAIN

void test_customer_group_update(int include_optional) {
    customer_group_update_t* customer_group_update_1 = instantiate_customer_group_update(include_optional);

	cJSON* jsoncustomer_group_update_1 = customer_group_update_convertToJSON(customer_group_update_1);
	printf("customer_group_update :\n%s\n", cJSON_Print(jsoncustomer_group_update_1));
	customer_group_update_t* customer_group_update_2 = customer_group_update_parseFromJSON(jsoncustomer_group_update_1);
	cJSON* jsoncustomer_group_update_2 = customer_group_update_convertToJSON(customer_group_update_2);
	printf("repeating customer_group_update:\n%s\n", cJSON_Print(jsoncustomer_group_update_2));
}

int main() {
  test_customer_group_update(1);
  test_customer_group_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // customer_group_update_MAIN
#endif // customer_group_update_TEST
