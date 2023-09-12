typedef enum {
    dvdr_rslt_success = 0,
    divideByZero_Err,
}

typedef struct {
    uint32_t quotient;
    uint32_t remainder;
} divider_s;

// Implement (with all possible error checks)
divider_e divide(divider_s* answer, uint32_t number, uint32_t divide_by)
{
    if(divide_by == 0)
    {
        return divideByZero_Err;
    }
    else
    {
        answer->quotient = number/divide_by;
        answer->remainder = number%divide_by;
        return dvdr_rslt_success;
    }
}

void main(void)
{
    uint8_t dividend = 35;
    uint8_t divisor = 0;
    divider_s* result = (divider_s *)malloc(sizeof(divider_s));
    divider_e div_status = dvdr_rslt_success;

    div_status = divide(result, dividend, divisor);
    
    if (div_status != divideByZero_Err)
    {
        printf("The resultant quotient is: %lu.\r\n", result->quotient);
        printf("The resultant remainder is: %lu.\r\n", result->remainder);
        printf("The result of a function is: %d.\r\n", div_status);
    }
    else
    {
        printf("The result of a function is: %d.\r\n", div_status);
    }
    
    free(result);
}