#ifndef cart_item_input_TEST
#define cart_item_input_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cart_item_input_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cart_item_input.h"
cart_item_input_t* instantiate_cart_item_input(int include_optional);



cart_item_input_t* instantiate_cart_item_input(int include_optional) {
  cart_item_input_t* cart_item_input = NULL;
  if (include_optional) {
    cart_item_input = cart_item_input_create(
      "0",
      56
    );
  } else {
    cart_item_input = cart_item_input_create(
      "0",
      56
    );
  }

  return cart_item_input;
}


#ifdef cart_item_input_MAIN

void test_cart_item_input(int include_optional) {
    cart_item_input_t* cart_item_input_1 = instantiate_cart_item_input(include_optional);

	cJSON* jsoncart_item_input_1 = cart_item_input_convertToJSON(cart_item_input_1);
	printf("cart_item_input :\n%s\n", cJSON_Print(jsoncart_item_input_1));
	cart_item_input_t* cart_item_input_2 = cart_item_input_parseFromJSON(jsoncart_item_input_1);
	cJSON* jsoncart_item_input_2 = cart_item_input_convertToJSON(cart_item_input_2);
	printf("repeating cart_item_input:\n%s\n", cJSON_Print(jsoncart_item_input_2));
}

int main() {
  test_cart_item_input(1);
  test_cart_item_input(0);

  printf("Hello world \n");
  return 0;
}

#endif // cart_item_input_MAIN
#endif // cart_item_input_TEST
