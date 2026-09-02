#ifndef datev_import_row_TEST
#define datev_import_row_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define datev_import_row_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/datev_import_row.h"
datev_import_row_t* instantiate_datev_import_row(int include_optional);



datev_import_row_t* instantiate_datev_import_row(int include_optional) {
  datev_import_row_t* datev_import_row = NULL;
  if (include_optional) {
    datev_import_row = datev_import_row_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    datev_import_row = datev_import_row_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return datev_import_row;
}


#ifdef datev_import_row_MAIN

void test_datev_import_row(int include_optional) {
    datev_import_row_t* datev_import_row_1 = instantiate_datev_import_row(include_optional);

	cJSON* jsondatev_import_row_1 = datev_import_row_convertToJSON(datev_import_row_1);
	printf("datev_import_row :\n%s\n", cJSON_Print(jsondatev_import_row_1));
	datev_import_row_t* datev_import_row_2 = datev_import_row_parseFromJSON(jsondatev_import_row_1);
	cJSON* jsondatev_import_row_2 = datev_import_row_convertToJSON(datev_import_row_2);
	printf("repeating datev_import_row:\n%s\n", cJSON_Print(jsondatev_import_row_2));
}

int main() {
  test_datev_import_row(1);
  test_datev_import_row(0);

  printf("Hello world \n");
  return 0;
}

#endif // datev_import_row_MAIN
#endif // datev_import_row_TEST
