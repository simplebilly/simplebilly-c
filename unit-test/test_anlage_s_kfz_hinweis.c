#ifndef anlage_s_kfz_hinweis_TEST
#define anlage_s_kfz_hinweis_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define anlage_s_kfz_hinweis_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/anlage_s_kfz_hinweis.h"
anlage_s_kfz_hinweis_t* instantiate_anlage_s_kfz_hinweis(int include_optional);



anlage_s_kfz_hinweis_t* instantiate_anlage_s_kfz_hinweis(int include_optional) {
  anlage_s_kfz_hinweis_t* anlage_s_kfz_hinweis = NULL;
  if (include_optional) {
    anlage_s_kfz_hinweis = anlage_s_kfz_hinweis_create(
      "0",
      "0",
      "0"
    );
  } else {
    anlage_s_kfz_hinweis = anlage_s_kfz_hinweis_create(
      "0",
      "0",
      "0"
    );
  }

  return anlage_s_kfz_hinweis;
}


#ifdef anlage_s_kfz_hinweis_MAIN

void test_anlage_s_kfz_hinweis(int include_optional) {
    anlage_s_kfz_hinweis_t* anlage_s_kfz_hinweis_1 = instantiate_anlage_s_kfz_hinweis(include_optional);

	cJSON* jsonanlage_s_kfz_hinweis_1 = anlage_s_kfz_hinweis_convertToJSON(anlage_s_kfz_hinweis_1);
	printf("anlage_s_kfz_hinweis :\n%s\n", cJSON_Print(jsonanlage_s_kfz_hinweis_1));
	anlage_s_kfz_hinweis_t* anlage_s_kfz_hinweis_2 = anlage_s_kfz_hinweis_parseFromJSON(jsonanlage_s_kfz_hinweis_1);
	cJSON* jsonanlage_s_kfz_hinweis_2 = anlage_s_kfz_hinweis_convertToJSON(anlage_s_kfz_hinweis_2);
	printf("repeating anlage_s_kfz_hinweis:\n%s\n", cJSON_Print(jsonanlage_s_kfz_hinweis_2));
}

int main() {
  test_anlage_s_kfz_hinweis(1);
  test_anlage_s_kfz_hinweis(0);

  printf("Hello world \n");
  return 0;
}

#endif // anlage_s_kfz_hinweis_MAIN
#endif // anlage_s_kfz_hinweis_TEST
