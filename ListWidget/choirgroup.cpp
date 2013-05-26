#include "choirgroup.h"
#include "staff.h"

ChoirGroup::ChoirGroup(QString name, Score *sc, QWidget *parent) :
    InnerList(name, parent)
{
    score = sc;
    setMyStyle();
    setButtonText("Add Staff");
    layout->setMargin(3);

    setDraggableType("ChoirGroup");

    // setAcceptedDrops
    QSet<QString> tmp;
    tmp.insert("Staff");
    tmp.insert("ChoirGroup");

    setAcceptedDrops(tmp);
    connect(this, SIGNAL(rename(ListItem*,QString)), score, SLOT(elementRenamed(ListItem*,QString)));
    connect(this, SIGNAL(moved(ListItem*,ListItem*)), score, SLOT(elementMoved(ListItem*,ListItem*)));
}

void ChoirGroup::setMyStyle()
{
    setObjectName("ChoirGroup");
    setStyleSheet(
                "ChoirGroup {"
                "border-left: 2px solid black;"
                //"border-top-left-radius: 10px"
                "}"
        );
}


QWidget * ChoirGroup::defaultElement()
{
    return new Staff("staff", score);
}

void ChoirGroup::slotAddElement()
{
    score->elementAdded(UserAction::CreateStaff, this);
}
