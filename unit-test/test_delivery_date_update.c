#ifndef delivery_date_update_TEST
#define delivery_date_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_date_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_date_update.h"
delivery_date_update_t* instantiate_delivery_date_update(int include_optional);



delivery_date_update_t* instantiate_delivery_date_update(int include_optional) {
  delivery_date_update_t* delivery_date_update = NULL;
  if (include_optional) {
    delivery_date_update = delivery_date_update_create(
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
    delivery_date_update = delivery_date_update_create(
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

  return delivery_date_update;
}


#ifdef delivery_date_update_MAIN

void test_delivery_date_update(int include_optional) {
    delivery_date_update_t* delivery_date_update_1 = instantiate_delivery_date_update(include_optional);

	cJSON* jsondelivery_date_update_1 = delivery_date_update_convertToJSON(delivery_date_update_1);
	printf("delivery_date_update :\n%s\n", cJSON_Print(jsondelivery_date_update_1));
	delivery_date_update_t* delivery_date_update_2 = delivery_date_update_parseFromJSON(jsondelivery_date_update_1);
	cJSON* jsondelivery_date_update_2 = delivery_date_update_convertToJSON(delivery_date_update_2);
	printf("repeating delivery_date_update:\n%s\n", cJSON_Print(jsondelivery_date_update_2));
}

int main() {
  test_delivery_date_update(1);
  test_delivery_date_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_date_update_MAIN
#endif // delivery_date_update_TEST
