#ifndef data_quality_TEST
#define data_quality_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define data_quality_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/data_quality.h"
data_quality_t* instantiate_data_quality(int include_optional);



data_quality_t* instantiate_data_quality(int include_optional) {
  data_quality_t* data_quality = NULL;
  if (include_optional) {
    data_quality = data_quality_create(
      0,
      1.337,
      0
    );
  } else {
    data_quality = data_quality_create(
      0,
      1.337,
      0
    );
  }

  return data_quality;
}


#ifdef data_quality_MAIN

void test_data_quality(int include_optional) {
    data_quality_t* data_quality_1 = instantiate_data_quality(include_optional);

	cJSON* jsondata_quality_1 = data_quality_convertToJSON(data_quality_1);
	printf("data_quality :\n%s\n", cJSON_Print(jsondata_quality_1));
	data_quality_t* data_quality_2 = data_quality_parseFromJSON(jsondata_quality_1);
	cJSON* jsondata_quality_2 = data_quality_convertToJSON(data_quality_2);
	printf("repeating data_quality:\n%s\n", cJSON_Print(jsondata_quality_2));
}

int main() {
  test_data_quality(1);
  test_data_quality(0);

  printf("Hello world \n");
  return 0;
}

#endif // data_quality_MAIN
#endif // data_quality_TEST
