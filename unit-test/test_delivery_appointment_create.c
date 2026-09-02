#ifndef delivery_appointment_create_TEST
#define delivery_appointment_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_appointment_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_appointment_create.h"
delivery_appointment_create_t* instantiate_delivery_appointment_create(int include_optional);



delivery_appointment_create_t* instantiate_delivery_appointment_create(int include_optional) {
  delivery_appointment_create_t* delivery_appointment_create = NULL;
  if (include_optional) {
    delivery_appointment_create = delivery_appointment_create_create(
      "0",
      "0",
      "0",
      "2013-10-20",
      requested,
      "0",
      "0",
      "0"
    );
  } else {
    delivery_appointment_create = delivery_appointment_create_create(
      "0",
      "0",
      "0",
      "2013-10-20",
      requested,
      "0",
      "0",
      "0"
    );
  }

  return delivery_appointment_create;
}


#ifdef delivery_appointment_create_MAIN

void test_delivery_appointment_create(int include_optional) {
    delivery_appointment_create_t* delivery_appointment_create_1 = instantiate_delivery_appointment_create(include_optional);

	cJSON* jsondelivery_appointment_create_1 = delivery_appointment_create_convertToJSON(delivery_appointment_create_1);
	printf("delivery_appointment_create :\n%s\n", cJSON_Print(jsondelivery_appointment_create_1));
	delivery_appointment_create_t* delivery_appointment_create_2 = delivery_appointment_create_parseFromJSON(jsondelivery_appointment_create_1);
	cJSON* jsondelivery_appointment_create_2 = delivery_appointment_create_convertToJSON(delivery_appointment_create_2);
	printf("repeating delivery_appointment_create:\n%s\n", cJSON_Print(jsondelivery_appointment_create_2));
}

int main() {
  test_delivery_appointment_create(1);
  test_delivery_appointment_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_appointment_create_MAIN
#endif // delivery_appointment_create_TEST
