#ifndef betriebsstaetten_detail_TEST
#define betriebsstaetten_detail_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define betriebsstaetten_detail_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/betriebsstaetten_detail.h"
betriebsstaetten_detail_t* instantiate_betriebsstaetten_detail(int include_optional);



betriebsstaetten_detail_t* instantiate_betriebsstaetten_detail(int include_optional) {
  betriebsstaetten_detail_t* betriebsstaetten_detail = NULL;
  if (include_optional) {
    betriebsstaetten_detail = betriebsstaetten_detail_create(
      0,
      "0",
      "0"
    );
  } else {
    betriebsstaetten_detail = betriebsstaetten_detail_create(
      0,
      "0",
      "0"
    );
  }

  return betriebsstaetten_detail;
}


#ifdef betriebsstaetten_detail_MAIN

void test_betriebsstaetten_detail(int include_optional) {
    betriebsstaetten_detail_t* betriebsstaetten_detail_1 = instantiate_betriebsstaetten_detail(include_optional);

	cJSON* jsonbetriebsstaetten_detail_1 = betriebsstaetten_detail_convertToJSON(betriebsstaetten_detail_1);
	printf("betriebsstaetten_detail :\n%s\n", cJSON_Print(jsonbetriebsstaetten_detail_1));
	betriebsstaetten_detail_t* betriebsstaetten_detail_2 = betriebsstaetten_detail_parseFromJSON(jsonbetriebsstaetten_detail_1);
	cJSON* jsonbetriebsstaetten_detail_2 = betriebsstaetten_detail_convertToJSON(betriebsstaetten_detail_2);
	printf("repeating betriebsstaetten_detail:\n%s\n", cJSON_Print(jsonbetriebsstaetten_detail_2));
}

int main() {
  test_betriebsstaetten_detail(1);
  test_betriebsstaetten_detail(0);

  printf("Hello world \n");
  return 0;
}

#endif // betriebsstaetten_detail_MAIN
#endif // betriebsstaetten_detail_TEST
