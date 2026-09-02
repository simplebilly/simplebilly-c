#ifndef import_test_response_TEST
#define import_test_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define import_test_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/import_test_response.h"
import_test_response_t* instantiate_import_test_response(int include_optional);



import_test_response_t* instantiate_import_test_response(int include_optional) {
  import_test_response_t* import_test_response = NULL;
  if (include_optional) {
    import_test_response = import_test_response_create(
      "0",
      1
    );
  } else {
    import_test_response = import_test_response_create(
      "0",
      1
    );
  }

  return import_test_response;
}


#ifdef import_test_response_MAIN

void test_import_test_response(int include_optional) {
    import_test_response_t* import_test_response_1 = instantiate_import_test_response(include_optional);

	cJSON* jsonimport_test_response_1 = import_test_response_convertToJSON(import_test_response_1);
	printf("import_test_response :\n%s\n", cJSON_Print(jsonimport_test_response_1));
	import_test_response_t* import_test_response_2 = import_test_response_parseFromJSON(jsonimport_test_response_1);
	cJSON* jsonimport_test_response_2 = import_test_response_convertToJSON(import_test_response_2);
	printf("repeating import_test_response:\n%s\n", cJSON_Print(jsonimport_test_response_2));
}

int main() {
  test_import_test_response(1);
  test_import_test_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // import_test_response_MAIN
#endif // import_test_response_TEST
