#ifndef create_shipment_request_TEST
#define create_shipment_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_shipment_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_shipment_request.h"
create_shipment_request_t* instantiate_create_shipment_request(int include_optional);



create_shipment_request_t* instantiate_create_shipment_request(int include_optional) {
  create_shipment_request_t* create_shipment_request = NULL;
  if (include_optional) {
    create_shipment_request = create_shipment_request_create(
      "0",
      "0",
      1.337
    );
  } else {
    create_shipment_request = create_shipment_request_create(
      "0",
      "0",
      1.337
    );
  }

  return create_shipment_request;
}


#ifdef create_shipment_request_MAIN

void test_create_shipment_request(int include_optional) {
    create_shipment_request_t* create_shipment_request_1 = instantiate_create_shipment_request(include_optional);

	cJSON* jsoncreate_shipment_request_1 = create_shipment_request_convertToJSON(create_shipment_request_1);
	printf("create_shipment_request :\n%s\n", cJSON_Print(jsoncreate_shipment_request_1));
	create_shipment_request_t* create_shipment_request_2 = create_shipment_request_parseFromJSON(jsoncreate_shipment_request_1);
	cJSON* jsoncreate_shipment_request_2 = create_shipment_request_convertToJSON(create_shipment_request_2);
	printf("repeating create_shipment_request:\n%s\n", cJSON_Print(jsoncreate_shipment_request_2));
}

int main() {
  test_create_shipment_request(1);
  test_create_shipment_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_shipment_request_MAIN
#endif // create_shipment_request_TEST
