#ifndef delivery_note_create_TEST
#define delivery_note_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_note_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_note_create.h"
delivery_note_create_t* instantiate_delivery_note_create(int include_optional);



delivery_note_create_t* instantiate_delivery_note_create(int include_optional) {
  delivery_note_create_t* delivery_note_create = NULL;
  if (include_optional) {
    delivery_note_create = delivery_note_create_create(
      null,
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      null,
      "0",
      null,
      "0",
      order_confirmation,
      "0",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_delivery_note_create__open
    );
  } else {
    delivery_note_create = delivery_note_create_create(
      null,
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      null,
      "0",
      null,
      "0",
      order_confirmation,
      "0",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_delivery_note_create__open
    );
  }

  return delivery_note_create;
}


#ifdef delivery_note_create_MAIN

void test_delivery_note_create(int include_optional) {
    delivery_note_create_t* delivery_note_create_1 = instantiate_delivery_note_create(include_optional);

	cJSON* jsondelivery_note_create_1 = delivery_note_create_convertToJSON(delivery_note_create_1);
	printf("delivery_note_create :\n%s\n", cJSON_Print(jsondelivery_note_create_1));
	delivery_note_create_t* delivery_note_create_2 = delivery_note_create_parseFromJSON(jsondelivery_note_create_1);
	cJSON* jsondelivery_note_create_2 = delivery_note_create_convertToJSON(delivery_note_create_2);
	printf("repeating delivery_note_create:\n%s\n", cJSON_Print(jsondelivery_note_create_2));
}

int main() {
  test_delivery_note_create(1);
  test_delivery_note_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_note_create_MAIN
#endif // delivery_note_create_TEST
