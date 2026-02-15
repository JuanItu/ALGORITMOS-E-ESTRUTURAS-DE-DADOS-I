/* 
int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    
    
    char order1[128];
    char order2[128];
    
    strcpy(order1, str1);
    strcat(order1, str2);
    
    strcpy(order2, str2);
    strcat(order2, str1);

    return strcmp(order2,order1);
}

char* largestNumber(int* nums, int numsSize) {
    char **strNums = (char **)malloc(numsSize * sizeof(char *));
    int totalLength= 0;

    for (int i = 0; i <numsSize; i++){
       
        strNums[i] = (char *)malloc(12 * sizeof(char));
        sprintf(strNums[i], "%d", nums[i]);
        totalLength += strlen(strNums[i]);
    }

    qsort(strNums, numsSize, sizeof(char *), compare);

    if (strcmp(strNums[0], "0") == 0){
        char *result = (char *)malloc(2 * sizeof(char));
        strcpy(result, "0");
        
        return result;
    }

    char *result = (char*)malloc((totalLength + 1) * sizeof(char));
    result[0] = '\0'; 

    for (int i = 0; i < numsSize; i++){
        strcat(result, strNums[i]);
        free(strNums[i]); 
    }
    
    free(strNums); 
    return result;
}
*/