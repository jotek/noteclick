#include "AddStaffState.h"
#include "ItemEventHandlers.h"
#include "SystemScene.h"

using namespace SystemView;

class EventHandler : public ItemEventHandler
{
    bool mousePressEvent(SystemImageItem *, QGraphicsSceneMouseEvent *) { throw; return 0; }
};

static EventHandler handler;
static SceneEventHandlers handlers;

AddStaffState::AddStaffState(QState * parent, SystemScene *scene) :
    QState(parent), scene(scene)
{
    handlers.systemImageItemHandler = &handler;
}


void AddStaffState::onEntry(QEvent *)
{
    scene->setHandlers(&handlers);
}

void AddStaffState::onExit(QEvent *)
{
    scene->setHandlers(0);
}
