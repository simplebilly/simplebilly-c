#ifndef betriebsstaette_TEST
#define betriebsstaette_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define betriebsstaette_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/betriebsstaette.h"
betriebsstaette_t* instantiate_betriebsstaette(int include_optional);



betriebsstaette_t* instantiate_betriebsstaette(int include_optional) {
  betriebsstaette_t* betriebsstaette = NULL;
  if (include_optional) {
    betriebsstaette = betriebsstaette_create(
      0,
      "0"
    );
  } else {
    betriebsstaette = betriebsstaette_create(
      0,
      "0"
    );
  }

  return betriebsstaette;
}


#ifdef betriebsstaette_MAIN

void test_betriebsstaette(int include_optional) {
    betriebsstaette_t* betriebsstaette_1 = instantiate_betriebsstaette(include_optional);

	cJSON* jsonbetriebsstaette_1 = betriebsstaette_convertToJSON(betriebsstaette_1);
	printf("betriebsstaette :\n%s\n", cJSON_Print(jsonbetriebsstaette_1));
	betriebsstaette_t* betriebsstaette_2 = betriebsstaette_parseFromJSON(jsonbetriebsstaette_1);
	cJSON* jsonbetriebsstaette_2 = betriebsstaette_convertToJSON(betriebsstaette_2);
	printf("repeating betriebsstaette:\n%s\n", cJSON_Print(jsonbetriebsstaette_2));
}

int main() {
  test_betriebsstaette(1);
  test_betriebsstaette(0);

  printf("Hello world \n");
  return 0;
}

#endif // betriebsstaette_MAIN
#endif // betriebsstaette_TEST
