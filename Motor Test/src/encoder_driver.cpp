/** @file encoder_driver.cpp
 *  This program 
 * 
 *  @author Christian Clephan
 *  @date   11-16-22
 */

#include "encoder_driver.h"

/** @brief   Constructor which creates a encoder driver object.
 */
Encoder::Encoder (void)
{
    bool OUTA_val1 = digitalRead(OUTA);
    bool OUTA_val2 = digitalRead(OUTA);
    bool OUTB_val1 = digitalRead(OUTB);
}

