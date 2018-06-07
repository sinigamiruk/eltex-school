#include <stdlib.h>
#include <stdio.h>
 
/* колличество минут */
#define minutes_count 10
 
int main()
{
        double moscow_tax = 4.15,rostov_tax = 1.98, krasnodar_tax=2.69,kirov_tax = 5,overall_sum,tax;
        int city_code;
        printf("vvedite kod goroda\n");
        scanf("%d",&city_code);
        
        switch(city_code)
        {
        case 905:
                tax = moscow_tax;
                break;
        case 194:
                tax = rostov_tax;
                break;
        case 491:
                tax = krasnodar_tax;
                break;
        case 800:
                tax = kirov_tax;
                break;
        default:
                return 1;
        }
        overall_sum = tax*minutes_count;
        printf("itogo = %f rublei",overall_sum);
        return 0;
}
