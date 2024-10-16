#include <stdio.h>
#include <stdlib.h>
#define MAX_CLAUSE 20

struct Date{
    unsigned year;
    unsigned month;
    unsigned day;
};

int compare_date(struct Date *dateA,struct Date *dateB){
    //if A>B ,return 1.A<B return -1 , A=B return 0
    if(dateA->year>dateB->year){
        return 1;
    }else if (dateA->year<dateB->year){
        return -1;
    }else{
        if(dateA->month>dateB->month){
            return 1;
        }else if (dateA->month<dateB->month){
            return -1;
        }else{
            if(dateA->day>dateB->day){
                return 1;
            }else if (dateA->day<dateB->day){
                return -1;
            }else{
                return 0;
            }
        }
    }
}

void initialize_dates(struct Date dates[], int size) {
    for (int i = 0; i < size; ++i) {
        dates[i].year = 0;
        dates[i].month = 0;
        dates[i].day = 0;
    }
}

// void swap(struct Date *dateA,struct Date *dateB){
//     struct Date temp = *dateB;
//     *dateB = *dateA;
//     *dateA = temp;
// }

// void max_heapfy(struct Date *dates,int start,int end){
//     int dad = start;
//     int son = dad * 2 + 1;
//     while(son <= end){
//         if ((son+1 <= end) && (compare_date(&dates[son],&dates[son+1])<0)){
//             son++;
//         } 
//         if (compare_date(&dates[dad],&dates[son])){
//             return;
//         }else{
//             swap(&dates[dad],&dates[son]);
//             dad = son;
//             son = dad* 2 + 1;
//         }
//     }
// }

// void date_heap_sort(struct Date *dates ,int size){
//     int i;
//     for(i=size/2-1;i>=0;i--){
//         max_heapfy(dates,i,size-1);
//     }
//     for(i=size-1;i>0;i--){
//         swap(&dates[0],&dates[i]);
//         max_heapfy(dates,0,i-1);
//     }
// }

void date_sort(struct Date *dates, int size) {
        int gap, i, j;
        struct Date temp;

        for (gap = size >> 1; gap > 0; gap >>= 1)
                for (i = gap; i < size; i++) {
                        temp = dates[i];
                        for (j = i - gap; j >= 0 && (compare_date(&dates[j],&temp)>=0); j -= gap)
                                dates[j + gap] = dates[j];
                        dates[j + gap] = temp;
                }
}

void print_date(struct Date *dates ,int size){
    int i;
    //printf("Here is output:\n");
    for(i = 0;i<size;i++){
        //printf("this is line %d\n",i+1);
        printf("%04u %02u %02u\n",
        dates[i].year,dates[i].month,dates[i].day);
    }
    // printf("%04u %02u %02u\n",
    // dates[3].year,dates[3].month,dates[3].day);
}



int main(){
    struct Date dates[MAX_CLAUSE];
    initialize_dates(dates, MAX_CLAUSE);
    unsigned int i,y,m,d,size = 0;

    for(i=0;i<MAX_CLAUSE;i++){
        int leap = 0;
        if(scanf("%u %u %u",&y,&m,&d)==EOF){
            break;
        }       

        if ((y%4==0)&&(y%400!=0)){
            leap = 1;
        }else if(y%400==0){
            leap = 1;
        }

        if((m>12)||(m<=0)){
            continue;
        }
        if(d<=0){
            continue;
        }
        switch (m){
            case 1: case 3:case 5:case 7: case 8:case 10:case 12:
            {
                if(d>31){
                    continue;
                }else{
                    break;
                }
            }

            case 4: case 6:case 9:case 11:
            {
                if(d>30){
                    continue;
                }else{
                    break;
                }
            }
             
            case 2:
            {
                if(leap){
                    if(d>29){
                        continue;
                    }else{
                        break;
                    }
                }else{
                    if(d>28){
                        continue;
                    }else{
                        break;
                    }
                }
            }
        }
        

        dates[size].year = y;
        dates[size].month = m;
        dates[size].day = d;        
        //printf("input successfully\n");
        size++;
    }
    //printf("%d",size);
    date_sort(dates,size);
    print_date(dates,size);

    return 0;
}