#ifndef my_training_item_TEST
#define my_training_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define my_training_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/my_training_item.h"
my_training_item_t* instantiate_my_training_item(int include_optional);



my_training_item_t* instantiate_my_training_item(int include_optional) {
  my_training_item_t* my_training_item = NULL;
  if (include_optional) {
    my_training_item = my_training_item_create(
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      56,
      56,
      1,
      simplebilly_api_my_training_item__required,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    my_training_item = my_training_item_create(
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      56,
      56,
      1,
      simplebilly_api_my_training_item__required,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return my_training_item;
}


#ifdef my_training_item_MAIN

void test_my_training_item(int include_optional) {
    my_training_item_t* my_training_item_1 = instantiate_my_training_item(include_optional);

	cJSON* jsonmy_training_item_1 = my_training_item_convertToJSON(my_training_item_1);
	printf("my_training_item :\n%s\n", cJSON_Print(jsonmy_training_item_1));
	my_training_item_t* my_training_item_2 = my_training_item_parseFromJSON(jsonmy_training_item_1);
	cJSON* jsonmy_training_item_2 = my_training_item_convertToJSON(my_training_item_2);
	printf("repeating my_training_item:\n%s\n", cJSON_Print(jsonmy_training_item_2));
}

int main() {
  test_my_training_item(1);
  test_my_training_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // my_training_item_MAIN
#endif // my_training_item_TEST
