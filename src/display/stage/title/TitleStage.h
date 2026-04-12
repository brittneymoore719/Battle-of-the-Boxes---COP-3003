#ifndef TITLESTAGE_H
#define TITLESTAGE_H

#include "display/stage/Stage.h"
#include "../../displayable/ui/button/UiButton.h"
class TitleStage : public Stage {
public:
    TitleStage();
    virtual ~TitleStage() = default;
    void update() override;
private:
    UiButton startButton;
};

#endif
