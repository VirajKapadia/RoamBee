/**
*   Write a function that will manage a list of timers and call an associated
*   callback function when the timer expires. Also, when the timer expires, it
*   shall be restarted.
*
*   Given is an example timers configuration and the prototype for the main timer
*   periodic task function.
*
* - Define the timer_s struct type based on 'timer_s timers_example' below
* - Implement the timer_periodic_task() function
* - Test your code in main()
* - Create more timer configurations, if needed, for testing
*/

#include <stdio.h>
#include <stdint.h>

typedef void (*timer_callback)(void);

typedef struct timer_s
{
    uint32_t        time_remaining;
    uint32_t        timer_reload_value;
    timer_callback  callback;
}timer_s;

void timer_0_callback(void) {
    // just for test
    puts("Timer 0 Callback");
}
void timer_1_callback(void) {
    // just for test
    puts("Timer 1 Callback");
}
void timer_2_callback(void) {
    // just for test
    puts("Timer 2 Callback");
}

/* Initial timer example configuration */
timer_s timers_example[] = 
{
    {
        .time_remaining = 0U, // Timer starts at 0, so callback is triggered
        // When time_remaining goes to 0, this reload value is stored back to time_remaining
        .timer_reload_value = 5U, 
        .callback = timer_0_callback, // Called when time_remaining reaches 0
    },
    {
        .time_remaining = 3U, // Some initial value
        .timer_reload_value = 7U, // reload value
        .callback = timer_1_callback, // User callback
    },
    {
        .time_remaining = 7U, // Some initial value
        .timer_reload_value = 10U, // reload value
        .callback = timer_2_callback, // User callback
    },
};

/* Assume this is called back upon each timer tick but for testing at main(), you can invoke 
this manually*/
void timer_periodic_task(timer_s* timers, size_t timers_array_size) 
{
    // TODO
    
    for(int i = 0; i < timers_array_size; i++)
    {
        if(timers[i].time_remaining == 0) 
        // This check only will get executed for the 1st time when initial value of 'time_remaining' is set to 0.
        {
            timers[i].callback();
            timers[i].time_remaining = timers[i].timer_reload_value;
        }
        else
        {
            --timers[i].time_remaining;
            
            if(timers[i].time_remaining == 0)
            {
                timers[i].callback();
                timers[i].time_remaining = timers[i].timer_reload_value;
            }
        }
        printf("Timer = %d, Time remaining = %u.\n", i, timers[i].time_remaining);
    }
}

int main() {
// TODO test cases
// Test your code here with calls to timer_periodic_task()
    
    while(1)
    {
        for(uint32_t i = 0; i < 99999999; i++);
        timer_periodic_task(timers_example, (sizeof(timers_example)/sizeof(timer_s)));
    }
    return 0;
}