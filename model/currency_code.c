#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "currency_code.h"


char* currency_code_currency_code_ToString(simplebilly_api_currency_code__e currency_code) {
    char *currency_codeArray[] =  { "NULL", "ADP", "AED", "AFA", "AFN", "ALL", "AMD", "ANG", "AOA", "AOK", "AOR", "ARS", "ATS", "AUD", "AWG", "AZM", "AZN", "BAD", "BAM", "BBD", "BDT", "BEC", "BEF", "BEL", "BGJ", "BGN", "BHD", "BIF", "BMD", "BND", "BOB", "BOV", "BRB", "BRL", "BRR", "BSD", "BTN", "BWP", "BYB", "BYN", "BYR", "BZD", "CAD", "CDF", "CHE", "CHF", "CHW", "CLF", "CLP", "CNY", "COP", "COU", "CRC", "CSD", "CSK", "CUC", "CUP", "CVE", "CYP", "CZK", "DDM", "DJF", "DKK", "DOP", "DZD", "ECS", "ECV", "EEK", "EGP", "ERN", "ESA", "ESB", "ESP", "ETB", "EUR", "FIM", "FJD", "FKP", "FRF", "GBP", "GEK", "GEL", "GHC", "GHP", "GHS", "GIP", "GMD", "GNF", "GQE", "GRD", "GTQ", "GWE", "GYD", "HKD", "HNL", "HRD", "HTG", "HUF", "IDR", "IEP", "ILS", "INR", "IQD", "IRR", "ISK", "ITL", "JMD", "JOD", "JPY", "KES", "KGS", "KHR", "KMF", "KPW", "KRW", "KWD", "KYD", "KZT", "LAK", "LBP", "LKR", "LRD", "LSL", "LTL", "LUC", "LUF", "LUL", "LVL", "LYD", "MAD", "MDL", "MGA", "MGF", "MKD", "MLF", "MMK", "MNT", "MOP", "MRO", "MRU", "MTL", "MUR", "MVR", "MWK", "MXN", "MXV", "MYR", "MZE", "MZN", "NAD", "NGN", "NIO", "NLG", "NOK", "NPR", "NZD", "OMR", "PAB", "PEN", "PGK", "PHP", "PKR", "PLN", "PLZ", "PTE", "PYG", "QAR", "RHD", "ROK", "RON", "RSD", "RUB", "RUR", "RWF", "SAR", "SBD", "SCR", "SDD", "SDG", "SEK", "SGD", "SHP", "SIT", "SKK", "SLE", "SLL", "SOS", "SRD", "SRG", "SSP", "STD", "STN", "SVC", "SYP", "SZL", "THB", "TJR", "TJS", "TMM", "TMT", "TND", "TOP", "TPE", "TRL", "TRY", "TTD", "TWD", "TZS", "UAH", "UAK", "UGX", "USD", "USN", "USS", "UYI", "UYU", "UYW", "UZS", "VEB", "VED", "VEF", "VES", "VND", "VUV", "WST", "XAD", "XAF", "XAG", "XAU", "XBA", "XBB", "XBC", "XBD", "XCD", "XDR", "XEU", "XOF", "XPD", "XPF", "XPT", "XSU", "XTS", "XUA", "XXX", "YDD", "YER", "YUD", "ZAL", "ZAR", "ZMK", "ZMW", "ZRN", "ZWG", "ZWL", "ZWN", "ZWR" };
    return currency_codeArray[currency_code];
}

simplebilly_api_currency_code__e currency_code_currency_code_FromString(char* currency_code) {
    int stringToReturn = 0;
    char *currency_codeArray[] =  { "NULL", "ADP", "AED", "AFA", "AFN", "ALL", "AMD", "ANG", "AOA", "AOK", "AOR", "ARS", "ATS", "AUD", "AWG", "AZM", "AZN", "BAD", "BAM", "BBD", "BDT", "BEC", "BEF", "BEL", "BGJ", "BGN", "BHD", "BIF", "BMD", "BND", "BOB", "BOV", "BRB", "BRL", "BRR", "BSD", "BTN", "BWP", "BYB", "BYN", "BYR", "BZD", "CAD", "CDF", "CHE", "CHF", "CHW", "CLF", "CLP", "CNY", "COP", "COU", "CRC", "CSD", "CSK", "CUC", "CUP", "CVE", "CYP", "CZK", "DDM", "DJF", "DKK", "DOP", "DZD", "ECS", "ECV", "EEK", "EGP", "ERN", "ESA", "ESB", "ESP", "ETB", "EUR", "FIM", "FJD", "FKP", "FRF", "GBP", "GEK", "GEL", "GHC", "GHP", "GHS", "GIP", "GMD", "GNF", "GQE", "GRD", "GTQ", "GWE", "GYD", "HKD", "HNL", "HRD", "HTG", "HUF", "IDR", "IEP", "ILS", "INR", "IQD", "IRR", "ISK", "ITL", "JMD", "JOD", "JPY", "KES", "KGS", "KHR", "KMF", "KPW", "KRW", "KWD", "KYD", "KZT", "LAK", "LBP", "LKR", "LRD", "LSL", "LTL", "LUC", "LUF", "LUL", "LVL", "LYD", "MAD", "MDL", "MGA", "MGF", "MKD", "MLF", "MMK", "MNT", "MOP", "MRO", "MRU", "MTL", "MUR", "MVR", "MWK", "MXN", "MXV", "MYR", "MZE", "MZN", "NAD", "NGN", "NIO", "NLG", "NOK", "NPR", "NZD", "OMR", "PAB", "PEN", "PGK", "PHP", "PKR", "PLN", "PLZ", "PTE", "PYG", "QAR", "RHD", "ROK", "RON", "RSD", "RUB", "RUR", "RWF", "SAR", "SBD", "SCR", "SDD", "SDG", "SEK", "SGD", "SHP", "SIT", "SKK", "SLE", "SLL", "SOS", "SRD", "SRG", "SSP", "STD", "STN", "SVC", "SYP", "SZL", "THB", "TJR", "TJS", "TMM", "TMT", "TND", "TOP", "TPE", "TRL", "TRY", "TTD", "TWD", "TZS", "UAH", "UAK", "UGX", "USD", "USN", "USS", "UYI", "UYU", "UYW", "UZS", "VEB", "VED", "VEF", "VES", "VND", "VUV", "WST", "XAD", "XAF", "XAG", "XAU", "XBA", "XBB", "XBC", "XBD", "XCD", "XDR", "XEU", "XOF", "XPD", "XPF", "XPT", "XSU", "XTS", "XUA", "XXX", "YDD", "YER", "YUD", "ZAL", "ZAR", "ZMK", "ZMW", "ZRN", "ZWG", "ZWL", "ZWN", "ZWR" };
    size_t sizeofArray = sizeof(currency_codeArray) / sizeof(currency_codeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(currency_code, currency_codeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *currency_code_convertToJSON(simplebilly_api_currency_code__e currency_code) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "currency_code", currency_code_currency_code_ToString(currency_code)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

simplebilly_api_currency_code__e currency_code_parseFromJSON(cJSON *currency_codeJSON) {
    if(!cJSON_IsString(currency_codeJSON) || (currency_codeJSON->valuestring == NULL)) {
        return 0;
    }
    return currency_code_currency_code_FromString(currency_codeJSON->valuestring);
}
