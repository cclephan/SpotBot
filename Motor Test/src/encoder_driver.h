/** @file encoder_driver.h
 *  This is the header for the encoder driver file
 * 
 *  @author Christian Clephan
 */

#include <Arduino.h>

#define OUTA 36
#define OUTB 39

/** @brief   Class which drives quadrature encoder on dc motor.
 * 
 */
class Encoder
{
protected:
    int32_t counter = 0;
    int32_t new_pos = 0;
    int32_t last_pos = 0;
    int16_t del_pos = 0;

public:
    Encoder (void);
    void update_pos(void);
    int32_t get_pos(void);
    int16_t del_pos(void);
    void set_pos(int32_t);
};