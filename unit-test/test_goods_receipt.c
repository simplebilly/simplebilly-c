#ifndef goods_receipt_TEST
#define goods_receipt_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define goods_receipt_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/goods_receipt.h"
goods_receipt_t* instantiate_goods_receipt(int include_optional);



goods_receipt_t* instantiate_goods_receipt(int include_optional) {
  goods_receipt_t* goods_receipt = NULL;
  if (include_optional) {
    goods_receipt = goods_receipt_create(
      "0",
      null,
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      "0"
    );
  } else {
    goods_receipt = goods_receipt_create(
      "0",
      null,
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      "0"
    );
  }

  return goods_receipt;
}


#ifdef goods_receipt_MAIN

void test_goods_receipt(int include_optional) {
    goods_receipt_t* goods_receipt_1 = instantiate_goods_receipt(include_optional);

	cJSON* jsongoods_receipt_1 = goods_receipt_convertToJSON(goods_receipt_1);
	printf("goods_receipt :\n%s\n", cJSON_Print(jsongoods_receipt_1));
	goods_receipt_t* goods_receipt_2 = goods_receipt_parseFromJSON(jsongoods_receipt_1);
	cJSON* jsongoods_receipt_2 = goods_receipt_convertToJSON(goods_receipt_2);
	printf("repeating goods_receipt:\n%s\n", cJSON_Print(jsongoods_receipt_2));
}

int main() {
  test_goods_receipt(1);
  test_goods_receipt(0);

  printf("Hello world \n");
  return 0;
}

#endif // goods_receipt_MAIN
#endif // goods_receipt_TEST
