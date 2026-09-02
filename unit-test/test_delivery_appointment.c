#ifndef delivery_appointment_TEST
#define delivery_appointment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_appointment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_appointment.h"
delivery_appointment_t* instantiate_delivery_appointment(int include_optional);



delivery_appointment_t* instantiate_delivery_appointment(int include_optional) {
  delivery_appointment_t* delivery_appointment = NULL;
  if (include_optional) {
    delivery_appointment = delivery_appointment_create(
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
    delivery_appointment = delivery_appointment_create(
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

  return delivery_appointment;
}


#ifdef delivery_appointment_MAIN

void test_delivery_appointment(int include_optional) {
    delivery_appointment_t* delivery_appointment_1 = instantiate_delivery_appointment(include_optional);

	cJSON* jsondelivery_appointment_1 = delivery_appointment_convertToJSON(delivery_appointment_1);
	printf("delivery_appointment :\n%s\n", cJSON_Print(jsondelivery_appointment_1));
	delivery_appointment_t* delivery_appointment_2 = delivery_appointment_parseFromJSON(jsondelivery_appointment_1);
	cJSON* jsondelivery_appointment_2 = delivery_appointment_convertToJSON(delivery_appointment_2);
	printf("repeating delivery_appointment:\n%s\n", cJSON_Print(jsondelivery_appointment_2));
}

int main() {
  test_delivery_appointment(1);
  test_delivery_appointment(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_appointment_MAIN
#endif // delivery_appointment_TEST
