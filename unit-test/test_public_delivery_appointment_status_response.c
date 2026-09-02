#ifndef public_delivery_appointment_status_response_TEST
#define public_delivery_appointment_status_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define public_delivery_appointment_status_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/public_delivery_appointment_status_response.h"
public_delivery_appointment_status_response_t* instantiate_public_delivery_appointment_status_response(int include_optional);



public_delivery_appointment_status_response_t* instantiate_public_delivery_appointment_status_response(int include_optional) {
  public_delivery_appointment_status_response_t* public_delivery_appointment_status_response = NULL;
  if (include_optional) {
    public_delivery_appointment_status_response = public_delivery_appointment_status_response_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "0"
    );
  } else {
    public_delivery_appointment_status_response = public_delivery_appointment_status_response_create(
      "0",
      "2013-10-20",
      "0",
      "0",
      "0"
    );
  }

  return public_delivery_appointment_status_response;
}


#ifdef public_delivery_appointment_status_response_MAIN

void test_public_delivery_appointment_status_response(int include_optional) {
    public_delivery_appointment_status_response_t* public_delivery_appointment_status_response_1 = instantiate_public_delivery_appointment_status_response(include_optional);

	cJSON* jsonpublic_delivery_appointment_status_response_1 = public_delivery_appointment_status_response_convertToJSON(public_delivery_appointment_status_response_1);
	printf("public_delivery_appointment_status_response :\n%s\n", cJSON_Print(jsonpublic_delivery_appointment_status_response_1));
	public_delivery_appointment_status_response_t* public_delivery_appointment_status_response_2 = public_delivery_appointment_status_response_parseFromJSON(jsonpublic_delivery_appointment_status_response_1);
	cJSON* jsonpublic_delivery_appointment_status_response_2 = public_delivery_appointment_status_response_convertToJSON(public_delivery_appointment_status_response_2);
	printf("repeating public_delivery_appointment_status_response:\n%s\n", cJSON_Print(jsonpublic_delivery_appointment_status_response_2));
}

int main() {
  test_public_delivery_appointment_status_response(1);
  test_public_delivery_appointment_status_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // public_delivery_appointment_status_response_MAIN
#endif // public_delivery_appointment_status_response_TEST
