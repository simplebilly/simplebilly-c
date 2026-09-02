#ifndef delivery_date_status_TEST
#define delivery_date_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_date_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_date_status.h"
delivery_date_status_t* instantiate_delivery_date_status(int include_optional);



delivery_date_status_t* instantiate_delivery_date_status(int include_optional) {
  delivery_date_status_t* delivery_date_status = NULL;
  if (include_optional) {
    delivery_date_status = delivery_date_status_create(
    );
  } else {
    delivery_date_status = delivery_date_status_create(
    );
  }

  return delivery_date_status;
}


#ifdef delivery_date_status_MAIN

void test_delivery_date_status(int include_optional) {
    delivery_date_status_t* delivery_date_status_1 = instantiate_delivery_date_status(include_optional);

	cJSON* jsondelivery_date_status_1 = delivery_date_status_convertToJSON(delivery_date_status_1);
	printf("delivery_date_status :\n%s\n", cJSON_Print(jsondelivery_date_status_1));
	delivery_date_status_t* delivery_date_status_2 = delivery_date_status_parseFromJSON(jsondelivery_date_status_1);
	cJSON* jsondelivery_date_status_2 = delivery_date_status_convertToJSON(delivery_date_status_2);
	printf("repeating delivery_date_status:\n%s\n", cJSON_Print(jsondelivery_date_status_2));
}

int main() {
  test_delivery_date_status(1);
  test_delivery_date_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_date_status_MAIN
#endif // delivery_date_status_TEST
