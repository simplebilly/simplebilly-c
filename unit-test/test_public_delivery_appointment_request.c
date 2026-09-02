#ifndef public_delivery_appointment_request_TEST
#define public_delivery_appointment_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define public_delivery_appointment_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/public_delivery_appointment_request.h"
public_delivery_appointment_request_t* instantiate_public_delivery_appointment_request(int include_optional);



public_delivery_appointment_request_t* instantiate_public_delivery_appointment_request(int include_optional) {
  public_delivery_appointment_request_t* public_delivery_appointment_request = NULL;
  if (include_optional) {
    public_delivery_appointment_request = public_delivery_appointment_request_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      "0"
    );
  } else {
    public_delivery_appointment_request = public_delivery_appointment_request_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      "0"
    );
  }

  return public_delivery_appointment_request;
}


#ifdef public_delivery_appointment_request_MAIN

void test_public_delivery_appointment_request(int include_optional) {
    public_delivery_appointment_request_t* public_delivery_appointment_request_1 = instantiate_public_delivery_appointment_request(include_optional);

	cJSON* jsonpublic_delivery_appointment_request_1 = public_delivery_appointment_request_convertToJSON(public_delivery_appointment_request_1);
	printf("public_delivery_appointment_request :\n%s\n", cJSON_Print(jsonpublic_delivery_appointment_request_1));
	public_delivery_appointment_request_t* public_delivery_appointment_request_2 = public_delivery_appointment_request_parseFromJSON(jsonpublic_delivery_appointment_request_1);
	cJSON* jsonpublic_delivery_appointment_request_2 = public_delivery_appointment_request_convertToJSON(public_delivery_appointment_request_2);
	printf("repeating public_delivery_appointment_request:\n%s\n", cJSON_Print(jsonpublic_delivery_appointment_request_2));
}

int main() {
  test_public_delivery_appointment_request(1);
  test_public_delivery_appointment_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // public_delivery_appointment_request_MAIN
#endif // public_delivery_appointment_request_TEST
