#ifndef TABWIDGET_H
#define TABWIDGET_H

// Librerías Internas
#include "TabWidget_global.h"
#include "TabWidgetCorner.h"

// Librerías Qt
#include <QFlags>
#include <QFocusEvent>
#include <QHBoxLayout>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QResizeEvent>
#include <QShowEvent>
#include <QSizePolicy>
#include <QString>
#include <QTabBar>
#include <QTabWidget>
#include <QThread>
#include <QTimerEvent>
#include <QWidget>

class TabWidgetCorner;

class TABWIDGETSHARED_EXPORT TabWidget : public QTabWidget {

    Q_OBJECT

  public:
    explicit TabWidget ( bool collapsible = true, bool animated = true, QWidget *parent = 0 );

    /*bool getLockedTabWidget () const;
    bool getOpenTabWidget () const;
    int getPreviousHeight () const;
    QParallelAnimationGroup *getToggleAnimation () const;
    void leaveEvent ( QEvent *event ) Q_DECL_OVERRIDE;
    void setAnimation ();
    void setCornerWidget ( QWidget *widget, Qt::Corner corner = Qt::TopRightCorner );
    void setLockedTabWidget ( bool value );
    void setOpenTabWidget ( bool value );
    void setPreviousHeight ( int value );*/

    bool isAnimated () const;
    bool isCollapsible () const;
    bool isFloating () const;
    void setAnimated ( bool value );
    void setCollapsible ( bool value );
    void setCornerPosition ( QTabWidget::TabPosition cornerPosition );
    void setFloating ( bool value );
    void setTabPosition ( QTabWidget::TabPosition tabPosition );
    //void timerEvent ( QTimerEvent *timerEvent ) Q_DECL_OVERRIDE;




  protected:
    //void resizeEvent ( QResizeEvent *event ) Q_DECL_OVERRIDE;

  public slots:
    //void launchAnimation ();

  private:
    TabWidgetCorner *corner = nullptr;
    /*QParallelAnimationGroup *toggleAnimation;
    bool lockedTabWidget = false;
    bool openTabWidget = true;
    int previousIndex;
    int previousHeight;
    int timerId;
    bool finishedAnimation = false;*/
    bool collapsible;
    bool animated;
    bool floating;
};

#endif // TABWIDGET_H