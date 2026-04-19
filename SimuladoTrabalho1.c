//Miguel Muller da Rosa
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int val_5 = 0, val_10 = 0, val_20 = 0;

    for ( int i = 0; i < billsSize; i++ ) {
       
        if ( bills[i] == 5 ) { 
            val_5 += 5;
        } else if ( bills[i] == 10 ) { 
            val_10 += 10;
            if(val_5 >= 5){
                val_5 = val_5 - 5;
            } else {
                return false;
            }
        } else if ( bills[i] == 20 ){
            val_20 += 20;
            if(val_5 >= 5 && val_10 >= 10){
                val_5 = val_5 - 5;
                val_10 = val_10 - 10;
            } else if ( ( 3 * val_5 ) % 15 == 0 && val_5 >= 15 ){
                val_5 = val_5 - 15;
            } else {
                return false;
            }
        }
    }
    return true;
}