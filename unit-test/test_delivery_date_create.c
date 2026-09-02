#ifndef delivery_date_create_TEST
#define delivery_date_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_date_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_date_create.h"
delivery_date_create_t* instantiate_delivery_date_create(int include_optional);



delivery_date_create_t* instantiate_delivery_date_create(int include_optional) {
  delivery_date_create_t* delivery_date_create = NULL;
  if (include_optional) {
    delivery_date_create = delivery_date_create_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      "0",
      "2013-10-20",
      promised
    );
  } else {
    delivery_date_create = delivery_date_create_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      "0",
      "2013-10-20",
      promised
    );
  }

  return delivery_date_create;
}


#ifdef delivery_date_create_MAIN

void test_delivery_date_create(int include_optional) {
    delivery_date_create_t* delivery_date_create_1 = instantiate_delivery_date_create(include_optional);

	cJSON* jsondelivery_date_create_1 = delivery_date_create_convertToJSON(delivery_date_create_1);
	printf("delivery_date_create :\n%s\n", cJSON_Print(jsondelivery_date_create_1));
	delivery_date_create_t* delivery_date_create_2 = delivery_date_create_parseFromJSON(jsondelivery_date_create_1);
	cJSON* jsondelivery_date_create_2 = delivery_date_create_convertToJSON(delivery_date_create_2);
	printf("repeating delivery_date_create:\n%s\n", cJSON_Print(jsondelivery_date_create_2));
}

int main() {
  test_delivery_date_create(1);
  test_delivery_date_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_date_create_MAIN
#endif // delivery_date_create_TEST
