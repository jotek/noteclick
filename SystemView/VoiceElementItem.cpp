#include "VoiceElementItem.h"

using namespace SystemView;

VoiceElementItem::VoiceElementItem(IdRegister & reg, IdType id, IdType voiceId, StaffSystemItem *parent, QPixmap active, QPixmap inactive)
    : MusicItem(parent), SystemViewItem(reg, id), voiceId(voiceId), active(active), inactive(inactive)
{
    systemScene()->registerVoiceElement(voiceId, this);
    addState(InactiveVoice, inactive);
    addState(ActiveVoice, active);
//    systemScene()->registerVoiceElement(voiceId, this);
    if (systemScene()->currentVoice() == voiceId)
        MusicItem::setState(ActiveVoice);
    else
        MusicItem::setState(InactiveVoice);
}

VoiceElementItem::~VoiceElementItem()
{
    systemScene()->unregisterVoiceElement(voiceId, this);
}

void VoiceElementItem::setState(VoiceElementItem::VoiceState state)
{
    MusicItem::setState(state);
}

SystemScene *VoiceElementItem::systemScene()
{
    return dynamic_cast<SystemScene*>(scene());
}
