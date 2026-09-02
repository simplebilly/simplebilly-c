#ifndef section_TEST
#define section_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define section_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/section.h"
section_t* instantiate_section(int include_optional);



section_t* instantiate_section(int include_optional) {
  section_t* section = NULL;
  if (include_optional) {
    section = section_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    section = section_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return section;
}


#ifdef section_MAIN

void test_section(int include_optional) {
    section_t* section_1 = instantiate_section(include_optional);

	cJSON* jsonsection_1 = section_convertToJSON(section_1);
	printf("section :\n%s\n", cJSON_Print(jsonsection_1));
	section_t* section_2 = section_parseFromJSON(jsonsection_1);
	cJSON* jsonsection_2 = section_convertToJSON(section_2);
	printf("repeating section:\n%s\n", cJSON_Print(jsonsection_2));
}

int main() {
  test_section(1);
  test_section(0);

  printf("Hello world \n");
  return 0;
}

#endif // section_MAIN
#endif // section_TEST
