#ifndef liquidity_position_TEST
#define liquidity_position_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define liquidity_position_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/liquidity_position.h"
liquidity_position_t* instantiate_liquidity_position(int include_optional);



liquidity_position_t* instantiate_liquidity_position(int include_optional) {
  liquidity_position_t* liquidity_position = NULL;
  if (include_optional) {
    liquidity_position = liquidity_position_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    liquidity_position = liquidity_position_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return liquidity_position;
}


#ifdef liquidity_position_MAIN

void test_liquidity_position(int include_optional) {
    liquidity_position_t* liquidity_position_1 = instantiate_liquidity_position(include_optional);

	cJSON* jsonliquidity_position_1 = liquidity_position_convertToJSON(liquidity_position_1);
	printf("liquidity_position :\n%s\n", cJSON_Print(jsonliquidity_position_1));
	liquidity_position_t* liquidity_position_2 = liquidity_position_parseFromJSON(jsonliquidity_position_1);
	cJSON* jsonliquidity_position_2 = liquidity_position_convertToJSON(liquidity_position_2);
	printf("repeating liquidity_position:\n%s\n", cJSON_Print(jsonliquidity_position_2));
}

int main() {
  test_liquidity_position(1);
  test_liquidity_position(0);

  printf("Hello world \n");
  return 0;
}

#endif // liquidity_position_MAIN
#endif // liquidity_position_TEST
