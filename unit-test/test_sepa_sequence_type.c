#ifndef sepa_sequence_type_TEST
#define sepa_sequence_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sepa_sequence_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sepa_sequence_type.h"
sepa_sequence_type_t* instantiate_sepa_sequence_type(int include_optional);



sepa_sequence_type_t* instantiate_sepa_sequence_type(int include_optional) {
  sepa_sequence_type_t* sepa_sequence_type = NULL;
  if (include_optional) {
    sepa_sequence_type = sepa_sequence_type_create(
    );
  } else {
    sepa_sequence_type = sepa_sequence_type_create(
    );
  }

  return sepa_sequence_type;
}


#ifdef sepa_sequence_type_MAIN

void test_sepa_sequence_type(int include_optional) {
    sepa_sequence_type_t* sepa_sequence_type_1 = instantiate_sepa_sequence_type(include_optional);

	cJSON* jsonsepa_sequence_type_1 = sepa_sequence_type_convertToJSON(sepa_sequence_type_1);
	printf("sepa_sequence_type :\n%s\n", cJSON_Print(jsonsepa_sequence_type_1));
	sepa_sequence_type_t* sepa_sequence_type_2 = sepa_sequence_type_parseFromJSON(jsonsepa_sequence_type_1);
	cJSON* jsonsepa_sequence_type_2 = sepa_sequence_type_convertToJSON(sepa_sequence_type_2);
	printf("repeating sepa_sequence_type:\n%s\n", cJSON_Print(jsonsepa_sequence_type_2));
}

int main() {
  test_sepa_sequence_type(1);
  test_sepa_sequence_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // sepa_sequence_type_MAIN
#endif // sepa_sequence_type_TEST
