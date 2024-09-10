#include <string.h>

void dansketal(int number, char* result) {
    // arrays that represent the words that we use to build the end string.
    char* baseten[] = {"nul", "et", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"};
    char* weirdos[] = {"ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"};
    char* tens[] = {"", "", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"};
    
    //check for negative
    if (number < 0) {
        strcat(result, "minus ");
        number = -number;
    }

    // here we do a shitty loop where we reduce the number after each itteration based on how large the number is.
    // ie if the number was in the thousands we would find out how many thousands and add that to the string.
    //then divide by 1000 and call the function again with the new number.
    // repeat this until the number is <10 

    //TODO: make this a real loop instead of this nonsense.
    if (number < 10) {
        strcat(result, baseten[number]);
    } else if (number < 20) {
        strcat(result, weirdos[number - 10]);
    } else if (number < 100) {
        if (number % 10 == 0) {
            strcat(result, tens[number / 10]);
        } else {
            strcat(result, baseten[number % 10]);
            strcat(result, "og");
            strcat(result, tens[number / 10]);
        }
    } else if (number < 1000) {
        strcat(result, baseten[number / 100]);
        strcat(result, " hundrede ");
        if (number % 100 != 0) {
            dansketal(number % 100, result + strlen(result));
        }
    } else if (number < 1000000) {
        dansketal(number / 1000, result);
        strcat(result, " tusind ");
        if (number % 1000 != 0) {
            dansketal(number % 1000, result + strlen(result));
        }
    } else if( number < 1000000000){
        dansketal(number / 1000000, result);
        strcat(result, " million ");
        if (number % 1000000 != 0) {
            dansketal(number % 1000000, result + strlen(result));
        }
    }else if( number < 1000000000000){
        dansketal(number / 1000000000, result);
        strcat(result, " milliard ");
        if (number % 1000000000 != 0) {
            dansketal(number % 1000000000, result + strlen(result));
        }
    } else {
        strcat(result, "Tallet kan ikke være større end 999.999.999.999");
    }
}
