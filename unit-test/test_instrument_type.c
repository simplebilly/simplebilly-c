#ifndef instrument_type_TEST
#define instrument_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instrument_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instrument_type.h"
instrument_type_t* instantiate_instrument_type(int include_optional);



instrument_type_t* instantiate_instrument_type(int include_optional) {
  instrument_type_t* instrument_type = NULL;
  if (include_optional) {
    instrument_type = instrument_type_create(
    );
  } else {
    instrument_type = instrument_type_create(
    );
  }

  return instrument_type;
}


#ifdef instrument_type_MAIN

void test_instrument_type(int include_optional) {
    instrument_type_t* instrument_type_1 = instantiate_instrument_type(include_optional);

	cJSON* jsoninstrument_type_1 = instrument_type_convertToJSON(instrument_type_1);
	printf("instrument_type :\n%s\n", cJSON_Print(jsoninstrument_type_1));
	instrument_type_t* instrument_type_2 = instrument_type_parseFromJSON(jsoninstrument_type_1);
	cJSON* jsoninstrument_type_2 = instrument_type_convertToJSON(instrument_type_2);
	printf("repeating instrument_type:\n%s\n", cJSON_Print(jsoninstrument_type_2));
}

int main() {
  test_instrument_type(1);
  test_instrument_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // instrument_type_MAIN
#endif // instrument_type_TEST
