#ifndef quartile_band_TEST
#define quartile_band_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define quartile_band_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/quartile_band.h"
quartile_band_t* instantiate_quartile_band(int include_optional);



quartile_band_t* instantiate_quartile_band(int include_optional) {
  quartile_band_t* quartile_band = NULL;
  if (include_optional) {
    quartile_band = quartile_band_create(
      1.337,
      "0",
      1.337,
      "0"
    );
  } else {
    quartile_band = quartile_band_create(
      1.337,
      "0",
      1.337,
      "0"
    );
  }

  return quartile_band;
}


#ifdef quartile_band_MAIN

void test_quartile_band(int include_optional) {
    quartile_band_t* quartile_band_1 = instantiate_quartile_band(include_optional);

	cJSON* jsonquartile_band_1 = quartile_band_convertToJSON(quartile_band_1);
	printf("quartile_band :\n%s\n", cJSON_Print(jsonquartile_band_1));
	quartile_band_t* quartile_band_2 = quartile_band_parseFromJSON(jsonquartile_band_1);
	cJSON* jsonquartile_band_2 = quartile_band_convertToJSON(quartile_band_2);
	printf("repeating quartile_band:\n%s\n", cJSON_Print(jsonquartile_band_2));
}

int main() {
  test_quartile_band(1);
  test_quartile_band(0);

  printf("Hello world \n");
  return 0;
}

#endif // quartile_band_MAIN
#endif // quartile_band_TEST
