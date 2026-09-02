#ifndef konto_item_TEST
#define konto_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define konto_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/konto_item.h"
konto_item_t* instantiate_konto_item(int include_optional);



konto_item_t* instantiate_konto_item(int include_optional) {
  konto_item_t* konto_item = NULL;
  if (include_optional) {
    konto_item = konto_item_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    konto_item = konto_item_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return konto_item;
}


#ifdef konto_item_MAIN

void test_konto_item(int include_optional) {
    konto_item_t* konto_item_1 = instantiate_konto_item(include_optional);

	cJSON* jsonkonto_item_1 = konto_item_convertToJSON(konto_item_1);
	printf("konto_item :\n%s\n", cJSON_Print(jsonkonto_item_1));
	konto_item_t* konto_item_2 = konto_item_parseFromJSON(jsonkonto_item_1);
	cJSON* jsonkonto_item_2 = konto_item_convertToJSON(konto_item_2);
	printf("repeating konto_item:\n%s\n", cJSON_Print(jsonkonto_item_2));
}

int main() {
  test_konto_item(1);
  test_konto_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // konto_item_MAIN
#endif // konto_item_TEST
