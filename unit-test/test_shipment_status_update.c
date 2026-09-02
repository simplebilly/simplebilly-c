#ifndef shipment_status_update_TEST
#define shipment_status_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipment_status_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipment_status_update.h"
shipment_status_update_t* instantiate_shipment_status_update(int include_optional);



shipment_status_update_t* instantiate_shipment_status_update(int include_optional) {
  shipment_status_update_t* shipment_status_update = NULL;
  if (include_optional) {
    shipment_status_update = shipment_status_update_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    shipment_status_update = shipment_status_update_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return shipment_status_update;
}


#ifdef shipment_status_update_MAIN

void test_shipment_status_update(int include_optional) {
    shipment_status_update_t* shipment_status_update_1 = instantiate_shipment_status_update(include_optional);

	cJSON* jsonshipment_status_update_1 = shipment_status_update_convertToJSON(shipment_status_update_1);
	printf("shipment_status_update :\n%s\n", cJSON_Print(jsonshipment_status_update_1));
	shipment_status_update_t* shipment_status_update_2 = shipment_status_update_parseFromJSON(jsonshipment_status_update_1);
	cJSON* jsonshipment_status_update_2 = shipment_status_update_convertToJSON(shipment_status_update_2);
	printf("repeating shipment_status_update:\n%s\n", cJSON_Print(jsonshipment_status_update_2));
}

int main() {
  test_shipment_status_update(1);
  test_shipment_status_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipment_status_update_MAIN
#endif // shipment_status_update_TEST
