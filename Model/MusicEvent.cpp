#include "MusicEvent.h"

using namespace Model;

MusicEvent::MusicEvent(ScoreModel *sm_ptr, IdRegister &registered_in, Voice * v, StaffSystem * ss, NoteValue dur, StaffCoords coords) :
    StaffSystemElement(sm_ptr, registered_in, ss, coords), parentVoice(v), parentStaffSystem(ss), duration(dur)
{
}

MusicEvent::MusicEvent(ScoreModel *sm_ptr, IdRegister &registered_in, Voice * v, StaffSystem * ss, NoteValue dur, qreal coord_x, qreal coord_y) :
    StaffSystemElement(sm_ptr, registered_in, ss, coord_x, coord_y), parentVoice(v), parentStaffSystem(ss), duration(dur)
{
}

MusicEvent::~MusicEvent()
{
}