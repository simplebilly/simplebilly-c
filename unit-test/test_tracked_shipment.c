#ifndef tracked_shipment_TEST
#define tracked_shipment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tracked_shipment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tracked_shipment.h"
tracked_shipment_t* instantiate_tracked_shipment(int include_optional);



tracked_shipment_t* instantiate_tracked_shipment(int include_optional) {
  tracked_shipment_t* tracked_shipment = NULL;
  if (include_optional) {
    tracked_shipment = tracked_shipment_create(
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    tracked_shipment = tracked_shipment_create(
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      "0"
    );
  }

  return tracked_shipment;
}


#ifdef tracked_shipment_MAIN

void test_tracked_shipment(int include_optional) {
    tracked_shipment_t* tracked_shipment_1 = instantiate_tracked_shipment(include_optional);

	cJSON* jsontracked_shipment_1 = tracked_shipment_convertToJSON(tracked_shipment_1);
	printf("tracked_shipment :\n%s\n", cJSON_Print(jsontracked_shipment_1));
	tracked_shipment_t* tracked_shipment_2 = tracked_shipment_parseFromJSON(jsontracked_shipment_1);
	cJSON* jsontracked_shipment_2 = tracked_shipment_convertToJSON(tracked_shipment_2);
	printf("repeating tracked_shipment:\n%s\n", cJSON_Print(jsontracked_shipment_2));
}

int main() {
  test_tracked_shipment(1);
  test_tracked_shipment(0);

  printf("Hello world \n");
  return 0;
}

#endif // tracked_shipment_MAIN
#endif // tracked_shipment_TEST
