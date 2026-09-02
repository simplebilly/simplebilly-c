#ifndef public_return_item_TEST
#define public_return_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define public_return_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/public_return_item.h"
public_return_item_t* instantiate_public_return_item(int include_optional);



public_return_item_t* instantiate_public_return_item(int include_optional) {
  public_return_item_t* public_return_item = NULL;
  if (include_optional) {
    public_return_item = public_return_item_create(
      "0",
      "0",
      56,
      "0"
    );
  } else {
    public_return_item = public_return_item_create(
      "0",
      "0",
      56,
      "0"
    );
  }

  return public_return_item;
}


#ifdef public_return_item_MAIN

void test_public_return_item(int include_optional) {
    public_return_item_t* public_return_item_1 = instantiate_public_return_item(include_optional);

	cJSON* jsonpublic_return_item_1 = public_return_item_convertToJSON(public_return_item_1);
	printf("public_return_item :\n%s\n", cJSON_Print(jsonpublic_return_item_1));
	public_return_item_t* public_return_item_2 = public_return_item_parseFromJSON(jsonpublic_return_item_1);
	cJSON* jsonpublic_return_item_2 = public_return_item_convertToJSON(public_return_item_2);
	printf("repeating public_return_item:\n%s\n", cJSON_Print(jsonpublic_return_item_2));
}

int main() {
  test_public_return_item(1);
  test_public_return_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // public_return_item_MAIN
#endif // public_return_item_TEST
