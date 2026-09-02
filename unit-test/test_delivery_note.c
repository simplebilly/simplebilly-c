#ifndef delivery_note_TEST
#define delivery_note_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_note_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_note.h"
delivery_note_t* instantiate_delivery_note(int include_optional);



delivery_note_t* instantiate_delivery_note(int include_optional) {
  delivery_note_t* delivery_note = NULL;
  if (include_optional) {
    delivery_note = delivery_note_create(
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
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_delivery_note__open
    );
  } else {
    delivery_note = delivery_note_create(
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
      "0",
      "0",
      "2013-10-20",
      simplebilly_api_delivery_note__open
    );
  }

  return delivery_note;
}


#ifdef delivery_note_MAIN

void test_delivery_note(int include_optional) {
    delivery_note_t* delivery_note_1 = instantiate_delivery_note(include_optional);

	cJSON* jsondelivery_note_1 = delivery_note_convertToJSON(delivery_note_1);
	printf("delivery_note :\n%s\n", cJSON_Print(jsondelivery_note_1));
	delivery_note_t* delivery_note_2 = delivery_note_parseFromJSON(jsondelivery_note_1);
	cJSON* jsondelivery_note_2 = delivery_note_convertToJSON(delivery_note_2);
	printf("repeating delivery_note:\n%s\n", cJSON_Print(jsondelivery_note_2));
}

int main() {
  test_delivery_note(1);
  test_delivery_note(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_note_MAIN
#endif // delivery_note_TEST
