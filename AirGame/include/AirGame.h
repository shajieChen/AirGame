/**
 * @file AirGame.h
 * @date 23-Apr-2020
 */

#ifndef __AirGame_H__
#define __AirGame_H__

#define __NO_SCROLLED__
#include "Scroll.h"

/** Game Class
 */
class AirGame : public Scroll<AirGame>
{
public:


private:

                orxSTATUS       Bootstrap() const;

                void            Update(const orxCLOCK_INFO &Info);

                orxSTATUS       Init();
                orxSTATUS       Run();
                void            Exit();
                void            BindObjects();


private:
};

#endif // __AirGame_H__
