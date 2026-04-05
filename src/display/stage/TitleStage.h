#ifndef TITLESTAGE_H
#define TITLESTAGE_H

#include "display/stage/Stage.h"
class TitleStage : public Stage {
public:
    TitleStage();
    virtual ~TitleStage() = default;
    virtual void update() override;
};

#endif
