#ifndef SYSTEMMODELS_H
#define SYSTEMMODELS_H

#include <QList>
#include <QMultiMap>
#include <QString>
#include "ModelBase.h"
#include "StaffCoords.h"
#include "ClefInfo.h"

#warning temp KeySignature & TimeSignature
typedef int KeySignatureInfo;
typedef int TimeSignatureInfo;

namespace Model {

class SystemImage
{
protected:
    QString filename;
public:
    SystemImage(QString filename = "");
    ~SystemImage();
};

// -----------------------------------------------------------------------------

class System: public ModelBase // a.k.a. Page
{
protected:
    QList<SystemImage> image_list;
    explicit System();
public:
    explicit System(ScoreModel *sm_ptr, IdRegister& registered_in, QObject * parent = 0);
    ~System();
    virtual void complementCreationList(QList<ScoreChange> *list);
};

// -----------------------------------------------------------------------------

class StaffSystemElement; // forward declaration

class StaffSystem: public ModelBase {
protected:
    QMultiMap<StaffCoords, StaffSystemElement*> elements;
    explicit StaffSystem();
public:
    explicit StaffSystem(ScoreModel *sm_ptr, IdRegister& registered_in, QObject * parent = 0);
    ~StaffSystem();
    void addElement(StaffSystemElement *sse);
    QMultiMap<StaffCoords, StaffSystemElement*>::Iterator findMe(StaffSystemElement *child_sse); // zwraca iterator do obiektu child_sse w mapie StaffSystemu
    bool amIFirst(StaffSystemElement *child_sse);
    bool amILast(StaffSystemElement *child_sse);
    virtual void complementCreationList(QList<ScoreChange> *list);
};

// -----------------------------------------------------------------------------

class StaffSystemElement: public ModelBase {
protected:
    StaffCoords position;
    explicit StaffSystemElement();
public:
    explicit StaffSystemElement(ScoreModel *sm_ptr, IdRegister& registered_in, QObject * parent = 0, StaffCoords coords = StaffCoords());
    explicit StaffSystemElement(ScoreModel *sm_ptr, IdRegister& registered_in, QObject * parent = 0, qreal coord_x = 0, qreal coord_y = 0);
    ~StaffSystemElement();
    int compare(const StaffSystemElement& sse2) const;
    bool inline operator=(const StaffSystemElement& sse2) const;
    StaffCoords getCoords();
    StaffSystemElement * previous();
    StaffSystemElement * next();
//    virtual void complementCreationList(QList<ScoreChange> *list);
};

// -----------------------------------------------------------------------------

class Clef: public StaffSystemElement {
private:
    ClefInfo info;
    explicit Clef();
public:
    explicit Clef(ScoreModel *sm_ptr, IdRegister& registered_in, QObject * parent = 0, StaffCoords coords = StaffCoords());
    explicit Clef(ScoreModel *sm_ptr, IdRegister& registered_in, ClefInfo c_info, ModelBase * parent = 0, StaffCoords coords = StaffCoords());
//    explicit Clef(IdRegister& registered_in, ClefType c_type, int c_position, int c_octave = 0, ModelBase * parent = 0);
    ~Clef();
    virtual void complementCreationList(QList<ScoreChange> *list);
};

// -----------------------------------------------------------------------------

typedef int KeySignatureInfo;
class KeySignature: public ModelBase {
private:
    StaffCoords position;
    KeySignatureInfo signature;
    explicit KeySignature();
public:
    explicit KeySignature(ScoreModel *sm_ptr, IdRegister& registered_in, ModelBase * parent = 0);
    ~KeySignature();
    virtual void complementCreationList(QList<ScoreChange> *list);
};

// -----------------------------------------------------------------------------

class TimeSignature: public ModelBase {
private:
    explicit TimeSignature();
    StaffCoords position;
    TimeSignatureInfo signature;
public:
    explicit TimeSignature(ScoreModel *sm_ptr, IdRegister& registered_in, QObject * parent = 0);
    ~TimeSignature();
    virtual void complementCreationList(QList<ScoreChange> *list);
};

}

#endif // SYSTEMMODELS_H
