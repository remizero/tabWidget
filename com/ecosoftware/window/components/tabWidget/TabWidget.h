#ifndef TABWIDGET_H
#define TABWIDGET_H

// Librerías Internas
#include "TabWidget_global.h"
#include "CornerWidget.h"
#include "TabBar.h"
#include "ShowHideTabAct.h"

// Librerías Qt
#include <QAction>
#include <QEvent>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QResizeEvent>
#include <QShowEvent>
#include <QTabBar>
#include <QTabWidget>
#include <QToolButton>
/*
#include <QFlags>
#include <QFocusEvent>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QString>
#include <QTimerEvent>
#include <QWidget>
*/

class CornerWidget;

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace TabWidget {

          class TABWIDGETSHARED_EXPORT TabWidget : public QTabWidget {

              Q_OBJECT

            public:
              explicit TabWidget ( bool collapsible = true, bool animated = true, QTabWidget::TabPosition tabPosition = QTabWidget::North, QWidget *parent = 0 );

              enum CornerPosition {

                None = -1,
                Top,
                Bottom,
                Left,
                Right
              };
              Q_ENUM ( CornerPosition )

              void addActionCorner ( QAction *action, TabWidget::CornerPosition cornerPosition );
              TabWidget::CornerPosition getIndicatorPosition () const; // LISTO
              bool isAnimated () const; // LISTO
              bool isCollapsible () const; // LISTO
              bool isFloating () const;
              bool isTabLocked () const; // LISTO
              bool isTabOpened () const; // LISTO
              void setAnimated ( bool value );
              void setCollapsible ( bool value );
              void setDuration ( int msecs ); // LISTO
              void setEasingCurve ( const QEasingCurve &easing ); // LISTO
              void setIndicatorPosition ( TabWidget::CornerPosition cornerPosition );
              void setFloating ( bool value );
              void setTabPosition ( QTabWidget::TabPosition tabPosition );

            public slots:
              void launchAnimation (); // LISTO
              void onDobleClick (); // LISTO

            signals:
              void toCollapse ( bool toCollapse ); // LISTO

            protected:
              void leaveEvent ( QEvent *event ) Q_DECL_OVERRIDE; // LISTO
              void resizeEvent ( QResizeEvent *event ) Q_DECL_OVERRIDE; // LISTO
              void showEvent ( QShowEvent *event ) Q_DECL_OVERRIDE; // LISTO

            private slots:
              void onCollapse ( bool onCollapse ); // LISTO
              void onStoppedAnimation (); // LISTO

            private:
              /*
    int timerId;
    bool finishedAnimation = false;*/
              /**
               * @brief cornerTopLeft
               * Esquina izquierda/superior del QTabWidget para las posiciones North/West del QTabBar
               */
              CornerWidget *cornerTopLeft = nullptr; // LISTO
              /**
               * @brief cornerBottomRight
               * Esquina derecha/inferior del QTabWidget para las posiciones South/East del QTabBar
               */
              CornerWidget *cornerBottomRight = nullptr; // LISTO
              /**
               * @brief collapsible
               * Indica si se puede expandir/contraer el QTabWidget.
               */
              bool collapsible = false;
              /**
               * @brief animated
               * Indica si la acción expandir/contraer del QTabWidget será animada.
               */
              bool animated = false;
              bool floating = false;
              /**
               * @brief indicatorPosition
               * Indica la posición de la acción showHideTabAct, puede ser Top, Bottom, Left, Right.
               */
              TabWidget::CornerPosition indicatorPosition = TabWidget::None;
              /**
               * @brief showHideTabAct
               * Acción indicadora para expandir/contraer del QTabWidget.
               */
              ShowHideTabAct *showHideTabAct = nullptr;
              /**
               * @brief previousHeight
               * Indica el valor de la altura que deberá retornar al momento de expandir el QTabWidget.
               */
              int previousHeight;
              /**
               * @brief maxHeightPropertyAnimation
               * Representa la animación que se realizará para contraer el QTabWidget si animated es true.
               */
              QPropertyAnimation *collapsedAnimation = nullptr;
              /**
               * @brief minHeightPropertyAnimation
               * Representa la animación que se realizará para expandir el QTabWidget si animated es true.
               */
              QPropertyAnimation *uncollapsedAnimation = nullptr;
              TabBar *customTabBar = nullptr;
              bool lockedTabWidget = false;
              int previousIndex = 0;
              int minimunValue = 0;
              bool openTabWidget = true;

              void collapsed (); // LISTO
              void uncollapsed (); // LISTO
              void collapsedAnimated (); // LISTO
              void collapsedUnanimated (); // LISTO
              void uncollapsedAnimated (); // LISTO
              void uncollapsedUnanimated (); // LISTO
              void removeShowHideBtn (); // LISTO
              void setAnimation ();
          };
        }
      }
    }
  }
}

#endif // TABWIDGET_H
