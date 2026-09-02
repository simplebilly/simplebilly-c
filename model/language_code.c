#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "language_code.h"


char* language_code_language_code_ToString(simplebilly_api_language_code__e language_code) {
    char *language_codeArray[] =  { "NULL", "DE", "EN", "FR", "ES", "IT", "NL", "PL", "PT", "TR", "RU", "UK", "CS", "EL", "HU", "RO", "SV", "DA", "FI", "NO", "SK", "SL", "HR", "BG", "ET", "LV", "LT", "MT", "AR", "ZH", "JA", "KO", "TH", "VI", "ID", "HI", "AB", "AA", "AF", "AK", "SQ", "AM", "AN", "HY", "AS", "AV", "AE", "AY", "AZ", "BM", "BA", "EU", "BE", "BN", "BI", "BS", "BR", "MY", "CA", "CH", "CE", "NY", "CU", "CV", "KW", "CO", "CR", "DV", "DZ", "EO", "EE", "FO", "FJ", "FY", "FF", "GD", "GL", "LG", "KA", "KL", "GN", "GU", "HT", "HA", "HE", "HZ", "HO", "IS", "IO", "IG", "IA", "IE", "IU", "IK", "GA", "JV", "KN", "KR", "KS", "KK", "KM", "KI", "RW", "KY", "KV", "KG", "KJ", "KU", "LO", "LA", "LI", "LN", "LU", "LB", "MK", "MG", "MS", "ML", "GV", "MI", "MR", "MH", "MN", "NA", "NV", "ND", "NR", "NG", "NE", "NB", "NN", "OC", "OJ", "OR", "OM", "OS", "PI", "PS", "FA", "PA", "QU", "RM", "RN", "SE", "SM", "SG", "SA", "SC", "SR", "SN", "SD", "SI", "SO", "ST", "SU", "SW", "SS", "TL", "TY", "TG", "TA", "TT", "TE", "BO", "TI", "TO", "TS", "TN", "TK", "TW", "UG", "UR", "UZ", "VE", "VO", "WA", "CY", "WO", "XH", "II", "YI", "YO", "ZA", "ZU", "BB", "CB", "DB", "EB", "FB", "GB", "HB", "IB", "JB", "KB", "MB", "OB", "PB", "QB", "RB", "SB", "TB", "UB", "VB", "WB", "XB", "YB", "ZB" };
    return language_codeArray[language_code];
}

simplebilly_api_language_code__e language_code_language_code_FromString(char* language_code) {
    int stringToReturn = 0;
    char *language_codeArray[] =  { "NULL", "DE", "EN", "FR", "ES", "IT", "NL", "PL", "PT", "TR", "RU", "UK", "CS", "EL", "HU", "RO", "SV", "DA", "FI", "NO", "SK", "SL", "HR", "BG", "ET", "LV", "LT", "MT", "AR", "ZH", "JA", "KO", "TH", "VI", "ID", "HI", "AB", "AA", "AF", "AK", "SQ", "AM", "AN", "HY", "AS", "AV", "AE", "AY", "AZ", "BM", "BA", "EU", "BE", "BN", "BI", "BS", "BR", "MY", "CA", "CH", "CE", "NY", "CU", "CV", "KW", "CO", "CR", "DV", "DZ", "EO", "EE", "FO", "FJ", "FY", "FF", "GD", "GL", "LG", "KA", "KL", "GN", "GU", "HT", "HA", "HE", "HZ", "HO", "IS", "IO", "IG", "IA", "IE", "IU", "IK", "GA", "JV", "KN", "KR", "KS", "KK", "KM", "KI", "RW", "KY", "KV", "KG", "KJ", "KU", "LO", "LA", "LI", "LN", "LU", "LB", "MK", "MG", "MS", "ML", "GV", "MI", "MR", "MH", "MN", "NA", "NV", "ND", "NR", "NG", "NE", "NB", "NN", "OC", "OJ", "OR", "OM", "OS", "PI", "PS", "FA", "PA", "QU", "RM", "RN", "SE", "SM", "SG", "SA", "SC", "SR", "SN", "SD", "SI", "SO", "ST", "SU", "SW", "SS", "TL", "TY", "TG", "TA", "TT", "TE", "BO", "TI", "TO", "TS", "TN", "TK", "TW", "UG", "UR", "UZ", "VE", "VO", "WA", "CY", "WO", "XH", "II", "YI", "YO", "ZA", "ZU", "BB", "CB", "DB", "EB", "FB", "GB", "HB", "IB", "JB", "KB", "MB", "OB", "PB", "QB", "RB", "SB", "TB", "UB", "VB", "WB", "XB", "YB", "ZB" };
    size_t sizeofArray = sizeof(language_codeArray) / sizeof(language_codeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(language_code, language_codeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *language_code_convertToJSON(simplebilly_api_language_code__e language_code) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "language_code", language_code_language_code_ToString(language_code)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_language_code__e language_code_parseFromJSON(cJSON *language_codeJSON) {
    if(!cJSON_IsString(language_codeJSON) || (language_codeJSON->valuestring == NULL)) {
        return 0;
    }
    return language_code_language_code_FromString(language_codeJSON->valuestring);
}
