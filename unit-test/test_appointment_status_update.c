#ifndef appointment_status_update_TEST
#define appointment_status_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define appointment_status_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/appointment_status_update.h"
appointment_status_update_t* instantiate_appointment_status_update(int include_optional);



appointment_status_update_t* instantiate_appointment_status_update(int include_optional) {
  appointment_status_update_t* appointment_status_update = NULL;
  if (include_optional) {
    appointment_status_update = appointment_status_update_create(
      "0"
    );
  } else {
    appointment_status_update = appointment_status_update_create(
      "0"
    );
  }

  return appointment_status_update;
}


#ifdef appointment_status_update_MAIN

void test_appointment_status_update(int include_optional) {
    appointment_status_update_t* appointment_status_update_1 = instantiate_appointment_status_update(include_optional);

	cJSON* jsonappointment_status_update_1 = appointment_status_update_convertToJSON(appointment_status_update_1);
	printf("appointment_status_update :\n%s\n", cJSON_Print(jsonappointment_status_update_1));
	appointment_status_update_t* appointment_status_update_2 = appointment_status_update_parseFromJSON(jsonappointment_status_update_1);
	cJSON* jsonappointment_status_update_2 = appointment_status_update_convertToJSON(appointment_status_update_2);
	printf("repeating appointment_status_update:\n%s\n", cJSON_Print(jsonappointment_status_update_2));
}

int main() {
  test_appointment_status_update(1);
  test_appointment_status_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // appointment_status_update_MAIN
#endif // appointment_status_update_TEST
