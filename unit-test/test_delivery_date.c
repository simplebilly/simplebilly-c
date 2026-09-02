#ifndef delivery_date_TEST
#define delivery_date_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_date_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_date.h"
delivery_date_t* instantiate_delivery_date(int include_optional);



delivery_date_t* instantiate_delivery_date(int include_optional) {
  delivery_date_t* delivery_date = NULL;
  if (include_optional) {
    delivery_date = delivery_date_create(
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
    delivery_date = delivery_date_create(
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

  return delivery_date;
}


#ifdef delivery_date_MAIN

void test_delivery_date(int include_optional) {
    delivery_date_t* delivery_date_1 = instantiate_delivery_date(include_optional);

	cJSON* jsondelivery_date_1 = delivery_date_convertToJSON(delivery_date_1);
	printf("delivery_date :\n%s\n", cJSON_Print(jsondelivery_date_1));
	delivery_date_t* delivery_date_2 = delivery_date_parseFromJSON(jsondelivery_date_1);
	cJSON* jsondelivery_date_2 = delivery_date_convertToJSON(delivery_date_2);
	printf("repeating delivery_date:\n%s\n", cJSON_Print(jsondelivery_date_2));
}

int main() {
  test_delivery_date(1);
  test_delivery_date(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_date_MAIN
#endif // delivery_date_TEST
