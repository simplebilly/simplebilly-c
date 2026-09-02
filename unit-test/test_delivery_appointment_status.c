#ifndef delivery_appointment_status_TEST
#define delivery_appointment_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_appointment_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_appointment_status.h"
delivery_appointment_status_t* instantiate_delivery_appointment_status(int include_optional);



delivery_appointment_status_t* instantiate_delivery_appointment_status(int include_optional) {
  delivery_appointment_status_t* delivery_appointment_status = NULL;
  if (include_optional) {
    delivery_appointment_status = delivery_appointment_status_create(
    );
  } else {
    delivery_appointment_status = delivery_appointment_status_create(
    );
  }

  return delivery_appointment_status;
}


#ifdef delivery_appointment_status_MAIN

void test_delivery_appointment_status(int include_optional) {
    delivery_appointment_status_t* delivery_appointment_status_1 = instantiate_delivery_appointment_status(include_optional);

	cJSON* jsondelivery_appointment_status_1 = delivery_appointment_status_convertToJSON(delivery_appointment_status_1);
	printf("delivery_appointment_status :\n%s\n", cJSON_Print(jsondelivery_appointment_status_1));
	delivery_appointment_status_t* delivery_appointment_status_2 = delivery_appointment_status_parseFromJSON(jsondelivery_appointment_status_1);
	cJSON* jsondelivery_appointment_status_2 = delivery_appointment_status_convertToJSON(delivery_appointment_status_2);
	printf("repeating delivery_appointment_status:\n%s\n", cJSON_Print(jsondelivery_appointment_status_2));
}

int main() {
  test_delivery_appointment_status(1);
  test_delivery_appointment_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_appointment_status_MAIN
#endif // delivery_appointment_status_TEST
